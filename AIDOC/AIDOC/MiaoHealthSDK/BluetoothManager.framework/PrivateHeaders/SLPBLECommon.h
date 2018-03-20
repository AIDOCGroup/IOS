//
//  SLPBLECommon.h
//  Sleepace
//
//  Created by Martin on 6/7/16.
//  Copyright © 2016 com.medica. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger,SLPBLEProtocalType){
    SLPBLEProtocalType_Original = 0,
    SLPBLEProtocalType_Promotional,
};

//蓝牙消息的唯一ID 界面上使用
typedef NS_ENUM(NSInteger,SLPBLEMessagetUniqTypes) {
    //Reston
    SLPBLEMessagetUniqType_RestonLogin = 0,//reston登录
    SLPBLEMessagetUniqType_RestonSetSmartWake,//设置智能唤醒
    SLPBLEMessagetUniqType_RestonGetSmartWake,//获取智能唤醒
    SLPBLEMessagetUniqType_RestonSetAudoCollecting,//设置自动采集
    SLPBLEMessagetUniqType_RestonGetAudoCollecting,//获取自动采集
    SLPBLEMessagetUniqType_RestonGetBattery,//获取电量
    SLPBLEMessagetUniqType_RestonGetDeviceInfo,//获取设备信息
    SLPBLEMessagetUniqType_RestonSetCollectionStatus,//设置采集状态
    SLPBLEMessagetUniqType_RestonGetCollectionStatus,//获取采集状态
    SLPBLEMessagetUniqType_RestonGetDeviceVersion,//获取设备版本信息
    SLPBLEMessagetUniqType_RestonNotify,//通知设备开始上报数据
    SLPBLEMessagetUniqType_RestonPostRealTimeData,//设备向客户端上报实时数据 设备->APP
    SLPBLEMessagetUniqType_RestonPostOriginalData,//设备向客户端上报原始数据 设备->APP
    SLPBLEMessagetUniqType_RestonHistorySummaryQuery,//历史数据的概要查询
    SLPBLEMessagetUniqType_RestonHistoryBoundaryQuery,//历史数据的边界查询
    SLPBLEMessagetUniqType_RestonDownloadHistoryData,//历史数据下载
    SLPBLEMessagetUniqType_RestonDownloadHistoryDataAdditional,//带温湿度的历史数据下载
    SLPBLEMessagetUniqType_RestonPostStatus,//控制盒状态上报  设备->APP
    SLPBLEMessagetUniqType_RestonUpgradeSummery,//概要上传请求
    SLPBLEMessagetUniqType_RestonUpgradeContent,//内容上传请求
    SLPBLEMessagetUniqType_RestonGetEnviormentData,//获取环境数据
    
    //Milky
    SLPBLEMessagetUniqType_MilkyTimeCalibration,//时间校准
    SLPBLEMessagetUniqType_MilkyGetSystemInfo,//获取系统信息
    SLPBLEMessagetUniqType_MilkyGetVersionInfo,//获取版本信息
    SLPBLEMessagetUniqType_MilkySetUserInfo,//设置用户信息
    SLPBLEMessagetUniqType_MilkyGetUserInfo,//获取用户信息
    SLPBLEMessagetUniqType_MilkySetSleepTime,//设置睡眠时间
    SLPBLEMessagetUniqType_MilkyGetSleepTime,//获取睡眠时间
    SLPBLEMessagetUniqType_MilkySetAlarm,//闹钟配置
    SLPBLEMessagetUniqType_MilkySetSmartWakeupInfo,//设置智能唤醒
    SLPBLEMessagetUniqType_MilkyGetSmartWakeupInfo,//获取智能唤醒
    SLPBLEMessagetUniqType_MilkySetCollectionStatus,//设置采集状态
    SLPBLEMessagetUniqType_MilkyGetBatteryInfo,//获取电量信息
    SLPBLEMessagetUniqType_MilkyGetSleepStatus,//获取睡眠状态
    SLPBLEMessagetUniqType_MilkyGetCollectionStatus,//获取采集状态
    SLPBLEMessagetUniqType_MilkyGetEnviormentData,//获取环境数据
    SLPBLEMessagetUniqType_MilkyHistoryDataQuery,//历史数据查询
    SLPBLEMessagetUniqType_MilkyHistoryDownload,//历史数据下载啊
    SLPBLEMessagetUniqType_MilkyHistoryDownloadAdditional,//历史数据下载(含温湿度)
    SLPBLEMessagetUniqType_MilkySummaryUpload,//升级的概要信息上传
    SLPBLEMessagetUniqType_MilkyContrentUpload,//升级包上传
    
    //Pillow
    SLPBLEMessagetUniqType_PillowLogin,//Pillow登录
    SLPBLEMessagetUniqType_PillowSetSmartWake,//设置智能唤醒
    SLPBLEMessagetUniqType_PillowGetSmartWake,//获取智能唤醒
    SLPBLEMessagetUniqType_PillowSetAudoCollecting,//设置自动采集
    SLPBLEMessagetUniqType_PillowGetAudoCollecting,//获取自动采集
    SLPBLEMessagetUniqType_PillowGetBattery,//获取电量
    SLPBLEMessagetUniqType_PillowGetDeviceInfo,//获取设备信息
    SLPBLEMessagetUniqType_PillowSetCollectionStatus,//设置采集状态
    SLPBLEMessagetUniqType_PillowGetCollectionStatus,//获取采集状态
    SLPBLEMessagetUniqType_PillowGetDeviceVersion,//获取设备版本信息
    SLPBLEMessagetUniqType_PillowNotify,//通知设备开始上报数据
    SLPBLEMessagetUniqType_PillowPostRealTimeData,//设备向客户端上报实时数据 设备->APP
    SLPBLEMessagetUniqType_PillowPostOriginalData,//设备向客户端上报原始数据 设备->APP
    SLPBLEMessagetUniqType_PillowHistorySummaryQuery,//历史数据的概要查询
    SLPBLEMessagetUniqType_PillowHistoryBoundaryQuery,//历史数据的边界查询
    SLPBLEMessagetUniqType_PillowDownloadHistoryData,//历史数据下载
    SLPBLEMessagetUniqType_PillowPostStatus,//控制盒状态上报  设备->APP
    SLPBLEMessagetUniqType_PillowUpgradeSummery,//概要上传请求
    SLPBLEMessagetUniqType_PillowUpgradeContent,//内容上传请求
    
    SLPBLEMessagetUniqType_None,
};

