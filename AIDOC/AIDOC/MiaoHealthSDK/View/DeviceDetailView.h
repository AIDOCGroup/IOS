//
//  DeviceDetailView.h
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/7/17.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, ButtonActionTypeEnum) {
    ButtonActionTypeEnumBindDevice, //绑定设备
    ButtonActionTypeEnumGetNewData, //获取最新数据
    ButtonActionTypeEnumGetHistoryData, //获取历史数据
    ButtonActionTypeEnumDisConnectBlE, //断开蓝牙
};

typedef void (^ButtonActionBlock)(ButtonActionTypeEnum buttonActionTypeEnum);

@interface DeviceDetailView : UIView

@property (nonatomic , assign) DeviceDetailFromEnum deviceDetailFromEnum;

@property (nonatomic , weak) MCDevice *device;

@property (nonatomic , weak) MCUserDevice *userDevice;

@property (nonatomic , copy) ButtonActionBlock buttonActionBlock;

@property (nonatomic , weak) UIButton *buttonTwo;

+ (DeviceDetailView *)deviceDetailViewWithFrame:(CGRect)frame;


@end
