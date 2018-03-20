//
//  ICTBleSDKEnums.h
//  ICTBleSDKFramework
//
//  Created by MikeZhou on 15/7/6.
//  Copyright (c) 2015年 iCareTech. All rights reserved.
//

#ifndef iCareTek_ICTBleSDKEnums_h
#define iCareTek_ICTBleSDKEnums_h

//手环类型
typedef NS_ENUM(NSInteger, ICTBandType)
{
    ICTBandRedhare=1,//redhare手环
};

//数据是在什么情况下被采集的
typedef NS_ENUM(NSInteger, ICTBodyParamGatherType)
{
    ICTBodyParamGatherTypeNormalInMonitor         = 0x0001,//监护模板定制的正常采集
    ICTBodyParamGatherTypeEmergencyInMonitor      = ICTBodyParamGatherTypeNormalInMonitor << 1,//监护模板定制的紧急采集
    ICTBodyParamGatherTypeEmergencyWithoutMonitor = ICTBodyParamGatherTypeEmergencyInMonitor << 1,//手机发起的紧急采集
    ICTBodyParamGatherTypeManual                  = ICTBodyParamGatherTypeEmergencyWithoutMonitor << 1,//手动录入的数据
    ICTBodyParamGatherTypeByUser                  = ICTBodyParamGatherTypeManual << 1,//用户发起的单次测量和连续测量
    
    ICTBodyParamGatherTypeAll                     = 0xffff
};

//体参类别
typedef NS_ENUM(NSInteger, ICTBleSDKBodyParameterType)
{
    ICTBleSDKBodyParameterTemperature            = 0x0001,//腕温(当手环端需要采集运动强度时，也发送该值)
    ICTBleSDKBodyParameterHeartRate              = ICTBleSDKBodyParameterTemperature << 1,//0x0002
    ICTBleSDKBodyParameterSPO2                   = ICTBleSDKBodyParameterHeartRate << 1,//0x0004
    ICTBleSDKBodyParameterMoveIndex              = 0x0200,//运动强度
    
    ICTBleSDKBodyParameterStep                   = ICTBleSDKBodyParameterMoveIndex << 1,//步数
    ICTBleSDKBodyParameterDistance               = ICTBleSDKBodyParameterStep << 1,//距离
    ICTBleSDKBodyParameterCalorie                = ICTBleSDKBodyParameterDistance << 1,//卡路里
    
    ICTBleSDKBodyParameterStop                   = 0x00ff,
    ICTBleSDKBodyParameterAll                    = 0xffff
};

//采集途径
typedef NS_ENUM(NSInteger, ICTBleGatherWay)
{
    ICTGatherWayManual = 0,     //手动
    ICTGatherWayRealTime,       //即时采集
    ICTGatherWayDevice,         //设备同步
    
    ICTGatherWayUnknow = 0xffff
};

//监护方案
typedef NS_ENUM(NSInteger, ICTMonitorTemplateIDs)
{
    kICTMonitorTemplateNone = -1,                       //未选择方案
    kICTMonitorTemplateAtrialFibrillationID = 2,        //房颤
    kICTMonitorTemplateCHDID = 3,                       //冠心病
    kICTMonitorTemplateHeartRateID = 4,                 //循环系统-其他心脏病
    kICTMonitorTemplateAsthmaticBronchitis = 5,         //支气管哮喘
    kICTMonitorTemplateSleepApneaID = 6,                //睡眠综合症
    kIctmonitorTemplateCustomizeID = 7,                 //自定义
    kIctmonitorTemplateSubHealthID = 8,                 //亚健康
    kIctmonitorTemplateAltitudeStress = 9,              //高原反应 -- jun 添加
    kIctmonitorTemplateChronicObstructive = 10,         //慢性阻塞性肺疾病
    kIctmonitorTemplateNightLowSpo2 = 11,               //夜间低血氧
    kIctmonitorTemplateSnoring = 16,                    //鼾症方案
    
    kICTMonitorTemplateIDMax
};

//固件升级错误类型
typedef NS_ENUM(NSInteger, ICTFWError)
{
    ICTFWErrorNoFirmUpdate,//没有需要更新的固件
    ICTFWErrorBandDisconnect,//手环断开
    ICTFWErrorBandError,//手环升级出错
    ICTFWErrorFirmCRCError,//固件包CRC校验出错
    ICTFWErrorFirmPackageError//固件包错误(比如升级成功后，版本号正确)
};

//固件类型
typedef NS_ENUM(NSInteger, ICTBleSDKFWType)
{
    ICTBleSDKFWTypeMA = 0,
    ICTBleSDKFWTypeMB = 1<<4,
    ICTBleSDKFWTypeMC = 2<<4,
    ICTBleSDKFWTypeMD = 3<<4,
    ICTBleSDKFWTypeME = 4<<4,
    ICTBleSDKFWTypeInvalid = INT32_MAX
};

//数据查询方向和顺序
typedef NS_ENUM(NSInteger, ICTDaoSearchDirect)
{
    ICTDaoSearchDirectForward,      //时间轴负方向
    ICTDaoSearchDirectBackward      //时间轴正方向
};

typedef NS_ENUM(NSInteger, ICTDaoSearchOrder)
{
    ICTDaoSearchASC,    //升序
    ICTDaoSearchDESC,   //降序
};

//性别
typedef NS_ENUM(NSInteger, ICTUserSexEnum)
{
    ICTUserSexMale = 0,
    ICTUserSexFemale,
};

#endif
