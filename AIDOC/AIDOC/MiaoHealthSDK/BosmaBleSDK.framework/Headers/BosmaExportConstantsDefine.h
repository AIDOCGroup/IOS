//
//  BosmaExportConstantsDefine.h
//  BosmaBleSDK
//
//  Created by TaoLi on 2017/4/20.
//  Copyright © 2017年 Bosma. All rights reserved.
//

#ifndef BosmaExportConstantsDefine_h
#define BosmaExportConstantsDefine_h

typedef NS_ENUM(NSUInteger,  BosmaGenderType) {
    BosmaGenderType_Male=0,//男
    BosmaGenderType_Female=1,//女
};
typedef NS_ENUM(NSUInteger,  BosmaMeasureUnitType) {
    BosmaMeasureUnitType_KG=0x00,//公斤
    BosmaMeasureUnitType_HalftKG=0x01,//斤
    BosmaMeasureUnitType_LB=0x02,//镑
};
typedef NS_ENUM(NSUInteger,  BosmaDeviceType) {
    BosmaDeviceType_All=0,//所有设备
    BosmaDeviceType_Thermometer=1,//智能体温计
    BosmaDeviceType_Scale=2,//智能秤
};

typedef NS_ENUM(NSUInteger,  SendThmCmdType) {//App向体温计发送命令
    SendThmCmdType_Connect=0x81,//连接命令
    SendThmCmdType_SyncTime=0x82,//时间同步
    SendThmCmdType_Electric=0x84,//查看电量
    SendThmCmdType_RealtimeTemp=0x91,//实时温度
    SendThmCmdType_HistoryTemp=0x92,//历史温度
    SendThmCmdType_AlertTemp=0xA1,//报警温度
    SendThmCmdType_SettingHisFreque=0xA3,//历史温度记录频率
    SendThmCmdType_SettingLostMode=0xA2,//设置防丢模式
};

typedef NS_ENUM(NSUInteger,  ReceiveThmCmdType) {//收到体温计设备发过来的命令
    ThmReceiveCmdType_UnKnown=0xff,
    ThmReceiveCmdType_Connect=0x01,//连接命令
    ThmReceiveCmdType_SyncTime=0x02,//时间同步
    ThmReceiveCmdType_Electric=0x04,//查看电量
    ThmReceiveCmdType_RealtimeTemp=0x11,//实时温度
    ThmReceiveCmdType_HistoryTemperature=0x12,//历史温度
    ThmReceiveCmdType_AlertTemp=0x21,//报警温度
    ThmReceiveCmdType_SettingHisFreque=0x23,//历史温度记录频率
    ThmRecieveCmdType_SettingLostMode=0x22,//设置防丢模式
    };

typedef NS_ENUM(NSUInteger,  ThmConfirmResultType){//体温计处理确认结果
    ThmConfirmResultType_OK=0x00,//处理正确或设置成功
    ThmConfirmResultType_CheckError=0x01,//校验出错
    ThmConfirmResultType_OtherError=0xff,//其他错误
};
#define kBosmaScalePrefix @"JustFit" //Bosma体脂称产品蓝牙名称前缀
#define kBosmaThermometerPrefix @"Bosma" //Bosma体温计产品蓝牙名称前缀
static NSString * const  deviceVersionString = @"deviceVersion";//固件版本
static NSString * const  deviceIdString = @"deviceId";//设备Id
static NSString * const  electricString = @"electric";//设备电量百分比，整数（100-代表满电）
#endif /* BosmaExportConstantsDefine_h */
