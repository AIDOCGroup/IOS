//
//  DataElderCell.m
//  MiaoHealthConnectDemo
//
//  Created by 刘云梦 on 17/2/13.
//  Copyright © 2017年 刘云梦. All rights reserved.
//

#import "DataElderCell.h"
#import <MiaoHealthConnect/MiaoHealthConnect.h>

@implementation DataElderCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
    [self setSelectedBackgroundView:[[UIView alloc] init]];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

- (void) setData:(id)data {
    
    if ([data isKindOfClass:[MCElderDayReport class]]) {
        MCElderDayReport *dayReport = (MCElderDayReport *) data;
        _label1.text = [NSString stringWithFormat:@"全天累计步数:%ld", (long)dayReport.step_sum];
        _label2.text = [NSString stringWithFormat:@"久坐次数:%ld", (long)dayReport.sit_long];
        _label3.text = [NSString stringWithFormat:@"行走次数:%ld", (long)dayReport.liveness];
        _label4.text = [NSString stringWithFormat:@"健康评分:%ld", (long)dayReport.point_today];
        _label5.text = [NSString stringWithFormat:@"睡眠时长（秒）:%ld", (long)dayReport.sleep_time];
        _label6.text = [NSString stringWithFormat:@"佩戴有效时长（秒）:%ld", (long)dayReport.valid_wear];
        _label7.text = [NSString stringWithFormat:@"步频（步/分钟）:%ld", (long)dayReport.step_freq];
    } else if ([data isKindOfClass:[MCElderWearInfo class]]) {
        MCElderWearInfo *wearInfo = (MCElderWearInfo *) data;
        _label1.text = [NSString stringWithFormat:@"开始时间:%ld", (long)wearInfo.start_time];
        _label2.text = [NSString stringWithFormat:@"结束时间:%ld", (long)wearInfo.end_time];
        _label3.text = [NSString stringWithFormat:@"位置信息:%@", wearInfo.position];
        _label4.text = [NSString stringWithFormat:@"佩戴状态:%@", wearInfo.wear_state];
        _label5.text = [NSString stringWithFormat:@"行为状态:%@", wearInfo.behavior_state];
        _label6.text = [NSString stringWithFormat:@"文字说明:%@", wearInfo.remark];
    } else if ([data isKindOfClass:[MCElderPosition class]]) {
        MCElderPosition *position = (MCElderPosition *) data;
        _label1.text = [NSString stringWithFormat:@"纬度:%ld", (long)position.latitude];
        _label2.text = [NSString stringWithFormat:@"经度:%ld", (long)position.longitude];
        _label3.text = [NSString stringWithFormat:@"位置信息:%@", position.position];
        _label4.text = [NSString stringWithFormat:@"位置时间:%@", position.position_time];
        _label5.text = [NSString stringWithFormat:@"状态:%@", position.state];
        _label6.text = [NSString stringWithFormat:@"精度:%ld", (long)position.accuracy];
        _label7.text = [NSString stringWithFormat:@"坐标系:%ld", (long)position.coordinate_system	];
    } else if ([data isKindOfClass:[MCElderCaution class]]) {
        MCElderCaution *caution = (MCElderCaution *) data;
        _label1.text = [NSString stringWithFormat:@"纬度:%ld", (long)caution.latitude];
        _label2.text = [NSString stringWithFormat:@"经度:%ld", (long)caution.longitude];
        _label3.text = [NSString stringWithFormat:@"位置信息:%@", caution.position];
        _label4.text = [NSString stringWithFormat:@"报警时间:%ld", (long)caution.alert_time];
        _label5.text = [NSString stringWithFormat:@"报警类型描述%@", caution.alert_type];
        _label6.text = [NSString stringWithFormat:@"老人名称:%@", caution.name];
        _label7.text = [NSString stringWithFormat:@"处理状态:%ld", (long)caution.status];
    }
}

@end
