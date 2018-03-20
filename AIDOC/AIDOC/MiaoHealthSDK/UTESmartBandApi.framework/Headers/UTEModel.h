//
//  UTEModel.h
//  UTESmartBandApi
//
//  Created by VV on 2017/8/9.
//  Copyright © 2017年 vv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UTEDefine.h"

@interface UTEModel : NSObject
@end

/*!
 *  UTEModelDevices 设备属性模型
 */
@interface UTEModelDevices : NSObject
/**
 *  设备版本
 */
@property (nonatomic,copy  ) NSString *version;
/**
 *  设备名称
 */
@property (nonatomic,copy  ) NSString *name;
/**
 *  设备唯一标示
 */
@property (nonatomic,copy  ) NSString *identifier;
/**
 *  设备电量 只有连接上设备才有值
 */
@property (nonatomic,assign) NSInteger battery;
/**
 *  设备连接状态
 */
@property (nonatomic,assign) BOOL     isConnected;
/**
 *  设备是否具有此属性（连接上才有值） （RK平台无此信息，无需考虑此属性）
 */
@property (nonatomic,assign) BOOL     isHasExtra;
/**
 *  设备是否具心率功能
 */
@property (nonatomic,assign) BOOL     isHasHRM;
/**
 *  设备是否具血压功能
 */
@property (nonatomic,assign) BOOL     isHasBlood;
/**
 *  设备是否具天气功能 设备支持2天内的天气
 */
@property (nonatomic,assign) BOOL     isHasWeather;
/**
 *  设备是否具天气功能 设备支持7天内的天气
 */
@property (nonatomic,assign) BOOL     isHasWeatherSeven;
/**
 *  设备是否具横竖屏幕切换功能
 */
@property (nonatomic,assign) BOOL     isHasOrientation;
/**
 *  设备是否具勿打扰功能
 */
@property (nonatomic,assign) BOOL     isHasSilence;
/**
 *  设备是否可以使能抬手亮屏
 */
@property (nonatomic,assign) BOOL     isHasHandLight;
/**
 *  设备是否具备最大心率警报功能
 */
@property (nonatomic,assign) BOOL     isHasMaxHeartAlert;
/**
 *  设备是否支持动静态切换功能
 *  这个值只在扫描设备时有值,连接之后无效
 */
@property (nonatomic,assign) BOOL     isSwitchHeart;
/**
 *  设备是否支持表盘切换 和 左右手切换
 */
@property (nonatomic,assign) BOOL     isHasSwitchHand;
/**
 *  设备是否支持ibeacon 功能
 */
@property (nonatomic,assign) BOOL     isHasIbeacon;
/**
 *  设备是否支持 走路和跑步区分 功能
 */
@property (nonatomic,assign) BOOL     isHasWalkRun;
/**
 *  设备是否支持 跳绳 功能
 */
@property (nonatomic,assign) BOOL     isHasSkip;
/**
 *  设备是否支持 游泳 功能
 */
@property (nonatomic,assign) BOOL     isHasSwim;
/**
 *  设备是否支持 骑车 功能
 */
@property (nonatomic,assign) BOOL     isHasBicycle;
/**
 *  设备是否支持 乒乓球 功能
 */
@property (nonatomic,assign) BOOL     isHasTableTennis;
/**
 *  设备是否支持 羽毛球 功能
 */
@property (nonatomic,assign) BOOL     isHasBadminton;
/**
 *  设备是否支持 网球 功能
 */
@property (nonatomic,assign) BOOL     isHasTennis;
/**
 *  设备是否为 新的距离和卡路里 计算方式
 */
@property (nonatomic,assign) BOOL     isHasNewCalculate;
/**
 *  设备是否支持 多个闹钟(三个) 功能  仅新的固件支持
 */
@property (nonatomic,assign) BOOL     isHasMulClock;
/**
 *  设备是否支持 久坐提醒 功能 仅新的固件支持
 */
@property (nonatomic,assign) BOOL     isHasRemindSit;
/**
 *  设备是否支持 事务提醒 功能 仅新的固件支持
 */
@property (nonatomic,assign) BOOL     isHasRemindTask;
/**
 *  成功连接的设备是否有升级功能(如有，就不需要多一个操作：改变特性了)
 */
