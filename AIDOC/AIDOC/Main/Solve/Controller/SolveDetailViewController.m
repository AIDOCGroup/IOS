//
//  SolveDetailViewController.m
//  AlarmDemo
//
//  Created by apple on 16/7/13.
//  Copyright © 2016年 apple. All rights reserved.
//

#import "SolveDetailViewController.h"
#import "MeCell.h"
#import "EquipmentModel.h"
@interface SolveDetailViewController ()<UITableViewDelegate,UITableViewDataSource>

@property (nonatomic, strong)UITableView *tableView;
@property (nonatomic, strong)EquipmentModel *equipmentModel;
@end


@implementation SolveDetailViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    _tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, kScreenHeight + 49) style:UITableViewStyleGrouped];
    _tableView.backgroundColor = [UIColor clearColor];
    _tableView.delegate = self;
    _tableView.dataSource = self;
    [self.view addSubview:_tableView];
    
    //请求数据
    [self _loadDetailData];
}

//请求数据
- (void)_loadDetailData{
    
    [YTNetworkRequest loadDeviceWithBuildID:_build_ID success:^(id result) {
        
        NSLog(@"%@",result);
        
        NSDictionary *resultDic = [result valueForKey:@"data"];
        _equipmentModel = [[EquipmentModel alloc] initContentWithDic:resultDic];
        _equipmentModel.build_ID = [resultDic valueForKey:@"id"];
        
        self.title = _equipmentModel.name;
        [_tableView reloadData];
    } failure:^(NSString *error) {
        
    }];
}


#pragma -UITableViewDataSource
#pragma mark -
#pragma mark UITableViewDataSource
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 5;
}
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    if (section == 1 || section == 2 || section == 4) {
        return 2;
    }else if (section == 3){
        
        return 3;
    }
    
    return 1;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    
    static NSString *identify = @"MeCell";
    MeCell *cell = [tableView dequeueReusableCellWithIdentifier:identify];
    if (cell == nil) {
        cell = [[MeCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:identify];
    }
    
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
   
    
    tableView.separatorStyle = UITableViewCellSeparatorStyleSingleLine;
    cell.imgStr = @"icon_details_left";
    cell.isSmallImg = YES;
    cell.isDetail = YES;
    cell.isInfomation = NO;
    
    if (indexPath.section == 0){

        cell.itemName.text = @"位置";
        cell.detailLabel.text = _equipmentModel.position;
        
        
    }else  if (indexPath.section == 1){
        
        if (indexPath.row == 0) {
            
            cell.itemName.text = @"制造商";
            cell.detailLabel.text = _equipmentModel.maker;
            

            
        }
        else if (indexPath.row == 1){
            

            cell.itemName.text = @"型号";
            cell.detailLabel.text = _equipmentModel.model;
            
        }
        
        
    }else  if (indexPath.section == 2){
        
        if (indexPath.row == 0) {
            
            cell.itemName.text = @"SIM卡号";
            cell.detailLabel.text = _equipmentModel.phone;

        }
        else if (indexPath.row == 1){
            
            
            cell.itemName.text = @"类型";
            cell.detailLabel.text = _equipmentModel.typeName;
            
        }
        
        
    }else if (indexPath.section == 3){
        
        if (indexPath.row == 0) {
    
            cell.itemName.text = @"所属企业";
            cell.detailLabel.text = _equipmentModel.orgName;
            

             
        }else if (indexPath.row == 1){
            
            cell.itemName.text = @"状态";
            
            if ([_equipmentModel.flag intValue]==1) {
            
                cell.detailLabel.text = @"正常";
            }
            
            

            
        }else if (indexPath.row == 2){
            
            cell.itemName.text = @"编号";
            cell.detailLabel.text = _equipmentModel.sn;
            
        }

        
        
    }else if (indexPath.section == 4){
        
        if (indexPath.row == 0) {
            
            cell.itemName.text = @"水压报警上限";
            cell.detailLabel.text = [NSString stringWithFormat:@"%.1fMPa",[_equipmentModel.max floatValue]];
            
            
            
        }
        else if (indexPath.row == 1){
            
            
            cell.itemName.text = @"水压报警下限";
            cell.detailLabel.text = [NSString stringWithFormat:@"%.1fMPa",[_equipmentModel.min floatValue]];
            
        }
        
        
    }
    
    return cell;
}

//cell 分割线 两端封头 实现这个两个方法 1
-(void)viewDidLayoutSubviews
{
    [super viewDidLayoutSubviews];
    if ([_tableView respondsToSelector:@selector(setSeparatorInset:)]) {
        [_tableView setSeparatorInset:UIEdgeInsetsZero];
    }
    
    if ([_tableView respondsToSelector:@selector(setLayoutMargins:)]) {
        [_tableView setLayoutMargins:UIEdgeInsetsZero];
    }
}

//cell 分割线 两端封头 实现这个两个方法 1
-(void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ([cell respondsToSelector:@selector(setSeparatorInset:)]) {
        [cell setSeparatorInset:UIEdgeInsetsZero];
    }
    
    if ([cell respondsToSelector:@selector(setLayoutMargins:)]) {
        [cell setLayoutMargins:UIEdgeInsetsZero];
    }
}

#pragma -UITableViewDelegate
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 60;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    if (section == 0) {
        return 10;
    }
    return 5;
}
- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section
{
    if (section == 3) {
        return 10;
    }
    return 5;
}

- (UIView *)tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section
{
    float height = 5;
    
    if (section == 3) {
        height = 10;
    }
    
    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, height)];
    view.backgroundColor = [UIColor clearColor];
    return view;
}

- (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section
{
    float height = 5;
    
    if (section == 0) {
        height = 10;
    }
    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, height)];
    view.backgroundColor = [UIColor clearColor];
    return view;
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
