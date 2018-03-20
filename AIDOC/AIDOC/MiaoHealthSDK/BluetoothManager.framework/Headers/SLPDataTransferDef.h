//
//  SLPDataTransferDef.h
//  Sleepace
//
//  Created by Martin on 17/3/31.
//  Copyright © 2017年 com.medica. All rights reserved.
//

#ifndef SLPDataTransferDef_h
#define SLPDataTransferDef_h

typedef enum {
    SLPConnectStatusInit = 0, //初始状态
    SLPConnectStatusConnecting,//正在连接
    SLPConnectStatusConnected,//已连接
    SLPConnectStatusDisconnected,//断开连接状态
}SLPConnectStatus;

//TCP或蓝牙请求返回值的枚举
typedef NS_ENUM(NSInteger,SLPDataTransferReturnStatus) {
    SLPDataTransferReturnStatus_Succeed = 0,//成功
    SLPDataTransferReturnStatus_ConnectionDisconnected = -1,//连接断开
    SLPDataTransferReturnStatus_TimeOut = -2,//超时
    SLPDataTransferReturnStatus_Illegal = -3,//非法的
    SLPDataTransferReturnStatus_WrongMessageType = -4,//错误的消息类型
    SLPDataTransferReturnStatus_ConnectionDisabled = -5,//连接禁用了 或者网络断开了
};

typedef NS_ENUM(NSInteger,SLPDataTransferStatus) {
    SLPDataTransferStatus_Succeed = 0,//成功
    SLPDataTransferStatus_ConnectionDisconnected = -1,//连接断开
    SLPDataTransferStatus_TimeOut = -2,//超时
    SLPDataTransferStatus_Failed = -3,// 失败
    SLPDataTransferStatus_ConnectionDisabled = -4,//连接禁用了 或者网络断开了
    SLPDataTransferStatus_ParameterError = -5,//参数错误
};

/*蓝牙或TCP请求时的回调
 status :TCP或蓝牙请求返回值
 data   :回调的数据,status为SLPDataTransferReturnStatus_Succeed时有效
 */
typedef void(^SLPTransforCompletion)(SLPDataTransferReturnStatus status,id data);

/*蓝牙或TCP请求时的回调
 status :TCP或蓝牙请求返回值
 data   :回调的数据,status为SLPDataTransferReturnStatus_Succeed时有效
 */
typedef void(^SLPTransforCallback)(SLPDataTransferStatus status,id data);

//设备类型
typedef NS_ENUM(NSInteger,SLPDeviceTypes) {
    SLPDeviceType_Unknown = -2,//用于之前老协议没有带设备类型的情况
    SLPDeviceType_Phone = -1,//手机
    SLPDeviceType_None = 0,//无设备
    SLPDeviceType_Z1 = 1,
    SLPDeviceType_Nox,
    SLPDeviceType_Pillow,
    SLPDeviceType_WIFIReston,
    SLPDeviceType_BLE_SingleMattress, //5
    SLPDeviceType_WIFI_SingleMattress,
    SLPDeviceType_BLE_DoubleMattress,
    SLPDeviceType_WIFI_DoubleMattress,
    SLPDeviceType_Z2 = 9, //9
    SLPDeviceType_Milky,
    SLPDeviceType_NOX2,
    SLPDeviceType_NOX2_WiFi, //12
    SLPDeviceType_Milky2 = 0x0010, //16 第二代
    SLPDeviceType_Milky2T = 0x0011,
    SLPDeviceType_Patch = 0x0012, // 眼罩
    SLPDeviceType_Z4 = 0x0016,//22
};

//样本数据的人群类型 目前只有男性和女性
typedef NS_ENUM(NSInteger,SLPSleepPersonTypes) {
    SLPSleepPersonType_Female = 0,
    SLPSleepPersonType_Male,
};

//typedef NS_ENUM(NSInteger,SLPBreathStatus) {
//    SLPBreathStatus_Normal = 0,//呼吸正常
//    SLPBreathStatus_TooFast,//呼吸过快
//    SLPBreathStatus_TooSlow,//呼吸过缓
//};
//
//typedef NS_ENUM (NSInteger,SLPHearbeatStatus){
//    SLPHearbeatStatus_Normal = 0,//心跳正常
//    SLPHearbeatStatus_TooFast,//心跳过快
//    SLPHearbeatStatus_TooSlow,//心跳过缓
//};

//特殊时令
typedef NS_ENUM(UInt8,SLPSpecialTimeSeason) {
    SLPSpecialTimeSeason_None = 0,
    SLPSpecialTimeSeason_DaylightSsavingTime,//夏令时
    SLPSpecialTimeSeason_Winterzeit,//冬令时
};

typedef NS_ENUM(UInt8,SLPOperationMode) {
    SLPOperationMode_Get = 0x00,//获取
    SLPOperationMode_Set,//设置
};

typedef NS_ENUM(UInt8,SLPSleepStataus) {
    SLPSleepStataus_fallAsleep = 0,//睡着了
    SLPSleepStataus_awake,//醒来了
    SLPSleepStataus_Invalid,//无效值
};

typedef NS_ENUM(UInt8,SLPCollectionDataFinishMode) {
    SLPCollectionDataFinishMode_Normal,//正常结束
    SLPCollectionDataFinishMode_Auto,//自动结束
    SLPCollectionDataFinishMode_Force,//强制结束(如:关机)
    SLPCollectionDataFinishMode_Wrong,//错误结束(如:供电不足、系统异常)
};

#define kLongReportMinRecortCount (180)//长报告最短时间

//post消息放在dictionary中的key
#define kNotificationPostData @"postData"//post的数据
#endif /* SLPDataTransferDef_h */