@property (nonatomic,assign) BOOL     isHasUpdateFunction;
/**
 *  设备是否支持紫外线检功能
 */
@property (nonatomic,assign) BOOL     isHasUV;
/**
 *  设备当前是否支持微信排行功能
 */
@property (nonatomic,assign) BOOL     isHasWechat;
/**
 *  设备当前是否新的微信协议5模式
 */
@property (nonatomic,assign) BOOL     isWechatModel5;
/**
 *  设备当前是可以设置年龄和性别等等参数
 */
@property (nonatomic,assign) BOOL     isHasAgeSex;
/**
 *  设备当前是否支持来电拒接功能
 */
@property (nonatomic,assign) BOOL     isHasHangup;
/**
 *  设备当前是否支持心率辅助睡眠监测
 */
@property (nonatomic,assign) BOOL     isHasSleepAux;
/**
 *  设备当前是否支持GPS定位
 */
@property (nonatomic,assign) BOOL     isHasGPS;
/**
 *  设备当前是否支持久坐提醒时间范围的设置
 */
@property (nonatomic,assign) BOOL     isHasSitRemindDuration;
/**
 *  设备当前是否支持设备多国语言设置
 */
@property (nonatomic,assign) BOOL     isHasMultiLanguage;
/**
 *  设备当前是否支持设备的智能防丢
 */
@property (nonatomic,assign) BOOL     isHasSmartLost;
/**
 *  设备当前是否支持设备的找手机
 */
@property (nonatomic,assign) BOOL     isHasFindiPhone;
/**
 *  设备当前是否支持 单独控制指定App软件信息推送
 *  支持Facebook,Facebook Messenger,Twitter,WhatsApp,Line,Skype,Hangouts
 */
@property (nonatomic,assign) BOOL     isHasSocialNotification;
/**
 *  支持修改睡眠时间
 */
@property (nonatomic,assign) BOOL     isHasCustomSleep;
/**
 *  设备信号强度 （如_isScanRepeat=true，则在扫描过程中会实时变化,被连上的设备不被赋值）
 */
@property (nonatomic,assign) NSInteger rssi;
/**
 *  设备蓝牙地址，只有连接上设备才有值
 */
@property (nonatomic,strong) NSData   *address;
/**
 *  设备另外特性，只有连接上设备才有实际值：不同的特性支持不同的功能（具体请看文档说明）
 */
@property (nonatomic,assign) UTEDeviceFeature   featureAnother;
/**
 *  设备广播里面包含的内容(4个key):
 *
 *    kCBAdvDataServiceUUIDs
 *    kCBAdvDataLocalName
 *    kCBAdvDataManufacturerData
 *    kCBAdvDataIsConnectable
 *
 *  备注:如设备连上了，此值将变为空.
 */
@property (nonatomic,strong) NSDictionary       *advertisementData;
@end

/*!
 *  UTEModelAlarm 设备闹钟模型
 */
@interface UTEModelAlarm : NSObject
/**
 *  闹钟时间24进制 格式: @"09:30" @"21:05"
 */
@property (nonatomic,copy  ) NSString      *time;
/**
 *  闹钟星期(七位数) 格式:详细请看文档
 */
@property (nonatomic,assign) UTEAlarmWeek  week;
/**
 *  闹钟使能
 */
@property (nonatomic,assign) BOOL          enable;
/**
 *  闹钟序列号,第几个闹钟
 */
@property (nonatomic,assign) UTEAlarmNum   num;

@end

/*!
 *  UTEModelRunData 历史步数模型
 */
@interface UTEModelRunData : NSObject
/**
 *  时间格式: @"2015-08-08-13"
 */
@property (nonatomic,copy  ) NSString     *time;
/**
 *  一天的总卡路里 单位千卡
 */
@property (nonatomic,assign) CGFloat      calories;
/**
 *  一小时内的卡路里 单位千卡
 */
@property (nonatomic,assign) CGFloat      hourCalories;
/**
 *  一小时内步数
 */
@property (nonatomic,assign) NSInteger    hourSteps;
/**
 *  一天的总步数
 */
@property (nonatomic,assign) NSInteger    totalSteps;
/**
 *  一天的总距离 单位米
 */
