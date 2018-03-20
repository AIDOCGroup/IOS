//
//  UTEDefine.h
//  UTESmartBandApi
//
//  Created by VV on 2017/4/22.
//  Copyright © 2017年 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface UTEDefine : NSObject
/**
 *  NSDictionary 同步数据完 - 步数键值,value:NSArray
 */
extern NSString *const kUTEQueryRunData;
/**
 *  NSDictionary 同步数据完 - 睡眠键值,value:NSArray
 */
extern NSString *const kUTEQuerySleepData;
/**
 *  NSDictionary 同步数据完 - 午睡键值,value:NSArray
 */
extern NSString *const kUTEQuerySiestaData;
/**
 *  NSDictionary 同步数据完/测试心率完 - 心率键值,value:NSArray
 */
extern NSString *const kUTEQueryHRMData;
/**
 *  NSDictionary 同步数据完/测试血压完 - 血压键值,value:NSArray
 */
extern NSString *const kUTEQueryBloodData;
/**
 *  NSDictionary 设备密码状态 键值,value:NSString 转为NSInteger 对应UTEPasswordState枚举
 */
extern NSString *const kUTEPasswordState;
/**
 *  NSDictionary 具有运动模式的设备 走路与跑步模式的键值
 */
extern NSString *const kUTEQuerySportWalkRunData;
/**
 *  NSDictionary 具有运动模式的设备 骑车模式的键值
 */
extern NSString *const kUTEQuerySportBicycleData;
/**
 *  NSDictionary 具有运动模式的设备 游泳模式的键值
 */
extern NSString *const kUTEQuerySportSwimData;
/**
 *  NSDictionary 具有运动模式的设备 跳绳模式的键值
 */
extern NSString *const kUTEQuerySportSkipData;
/**
 *  NSDictionary 具有运动模式的设备 乒乓球模式的键值
 */
extern NSString *const kUTEQuerySportTableTennisData;
/**
 *  NSDictionary 具有运动模式的设备 羽毛球模式的键值
 */
extern NSString *const kUTEQuerySportBadmindonData;
/**
 *  NSDictionary 具有运动模式的设备 网球模式的键值
 */
extern NSString *const kUTEQuerySportTennisData;
/**
 *  NSDictionary 获取到紫外线的键值,value:NSNumber
 */
extern NSString *const kUTEQueryUVData;
/**
 *  NSDictionary 获取到同步GPS数据的键值,value:NSArray
 */
extern NSString *const kUTEQueryGPSData;
/**
 *  NSDictionary 检测到有新版本的键值(是否需要强制升级,为了方便固件支持新的功能或解决固件BUG)
                value:NSNumber numberWithBool
 */
extern NSString *const kUTEForceUpdateFirmware;

