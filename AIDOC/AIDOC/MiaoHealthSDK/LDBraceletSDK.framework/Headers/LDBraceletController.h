//
//  LDBraceletController.h
//  LDBraceletSDK
//
//  Created by houhm on 16/11/23.
//  Copyright © 2016年 houhm. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LDBraceletBLEDeviceOperator.h"
#import "LDBraceletDeviceDelegate.h"
#import "LDBraceletFitOperator.h"
#import "LDBraceletEMVOperator.h"
#import "LDBraceletOutType.h"
//#import "LDBraceletEMVController.h"

@interface LDBraceletController : NSObject<LDBraceletBLEDeviceOperator>
@property(nonatomic,weak)id<LDBraceletDeviceDelegate> deviceDelegate;
@property(nonatomic,weak)id<HealthDataChangeListener> healthDataChangeListener;

+ (instancetype)shareInstance;

- (void)connectResult:(BLEConnectCode)connectResult;

- (BOOL)isBLESwitchOn;

@end