@property (nonatomic,assign) CGFloat      distances;
/**
 *  一小时内的距离 单位米
 */
@property (nonatomic,assign) CGFloat      hourDistances;

@end

/*!
 *  UTEModelSleepData 历史睡眠模型
 */
@interface UTEModelSleepData : NSObject
/**
 *  开始时间格式: @"2015-08-08-23-30"
 */
@property (nonatomic,copy  ) NSString     *startTime;
/**
 *  结束时间格式: @"2015-08-09-07-30"
 */
@property (nonatomic,copy  ) NSString     *endTime;
/**
 *  睡眠状况
 */
@property (nonatomic,assign) UTESleepType sleepType;

@end

/*!
 *  UTEModelHRMData 心率模型
 */
@interface UTEModelHRMData : NSObject

/**
 *  心率时间格式: @"2015-08-08-23-30"
 */
@property (nonatomic,copy  ) NSString  *heartTime;
/**
 *  心率每分钟跳动次数
 */
@property (nonatomic,copy  ) NSString  *heartCount;
/**
 *  UTEHRMType 心率测试数据是否 正常、成功、超时、失败
 */
@property (nonatomic,assign) UTEHRMType heartType;

@end

/*!
 *  UTEModelBloodData 血压模型
 */
@interface UTEModelBloodData : NSObject

/**
 *  时间格式: @"2015-08-08-23-30"
 */
@property (nonatomic,copy) NSString  *bloodTime;
/**
 *  收缩压
 */
@property (nonatomic,copy) NSString  *bloodSystolic;
/**
 *  舒张压
 */
@property (nonatomic,copy) NSString  *bloodDiastolic;
/**
 *  血压状态
 */
@property (nonatomic,assign) UTEBloodType  bloodType;

@end

/*!
 *  UTEWeather 天气模型
 */
@interface UTEModelWeather : NSObject
/**
 *  城市 设备仅支持显示最多中文4个字，其他语言请填@"00"
 */
@property (nonatomic,copy  ) NSString   *city;
/**
 *  今天的PM2.5
 */
@property (nonatomic,assign) NSInteger  pm25;
/**
 *  今天的AQI
 */
@property (nonatomic,assign) NSInteger  aqi;
/**
 *  今天的当前温度
 */
@property (nonatomic,assign) NSInteger  temperatureCurrent;
/**
 *  最高气温
 */
@property (nonatomic,assign) NSInteger  temperatureMax;
/**
 *  最低气温
 */
@property (nonatomic,assign) NSInteger  temperatureMin;
/**
 *  天气类型
 */
@property (nonatomic,assign) UTEWeatherType  type;

@end

/*!
 *  UTEModelSportWalk 运动模式 走路模型
 */
@interface UTEModelSportWalkRun : NSObject
/**
 *  当前时间格式: @"2015-08-08-13"
 */
@property (nonatomic,copy  ) NSString     *time;
/**
 *  当前小时走路和跑步的总步数
 */
@property (nonatomic,assign) NSInteger    stepsTotal;
/**
 *  走路的步数
 */
@property (nonatomic,assign) NSInteger    walkSteps;
/**
 *  走路开始时间 格式:@"05" 如当前 2015-08-08-13 的 05 分
 */
@property (nonatomic,copy  ) NSString     *walkTimeStart;
/**
 *  走路结束时间 格式:@"59" 如当前 2015-08-08-13 的 59 分
 */
@property (nonatomic,copy  ) NSString     *walkTimeEnd;
/**
 *  走路时长 单位分钟
 */
@property (nonatomic,assign) NSInteger    walkDuration;
/**
 *  距离 单位米
 */
@property (nonatomic,assign) CGFloat      walkDistances;
/**
 *  卡路里 单位千卡
 */
@property (nonatomic,assign) CGFloat      walkCalories;


/**
 *  跑步的步数
 */
@property (nonatomic,assign) NSInteger    runSteps;
/**
 *  跑步开始时间 格式:@"05" 如当前 2015-08-08-13 的 05 分
 */
@property (nonatomic,copy  ) NSString     *runTimeStart;
/**
 *  跑步结束时间 格式:@"59" 如当前 2015-08-08-13 的 59 分
 */
