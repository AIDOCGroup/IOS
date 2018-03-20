//
//  SLPBLEManager.h
//  Sleepace
//
//  Created by Martin on 7/13/16.
//  Copyright © 2016 com.medica. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SLPBLEDef.h"
#import "SLPDataTransferDef.h"


@class CBCentralManager;
@class SLPPeripheral;
@class CBPeripheral;
@class SLPBLEBaseSendPacket;
@class SLPBLEScanObject;
#define SLPBLESharedManager [SLPBLEManager sharedBLEManager]
@interface SLPBLEManager : NSObject
{
    CBCentralManager *mCentralManager;
    NSMutableArray<SLPPeripheral *> *mPeripheralList;//连接设备列表
    NSMutableArray<SLPBLEScanObject *> *mScanRequestList;//扫描请求列表
    BOOL mIsScaning;//是否正在扫描
    BOOL mIsCenterManagerInited;//centralManager是否已经初始化
}
+ (SLPBLEManager *)sharedBLEManager;

#pragma mark private
//发送数据
- (BOOL)sendPacket:(SLPBLEBaseSendPacket *)packet peripheral:(CBPeripheral *)peripheral;

//清除蓝牙的连接
- (void)removePeripheralList:(NSArray<SLPPeripheral *> *)peripheralList;

//查询接口
- (SLPDeviceTypes)deviceTypeOfPeripheral:(CBPeripheral *)peripheral;
- (NSInteger)deviceTextureOfPeripheral:(CBPeripheral *)peripheral;
@end
