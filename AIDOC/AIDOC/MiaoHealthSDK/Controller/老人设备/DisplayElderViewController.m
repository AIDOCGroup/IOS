//
//  DisplayElderViewController.m
//  MiaoHealthConnectDemo
//
//  Created by 刘云梦 on 17/2/13.
//  Copyright © 2017年 刘云梦. All rights reserved.
//

#import "DisplayElderViewController.h"

#import <MiaoHealthConnect/MiaoHealthConnect.h>
#import "DataElderViewController.h"

@interface DisplayElderViewController ()<UITableViewDelegate, UITableViewDataSource>

@property (weak, nonatomic) IBOutlet UITableView *tableView;

@property (nonatomic, strong) NSMutableArray<NSString *> *messageArray;

@end

@implementation DisplayElderViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [_tableView setDataSource:self];
    [_tableView setDelegate:self];
    _messageArray = [NSMutableArray array];
}

- (void) setMessage:(NSString *) message {
    [_messageArray addObject:message];
    [_tableView reloadData];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)bindDeviceEvent:(id)sender {
    __weak typeof(self) weakSelf = self;
    [[MiaoHealthElderManager shareInstance] bindDevice:_device_sn deviceNO:_device_no name:@"haoletao" nickname:@"haoletao" mobile:@"12345678912" bind:^(NSInteger isSuccess, NSError * _Nullable error) {
        __strong typeof(self) strongSelf = weakSelf;
        [strongSelf setMessage: (isSuccess == 1 ? @"绑定成功" : [NSString stringWithFormat:@"绑定失败 :%@", error])];
    }];
}


- (IBAction)unbindDeviceEvent:(id)sender {
    __weak typeof(self) weakSelf = self;
    [[MiaoHealthElderManager shareInstance] unbindDevice:_device_sn deviceNO:_device_no bind:^(NSInteger isSuccess, NSError * _Nullable error) {
        __strong typeof(self) strongSelf = weakSelf;
        [strongSelf setMessage: (isSuccess == 1 ? @"解除绑定成功" : [NSString stringWithFormat:@"解除绑定失败 :%@", error])];
    }];
}



#pragma mark - UITableViewDelegate , DataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.messageArray count];
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"MessageCell"];
    cell.textLabel.text = self.messageArray[indexPath.row];
    
    return cell;
}

- (CGFloat) tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 50;
}

#pragma mark - StoryboardSegue跳转
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(UIButton *)sender {
    
    if (sender.tag > 0) {
        DataElderViewController *dataElderVC = segue.destinationViewController;
        [dataElderVC setDevice_no:_device_no];
        [dataElderVC setDevice_sn:_device_sn];
        [dataElderVC setType:sender.tag];
    }
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
