//
//  SolveCallViewController.m
//  AlarmDemo
//
//  Created by apple on 16/7/12.
//  Copyright © 2016年 apple. All rights reserved.
//

#import "SolveCallViewController.h"
#import "AlarmModel.h"
#import "AlarmCell.h"
#import "CallDetailViewConteoller.h"
@interface SolveCallViewController ()<UITableViewDelegate,UITableViewDataSource>

@property (nonatomic, strong)UITableView *tableView;
@property(nonatomic, strong)NSMutableArray *alarmArr;

@end

@implementation SolveCallViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.title  =@"报警";
    _tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, kScreenHeight + 49) style:UITableViewStyleGrouped];
    _tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
    _tableView.backgroundColor = rgbColor(0xf1f1f1);
    _tableView.delegate = self;
    _tableView.dataSource = self;
    [self.view addSubview:_tableView];

    
    //请求数据
    [self _loadDetailData];
}

//请求数据
- (void)_loadDetailData{

    _alarmArr = [NSMutableArray array];
    
    [YTNetworkRequest LoadFindFireMessageWithBuildID:_build_ID success:^(id result) {
        
        NSLog(@"%@",result);
        NSMutableArray *resultArr = [NSMutableArray array];
       
        if ([[[result objectForKey:@"data"] valueForKey:@"list"] isKindOfClass:[NSString class]]) {
            
            UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(kScreenWidth/2.0 - 50, _tableView.centerY - 10, 100, 20)];
            label.text = @"暂无数据";
            label.textColor = [UIColor orangeColor];
            label.textAlignment = NSTextAlignmentCenter;
            label.font = [UIFont systemFontOfSize:14.0];
            [_tableView addSubview:label];
        }else
        {
            resultArr = [[result objectForKey:@"data"] objectForKey:@"list"];
            
            
            for (NSDictionary *dic in resultArr) {
                AlarmModel *model = [[AlarmModel alloc] initContentWithDic:dic];
                model.alarm_id = [dic valueForKey:@"id"];
                [_alarmArr addObject:model];
            }
            
            
        }

                
        [_tableView reloadData];
            

    } failure:^(NSString *error) {
        
    }];
}

#pragma -UITableViewDataSource
#pragma mark -
#pragma mark UITableViewDataSource
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return _alarmArr.count;
}
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{

    return 1;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    
    static NSString *identify = @"AlarmCell";
    AlarmCell *cell = [tableView dequeueReusableCellWithIdentifier:identify];
    if (cell == nil) {
        cell = [[AlarmCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:identify];
    }
    
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    
    cell.model = _alarmArr[indexPath.section];
    
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
    return 85;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    if (section == 0) {
        return 4;
    }
    return 2;
}
- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section
{
    if (section == _alarmArr.count - 1) {
        return 4;
    }
    return 2;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    CallDetailViewConteoller *calldetail = [[CallDetailViewConteoller alloc] init];
    calldetail.model = _alarmArr[indexPath.section];
    [self.navigationController pushViewController:calldetail animated:YES];

}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
