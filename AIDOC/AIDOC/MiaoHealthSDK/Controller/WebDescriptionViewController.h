//
//  WebDescriptionViewController.h
//  MiaoHealthConnectDemo
//
//  Created by 刘云梦 on 17/3/14.
//  Copyright © 2017年 刘云梦. All rights reserved.
//
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, WebDescriptionType) {
    WebDescriptionTypeDefault = 0,
    WebDescriptionTypeWatchBracelet = 1,//手表或者手环
    WebDescriptionTypeBloodSugar = 2,//血糖仪
    WebDescriptionTypeBloodPressure = 3,//血压计
    WebDescriptionTypeBodyFat = 4,//体脂秤
    WebDescriptionTypeHeartRate = 5,//心率仪
    WebDescriptionTypeTemperature = 6,//体温计
};

@interface WebDescriptionViewController : BaseViewController

@property (nonatomic, strong) MCDeviceType *deviceType;
@property (nonatomic, strong) MCDevice *device;
@property (nonatomic, assign) DeviceDetailFromEnum deviceDetailFromEnum;
@property (assign, nonatomic) WebDescriptionType webDescriptionType;

@end