/*!
 *  @enum UTEOption
 *
 *  @discussion 设置设备特性
 *
 *
 *  @constant UTEOptionSyncAllStepsData      同步设备所有步数（包括运动模式的走路和跑步数据）
 *  @constant UTEOptionSyncAllSleepData      同步设备所有睡眠
 *  @constant UTEOptionSyncAllHRMData        同步设备所有心率
 *  @constant UTEOptionSyncAllBloodData      同步设备所有血压
 *  @constant UTEOptionSyncAllData           同步设备所有数据 （步数和睡眠）
 *  @constant UTEOptionSyncGPSData           同步设备GPS数据
 *  @constant UTEOptionSyncBicycleData       同步设备骑行数据
 *  @constant UTEOotionTodaySteps            获取今天总步数
 *  @constant UTEOptionIncall                来电指令 :当手机来电时，调用此值则设备会震动10次 1秒1次
 
 *  @constant UTEOptionHangup                挂断/接通:调用此值则设备会立即停止震动
 *  @constant UTEOptionFindBand              查找设备 :设备震动2次 1秒1次
 *  @constant UTEOptionSyncTime              同步当前手机时间
 *  @constant UTEOptionReadDevicesBattery    读取设备电量
 
 *  @constant UTEOptionHeartDetectingStart   开始测试心率
 *  @constant UTEOptionHeartDetectingStop    停止测试心率
 *  @constant UTEOptionHeartSwitchDynamic    切换为动态心率模式
 *  @constant UTEOptionHeartSwitchStatic     切换为静态心率模式
 
 *  @constant UTEOptionUnitInch              设置设备计量单位为 英制 磅(lbs) (RK 平台暂时无效)
 *  @constant UTEOptionUnitMeter             设置设备计量单位为 公制 千克    (RK 平台暂时无效)
 *  @constant UTEOptionUnitInch_12           设置设备计量单位为 英制 磅   时间12小时制(AM,PM) 需固件支持12、24小时制切换
 *  @constant UTEOptionUnitInch_24           设置设备计量单位为 英制 磅   时间24小时制        需固件支持12、24小时制切换
 *  @constant UTEOptionUnitMeter_12          设置设备计量单位为 公制 千克 时间12小时制(AM,PM) 需固件支持12、24小时制切换
 *  @constant UTEOptionUnitMeter_24          设置设备计量单位为 公制 千克 时间24小时制        需固件支持12、24小时制切换
 
 （RK平台 支持以下所有提醒，无需考虑isHasExtra值）
 *  @constant UTEOptionOpenRemindIncall      打开设备 来电提醒 震动1次  前提isHasExtra = YES
 *  @constant UTEOptionOpenRemindQQ          打开设备 QQ 提醒  震动1次   前提isHasExtra = YES
 *  @constant UTEOptionOpenRemindWeixin      打开设备 微信提醒 震动1次   前提isHasExtra = YES
 *  @constant UTEOptionOpenRemindSms         打开设备 SMS提醒  震动1次   前提isHasExtra = YES
 *  @constant UTEOptionOpenRemindMore        打开设备 更多提醒  震动1次   前提isHasExtra = YES
 *
 *  @constant UTEOptionCloseRemindIncall     关闭设备 来电提醒           前提isHasExtra = YES
 *  @constant UTEOptionCloseRemindQQ         关闭设备 QQ提醒             前提isHasExtra = YES
 *  @constant UTEOptionCloseRemindWeixin     关闭设备 微信提醒           前提isHasExtra = YES
 *  @constant UTEOptionCloseRemindSms        关闭设备 SMS提醒            前提isHasExtra = YES
 *  @constant UTEOptionCloseRemindMore       关闭设备 更多提醒           前提isHasExtra = YES
 
 *  @constant UTEOptionOpenCameraMode        打开设备摇一摇拍照模式:接着用户每摇晃3次设备左右
 代理uteManagerTakePicture方法就被调用
 *  @constant UTEOptionCloseCameraMode       关闭设备摇一摇拍照模式:退出拍照模式 一定要调用此值
 否则设备可能不计步
 *
 *  @constant UTEOptionDeleteDevicesAllData  清除设备所有数据
 
 (横竖屏功能需要固件支持,请看isHasOrientation属性)
 *  @constant UTEOptionDeviceHorizontal      设置设备横屏
 *  @constant UTEOptionDeviceVertical        设置设备竖屏
 *
 *  @constant UTEOptionBloodDetectingStart   开始测试血压
 *  @constant UTEOptionBloodDetectingStop    停止测试血压
 *
 *  @constant UTEOptionReadDisplaySize       查询表盘分辨率和能切换的个数
 *
 *  @constant UTEOptionSyncSkipData          同步跳绳所有数据
 *  @constant UTEOptionSyncSwimData          同步游泳所有数据
 *
 *  @constant UTEOptionReadBaseStatus        只能读取设备当前 监听计步 还是 监听睡眠 状态
 *
 *  @constant UTEOptionDetectUV              检测紫外线
 *  @constant UTEOptionFindPhoneFunctionOpen  设备找手机功能 开
 *  @constant UTEOptionFindPhoneFunctionClose 设备找手机功能 关
 *
 *
 *  提示:如果打开了如下一种运动A，不关闭A（关闭才保存数据），而直接打开运动B，那么运动A被强制关闭且会（可能不成功）保存之前运动A数据。
 *
 *  @constant UTEOptionOpenBicycle           打开骑行
 *  @constant UTEOptionCloseBicycle          关闭骑行
 *  @constant UTEOptionOpenSwim              打开游泳
 *  @constant UTEOptionCloseSwim             关闭游泳
 *  @constant UTEOptionOpenSkip              打开跳绳
 *  @constant UTEOptionCloseSkip             关闭跳绳
 *
 *  @constant UTEOptionOpenTableTennis       打开乒乓球
 *  @constant UTEOptionCloseTableTennis      关闭乒乓球
 *  @constant UTEOptionOpenBadminton         打开羽毛球
 *  @constant UTEOptionCloseBadminton        关闭羽毛球
 *  @constant UTEOptionOpenTennis            打开网球
 *  @constant UTEOptionCloseTennis           关闭网球
 *  @constant UTEOptionSyncBallData          同步如上所有球类数据
 *
 *
 */