@property (nonatomic,copy  ) NSString     *runTimeEnd;
/**
 *  跑步时长 单位分钟
 */
@property (nonatomic,assign) NSInteger    runDuration;
/**
 *  距离 单位米 前提isHasNewCalculate=Yes 否则为0
 */
@property (nonatomic,assign) CGFloat      runDistances;
/**
 *  卡路里 单位千卡 前提isHasNewCalculate=Yes 否则为0
 */
@property (nonatomic,assign) CGFloat      runCalories;



@end


/*!
 *  UTEModelSportSwim 运动模式 游泳模型
 */
@interface UTEModelSportSwim : NSObject

/**
 *  时间格式: @"2015-08-08"
 */
@property (nonatomic,copy  ) NSString     *time;
/**
 *  游泳开始时间格式: @"08-15" 时-分 只记录一天中的第一次
 */
@property (nonatomic,copy  ) NSString     *timeStart;
/**
 *  游泳结束时间格式: @"20-15" 时-分 只记录一天中的最后一次
 */
@property (nonatomic,copy  ) NSString     *timeEnd;
/**
 *  游泳时长 单位秒 累计一天总共时长
 */
@property (nonatomic,assign) NSInteger    duration;
/**
 *  游泳划臂力次数  累计一天总共次数
 */
@property (nonatomic,assign) NSInteger    count;

@end

/*!
 *  UTEModelSportSkip 运动模式 跳绳模型
 */
@interface UTEModelSportSkip : NSObject

/**
 *  时间格式: @"2015-08-08"
 */
@property (nonatomic,copy  ) NSString     *time;
/**
 *  跳绳开始时间格式: @"08-15" 时-分 只记录一天中的第一次
 */
@property (nonatomic,copy  ) NSString     *timeStart;
/**
 *  跳绳结束时间格式: @"20-15" 时-分 只记录一天中的最后一次
 */
@property (nonatomic,copy  ) NSString     *timeEnd;
/**
 *  跳绳时长 单位秒 累计一天总时长
 */
@property (nonatomic,assign) NSInteger    duration;
/**
 *  跳绳次数  累计一天总共次数
 */
@property (nonatomic,assign) NSInteger    count;

@end


/*!
 *  UTEModelDeviceBicycle 设备 骑行 模型
 */
@interface UTEModelDeviceBicycle : NSObject
/**
 *  时间格式: @"2015-08-08"
 */
@property (nonatomic,copy  ) NSString      *time;
/**
 * 开始时间 如@"15-30"
 */
@property (nonatomic,copy  ) NSString      *timeStart;
/**
 * 结束时间 如@"17-09"
 */
@property (nonatomic,copy  ) NSString      *timeEnd;
/**
 * 有效的骑行时间累计 单位 秒
 */
@property (nonatomic,assign) NSInteger     durationValid;

/**
 * 消耗卡路里 单位 千卡
 */
@property (nonatomic,assign) CGFloat       calories;

@end

/*!
 *  UTEModelDeviceTableTennis 设备 兵乓球 模型
 */
@interface UTEModelDeviceTableTennis : NSObject
/**
 *  时间格式: @"2015-08-08"
 */
@property (nonatomic,copy  ) NSString      *time;
/**
 * 开始时间 如@"15-30"
 */
@property (nonatomic,copy  ) NSString      *timeStart;
/**
 * 结束时间 如@"17-09"
 */
@property (nonatomic,copy  ) NSString      *timeEnd;
/**
 * 有效的兵乓球运动时间累计 单位 秒
 */
@property (nonatomic,assign) NSInteger     durationValid;

/**
 * 消耗卡路里 单位 千卡
 */
@property (nonatomic,assign) CGFloat       calories;

@end

/*!
 *  UTEModelDeviceTennis 设备 网球 模型
 */
@interface UTEModelDeviceTennis : NSObject
/**
 *  时间格式: @"2015-08-08"
 */
@property (nonatomic,copy  ) NSString      *time;
/**
 * 开始时间 如@"15-30"
 */
@property (nonatomic,copy  ) NSString      *timeStart;
/**
 * 结束时间 如@"17-09"
 */
