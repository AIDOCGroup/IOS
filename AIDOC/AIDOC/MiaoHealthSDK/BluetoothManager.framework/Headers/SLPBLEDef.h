//
//  SLPBLEDef.h
//  SDK
//
//  Created by Martin on 17/3/31.
//  Copyright © 2017年 Martin. All rights reserved.
//

#ifndef SLPBLEDef_h
#define SLPBLEDef_h

//扫描蓝牙
typedef NS_ENUM(NSInteger,SLPBLEScanReturnCodes) {
    SLPBLEScanReturnCode_Normal,
    SLPBLEScanReturnCode_Disable,//蓝牙禁止了
    SLPBLEScanReturnCode_TimeOut,
};

@class SLPPeripheralInfo;
typedef void(^SLPBLEScanHandle)(SLPBLEScanReturnCodes code,NSInteger handleID, SLPPeripheralInfo *peripheralInfo);
typedef void (^SLPBLEScanTimeoutHandle)(void);

//连接蓝牙
typedef NS_ENUM(NSInteger,SLPBLEConnectReturnCodes) {
    SLPBLEConnectReturnCode_Succeed,
    SLPBLEConnectReturnCode_Failed,
    SLPBLEConnectReturnCode_Disable,
    SLPBLEConnectReturnCode_Timeout,
};

typedef void(^SLPBLEConnectHandle)(SLPBLEConnectReturnCodes code,NSInteger connectHandleID);
typedef void (^SLPBLEConnectTimeoutHandle)(void);

//断开连接
typedef NS_ENUM(NSInteger,SLPBLEDisconnectReturnCodes) {
    SLPBLEDisconnectReturnCode_Succeed,
    SLPBLEDisconnectReturnCode_Failed,
    SLPBLEDisconnectReturnCode_Disable,
    SLPBLEDisconnectReturnCode_Timeout,
};

typedef void(^SLPBLEDisconnectHandle)(SLPBLEDisconnectReturnCodes code,NSInteger disconnectHandleID);
typedef void (^SLPBLEDisconnectTimeoutHandle)(void);

#define kNotificationNameBLEDeviceDisconnect @"kNotificationNameBLEDeviceDisconnect" //蓝牙设备断开了连接
#define kNotificationNameBLEDeviceConnected @"kNotificationNameBLEDeviceConnected" //蓝牙设备连接成功
#define kNotificationNameBLEEnable @"kNotificationNameBLEEnable"//蓝牙设备启用了
#define kNotificationNameBLEDisable @"kNotificationNameBLEDisable"//蓝牙设备禁用了

#endif /* SLPBLEDef_h */
