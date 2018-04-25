//
//  WeightViewController.m
//  AIDOC
//
//  Created by app on 2018/3/26.
//  Copyright © 2018年 app. All rights reserved.
//

#import "WeightViewController.h"

#import "HeartHisModel.h"
#import "WeightCell.h"

@interface WeightViewController ()
@property (strong, nonatomic) NSMutableArray *dataArr;
@property (assign , nonatomic) NSInteger page;

@end

@implementation WeightViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = @"历史记录";
    [self setupSubviews];
    [self _loadData:[[MJRefreshNormalHeader alloc] init]];
}

- (void)_loadData:(id)refreshType{
    
    self.page = ([refreshType isKindOfClass:[MJRefreshNormalHeader class]]) ? 1 : (++self.page);
    
    [YTNetworkRequest getDeviceHeartWeight:self.page success:^(id result) {
        
        NSLog(@"result = %@",result);
        NSMutableArray *resultArr = [NSMutableArray array];
        
        for (NSDictionary *dic in result) {
            HeartHisModel *model = [[HeartHisModel alloc] initContentWithDic:dic];
            [resultArr addObject:model];
        }
        if (([refreshType isKindOfClass:[MJRefreshNormalHeader class]])) {
            
            [self.dataArr removeAllObjects];
            self.dataArr = resultArr;
        }else{
            [self.dataArr addObjectsFromArray:resultArr];
        }
        
        [self.tableView reloadData];
        [self.tableView.mj_footer endRefreshing];
        [self.tableView.mj_header endRefreshing];
        
    } failure:^(NSString *error) {
        
    }];
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - UI
- (void)setupSubviews {
    [self initializeTableView];
    MJRefreshNormalHeader *header = [MJRefreshNormalHeader headerWithRefreshingTarget:self refreshingAction:@selector(_loadData:)];
    self.tableView.mj_header = header;
    
    MJRefreshBackNormalFooter *footer = [MJRefreshBackNormalFooter footerWithRefreshingTarget:self refreshingAction:@selector(_loadData:)];
    self.tableView.mj_footer = footer;
}

#pragma mark - lazy loading
- (NSMutableArray *)dataArr {
    if (!_dataArr) {
        _dataArr = [NSMutableArray array];
    }
    return _dataArr;
}

#pragma mark - super
- (void)initializeTableView {
    CGRect frame = CGRectMake(0, kNavH, SCREEN_WIDTH, SCREEN_HEIGHT-kNavH);
    self.tableViewFrame = frame;
    [super initializeTableView];
    self.tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
}

#pragma mark - UITableViewDataSource
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    
    return self.dataArr.count;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    HeartHisModel *model = self.dataArr[section];
    NSMutableArray *arr = model.list;
    return arr.count;
}

- (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section {
    UIView *view = [[UIView alloc]initWithFrame:CGRectMake(0, 0, SCREEN_WIDTH, 40)];
    view.backgroundColor = [UIColor clearColor];
    
    
    UIView *infoview = [[UIView alloc]initWithFrame:CGRectMake(12, 10, SCREEN_WIDTH-12*2, 30)];
    infoview.backgroundColor = rgbColor(0xFF9098FF);
    infoview.layer.masksToBounds = YES;
    
    UIBezierPath *maskPath = [UIBezierPath bezierPathWithRoundedRect:infoview.bounds byRoundingCorners:UIRectCornerTopLeft | UIRectCornerTopRight cornerRadii:CGSizeMake(5, 5)];
    CAShapeLayer *maskLayer = [[CAShapeLayer alloc] init];
    maskLayer.frame = infoview.bounds;
    maskLayer.path = maskPath.CGPath;
    infoview.layer.mask = maskLayer;

    [view addSubview:infoview];
    
    UILabel *markLabel = [[UILabel alloc]init];
    markLabel.frame = CGRectMake(15, 8, SCREEN_WIDTH - 12*2 - 15*2, 13);
    markLabel.textColor = rgbColor(0xFFFFFFFF);
    markLabel.font = [UIFont systemFontOfSize:13];
    [infoview addSubview:markLabel];
    HeartHisModel *model = self.dataArr[section];
    markLabel.text = model.day;
    return view;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section {
    return 40;
}

- (UIView *)tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section {
    return nil;
}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section {
    return CGFLOAT_MIN;
}

- (NSArray *)sectionIndexTitlesForTableView:(UITableView *)tableView {
    return nil;
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *CellIdentifier = @"WeightCell";
    WeightCell *cell = [tableView cellForRowAtIndexPath:indexPath];
    if (!cell) {
        cell = [[WeightCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    }
    
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    HeartHisModel *heartHisModel = self.dataArr[indexPath.section];
    NSMutableArray *arr = heartHisModel.list;
    NSMutableArray *arrModel = [NSMutableArray array];
    for (NSDictionary *dic in arr) {
        HeartModel *model = [[HeartModel alloc] initContentWithDic:dic];
        [arrModel addObject:model];
    }
    cell.model = arrModel[indexPath.row];
    if (indexPath.row == arrModel.count-1) {
        cell.isLastCell = YES;
    }
    return cell;
}

#pragma mark - UITableViewDelegate
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 60;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    //数据
}


- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath {
    if ([cell respondsToSelector:@selector(setLayoutMargins:)]) {
        [cell setLayoutMargins:UIEdgeInsetsZero];
    }
    if ([cell respondsToSelector:@selector(setSeparatorInset:)]){
        [cell setSeparatorInset:UIEdgeInsetsZero];
    }
}

@end



