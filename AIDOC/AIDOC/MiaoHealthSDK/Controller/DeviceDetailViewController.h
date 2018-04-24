//
//  DeviceDetailViewController.h
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/7/17.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import "BaseViewController.h"

@interface DeviceDetailViewController : BaseViewController

@property (nonatomic , weak) MCDevice *device;

@property (nonatomic , weak) MCUserDevice *userDevice;

@property (nonatomic , assign) DeviceDetailFromEnum deviceDetailFromEnum;
@end
