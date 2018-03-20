//
//  SLPBLEManager+Scan.h
//  Sleepace
//
//  Created by Martin on 7/13/16.
//  Copyright © 2016 com.medica. All rights reserved.
//

#import "SLPBLEManager.h"
#import "SLPBLEDef.h"

@interface SLPBLEManager (Scan)

//停止单个扫描
- (void)stopScanHandle:(NSInteger)handleID;
//扫描设置
- (BOOL)scanBluetoothWithTimeoutInterval:(CGFloat)timeOutInterval completion:(SLPBLEScanHandle)handle;

//蓝牙是否打开
- (BOOL)blueToothIsOpen;

///停止所有扫描
- (void)stopAllPeripheralScan;

//断开连接
- (BOOL)disconnectPeripheral:(CBPeripheral *)peripheral timeout:(CGFloat)timeout completion:(SLPBLEDisconnectHandle)handle;
//判断蓝牙是否连接
- (BOOL)peripheralIsConnected:(CBPeripheral *)peripheral;

- (void)_checkScan;
@end

@class CBPeripheral;
@interface SLPPeripheralInfo : NSObject
@property (nonatomic,strong) CBPeripheral *peripheral;
@property (nonatomic,copy) NSString *name;
@end
