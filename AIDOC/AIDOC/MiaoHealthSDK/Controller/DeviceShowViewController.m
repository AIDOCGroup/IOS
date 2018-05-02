//
//  DeviceViewController.m
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/10/17.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import "DeviceShowViewController.h"
#import "DeviceView.h"
#import "DeviceCell.h"
#import "DeviceSectionCell.h"
#import "DeviceDetailViewController.h"
#import "SleepPillowController.h"

@interface DeviceShowViewController ()<UITableViewDelegate,UITableViewDataSource>
@property (nonatomic , strong) UITableView *tableView;
@property (nonatomic , strong) DeviceView *headView;
@property (nonatomic , strong) NSDictionary *deviceDictionary;
@end

@implementation DeviceShowViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.automaticallyAdjustsScrollViewInsets = NO;
    self.title = @"设备详情";
    // Do any additional setup after loading the view.
}

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    [[MiaoHealthConnectManager shareInstance] fetchDeviceDetail:self.device.device_sn result:^(NSDictionary * _Nullable deviceDetail, NSError * _Nullable error) {
        NSLog(@"device = %@",deviceDetail);
        self.deviceDictionary = deviceDetail;
        self.headView.name = [deviceDetail objectForKey:@"device_name"];
        self.headView.enName = [deviceDetail objectForKey:@"device_name_en"];
        self.headView.desc = [deviceDetail objectForKey:@"device_des"];
        self.headView.enDesc = [deviceDetail objectForKey:@"device_des_en"];
        self.headView.url = [deviceDetail objectForKey:@"buy_url"];
        [self.tableView reloadData];
    }];
}
- (DeviceView *)headView{
    if (!_headView) {
        DeviceView *headView = [DeviceView deviceView];
        self.tableView.tableHeaderView = headView;
        _headView = headView;
    }
    return _headView;
}
- (UITableView *)tableView{
    if (!_tableView) {
        UITableView *tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, kNavigationHeight.integerValue, kMainScreenWidth, kMainScreenHeight - kNavigationHeight.integerValue - 50)];
        tableView.delegate = self;
        tableView.dataSource = self;
        [tableView registerNib:[UINib nibWithNibName:@"DeviceSectionCell" bundle:nil] forCellReuseIdentifier:DeviceSectionCellIdentifier];
        [tableView registerNib:[UINib nibWithNibName:@"DeviceCell" bundle:nil] forCellReuseIdentifier:DeviceCellIdentifier];
        [self.view addSubview:tableView];
        
        UIButton *bindButton = [[UIButton alloc] initWithFrame:CGRectMake(0, kMainScreenHeight - 50, kMainScreenWidth, 50)];
        bindButton.backgroundColor = [UIColor groupTableViewBackgroundColor];
        [bindButton setTitle:@"前往绑定" forState:UIControlStateNormal];
        [bindButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [bindButton addTarget:self action:@selector(bindAction) forControlEvents:UIControlEventTouchUpInside];
        [self.view addSubview:bindButton];
        
        _tableView = tableView;
    }
    return _tableView;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return 3;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    if (section == 0) {
        return [[self.deviceDictionary objectForKey:@"proc_details"] count] + 1;
    }else if (section == 1){
        return [[self.deviceDictionary objectForKey:@"bind_guide"] count] + 1;
    }else if (section == 2){
        return [[self.deviceDictionary objectForKey:@"measure_guide"] count] + 1;
    }
    return 0;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    if (indexPath.row == 0) {
        NSString *title = @"";
        if (indexPath.section == 0) {
            title = @"设备描述";
        }else if (indexPath.section == 1){
            title = @"绑定说明";
        }else{
            title = @"测量方法说明";
        }
        DeviceSectionCell *cell = [DeviceSectionCell deviceSectionCellWithTableView:self.tableView];
        cell.title = title;
        return cell;
    }else{
        DeviceCell *cell = [DeviceCell deviceCell];
        NSArray *array = nil;
        if (indexPath.section == 0) {
            array = [self.deviceDictionary objectForKey:@"proc_details"];
        }else if (indexPath.section == 1){
            array = [self.deviceDictionary objectForKey:@"bind_guide"];
        }else{
            array = [self.deviceDictionary objectForKey:@"measure_guide"];
        }
        cell.num = [[array[indexPath.row - 1] objectForKey:@"order"] stringValue];
        cell.imageString = [array[indexPath.row - 1] objectForKey:@"img"];
        cell.descString = [array[indexPath.row - 1] objectForKey:@"desc"];
        cell.enDescString = [array[indexPath.row - 1] objectForKey:@"desc_en"];
        return cell;
    }
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    return (indexPath.row == 0) ? 60 : 130;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section{
    return 1;
}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section{
    return 1;
}
- (IBAction)bindAction{
    if (self.device.connect_type == 90) {
        SleepPillowController *vc = [[SleepPillowController alloc] init];
        vc.deviceSN = self.device.device_sn;
        vc.deviceDetailFromEnum = self.deviceDetailFromEnum;
        [self.navigationController pushViewController:vc animated:YES];
    }else{
        DeviceDetailViewController *vc = [[DeviceDetailViewController alloc] init];
        vc.device = self.device;
        vc.deviceDetailFromEnum = self.deviceDetailFromEnum;
        [self.navigationController pushViewController:vc animated:YES];
    }
}

@end
