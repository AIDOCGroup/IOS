//
//  DeviceTypeViewController.m
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/7/13.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import "DeviceTypeViewController.h"
#import "DeviceTypeCell.h"
#import "DeviceSearchViewController.h"

@interface DeviceTypeViewController ()<UICollectionViewDelegate,UICollectionViewDataSource>

@property (nonatomic , weak) UICollectionView *collectionView;

@property (nonatomic  ,strong) NSArray *typeArray;

@end

@implementation DeviceTypeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = @"设备类型";
    self.automaticallyAdjustsScrollViewInsets = NO;
    [self initMiaoHealthConnectManager];
}

- (void)setupData{
    kWeakSelf(self);
    [[MiaoHealthConnectManager shareInstance] fetchDeviceTypeList:^(NSMutableArray<MCDeviceType *> * _Nullable deviceTypeArray, NSError * _Nullable error) {
        [MBProgressHUD hideHUDForView:self.view animated:YES];
        if (error) {
        }else if(deviceTypeArray.count) {
            weakself.typeArray = deviceTypeArray;
            [weakself.collectionView reloadData];
        }
    }];
}

#pragma mark - lazy collectionView;
- (UICollectionView *)collectionView{
    if (!_collectionView) {
        //此处必须要有创见一个UICollectionViewFlowLayout的对象
        UICollectionViewFlowLayout *layout=[[UICollectionViewFlowLayout alloc]init];
        //同一行相邻两个cell的最小间距
        layout.minimumInteritemSpacing = 5;
        //最小两行之间的间距
        layout.minimumLineSpacing = 5;
        layout.sectionInset = UIEdgeInsetsMake(10, 10, 0, 10);
        
        UICollectionView *collectionView = [[UICollectionView alloc] initWithFrame:CGRectMake(0, kNavigationHeight.integerValue, kMainScreenWidth, kMainScreenHeight - kNavigationHeight.integerValue) collectionViewLayout:layout];
        collectionView.backgroundColor=[UIColor whiteColor];
        collectionView.delegate=self;
        collectionView.dataSource=self;
        [collectionView registerClass:[DeviceTypeCell class] forCellWithReuseIdentifier:@"DeviceTypeCell"];
        [self.view addSubview:collectionView];
        _collectionView = collectionView;
    }
    return _collectionView;
}

#pragma mark - collectionView Delegate
//一共有多少个组
-(NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView{
    return 1;
}
//每一组有多少个cell
-(NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section{
    return self.typeArray.count;
}
//每一个cell是什么
-(UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath{
    DeviceTypeCell *cell = [DeviceTypeCell deviceTypeCell:collectionView indexPath:indexPath];
    cell.deviceType = [self.typeArray objectAtIndex:indexPath.row];
    cell.backgroundColor=[UIColor groupTableViewBackgroundColor];
    return cell;
}

//定义每一个cell的大小
- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath
{
    return CGSizeMake((kMainScreenWidth - (4 * 5) - 20) / 3, 90);
}

//cell的点击事件
-(void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath{
    //cell被点击后移动的动画
    [collectionView selectItemAtIndexPath:indexPath animated:YES scrollPosition:UICollectionViewScrollPositionTop];
    DeviceSearchViewController *searchVC = [[DeviceSearchViewController alloc] init];
    MCDeviceType *type = [self.typeArray objectAtIndex:indexPath.row];
    searchVC.typeId = type.tid;
    [self.navigationController pushViewController:searchVC animated:YES];
}

#pragma mark - 妙健康sdk
- (void)initMiaoHealthConnectManager {
    [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    [[MiaoHealthConnectManager shareInstance] initWithAppid:OpenID appkey:OpenSecret officialVersion:OfficialVersionTypePro resultBlock:^(NSError * _Nullable error) {
        [[NSUserDefaults standardUserDefaults] setObject:[CommonFunc getUserHealthModelKey] forKey:@"APPID"];
        [[NSUserDefaults standardUserDefaults] synchronize];
        [[NSUserDefaults standardUserDefaults] setObject:OpenSecret forKey:@"APPSecret"];
        [[NSUserDefaults standardUserDefaults] synchronize];
        if (!error) {//初始化成功
            [[MiaoHealthConnectManager shareInstance] registerUserIdentity:[CommonFunc getUserHealthModelKey] resultBlock:^(NSError * _Nullable error) {
                [MBProgressHUD hideHUDForView:self.view animated:YES];
                if (!error) {//注册成功
                    [self setupData];
                }else {
                    NSLog(@"注册失败");
                }
            }];
        }else {
            [MBProgressHUD hideHUDForView:self.view animated:YES];
            NSLog(@"初始化未成功");
        }
    }];
}

@end
