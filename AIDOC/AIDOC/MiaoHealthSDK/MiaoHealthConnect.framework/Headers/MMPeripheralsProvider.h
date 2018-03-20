//
//  MMPeripheralsProvider.h
//  MiaoMoreNew
//
//  Created by 罗志平 on 16/10/11.
//  Copyright © 2016年 cn.miao. All rights reserved.
//

#ifndef MMPeripheralsProvider_h
#define MMPeripheralsProvider_h
/** 设备类型 */
typedef NS_ENUM(NSInteger, PeripheralsType) {
    /// 体重秤（0体重未定义，正确类型为PeripheralsTypeBodyFat）
    PeripheralsTypeWeighing = 0,
    /// 血糖仪
    PeripheralsTypeBloodSugar,
    /// 血压计
    PeripheralsTypeBloodPressure,
    /// 行为检测仪
    PeripheralsTypeBehaviorDetector,
    /// 手表
    PeripheralsTypeWatch,
    /// 体脂称(体重)
    PeripheralsTypeBodyFat,
    /// 体温计
    PeripheralsTypeThermometer,
    /// 手环
    PeripheralsTypeWristbands,
    /// 血氧
    PeripheralsTypeOximeter,
    /// 尿检仪
    PeripheralsTypeUroscopy,

};

/** 设备数据类型   0 和 10以后 */
typedef NS_ENUM(NSInteger, PeripheralsDataType) {
    /// 消息
    PeripheralsDataTypeMessage = 0,
    /// 运动
    PeripheralsDataTypeSport,
    /// 睡眠
    PeripheralsDataTypeSleep,
    /// 血压
    PeripheralsDataTypeBloodPressure,
    /// 血糖
    PeripheralsDataTypeBloodSugar,
    /// 温度
    PeripheralsDataTypeThermometer,
    /// 行为检测仪
    PeripheralsDataTypeBehaviorDetector,
    /// 瘦身(体重,体脂)
    PeripheralsDataTypeBodyFat,
    /// 心率
    PeripheralsDataTypeHeartRate,
    /// 血氧
    PeripheralsDataTypeOximeter,
    
    /// 尿检仪
    PeripheralsDataTypeUroscopy,
    /// 专业睡眠
    PeripheralsDataTypeSleepPro,
    
    /// 体重(0 和 10 非API请求数据类型 体重数据使用PeripheralsDataTypeBodyFat)
    PeripheralsDataTypeWeighing,
    //多功能
    PeripheralsDataMultiply = 13,
};

/** 设备连接方式 */
typedef NS_ENUM(NSInteger, PeripheralsAttendedMode) {
    /// 未知
    PeripheralsAttendedModeUnknown = -1,
    /// 蓝牙
    PeripheralsAttendedModeBluetooth = 1,
    /// 二维码
    PeripheralsAttendedModeQRCode,
    /// Web(授权)
    PeripheralsAttendedModeWebAuthority,
    /// Wifi
    PeripheralsAttendedModeWifi,
    /// 端口
    PeripheralsAttendedModePort
};

/** 检测绑定结果 */
typedef NS_ENUM(NSInteger, BindDeviceStatus) {
    BindDeviceStatusError   = 0,                                      // 错误
    BindDeviceStatusUnbound = 1,                                      // 设备未被绑定
    BindDeviceStatusOtherBound,                                       // 设备已被其他人绑定
    BindDeviceStatusSelfBound,                                        // 设备已被自己绑定
};

/** 蓝牙状态 */
typedef NS_ENUM(NSInteger, BluetoothStatus) {
    
    BluetoothStatusDefault  = -1,                                     // 默认状态
    
    // 蓝牙开启状态
    BluetoothStatusUnknown  = 0,                                      // 未知错误   更新提示
    BluetoothStatusResetting,                                         // 未能连接   更新提示
    BluetoothStatusUnsupported,                                       // 不支持     低能耗蓝牙（BTLE）
    BluetoothStatusUnauthorized,                                      // 未授权     低能耗蓝牙（BTLE）
    BluetoothStatusPowerOff,                                          // 蓝牙未开启
    BluetoothStatusPowerOn,                                           // 蓝牙开启
    
    // 蓝牙进行状态
    BluetoothStatusConnectBegin = 20,                                 // 开始连接
    BluetoothStatusConnectSuccess,                                    // 连接成功
    BluetoothStatusConnectFail,                                       // 连接失败
    BluetoothStatusDisconnect,                                        // 连接断开
    BluetoothStatusTimeout,                                           // 连接超时
    
    BluetoothStatusFinish,                                            // 蓝牙完成工作（通常获得到数据后自动关闭当前连接）
    
    //体温计使用
    BluetoothStatusMeasuring,                                         // 测量中
};


typedef void (^BluetoothStatusBlock)(BluetoothStatus status);

//蓝牙断开 返回血氧数据
typedef void (^BluetoothStatusOximeterBlock)(BluetoothStatus status);

/** 网络请求状态 */
typedef NS_ENUM(NSInteger, NetworkRequestStatus) {
    NetworkRequestStatusBegin   = 0,                                      // 开始请求
    NetworkRequestStatusSuccess = 1,                                      // 请求成功
    NetworkRequestStatusFail,                                       // 请求失败
    NetworkRequestStatusLoading,                                        // 请求中
    NetworkRequestStatusFinished,                                       //请求结束
};

typedef void (^NetworkRequestStatusBlock)(NetworkRequestStatus status);

#endif /* MMPeripheralsProvider_h */



