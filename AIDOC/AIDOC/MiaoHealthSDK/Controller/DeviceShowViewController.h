//
//  DeviceViewController.h
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/10/17.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DeviceShowViewController : UIViewController
@property (nonatomic, strong) MCDevice *device;

@property (nonatomic , assign) DeviceDetailFromEnum deviceDetailFromEnum;
@end
