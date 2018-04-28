//
//  TextSearchViewController.m
//  搜索控制器Demo
//
//  Created by 樊小聪 on 2017/6/7.
//  Copyright © 2017年 樊小聪. All rights reserved.
//

#import "DeviceSearchViewController.h"
#import "DisplayModel.h"
#import "DisplayCell.h"
#import "UITableViewCell+HYBMasonryAutoCellHeight.h"
#import "WebDescriptionViewController.h"
@interface DeviceSearchViewController ()

@property (assign , nonatomic) NSInteger page;

@end


static NSString * const cellIdentifier = @"DisplayCell";

@implementation DeviceSearchViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = @"设备列表";
    [self.tableView registerClass:[DisplayCell class] forCellReuseIdentifier:cellIdentifier];
    MJRefreshNormalHeader *header = [MJRefreshNormalHeader headerWithRefreshingTarget:self refreshingAction:@selector(setupData:)];
    self.tableView.mj_header = header;
    
    MJRefreshBackNormalFooter *footer = [MJRefreshBackNormalFooter footerWithRefreshingTarget:self refreshingAction:@selector(setupData:)];
    self.tableView.mj_footer = footer;
    __weak typeof(self)weakSelf = self;
    
    /// 更新数据
    self.updateSearchResultsConfigure = ^(NSString *searchText,BOOL isSearching){
        if (!searchText.length) {
            weakSelf.searchResults = nil;
            [weakSelf.tableView reloadData];
            return;
        }
        if (isSearching && searchText.length) {
            [MBProgressHUD showHUDAddedTo:weakSelf.view animated:YES];
            [[MiaoHealthConnectManager shareInstance] fetchDevice:weakSelf.typeId Keyword:searchText result:^(NSMutableArray<MCDevice *> * _Nullable deviceArray, NSError * _Nullable error) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    [MBProgressHUD hideHUDForView:weakSelf.view animated:YES];
                    if (!error) {
                        weakSelf.searchResults = [NSArray arrayWithArray:deviceArray];
                        [weakSelf.tableView reloadData];
                    }else{
                        [[[UIAlertView alloc] initWithTitle:@"错误提示" message:error.domain delegate:nil cancelButtonTitle:@"取消" otherButtonTitles:@"确定", nil] show];
                    }
                });
            }];
        }else{
            [weakSelf.tableView reloadData];
        }
    };
    
    
    /// 配置 cell
    self.cellForRowAtIndexPathConfigure = ^(UITableView *tableView, NSIndexPath *indexPath, BOOL isSearching){
        DisplayCell *cell = [DisplayCell displayCellWithTableView:tableView];
        MCDevice *device = isSearching ? weakSelf.searchResults[indexPath.row] : weakSelf.dataArr[indexPath.row];
        DisplayModel *model = [[DisplayModel alloc] init];
        model.name = [device device_name];
        model.descr = @"";
        model.imageUrl = [device logo];
        model.link_type = device.link_type;
        cell.displayModel = model;
        return cell;
    };
    
    /// 点击了某一行
    self.didSelectRowAtIndexPathConfigure = ^(UITableView *tableView, NSIndexPath *indexPath, BOOL isSearching){
        if (isSearching) {
            WebDescriptionViewController *displayVC = [[WebDescriptionViewController alloc] init];
            MCDevice *device = isSearching ? weakSelf.searchResults[indexPath.row] : weakSelf.dataArr[indexPath.row];
            NSDictionary *dict = device.mj_keyValues;
            displayVC.device = [MCDevice mj_objectWithKeyValues:dict];
            displayVC.deviceDetailFromEnum = DeviceDetailFromEnumDeviceType;
            [weakSelf.searchController.searchBar endEditing:YES];
            weakSelf.searchController.active = NO;
//            MHWebViewController *webViewVC = [[MHWebViewController alloc] init];
//            webViewVC.url = @"https://www.baidu.com";
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                [weakSelf.navigationController pushViewController:displayVC animated:YES];
            });
        }else{
            WebDescriptionViewController *displayVC = [[WebDescriptionViewController alloc] init];
            displayVC.device = isSearching ? weakSelf.searchResults[indexPath.row] : weakSelf.dataArr[indexPath.row];;
            displayVC.deviceDetailFromEnum = DeviceDetailFromEnumDeviceType;
//            MHWebViewController *webViewVC = [[MHWebViewController alloc] init];
//            webViewVC.url = @"https://www.baidu.com";
            [weakSelf.navigationController pushViewController:displayVC animated:YES];
        }
    };
    
    self.heightForRowAtIndexPathConfigure = ^CGFloat(UITableView *tableView, NSIndexPath *indexPath, BOOL isSearching) {
        MCDevice *device = isSearching ? weakSelf.searchResults[indexPath.row] : weakSelf.dataArr[indexPath.row];
        DisplayModel *model = [[DisplayModel alloc] init];
        model.name = [device device_name];
        model.descr = [device device_des];
        model.imageUrl = [device logo];
        model.link_type = device.link_type;
        CGFloat height = [DisplayCell hyb_heightForTableView:tableView config:^(UITableViewCell *sourceCell) {
            DisplayCell *cell = (DisplayCell *)sourceCell;
            // 配置数据
            [cell setDisplayModel:model];
        } cache:^NSDictionary *{
            return @{kHYBCacheUniqueKey: [NSString stringWithFormat:@"%ld",(long)indexPath.row],
                     kHYBCacheStateKey : @"expanded",
                     // 如果设置为YES，若有缓存，则更新缓存，否则直接计算并缓存
                     // 主要是对社交这种有动态评论等不同状态，高度也会不同的情况的处理
                     kHYBRecalculateForStateKey : @(NO) // 标识不用重新更新
                     };
        }];
        return height;
    };
    [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    
    self.page = 1;
    [self.dataArr removeAllObjects];
    /// 设置数据
    [self setupData:[[MJRefreshNormalHeader alloc] init]];
}

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated{
    [super viewWillDisappear:animated];
//    [self.searchController.searchBar setHidden:YES];
}
/**
 *  设置数据
 */
- (void)setupData:(id)refreshType
{
    if (self.searchController.active) {
        [self.tableView.mj_footer endRefreshing];
        [self.tableView.mj_header endRefreshing];
        return;
    }
    self.page = ([refreshType isKindOfClass:[MJRefreshNormalHeader class]]) ? 1 : (++self.page);
    [[MiaoHealthConnectManager shareInstance] fetchDeviceList:self.typeId pageNO:self.page result:^(NSMutableArray<MCDevice *> *deviceArray, NSError * _Nullable error) {
        [MBProgressHUD hideHUDForView:self.view animated:YES];
        if (error){
            self.page--;
            [[[UIAlertView alloc] initWithTitle:@"错误提示" message:error.domain delegate:nil cancelButtonTitle:@"取消" otherButtonTitles:@"确定", nil] show];
        } else {
            
            (!deviceArray.count) ? self.page-- : NO;
            
            if (([refreshType isKindOfClass:[MJRefreshNormalHeader class]])) {
                [self.dataArr removeAllObjects];
                self.dataArr = (NSMutableArray<id> *)deviceArray;
            }else{
                [self.dataArr addObjectsFromArray:deviceArray];
            }
            [self.tableView reloadData];
        }
        [self.tableView.mj_footer endRefreshing];
        [self.tableView.mj_header endRefreshing];
    }];
}

- (void)scrollViewWillBeginDragging:(UIScrollView *)scrollView{
    [self.searchController.searchBar endEditing:YES];
    [self.view endEditing:YES];
}

@end