typedef NS_ENUM(NSInteger, UTEOption) {
    
    UTEOptionSyncAllStepsData,
    UTEOptionSyncAllSleepData,
    UTEOptionSyncAllHRMData,
    UTEOptionSyncAllBloodData,
    UTEOptionSyncAllData,
    UTEOptionSyncGPSData,
    UTEOptionSyncBicycleData,
    UTEOotionTodaySteps,
    UTEOptionIncall,
    UTEOptionHangup,
    UTEOptionFindBand,
    UTEOptionSyncTime,
    UTEOptionReadDevicesBattery,
    
    UTEOptionHeartDetectingStart,
    UTEOptionHeartDetectingStop,
    UTEOptionHeartSwitchDynamic,
    UTEOptionHeartSwitchStatic,
    
    UTEOptionUnitInch,
    UTEOptionUnitMeter,
    UTEOptionUnitInch_12,
    UTEOptionUnitInch_24,
    UTEOptionUnitMeter_12,
    UTEOptionUnitMeter_24,
    
    UTEOptionOpenRemindIncall,
    UTEOptionOpenRemindQQ,
    UTEOptionOpenRemindWeixin,
    UTEOptionOpenRemindSms,
    UTEOptionOpenRemindMore,
    UTEOptionCloseRemindIncall,
    UTEOptionCloseRemindQQ,
    UTEOptionCloseRemindWeixin,
    UTEOptionCloseRemindSms,
    UTEOptionCloseRemindMore,
    
    UTEOptionOpenCameraMode,
    UTEOptionCloseCameraMode,
    
    UTEOptionDeleteDevicesAllData,
    
    UTEOptionDeviceHorizontal,
    UTEOptionDeviceVertical,
    
    UTEOptionBloodDetectingStart,
    UTEOptionBloodDetectingStop,
    UTEOptionReadDisplaySize,
    
    UTEOptionSyncSkipData,
    UTEOptionSyncSwimData,
    
    UTEOptionReadBaseStatus,
    
    UTEOptionDetectUV,
    UTEOptionFindPhoneFunctionOpen,
    UTEOptionFindPhoneFunctionClose,
    
    UTEOptionOpenBicycle,
    UTEOptionCloseBicycle,
    UTEOptionOpenSwim,
    UTEOptionCloseSwim,
    UTEOptionOpenSkip,
    UTEOptionCloseSkip,
    
    UTEOptionOpenTableTennis,
    UTEOptionCloseTableTennis,
    UTEOptionOpenBadminton,
    UTEOptionCloseBadminton,
    UTEOptionOpenTennis,
    UTEOptionCloseTennis,
    UTEOptionSyncBallData,
};


/*!
 *  @enum UTECallBack
 
 *
 *  @discussion SDK对固件发送命令以下对应，如固件接收到值，将发送返回值给SDK，如SDK接收到值将回调；否则无。
 *
 *  @constant UTECallBackUnit                     设置设备计量单位
 *  @constant UTECallBackInfoHeightWeight         设置设备里面身高、体重
 *  @constant UTECallBackSyncTime                 同步当前时间
 *  @constant UTECallBackAlarm                    设置闹钟
 
 *  @constant UTECallBackOpenRemindIncall         打开设备 来电提醒
 *  @constant UTECallBackOpenRemindQQ             打开设备 QQ 提醒
 *  @constant UTECallBackOpenRemindWeixin         打开设备 微信提醒
 *  @constant UTECallBackOpenRemindSms            打开设备 SMS提醒
 *  @constant UTECallBackOpenRemindMore           打开设备 更多提醒（除以上提醒，所有的App允许系统打开了的通知提示）
 
 *  @constant UTECallBackCloseRemindIncall        关闭设备 来电提醒
 *  @constant UTECallBackCloseRemindQQ            关闭设备 QQ提醒
 *  @constant UTECallBackCloseRemindWeixin        关闭设备 微信提醒
 *  @constant UTECallBackCloseRemindSms           关闭设备 SMS提醒
 *  @constant UTECallBackCloseRemindMore          关闭设备 更多提醒
 
 *  @constant UTECallBackOpenRemindFacebook            打开设备
 *  @constant UTECallBackOpenRemindFacebookMessenger   打开设备
 *  @constant UTECallBackOpenRemindTwitter             打开设备
 *  @constant UTECallBackOpenRemindWhatsApp            打开设备
 *  @constant UTECallBackOpenRemindLine                打开设备
 *  @constant UTECallBackOpenRemindSkype               打开设备
 *  @constant UTECallBackOpenRemindHangouts            打开设备
 *
 *  @constant UTECallBackCloseRemindFacebook            关闭设备
 *  @constant UTECallBackCloseRemindFacebookMessenger   关闭设备
 *  @constant UTECallBackCloseRemindTwitter             关闭设备
 *  @constant UTECallBackCloseRemindWhatsApp            关闭设备
 *  @constant UTECallBackCloseRemindLine                关闭设备
 *  @constant UTECallBackCloseRemindSkype               关闭设备
 *  @constant UTECallBackCloseRemindHangouts            关闭设备
 
 *  @constant UTECallBackOpenUnitSitRemind        打开久坐提醒
 *  @constant UTECallBackCloseSitRemind           关闭久坐提醒
 
 *  @constant UTECallBackHeartSwitchDynamic       切换动态心率
 *  @constant UTECallBackHeartSwitchStatic        切换静态心率
 
 *  @constant UTECallBackDevicesVersion           获取到了设备版本号
 *
 *  @constant UTECallBackDeviceHorizontal         设备横屏
 *  @constant UTECallBackDeviceVertical           设备竖屏
 
 *  @constant UTECallBackDeviceSilence            设备勿打扰
 *
 *  @constant UTECallBackDeviceWeather            设置2天内的天气
 *
 *  @constant UTECallBackDeviceBattery            获取到电量
 *  @constant UTECallBackSwitchHandAndDisplay     切换佩戴方式和表盘显示模式
 *  @constant UTECallBackWeatherSevenDay          设置7天内的天气
 *  @constant UTECallBackIbeaconOption            设置ibeacon数据
 *  @constant UTECallBackMultiLanguage            设置多国语言 会有多次回调
 *
 *  @constant UTECallBackSiestaSet                设置午睡时间范围
 *  @constant UTECallBackSleepNightSet            设置晚上睡眠范围
 *  @constant UTECallBackSleepAdjust              矫正晚上睡眠
 
 *  @constant UTECallBackFindPhoneFunctionOpen     设备找手机功能 开
 *  @constant UTECallBackFindPhoneFunctionClose    设备找手机功能 关
 *
 *  @constant UTECallBackOpenBicycle              打开骑行
 *  @constant UTECallBackCloseBicycle             关闭骑行
 *  @constant UTECallBackOpenSwim                 打开游泳
 *  @constant UTECallBackCloseSwim                关闭游泳
 *  @constant UTECallBackOpenSkip                 打开跳绳
 *  @constant UTECallBackCloseSkip                关闭跳绳
 *
 *  @constant UTECallBackOpenTableTennis          打开乒乓球
 *  @constant UTECallBackCloseTableTennis         关闭乒乓球
 *  @constant UTECallBackOpenBadminton            打开羽毛球
 *  @constant UTECallBackCloseBadminton           关闭羽毛球
 *  @constant UTECallBackOpenTennis               打开网球
 *  @constant UTECallBackCloseTennis              关闭网球
 *
 */
