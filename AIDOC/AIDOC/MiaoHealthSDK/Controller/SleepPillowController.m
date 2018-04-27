//
//  SleepPillowController.m
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2018/3/7.
//  Copyright © 2018年 MiaoHealth. All rights reserved.
//

#import "SleepPillowController.h"
#import "DataViewController.h"

@interface SleepPillowController ()
@property (weak, nonatomic) IBOutlet UIButton *startButton;
@property (weak, nonatomic) IBOutlet UIButton *endButton;
@property (weak, nonatomic) IBOutlet UIButton *historyButton;
@property (weak, nonatomic) IBOutlet UIButton *bindButton;
@end

@implementation SleepPillowController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    [self.bindButton setTitle:(self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) ? @"绑定设备" : @"解绑设备" forState:0];
}
- (IBAction)startAction:(id)sender {
    [[MiaoHealthConnectManager shareInstance] beginRecordResponedata:^(PeripheralsDataType peripheralsDataType, id  _Nullable result, NSError * _Nullable error) {
        if (!error) {
            NSLog(@"%@",@"开启录音成功");
        }else {
            NSLog(@"%@",@"开启录音失败\n请检查录音权限是否打卡");
        }
    }];
}

- (IBAction)endAction:(id)sender {
    NSString *openID = [[NSUserDefaults standardUserDefaults] objectForKey:@"APPID"];
    [[MiaoHealthConnectManager shareInstance] stopRecordResponedata:^(PeripheralsDataType peripheralsDataType, id  _Nullable result, NSError * _Nullable error) {
        DataViewController *dataVC = [[DataViewController alloc] init];
        [dataVC setDataArray:[NSMutableArray arrayWithObject:result]];
        [dataVC setPeripheralsDataType:PeripheralsDataTypeSleepPro];
        [self.navigationController pushViewController:dataVC animated:YES];
    } deviceSN:self.deviceSN uuid:openID];
}


- (IBAction)historyDataAction:( id)sender {
    [self fetchDeviceDataAPI:PeripheralsDataTypeSleepPro];
}

- (void)fetchDeviceDataAPI:(PeripheralsDataType) peripheralsDataType{
    
    typeof(self) __weak weakSelf = self;
    
    long long currentTimeInterval = [[NSDate date] timeIntervalSince1970];
    //    long long startTime = (currentTimeInterval - 24 * 3600 * 7) * 1000;
    //    long long endTime   = currentTimeInterval * 1000;
    long long startTime = 0;
    long long endTime   = 0;
    NSString *openID = [[NSUserDefaults standardUserDefaults] objectForKey:@"APPID"];
    [[MiaoHealthConnectManager shareInstance] fetchApiDeviceData:self.deviceSN device_no:openID functionId:11 startTime:startTime end:endTime queryComplete:^(NSArray * _Nullable queryResponse, NSError * _Nullable error) {
        typeof(self) __strong strongSelf = weakSelf;
        DataViewController *dataVC = [[DataViewController alloc] init];
        [dataVC setDataArray:[NSMutableArray arrayWithArray:queryResponse]];
        [dataVC setPeripheralsDataType:peripheralsDataType];
        [strongSelf.navigationController pushViewController:dataVC animated:YES];
    }];
}
- (IBAction)bindAction:(id)sender {
    typeof(self) __weak weakSelf = self;
    NSString *openID = [[NSUserDefaults standardUserDefaults] objectForKey:@"APPID"];
    if (self.deviceDetailFromEnum == DeviceDetailFromEnumDeviceType) {
        [[MiaoHealthConnectManager shareInstance] bindDevice:self.deviceSN deviceNO:openID bind:^(NSInteger isSuccess,NSString *_Nullable device_no, NSError * _Nullable error) {
            if (!error) {
                NSLog(@"绑定成功");
            }else {
                NSLog(@"%@",error.domain);
            }
        }];
    }else{
        [[MiaoHealthConnectManager shareInstance] unbindDevice:self.deviceSN deviceNO:openID bind:^(NSInteger isSuccess, NSString *_Nullable device_no,NSError * _Nullable error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                if (!error) {
                    NSLog(@"解绑成功");
                }else {
                    NSLog(@"%@",error.domain);
                }
            });
        }];
    }
}
@end
