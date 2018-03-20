//
//  LDBraceletDeviceDelegate.h
//  LDBraceletSDK
//
//  Created by houhm on 16/12/26.
//  Copyright © 2016年 houhm. All rights reserved.
//

#ifndef LDBraceletDeviceDelegate_h
#define LDBraceletDeviceDelegate_h

/**
 * code:
 *0表示主动断开成功    调用disconnect返回
 *1表示链接成功       调用connect成功返回
 *2表示被动断开成功    当手环与手机在没有调用disconnect的条件下出现蓝牙断开返回。
 *3表示重连失败       当手环与手机在没有调用connect的条件下出现蓝牙连接失败。
 *4表示重连成功       当手环与手机在没有调用connect的条件下出现蓝牙连接成功。
 *5表示超时          调用connect超时返回
 *6表示主动连接失败    调用connect失败返回；
 */
typedef NS_ENUM(NSUInteger, BLEConnectCode) {
    BLEConnectCode_ActiveDisconnectSucc =0,
    BLEConnectCode_ActiveConnectSucc,
    BLEConnectCode_InactiveDisconnectSucc,
    BLEConnectCode_ReconnectFail,
    BLEConnectCode_ReconnectSucc,
    BLEConnectCode_ActiveConnectTimeout,
    BLEConnectCode_ActiveConnectFail
};
@protocol LDBraceletDeviceDelegate

- (void)deviceConnectWithResultCode:(BLEConnectCode)code;

@end

#endif /* LDBraceletDeviceDelegate_h */