typedef NS_ENUM(NSInteger, UTECallBack) {
    
    UTECallBackUnit,
    UTECallBackInfoHeightWeight,
    UTECallBackSyncTime,
    UTECallBackAlarm,
    
    UTECallBackOpenRemindIncall,
    UTECallBackOpenRemindQQ,
    UTECallBackOpenRemindWeixin,
    UTECallBackOpenRemindSms,
    UTECallBackOpenRemindMore,
    
    UTECallBackCloseRemindIncall,
    UTECallBackCloseRemindQQ,
    UTECallBackCloseRemindWeixin,
    UTECallBackCloseRemindSms,
    UTECallBackCloseRemindMore,
    
    UTECallBackOpenRemindFacebook,
    UTECallBackOpenRemindFacebookMessenger,
    UTECallBackOpenRemindTwitter,
    UTECallBackOpenRemindWhatsApp,
    UTECallBackOpenRemindLine,
    UTECallBackOpenRemindSkype,
    UTECallBackOpenRemindHangouts,
    
    UTECallBackCloseRemindFacebook,
    UTECallBackCloseRemindFacebookMessenger,
    UTECallBackCloseRemindTwitter,
    UTECallBackCloseRemindWhatsApp,
    UTECallBackCloseRemindLine,
    UTECallBackCloseRemindSkype,
    UTECallBackCloseRemindHangouts,
    
    UTECallBackOpenUnitSitRemind,
    UTECallBackCloseSitRemind,
    
    UTECallBackHeartSwitchDynamic,
    UTECallBackHeartSwitchStatic,
    
    UTECallBackDevicesVersion,
    
    UTECallBackDeviceHorizontal,
    UTECallBackDeviceVertical,
    
    UTECallBackDeviceSilence,
    
    UTECallBackDeviceWeather,
    UTECallBackDeviceBattery,
    UTECallBackSwitchHandAndDisplay,
    UTECallBackWeatherSevenDay,
    UTECallBackIbeaconOption,
    UTECallBackMultiLanguage,
    
    UTECallBackSiestaSet,
    UTECallBackSleepNightSet,
    UTECallBackSleepAdjust,
    
    UTECallBackFindPhoneFunctionOpen,
    UTECallBackFindPhoneFunctionClose,
    
    UTECallBackOpenBicycle,
    UTECallBackCloseBicycle,
    UTECallBackOpenSwim,
    UTECallBackCloseSwim,
    UTECallBackOpenSkip,
    UTECallBackCloseSkip,
    
    UTECallBackOpenTableTennis,
    UTECallBackCloseTableTennis,
    UTECallBackOpenBadminton,
    UTECallBackCloseBadminton,
    UTECallBackOpenTennis,
    UTECallBackCloseTennis,
    
};