@property (nonatomic,copy  ) NSString      *timeEnd;
/**
 * 有效的网球运动时间累计 单位 秒
 */
@property (nonatomic,assign) NSInteger     durationValid;

/**
 * 消耗卡路里 单位 千卡
 */
@property (nonatomic,assign) CGFloat       calories;

@end

/*!
 *  UTEModelDeviceTennis 设备 羽毛球 模型
 */
@interface UTEModelDeviceBadminton : NSObject
/**
 *  时间格式: @"2015-08-08"
 */
@property (nonatomic,copy  ) NSString      *time;
/**
 * 开始时间 如@"15-30"
 */
@property (nonatomic,copy  ) NSString      *timeStart;
/**
 * 结束时间 如@"17-09"
 */
@property (nonatomic,copy  ) NSString      *timeEnd;
/**
 * 有效的羽毛球运动时间累计 单位 秒
 */
@property (nonatomic,assign) NSInteger     durationValid;

/**
 * 消耗卡路里 单位 千卡
 */
@property (nonatomic,assign) CGFloat       calories;

@end


/*!
 *  UTEModelDeviceInfo 设置设备信息的模型
 */
@interface UTEModelDeviceInfo : NSObject
/**  身高 UTEOptionUnitMeter  单位cm   范围格式 <91,240>
 *   身高 UTEOptionUnitInch   单位inch 范围格式 <3.00,7.11> 3尺00寸 ~ 7尺11寸 (小数点为11进制)
 *   如不修改，不需要赋值。但是第一次连接成功设备必须赋值，然后SDK 会保存此为临时变量，如不设置，则距离和卡路里 可能全部为 0
 */
@property (nonatomic,assign) CGFloat      heigh;
/**
 *   体重 UTEOptionUnitMeter 单位kg 范围格式 <20,150>
 *   体重 UTEOptionUnitInch  单位lb 范围格式 <44,333>
 *   如不修改，不需要赋值。但是第一次连接成功设备必须赋值，然后SDK 会保存此为临时变量，如不设置，则距离和卡路里 可能全部为 0
 */
@property (nonatomic,assign) NSInteger    weight;
/**
 *  亮屏时间(秒) 范围<5,60>
 *  如不修改，不需要赋值
 */
@property (nonatomic,assign) NSInteger     lightTime;
/**
 *  有的设备支持显示一天的步数进度
 *  如不修改，不需要赋值
 */
@property (nonatomic,assign) NSInteger     sportTarget;
/**
 *  抬手亮屏的开关 请查看isHasHandLight来判断是否支持此功能
 *   1 表示打开，-1 表示关闭 ，0 表示默认原来的
 *  如不修改，不需要赋值
 */
@property (nonatomic,assign) NSInteger     handlight;
/**
 *  超过最大心率值警报 请查看isHasMaxHeartAlert来判断是否支持此功能
 *  如不修改，不需要赋值 范围<100,200> 关闭则填 -1
 */
@property (nonatomic,assign) NSInteger     maxHeart;
/**
 *  睡眠辅助功能 请查看isHasSleepAux来判断是否支持此功能
 *  如打开，则睡眠监测会相对更加准确，但也会增加设备电量消耗
 *  UTEDeviceSleepAuxTypeOpen 1 表示打开，
 *  UTEDeviceSleepAuxTypeClose -1 表示关闭 ，
 *  UTEDeviceSleepAuxTypeDefalut 0 表示默认原来的
 *  如不修改，不需要赋值
 */
@property (nonatomic,assign) UTEDeviceSleepAuxType    sleepAux;
/**
 *  年龄 范围格式 <0,100>
 *  如不修改，不需要赋值
 */
@property (nonatomic,assign) NSInteger    age;
/**
 *  性别
 *  如不赋值，则为UTEDeviceInfoSexDefault
 */
@property (nonatomic,assign) UTEDeviceInfoSex    sex;
/**
 *  设备智能防丢
 *  当为Yes，设备与手机断开时，设备将会警报(振动或者声音警报)
 */
@property (nonatomic,assign) BOOL    isSmartLost;

@end

/*!
 *  UTEModelDeviceGPS 设置设备 GPS 模型
 */
