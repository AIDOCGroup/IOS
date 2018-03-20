//
//  SLPRestonDef.h
//  SDK
//
//  Created by Martin on 17/3/31.
//  Copyright © 2017年 Martin. All rights reserved.
//

#ifndef SLPRestonDef_h
#define SLPRestonDef_h

/*
 object: 蓝牙设备的句柄 CBPeripheral *peripheral
 userInfo: @{kNotificationPostData:RestonRealTimeData}
 */
#define kNotificationNameBLERestonRealtimeData @"kNotificationNameBLERestonRealtimeData" //实时数据
/*
 object: 蓝牙设备的句柄 CBPeripheral *peripheral
 userInfo: @{kNotificationPostData:RestonOriginalData}
 */
#define kNotificationNameBLERestonOriginalData @"kNotificationNameBLERestonOriginalData" //原始数据
/*
 object: 蓝牙设备的句柄 CBPeripheral *peripheral
 userInfo: @{kNotificationPostData:[NSNumber numberWithInteger:电量(0~100)]}
 */
#define kNotificationNameBLERestonBattery @"kNotificationNameBLERestonBattery"//Reston 电量
/*
 object: 蓝牙设备的句柄 CBPeripheral *peripheral
 userInfo: nil
 */
#define kNotificationNameBLERestonStartCollection @"kNotificationNameBLERestonStartCollection"//reston开始采集
/*
 object: 蓝牙设备的句柄 CBPeripheral *peripheral
 userInfo: nil
 */
#define kNotificationNameBLERestonStopCollection @"kNotificationNameBLERestonStopCollection"//reston停止采集

#endif /* SLPRestonDef_h */