/*!
 *  @enum UTEDevicesSate
 *
 *  @discussion 设备状态
 *
 *  @constant UTEDevicesSateConnected             设备已经连接状态
 *  @constant UTEDevicesSateDisconnected          设备已经断开状态，如有错误码，请查看UTEErrorCode
 
 *  @constant UTEDevicesSateSyncBegin             设备在同步数据开始
 *  @constant UTEDevicesSateSyncSuccess           设备同步成功完毕
 *  @constant UTEDevicesSateSyncError             设备同步错误，请查看UTEErrorCode
 
 *  @constant UTEDevicesSateHeartDetectingStart   设备心率开始检测
 *  @constant UTEDevicesSateHeartDetectingProcess 设备心率检测中（带有值）
 *  @constant UTEDevicesSateHeartDetectingStop    设备心率停止检测
 *  @constant UTEDevicesSateHeartDetectingError   设备心率检测中错误， 请查看UTEErrorCode
 
 *  @constant UTEDevicesSateBloodDetectingStart   设备血压开始检测
 *  @constant UTEDevicesSateBloodDetectingProcess 设备血压检测中（带有值）
 *  @constant UTEDevicesSateBloodDetectingStop    设备血压停止检测
 *  @constant UTEDevicesSateBloodDetectingError   设备血压检测中错误， 请查看UTEErrorCode
 
 *  @constant UTEDevicesSateCheckFirmwareError    设备检查错误，请查看UTEErrorCode
 
 *  @constant UTEDevicesSateUpdateHaveNewVersion  设备有新版本
 *  @constant UTEDevicesSateUpdateNoNewVersion    设备没有新版本
 *  @constant UTEDevicesSateUpdateBegin           设备升级开始
 *  @constant UTEDevicesSateUpdateSuccess         设备升级成功，设备会自动断开，请重新连接
 *  @constant UTEDevicesSateUpdateError           设备升级失败，请查看UTEErrorCode
 *
 *  @constant UTEDevicesSateCardApduError         设备Apdu数据交互失败，请查看UTEErrorCode
 *
 *  @constant UTEDevicesSatePasswordState         设备密码验证状态 请看UTEPasswordState 请询问相关人员：设备是否有连接的密码验证过程
 *
 *  @constant UTEDevicesSateStep                  设备处于监听计步状态
 *  @constant UTEDevicesSateSleep                 设备处于监听睡眠状态
 *  @constant UTEDevicesSateOther                 设备处于监听其他状态
 *
 *  @constant UTEDevicesSateUV                    设备检测后获取到紫外线的值
 */
typedef NS_ENUM(NSInteger, UTEDevicesSate) {
    UTEDevicesSateConnected = 0,
    UTEDevicesSateDisconnected,
    
    UTEDevicesSateSyncBegin,
    UTEDevicesSateSyncSuccess,
    UTEDevicesSateSyncError,
    
    UTEDevicesSateHeartDetectingStart,
    UTEDevicesSateHeartDetectingProcess,
    UTEDevicesSateHeartDetectingStop,
    UTEDevicesSateHeartDetectingError,
    
    UTEDevicesSateBloodDetectingStart,
    UTEDevicesSateBloodDetectingProcess,
    UTEDevicesSateBloodDetectingStop,
    UTEDevicesSateBloodDetectingError,
    
    UTEDevicesSateCheckFirmwareError,
    
    UTEDevicesSateUpdateHaveNewVersion,
    UTEDevicesSateUpdateNoNewVersion,
    UTEDevicesSateUpdateBegin,
    UTEDevicesSateUpdateSuccess,
    UTEDevicesSateUpdateError,
    
    UTEDevicesSateCardApduError,
    
    UTEDevicesSatePasswordState,
    
    UTEDevicesSateStep,
    UTEDevicesSateSleep,
    UTEDevicesSateOther,
    
    UTEDevicesSateUV,
};

/*!
 *  @enum UTEPasswordState
 *
 *  @discussion 密码状态
 *
 *  @constant UTEPasswordStateNew               设备需要设置一个新的密码(设备从未被连接过,密码是空的)
 *  @constant UTEPasswordStateNeed              设备需要密码输入(设备已设置过密码)
 *  @constant UTEPasswordStateCorrect           输入、验证或者修改的密码成功
 *  @constant UTEPasswordStateError             输入、验证或者修改的密码失败
 */
typedef NS_ENUM(NSInteger, UTEPasswordState) {
    
    UTEPasswordStateNew    = 1,
    UTEPasswordStateNeed,
    UTEPasswordStateCorrect,
    UTEPasswordStateError,
};

/*!
 *  @enum UTEPasswordType
 *
 *  @discussion 密码类型
 *
 *  @constant UTEPasswordTypeConnect           用于连接设备的时候
 *  @constant UTEPasswordTypeConfirm           用于修改密码时候必须验证
 *  @constant UTEPasswordTypeReset             用于修改密码时候验证成功后 重新设置密码
 */
typedef NS_ENUM(NSInteger, UTEPasswordType) {
    
    UTEPasswordTypeConnect    = 1,
    UTEPasswordTypeConfirm,
    UTEPasswordTypeReset,
};