@interface UTEModelDeviceGPS : NSObject
/**
 *   开始时间 如@"2008-08-25-16-21" 同步 GPS 数据的时候才有值
 */
@property (nonatomic,copy) NSString     *startTime;
/**
 *   结束时间 如@"2008-08-25-17-30" 同步 GPS 数据的时候才有值
 */
@property (nonatomic,copy) NSString     *endTime;
/**
 *   纬度 如@"23.3333" wgs84坐标
 */
@property (nonatomic,copy) NSString     *latitude;
/**
 *   经度 如@"23.3333" wgs84坐标
 */
@property (nonatomic,copy) NSString     *longitude;
/**
 *   速度 如@"30.5" (km/h)
 */
@property (nonatomic,copy) NSString     *speed;
/**
 *   信号强度 如@"45" 范围 0 ~ 100,越大信号越好
 */
@property (nonatomic,copy) NSString     *signal;

@end

/*!
 *  UTEModelDeviceSitRemind 设备 久坐 模型
 */
@interface UTEModelDeviceSitRemind : NSObject

/**
 *   总开关
 */
@property (nonatomic,assign) BOOL       enable;
/**
 *   开始时间 如@"16:21"
 */
@property (nonatomic,copy) NSString     *startTime;
/**
 *   结束时间 如@"17:30"
 */
@property (nonatomic,copy) NSString     *endTime;
/**
 *   久坐多长时间就提醒
 *   单位分钟
 *   范围<30,254> 如不在范围内，则设备此属性保持原来不变
 */
@property (nonatomic,assign) NSInteger   duration;
/**
 *   午休勿打扰开关 范围(中午12点 到 下午 14点)
 */
@property (nonatomic,assign) BOOL        enableSiesta;

@end

/*!
 *  UTEModelDeviceInterface 设备 界面文字 模型
 */
@interface UTEModelDeviceInterface : NSObject

/**
    Tips: 显示的文字 (NSString最大长度为25,支持任何字符 简单例如俄语@"привет" 阿拉伯语@"مرحبا")
    哪国语言
 */
@property (nonatomic,assign) UTEDeviceLanguage     language;

/**
    步数界面  显示文字默认:  步
 */
@property (nonatomic,copy) NSString     *num1Step;
/**
    距离界面  显示文字默认:  千米
 */
@property (nonatomic,copy) NSString     *num2KM;
/**
    卡路里界面 显示文字默认: 千卡
 */
@property (nonatomic,copy) NSString     *num3KCAL;
/**
    心率界面  显示文字默认: 正在识别
 */
@property (nonatomic,copy) NSString     *num4Reading;
/**
    锻炼界面  显示文字默认: 锻炼
 */
@property (nonatomic,copy) NSString     *num5Training;
/**
    跳绳界面  显示文字默认: 跳绳
 */
@property (nonatomic,copy) NSString     *num6Skipping;
/**
    游泳界面  显示文字默认: 游泳
 */
@property (nonatomic,copy) NSString     *num7Swiming;
/**
    消息界面  显示文字默认: 消息
 */
@property (nonatomic,copy) NSString     *num8Message;
/**
    功能界面  显示文字默认: 功能
 */
@property (nonatomic,copy) NSString     *num9Function;
/**
    更换表盘界面  显示文字默认: 更换表盘
 */
@property (nonatomic,copy) NSString     *num10Dial;
/**
    版本信息界面  显示文字默认: 产品信息
 */
@property (nonatomic,copy) NSString     *num11Information;
/**
    还原设置界面  显示文字默认: 还原设置
 */
@property (nonatomic,copy) NSString     *num12Restore;
/**
    关机界面  显示文字默认: 关机
 */
@property (nonatomic,copy) NSString     *num13Poweroff;
/**
    来电界面  显示文字默认: 长按拒接
 */
@property (nonatomic,copy) NSString     *num14Refused;
/**
    版本界面  显示文字默认: 版本
 */
@property (nonatomic,copy) NSString     *num15Version;
/**
    查找手机界面  显示文字默认: 查找手机
 */
@property (nonatomic,copy) NSString     *num16FindiPhone;
/**
    自行车界面  显示文字默认: 自行车
 */