typedef NS_ENUM(NSInteger,SLPBLEPillowPostMessageType) {
    SLPBLEPillowPostMessageType_RealtimeData = 0x07,//pillow 实时数据
    SLPBLEPillowPostMessageType_OriginalData = 0x1D,//pillow 原始数据
    SLPBLEPillowPostMessageType_PillowPostStatus = 0x05//pillow 控制盒状态上报
};

typedef NS_ENUM(NSInteger,SLPBLERestonPostMessageType) {
    SLPBLERestonPostMessageType_RealtimeData = 0x07,//reston 实时数据
    SLPBLERestonPostMessageType_OriginalData = 0x1D,//reston 原始数据
    SLPBLERestonPostMessageType_RestonPostStatus = 0x05//Reston 控制盒状态上报
};

typedef NS_ENUM(NSInteger,SLPBLENoxPostMessageType) {
    SLPBLENoxPostMessageType_WorkStatus = 0x41,//工作模式
};

//蓝牙传输数据的默认超时时间
#define kBLEDefaultTimeoutInterval (10.0)
//蓝牙扫描的默认的超时时间
#define kBLEDefaultScanTimeoutInterval (10.0)
//蓝牙连接的默认的超时时间
#define kBLEDefaultConnectTimeoutInterval (10.0)

//获取蓝牙消息类型的描述
#define SLPBLEMessageTypeDescription(type) [SLPBLECommon descriptionOfMessagetType:type]

#define kBLEPreCode (0x12ef) //蓝牙老协议前导码
@interface SLPBLECommon : NSObject

+ (NSString *)descriptionOfMessagetType:(SLPBLEMessagetUniqTypes)type;
+ (NSString *)entityClassStringFrom:(SLPBLEMessagetUniqTypes)type;
@end