/*!
 *  @enum UTEErrorCode
 *
 *  @discussion 设备错误码
 *
 *  @constant UTEErrorCodeDisconnect          设备远离手机断开，或没电了
 
 *  @constant UTEErrorCodeSyncDisconnect      同步数据时，设备异常断开
 *  @constant UTEErrorCodeHeartingDisconnect  心率测试时，设备异常断开
 *  @constant UTEErrorCodeBloodDisconnect     血压测试时，设备异常断开
 *  @constant UTEErrorCodeSyncVerify          同步数据完毕后，数据校验失败(说明有数据丢失)
 
 *  @constant UTEErrorCodeCheckTimeout        检查设备超时，一般网络超时(10秒)
 *  @constant UTEErrorCodeCheckChara          检查设备时，固件不完整
 *  @constant UTEErrorCodeCheckAddress        检查设备时，固件不完整
 
 *  @constant UTEErrorCodeUpdateDownload      升级设备时，下载固件错误
 *  @constant UTEErrorCodeUpdateDisconnect    升级设备时，设备断开
 
 *  @constant UTEErrorCodeApduDisconnect      设备Apdu数据交互时，设备断开了
 */
typedef NS_ENUM(NSInteger, UTEErrorCode) {
    UTEErrorCodeDisconnect = 1,
    
    UTEErrorCodeSyncVerify,
    UTEErrorCodeSyncDisconnect,
    UTEErrorCodeHeartingDisconnect,
    UTEErrorCodeBloodDisconnect,
    
    UTEErrorCodeCheckTimeout,
    UTEErrorCodeCheckChara,
    UTEErrorCodeCheckAddress,
    
    UTEErrorCodeUpdateDownload,
    UTEErrorCodeUpdateDisconnect,
    
    UTEErrorCodeApduDisconnect,
};

/*!
 *  @enum UTEBluetoothSate
 *
 *  @discussion 手机蓝牙状态
 *
 *  @constant UTEBluetoothSateOpen       手机蓝牙打开
 *  @constant UTEBluetoothSateClose      手机蓝牙关闭
 *  @constant UTEBluetoothSateResetting  手机蓝牙重启
 */
typedef NS_ENUM(NSInteger, UTEBluetoothSate) {
    UTEBluetoothSateOpen = 0,
    UTEBluetoothSateClose,
    UTEBluetoothSateResetting,
};

/*!
 *  @enum UTEQueryType
 *
 *  @discussion 查找数据类型
 *
 *  @constant UTEQueryTypeRun        步数数据
 *  @constant UTEQueryTypeSleep      睡眠数据
 *  @constant UTEQueryTypeHRM        心率数据
 *  @constant UTEQueryTypeAll        所有数据(步数+睡眠)
 */
typedef NS_ENUM(NSInteger, UTEQueryType) {
    UTEQueryTypeRun = 0,
    UTEQueryTypeSleep,
    UTEQueryTypeHRM,
    UTEQueryTypeAll,
};

/*!
 *  @enum UTESleepType
 *
 *  @discussion 睡眠状况
 *
 *  @constant UTESleepTypeAwake          清醒
 *  @constant UTESleepTypeDeepSleep      深睡
 *  @constant UTESleepTypeLightSleep     浅睡
 */
typedef NS_ENUM(NSInteger, UTESleepType) {
    UTESleepTypeAwake = 0,
    UTESleepTypeDeepSleep,
    UTESleepTypeLightSleep,
};

/*!
 *  @enum UTEHRMType
 *
 *  @discussion 睡眠状况
 *
 *  @constant UTEHRMTypeNormal      心率数据正常（用于同步心率数据、正在测试心率时）
 *  @constant UTEHRMTypeSuccess     测试心率成功（用于测试心率完毕后返回，成功）
 *  @constant UTEHRMTypeFail        测试心率失败（用于测试心率完毕后返回，失败）
 *  @constant UTEHRMTypeTimeout     测试心率超时（用于测试心率完毕后返回，超时）
 */
typedef NS_ENUM(NSInteger, UTEHRMType) {
    UTEHRMTypeNormal = 0,
    UTEHRMTypeSuccess,
    UTEHRMTypeFail,
    UTEHRMTypeTimeout,
};

/*!
 *  @enum UTEBloodType
 *
 *  @discussion 血压状况
 *
 *  @constant UTEHRMTypeNormal      血压数据正常（用于同步数据的血压）
 *  @constant UTEHRMTypeSuccess     血压数据成功（用于测试血压完毕后返回，成功）
 *  @constant UTEHRMTypeFail        血压数据失败（用于测试血压完毕后返回，失败）
 *  @constant UTEHRMTypeTimeout     血压数据超时（用于测试血压完毕后返回，超时）
 */
typedef NS_ENUM(NSInteger, UTEBloodType) {
    UTEBloodTypeNormal = 0,
    UTEBloodTypeSuccess,
    UTEBloodTypeFail,
    UTEBloodTypeTimeout,
};