@property (nonatomic,copy) NSString     *num17Bicycle;
/**
    乒乓球界面  显示文字默认: 兵乓球
 */
@property (nonatomic,copy) NSString     *num18TableTennis;
/**
    羽毛球界面  显示文字默认: 羽毛球
 */
@property (nonatomic,copy) NSString     *num19Badminton;
/**
    网球界面  显示文字默认: 网球
 */
@property (nonatomic,copy) NSString     *num20Tennis;

@end

/*!
 *  UTEModelDeviceRemindApp 设备 App 模型
 */
@interface UTEModelDeviceRemindApp : NSObject

@property (nonatomic,assign) UTEDeviceRemindEnableType     Phone;
@property (nonatomic,assign) UTEDeviceRemindEnableType     SMS;
@property (nonatomic,assign) UTEDeviceRemindEnableType     QQ;
@property (nonatomic,assign) UTEDeviceRemindEnableType     Wechat;
@property (nonatomic,assign) UTEDeviceRemindEnableType     Facebook;
@property (nonatomic,assign) UTEDeviceRemindEnableType     FacebookMessenger;
@property (nonatomic,assign) UTEDeviceRemindEnableType     Twitter;
@property (nonatomic,assign) UTEDeviceRemindEnableType     WhatsApp;
@property (nonatomic,assign) UTEDeviceRemindEnableType     Line;
@property (nonatomic,assign) UTEDeviceRemindEnableType     Skype;
@property (nonatomic,assign) UTEDeviceRemindEnableType     Hangouts;

@property (nonatomic,assign) UTEDeviceRemindEnableType     Other;     //除了以上之外,其他App

@end

/*!
 *  UTEModelDeviceSleepAdjust 设备 矫正睡眠 模型
 *  提示:晚上的睡眠时间范围 与 午睡的睡眠时间范围 不要重叠
 */
@interface UTEModelDeviceSleepAdjust : NSObject

/**
    监测睡眠开始时间 如格式: @"23:05"
    晚上睡眠开始时间范围:  18:00 ~ 23:59
    午睡时间范围:     12:00 ~ 17:59
 */
@property (nonatomic,copy  ) NSString                   *timeDurationStart;
/**
    监测睡眠结束时间 如格式: @"08:20"
    晚上睡眠结束时间范围:  00:00 ~ 11:59
    午睡时间范围:     12:00 ~ 17:59
 */
@property (nonatomic,copy  ) NSString                   *timeDurationEnd;
/**
    指定修改睡眠监测范围
 */
@property (nonatomic,assign) BOOL                       timeDurationSet;
/**
    睡眠时间段的打开/关闭
 */
@property (nonatomic,assign) UTEDeviceSleepStatus       timeDurationStatus;
/**
    晚上/午睡
 */
@property (nonatomic,assign) UTEDeviceSleepTimeType     timeDurationType;




/**
    调整一整晚睡眠时间 开始睡眠 原来时间点
    如格式: @"23:05"
    针对 UTEDeviceSleepTimeTypeNight有效
 */
@property (nonatomic,copy  ) NSString                   *timeAdjustStartTimeDefault;
/**
    调整一整晚睡眠时间 的 开始睡眠 修改的时间点
    如格式: @"00:30"
    针对 UTEDeviceSleepTimeTypeNight有效
 */
@property (nonatomic,copy  ) NSString                   *timeAdjustStartTimeChange;
/**
    指定矫正睡眠监测 开始的睡眠点
 */
@property (nonatomic,assign) BOOL                       timeAdjustStartTimeSet;

/**
    调整一整晚睡眠时间 的 结束睡眠 原来时间点
    如格式: @"08:20"
    针对 UTEDeviceSleepTimeTypeNight有效
 */
@property (nonatomic,copy  ) NSString                   *timeAdjustEndTimeDefault;
/**
    调整一整晚睡眠时间 的 结束睡眠 修改的时间点
    如格式: @"09:30"
    针对 UTEDeviceSleepTimeTypeNight有效
 */
@property (nonatomic,copy  ) NSString                   *timeAdjustEndTimeChange;
/**
    指定矫正睡眠监测 结束的睡眠点
 */
@property (nonatomic,assign) BOOL                       timeAdjustEndTimeSet;


@end




