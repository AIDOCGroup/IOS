//
//  AlarmCell.m
//  AlarmDemo
//
//  Created by apple on 16/7/13.
//  Copyright © 2016年 apple. All rights reserved.
//

#import "AlarmCell.h"

@interface AlarmCell()
{
    UILabel *equipLabel;          //报警设备
    UILabel *locationLabel;       //报警位置
    UILabel *type;                //处理状态
    UILabel *timeLabel;           //时间
}

@end
@implementation AlarmCell
- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        // 点击cell的时候不要变色
        self.selectionStyle = UITableViewCellSelectionStyleNone;
        self.backgroundColor = [UIColor whiteColor];
        [self initViews];
    }
    return self;
}

-(void)initViews{
    
    UIImageView *iconView =[[UIImageView alloc] initWithFrame:CGRectMake(20, 5, 50, 50)];
    iconView.image = [UIImage imageNamed:@"alarm_icon_fire"];
    [self.contentView addSubview:iconView];
    
    UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(5, iconView.bottom + 5, 80, 20)];
    label.textColor = [UIColor blackColor];
    label.text = @"火警";
    label.textAlignment = NSTextAlignmentCenter;
    label.font = [UIFont systemFontOfSize:17];
    [self.contentView addSubview:label];
    
    equipLabel = [[UILabel alloc] initWithFrame:CGRectMake(iconView.right+ +20, iconView.top, kScreenWidth - iconView.right - 20, 20)];
//    equipLabel.text = @"报警设备";
    equipLabel.textColor = [UIColor darkGrayColor];
    equipLabel.textAlignment = NSTextAlignmentLeft;
    equipLabel.font = [UIFont systemFontOfSize:15];
    [self.contentView addSubview:equipLabel];

    locationLabel = [[UILabel alloc] initWithFrame:CGRectMake(equipLabel.left, equipLabel.bottom + 8, kScreenWidth - 100, 20)];
//    locationLabel.text = @"报警位置";
    locationLabel.textColor = [UIColor darkGrayColor];
    locationLabel.textAlignment = NSTextAlignmentLeft;
    locationLabel.font = [UIFont systemFontOfSize:15];
    [self.contentView addSubview:locationLabel];
    //分割线
    UIView *lineView = [[UIView alloc] initWithFrame:CGRectMake(locationLabel.left, locationLabel.bottom +2, kScreenWidth - locationLabel.left, 0.3)];
    lineView.backgroundColor = [UIColor grayColor];
    [self.contentView addSubview:lineView];
    
    type = [[UILabel alloc] initWithFrame:CGRectMake(kScreenWidth - 60, label.top, 50, 20)];
    type.textColor = [UIColor orangeColor];
//    type.text = @"未消除";
    type.font = [UIFont systemFontOfSize:13];
    type.textAlignment = NSTextAlignmentLeft;
    [self.contentView addSubview:type];
    
    UIImageView *typeIconView = [[UIImageView alloc] initWithFrame:CGRectMake(type.left - 12, type.top+5, 10, 10)];
    typeIconView.image = [UIImage imageNamed:@"alarm_item_icon_type"];
    [self.contentView addSubview:typeIconView];
    
    timeLabel = [[UILabel alloc] initWithFrame:CGRectMake(typeIconView.left - 100, type.top, 95, 20)];
//    timeLabel.text = @"03-01 15:20";
    timeLabel.textColor = [UIColor darkGrayColor];
    timeLabel.textAlignment = NSTextAlignmentCenter;
    timeLabel.font = [UIFont systemFontOfSize:13];
    [self.contentView addSubview:timeLabel];

    UIImageView *timeIconView = [[UIImageView alloc] initWithFrame:CGRectMake(timeLabel.left - 12, timeLabel.top + 5, 10, 10)];
    timeIconView.image = [UIImage imageNamed:@"alarm_item_icon_time"];
    [self.contentView addSubview:timeIconView];
    

    
}

- (void)setModel:(AlarmModel *)model
{
    _model = model;
    equipLabel.text = [NSString stringWithFormat:@"报警设备: %@",model.name];
    locationLabel.text = [NSString stringWithFormat:@"报警位置: %@",model.position];
    if ([model.type intValue] == 0) {
        type.text = @"未消除";
    }else
    {
        type.text = @"已消除"; 
    }
    //时间格式化
    NSDate *date = [NSDate dateWithTimeIntervalSince1970:[_model.alarmTime doubleValue]];
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"MM-dd HH:mm"];
    NSString *timeString = [formatter stringFromDate:date];

    timeLabel.text = timeString;
    
}
- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];
    
    // Configure the view for the selected state
}

@end