/*!
 *  @enum UTEAlarmWeek
 *
 *  @discussion 星期
 *
 *  @constant UTEAlarmWeekSunday       星期天
 *  @constant UTEAlarmWeekMonday       星期一
 *  @constant UTEAlarmWeekTuesday      星期二
 *  @constant UTEAlarmWeekWednesday    星期三
 *  @constant UTEAlarmWeekThursday     星期四
 *  @constant UTEAlarmWeekFriday       星期五
 *  @constant UTEAlarmWeekSaturday     星期六
 */
typedef NS_ENUM(NSInteger, UTEAlarmWeek) {
    UTEAlarmWeekSunday    = 1 << 0,
    UTEAlarmWeekMonday    = 1 << 1,
    UTEAlarmWeekTuesday   = 1 << 2,
    UTEAlarmWeekWednesday = 1 << 3,
    UTEAlarmWeekThursday  = 1 << 4,
    UTEAlarmWeekFriday    = 1 << 5,
    UTEAlarmWeekSaturday  = 1 << 6,
};

/*!
 *  @enum UTEAlarmNum
 *
 *  @discussion 闹钟序列号
 *
 *  @constant UTEAlarmNum1       第一个闹钟
 *  @constant UTEAlarmNum2       第二个闹钟
 *  @constant UTEAlarmNum3       第三个闹钟
 */
typedef NS_ENUM(NSInteger, UTEAlarmNum) {
    UTEAlarmNum1 = 1,
    UTEAlarmNum2,
    UTEAlarmNum3,
};

/*!
 *  @enum UTEDeviceFeature
 *
 *  @discussion 设备特性 （RK平台无此信息，无需考虑此属性）
 *
 *  @constant UTEDeviceFeatureNone             默认模式
 *  @constant UTEDeviceFeatureWechat           微信模式(微信排行)
 *  @constant UTEDeviceFeatureMessage          消息推送模式
 *  @constant UTEDeviceFeatureWechatMessage    消息推送与微信模式
 *  @constant UTEDeviceFeatureUpdate           升级模式
 *  @constant UTEDeviceFeatureUpdateWechat     升级模式与微信模式(微信排行)
 */
typedef NS_ENUM(NSInteger, UTEDeviceFeature) {
    UTEDeviceFeatureNone,
    UTEDeviceFeatureWechat,
    UTEDeviceFeatureMessage,
    UTEDeviceFeatureWechatMessage,
    UTEDeviceFeatureUpdate,
    UTEDeviceFeatureUpdateWechat,
};

/*!
 *  @enum UTESilenceType
 *
 *  @discussion 勿打扰模式 （需要固件支持）
 *
 *  @constant UTESilenceTypeNone             打开所有功能(不需要手环勿打扰)
 *  @constant UTESilenceTypeScreen           关闭手环屏幕，屏幕将永不亮屏
 *  @constant UTESilenceTypeVibration        关闭手环马达震动，手环将永不震动
 *  @constant UTESilenceTypeMessage          关闭手环任何信息提醒（QQ/Wechat/短信/电话）
 *  @constant UTESilenceTypePhone            关闭手环上一键挂电话功能
 */
typedef NS_ENUM(NSInteger, UTESilenceType) {
    UTESilenceTypeNone              = 0,
    UTESilenceTypeScreen            = 1 << 0,
    UTESilenceTypeVibration         = 1 << 1,
    UTESilenceTypeMessage           = 1 << 2,
    UTESilenceTypePhone             = 1 << 3,
};

/*!
 *  @enum UTEWeatherType
 *
 *  @discussion 天气类型 (固件支持的天气类型)
 *
 *  @constant UTEWeatherTypeSunny         //晴朗
 *  @constant UTEWeatherTypeCloudy        //多云
 *  @constant UTEWeatherTypeOvercast      //阴天
 *  @constant UTEWeatherTypeShower        //阵雨
 *  @constant UTEWeatherTypeThunderStorm  //雷阵雨
 *  @constant UTEWeatherTypeRainSnow      //雨夹雪
 *  @constant UTEWeatherTypeLightRain     //小雨
 *  @constant UTEWeatherTypePouring       //大雨
 *  @constant UTEWeatherTypeSnow          //下雪
 *  @constant UTEWeatherTypeSandstorm     //沙尘暴
 *  @constant UTEWeatherTypeMistHaze      //雾霾
 *  @constant UTEWeatherTypeWind          //有风
 */
typedef NS_ENUM(NSInteger, UTEWeatherType) {
    UTEWeatherTypeSunny         = 1,
    UTEWeatherTypeCloudy,
    UTEWeatherTypeOvercast,
    UTEWeatherTypeShower,
    UTEWeatherTypeThunderStorm,
    UTEWeatherTypeRainSnow,
    UTEWeatherTypeLightRain,
    UTEWeatherTypePouring,
    UTEWeatherTypeSnow,
    UTEWeatherTypeSandstorm,
    UTEWeatherTypeMistHaze,
    UTEWeatherTypeWind,
};

