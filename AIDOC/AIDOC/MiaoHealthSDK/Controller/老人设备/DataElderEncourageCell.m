//
//  DataElderEncourageCell.m
//  MiaoHealthConnectDemo
//
//  Created by 刘云梦 on 17/2/13.
//  Copyright © 2017年 刘云梦. All rights reserved.
//

#import "DataElderEncourageCell.h"
#import <MiaoHealthConnect/MiaoHealthConnect.h>

@implementation DataElderEncourageCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
    [self setSelectedBackgroundView:[[UIView alloc] init]];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

- (IBAction)buttonEvent:(UIButton *)sender {
    if ([[MiaoHealthElderManager shareInstance] encourageElder:_device_sn deviceNO:_device_no type:sender.tag]){
        _alerMessage = @"关爱老人消息发送成功";
    } else {
        _alerMessage = @"关爱老人消息发送失败";
    }
    [self showAlerView:_alerMessage];
}

- (void) showAlerView:(NSString *) string {
    [[[UIAlertView alloc] initWithTitle:@"消息提示" message:string delegate:nil cancelButtonTitle:@"取消" otherButtonTitles:@"确定", nil] show];
}

@end
