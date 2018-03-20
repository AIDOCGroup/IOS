//
//  CommonClass.h
//  LandiReader
//
//  Created by HudongFang on 16/2/10.
//  Copyright © 2016年 LANDI. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *	@brief	通讯方式
 *	param 	CHANNEL_AJ   音频方式
 *	param 	CHANNEL_BT   蓝牙方式
 */
typedef enum {
    CHANNEL_AJ = 0x00,
    CHANNEL_BT = 0x01,
}LD_DEVICE_CHANNEL;

typedef enum  {
    CARD_MAG        = 0x01,
    CARD_IC         = 0x02,
    CARD_RF         = 0x04,
    CARD_SE         = 0x05,
}ICCardSlot;

typedef enum  {
    CARD_SCIRPT        = 0x01,
    HEART_RECORD       = 0x03,
    TRADE_RECORD       = 0x04,
    RUNNING_RECORD     = 0x05,
}FileType;

typedef enum  {
    POWER_DOWN        = 0x01,
    POWER_SAVE_MODE   = 0x02,
    POWER_REBOOT      = 0x03,
}SystemPowerManageType;

typedef enum  {
    TM_PBOC_RET_SUCCESS	= 0x00,
    TM_PBOC_RET_REJECT	= 0x01,
    TM_PBOC_RET_ONLINE	= 0x02,
    TM_PBOC_RET_NO_MATCH_AID = 0x03,
    TM_PBOC_RET_SELECT_AID = 0x04,
    
    // TM_PBOC_RET_FALLBACK = 0xFF,
    TM_PBOC_RET_FAIL = 0xFF,
}PBOC_RET_CODE;

@interface EMVRet : NSObject
@property (nonatomic) PBOC_RET_CODE retCode;
@property (nonatomic,strong) NSData *retData;
@end

@interface LDStepLength : NSObject
@property (nonatomic) int walk;     //走路步长：范围0-255 单位cm
@property (nonatomic) int run;      //跑步步长：范围0-255 单位cm
@end


@interface LDPersonal : NSObject
@property (nonatomic) int height;//	身高：范围0-255单位cm
@property (nonatomic) int weight;//	体重：范围0-255单位cm
@property (nonatomic) int sex;  //	性别：男0 女1
@property (nonatomic,copy) NSString* birthDay;     //出生年月YYYYMM
@end


@interface DeviceBaseInfo : NSObject
@property (nonatomic,copy) NSString* deviceUUID;     //设备UUID，音频设备无此参数
@property (nonatomic,copy) NSString* deviceName;            //设备名称
@property (nonatomic,copy) NSDictionary* deviceAdData;            //设备广播数据
@property (nonatomic) LD_DEVICE_CHANNEL  deviceChannel;        //设备通讯方式
@end


/**
 *	@brief	设备硬件配置
 */
@interface TerminalCap :NSObject
@property (nonatomic)bool isSuportLCD;//带屏幕
@property (nonatomic)bool isSuportBT;//正常蓝牙
@property (nonatomic)bool isSuportUSB;//带USB
@property (nonatomic)bool isSuportSE;//带SE
@property (nonatomic)bool isSuportHeart;//带心率模块
@property (nonatomic)bool isSuportGsensor;//带陀螺仪
@property (nonatomic)bool isSupportLongSitRemind;//是否支持久坐
@property (nonatomic)bool isSupportCallInRemind;//是否支持来电
@property (nonatomic)bool isSupportMsgInRemind;//是否支持短信
@property (nonatomic)bool isSupportHandUpRemind;//是否支持抬手
@property (nonatomic)bool isSupportLostRemind;//是否支持防丢
@property (nonatomic)bool isSupportWeChatSport;//是否支持微信运动
@property (nonatomic)bool isSupportDoubleNums;//是否支持双享号
@property (nonatomic)bool isSupportRunningMode;//是否支持跑步
-(id)initWithData:(NSData*)data;
@end

@interface DeviceInfo : NSObject
@property (copy,nonatomic) NSString *lakalaSn;          //客户自定义SN号
@property (copy,nonatomic) NSString *ksn;               //即SEID
@property (copy,nonatomic) NSString *LandiSn;           //联迪自有SN号
@property (copy,nonatomic) NSString *bandType;          //手环型号
@property (nonatomic) int batteryLevel;                 //电池电量
@property (copy,nonatomic) NSString *BtMac;             //蓝牙MAC地址
@property (copy,nonatomic) NSString *userVer;           //设备固件版本
@property (copy,nonatomic) NSString *bootVer;           //设备Boot版本
@property (copy,nonatomic) NSString *ctrlVer;           //设备Ctrl版本
@property (copy,nonatomic) NSString *productAllocation; //生产配置
@property (copy,nonatomic) NSString *cardScriptVersion; //脚本版本号
@property (nonatomic) TerminalCap *terminalCap;    //手环配置能力
@end

typedef NS_ENUM(NSInteger, HealthDataType) {
    HealthDataType_HeartRecord = 0,
    HealthDataType_SleepRecord,
    HealthDataType_SportRecord,
    HealthDataType_TradeRecord,

};

@protocol SearchDeviceListener <NSObject>
/**
 *  发现一台设备
 */
- (void) onFindOneDevice:(DeviceBaseInfo*)deviceInfo;
/**
 *  设备搜索完成
 */
- (void) onSearchComplete;
@end


@protocol HealthDataChangeListener <NSObject>

- (void) onStepChange:(int)step;

- (void) onHealthDataChange:(NSArray *)newDataType;
@end


@protocol ConnectDeviceListener <NSObject>
/**
 *  设备已断开
 */
-(void)deviceDisconnect:(int) code;
/**
 *  设备连接成功
 */
-(void)connectSuccess;
/**
 *  设备连接失败
 */
-(void)connectFailed:(NSString*) errorMesg;
@end


@protocol UpdateFirmwareListener <NSObject>
/**
 *  固件更新成功
 */
-(void)onUpdateFirmwareSucc;
/**
 *  正在更新
 *
 *  @param percent 更新进度 0 - 100
 */
-(void)onUpdateFirmwarePercent:(int)percent;
/**
 *  固件更新失败
 *
 *  @param errorMesg 错误信息
 */
-(void)onUpdateFirmwareFail:(NSString*) errorMesg;
@end