/*!
 *  @enum UTEDeviceSreenDisplayType
 *
 *  @discussion 表盘显示方式
 *
 *  @constant UTEDeviceSreenDisplayTypeHorizontal        //横屏
 *  @constant UTEDeviceSreenDisplayTypeVerticalEN        //竖屏 英文显示
 *  @constant UTEDeviceSreenDisplayTypeVerticalCH        //竖屏 中文显示
 */
typedef NS_ENUM(NSInteger, UTEDeviceSreenDisplayType) {
    UTEDeviceSreenDisplayTypeHorizontal,
    UTEDeviceSreenDisplayTypeVerticalEN,
    UTEDeviceSreenDisplayTypeVerticalCH,
};

/*!
 *  @enum UTEWearType
 *
 *  @discussion 佩戴方式
 *
 *  @constant UTEWearTypeLeft         //左手
 *  @constant UTEWearTypeRight        //右手
 */
typedef NS_ENUM(NSInteger, UTEWearType) {
    UTEWearTypeLeft,
    UTEWearTypeRight,
};

/*!
 *  @enum UTEIbeaconOption
 *
 *  @discussion ibeacon 设置类型
 *
 *  @constant UTEIbeaconOptionUUID                 //uuid
 *  @constant UTEIbeaconOptionMajor                //major
 *  @constant UTEIbeaconOptionMinor                //minor
 *  @constant UTEIbeaconOptionName                 //device name
 *  @constant UTEIbeaconOptionTXPower              //TX Power
 *  @constant UTEIbeaconOptionAdvertisingInterval  //Advertising Interval
 */
typedef NS_ENUM(NSInteger, UTEIbeaconOption) {
    UTEIbeaconOptionUUID,
    UTEIbeaconOptionMajor,
    UTEIbeaconOptionMinor,
    UTEIbeaconOptionName,
    UTEIbeaconOptionTXPower,
    UTEIbeaconOptionAdvertisingInterval,
};

/*!
 *  @enum UTEDeviceInfoSex
 *
 *  @discussion 设置设备信息
 *
 *  @constant UTEDeviceInfoSexDefault       // 默认值
 *  @constant UTEDeviceInfoSexMale          // 男
 *  @constant UTEDeviceInfoSexFemale        // 女
 */
typedef NS_ENUM(NSInteger, UTEDeviceInfoSex) {
    UTEDeviceInfoSexDefault,
    UTEDeviceInfoSexMale,
    UTEDeviceInfoSexFemale,
};

/*!
 *  @enum UTEDeviceLanguage
 *
 *  @discussion 设备哪种语言
 *
 */
typedef NS_ENUM(NSInteger, UTEDeviceLanguage) {
    UTEDeviceLanguageChinese  = 1,        //中文
    UTEDeviceLanguageOther,               //非中文
};


/*!
 *  @enum UTEDeviceSleepAuxType
 *
 *  @discussion 睡眠辅助开关
 *
 */
typedef NS_ENUM(NSInteger, UTEDeviceSleepAuxType) {
    UTEDeviceSleepAuxTypeDefault  = 0,        //默认
    UTEDeviceSleepAuxTypeOpen     = 1,        //开
    UTEDeviceSleepAuxTypeClose    = -1,       //关
};

/*!
 *  @enum UTEDeviceRemindEnableType
 *
 *  @discussion 设备推送信息的开关
 *
 */
typedef NS_ENUM(NSInteger, UTEDeviceRemindEnableType) {
    UTEDeviceRemindDefault  = 0,        //默认
    UTEDeviceRemindOpen     = 1,        //开
    UTEDeviceRemindClose    = -1,       //关
};

/*!
 *  @enum UTEDeviceSleepStatus
 *
 *  @discussion 设备设置睡眠的开关
 *
 */
typedef NS_ENUM(NSInteger, UTEDeviceSleepStatus) {
    UTEDeviceSleepStatusOpen ,       //打开设置睡眠时间段监测
    UTEDeviceSleepStatusClose,       //关闭设置睡眠时间段监测
};

/*!
 *  @enum UTEDeviceSleepTimeType
 *
 *  @discussion 设备设置睡眠的类型
 *
 */
typedef NS_ENUM(NSInteger, UTEDeviceSleepTimeType) {
    UTEDeviceSleepTimeTypeSiesta,      //白天午睡
    UTEDeviceSleepTimeTypeNight,       //晚上睡眠
};

/*!
 *  @enum UTEDeviceBallType
 *
 *  @discussion 设备球类类型
 *
 */
typedef NS_ENUM(NSInteger, UTEDeviceBallType) {
    UTEDeviceBallTypeTableTennis  = 1,      //乒乓球
    UTEDeviceBallTypeBadminton,             //羽毛球
    UTEDeviceBallTypeTennis,                //网球
};

@end






