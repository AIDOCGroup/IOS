//
//  RestonRealTimeData.h
//  SDK
//
//  Created by Martin on 2017/7/28.
//  Copyright © 2017年 Martin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BluetoothManager/SLPDataTransferDef.h>

@interface RestonRealTimeData : NSObject

@property (nonatomic,assign) BOOL awakFlag;//清醒标志
@property (nonatomic,assign) BOOL asleepFlag;//入睡标志
@property (nonatomic,assign) UInt8 breathRate;//呼吸率
@property (nonatomic,assign) UInt8 heartRate;//心率
@property (nonatomic,assign) NSInteger status;//状态
@property (nonatomic,assign) NSInteger statusValue;//状态值

@property (nonatomic,readonly) BOOL isOffBed;//是否为离床
@property (nonatomic,readonly) BOOL isInit;
@end
