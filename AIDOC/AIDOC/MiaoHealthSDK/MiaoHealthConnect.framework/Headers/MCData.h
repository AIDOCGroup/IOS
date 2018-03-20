//
//  MCData.h
//  MiaoHealthConnect
//
//  Created by 罗志平 on 16/12/29.
//  Copyright © 2016年 Miao Health. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MMPeripheralsProvider.h"

@interface MCUserInfo : NSObject

#pragma mark - 数值信息 非必填项
/// 用户名
@property (nonatomic, strong) NSString  *_Nullable userName;
/// 年龄  (瘦身)
@property (nonatomic, assign) NSInteger age;
/// 性别  (瘦身)  0 为男  1 为女
@property (nonatomic, assign) BOOL      sex;
/// 区域
@property (nonatomic, strong) NSString  *_Nullable area;

#pragma mark - 数值信息 相应数据必填项
/// 身高  （运动，瘦身）
@property (nonatomic, assign) NSInteger height;
/// 体重   (运动)
@property (nonatomic, assign) float     weight;

/// 出生日期
@property (nonatomic , copy) NSString * _Nullable birthDay;

@end


@interface MCData : NSObject
/// 设备编码
@property (nonatomic, strong) NSString *_Nonnull device_sn;
/// 设备序列号
@property (nonatomic, strong) NSString *_Nonnull device_no;
/// 测量时间
@property (nonatomic, strong) NSString *_Nonnull measure_time;
/// 数据来源
@property (nonatomic, strong) NSString *_Nullable data_source;
/// 数据类型(默认PeripheralsDataTypeMessage 为没有)
@property (nonatomic, assign) PeripheralsDataType functional_id;

@end

@interface MCBloodSugar : MCData

#pragma mark - 数值信息
/// 血糖值
@property (nonatomic, assign) float glucose_value;

@end


@interface MCWeight : MCData

/// 数据来源（1：一般秤，2：体脂称
@property (nonatomic, assign) NSInteger fat_scale;

#pragma mark - 传入值
//@property (nonatomic, assign) NSInteger height;

#pragma mark - 数值信息  固值
/// 体重
@property (nonatomic, assign) float weight;

#pragma mark - 数值信息  非固值
/// BMI最新值
@property (nonatomic, assign) float bmi;
/// 体脂率
@property (nonatomic, assign) float fat_ratio;
/// 肌肉
@property (nonatomic, assign) float muscle;
/// 骨量
@property (nonatomic, assign) float bone_mass;
/// 基础代谢
@property (nonatomic, assign) float metabolism;
/// 体水分
@property (nonatomic, assign) float moisture;

#pragma mark - 蓝牙值 非固值
/// 皮下脂肪
@property (nonatomic, assign) float subcutaneousFat;
/// 蛋白率
@property (nonatomic, assign) float proteinRate;
/// 内脏脂肪
@property (nonatomic, assign) float visceralFat;
/// 生理年龄
@property (nonatomic, assign) float physicalAge;
/// 阻抗值
@property (nonatomic, assign) int newAdc;


@end


@interface MCThermometer : MCData

#pragma mark - 数值信息  固值
/// 温度
@property (nonatomic, assign) float temperature;

@end


@interface MCBloodPressure : MCData

#pragma mark - 数值信息  固值
/// 高压
@property (nonatomic, assign) NSInteger high_press;
/// 低压
@property (nonatomic, assign) NSInteger low_press;
/// 心率
@property (nonatomic, assign) NSInteger heart_rate;

#pragma mark - 数值信息  非固值
/// 平均血压值
@property (nonatomic, assign) NSInteger avg_press_value;
/// 血压等级 1、  值为（1-低血压，2-正常，3-正常高，4-轻度高血压，5-中度高血压，6-重度高血压）
@property (nonatomic, assign) NSInteger bloodpress_level;

@end


@interface MCSport : MCData
/// 日期
@property (nonatomic, strong) NSString *_Nullable date_time;

#pragma mark - 数值信息  固值
/// 步数
@property (nonatomic, assign) NSInteger steps;
/// 卡路里
@property (nonatomic, assign) double calories;
/// 距离
@property (nonatomic, assign) double distance;
/// 睡眠时长
@property (nonatomic, assign) NSInteger duration;
/// 有效睡眠时长
@property (nonatomic, assign) NSInteger effect_duration;

@property (nonatomic , assign) BOOL showSleep;

@end

@interface MCHeartRate : MCData

#pragma mark - 数值信息  固值
/// 心率
@property (nonatomic, assign) NSInteger heartRate;

@end


@interface MCSleep : MCData
/// 记录日期（yyyy-MM-dd）
@property (nonatomic, strong) NSString *_Nullable date_time;

#pragma mark - 数值信息  固值
/// 睡眠时长
@property (nonatomic, assign) NSInteger duration;
/// 有效睡眠时长
@property (nonatomic, assign) NSInteger effect_duration;
/// 深度睡眠
@property (nonatomic  ,assign) NSInteger deep_duration;
///浅睡眠
@property (nonatomic , assign) NSInteger light_duration;

//开始时间
@property (nonatomic , copy) NSString *_Nullable startTime;

//结束时间
@property (nonatomic , copy) NSString *_Nullable endTime;

@end

/* 专业睡眠 */
@interface MCSleepPro : MCData

/// 记录日期（yyyy-MM-dd）
@property (nonatomic, strong) NSString *_Nullable date_time;

/// 睡眠时长
@property (nonatomic, assign) NSInteger duration;

/// 有效睡眠时长：单位秒
@property (nonatomic, assign) NSInteger effect_duration;

//开始时间
@property (nonatomic , copy) NSString *_Nullable startTime;

//结束时间
@property (nonatomic , copy) NSString *_Nullable endTime;

/// 清醒时长(秒)
@property (nonatomic, assign) NSInteger awake_duration;
/// 清醒期占比（整数）
@property (nonatomic, assign) NSInteger awake_percent;
/// 中睡时长(秒)
@property (nonatomic, assign) NSInteger moderate_duration;
/// 中睡占比(整数)
@property (nonatomic  ,assign) NSInteger moderate_percent;
/// 浅睡占比(整数)
@property (nonatomic , assign) NSInteger light_percent;
///浅睡眠
@property (nonatomic , assign) NSInteger light_duration;

/// 深度睡眠
@property (nonatomic  ,assign) NSInteger deep_duration;
// 深睡占比(整数)
@property (nonatomic , assign) NSInteger deep_percent;

// 体动次数
@property (nonatomic , assign) NSInteger movement_times;

// 平均呼吸
@property (nonatomic , assign) NSInteger avg_breath;

// 平均心率
@property (nonatomic , assign) NSInteger avg_heart_rate;

// 呼吸暂停次数
@property (nonatomic , assign) NSInteger apnea_times;

// 呼吸暂停时长(秒)
@property (nonatomic , assign) NSInteger apnea_duration;

//  呼吸次数
@property (nonatomic , assign) NSInteger breath_times;

@end

@interface MCOximeter : MCData

#pragma mark - 数值信息  固值
/// 血氧值
@property (nonatomic, assign) NSInteger spO2;
/// 心率
@property (nonatomic, assign) NSInteger heartRate;

@end

/*
 多功能设备
 */
@interface MCMultiplyDevice : MCData

#pragma mark - 数值信息  固值
/// 睡眠时长
@property (nonatomic, assign) NSInteger duration;
/// 有效睡眠时长
@property (nonatomic, assign) NSInteger effect_duration;

/// 日期
@property (nonatomic, strong) NSString *_Nullable date_time;

#pragma mark - 数值信息  固值
/// 步数
@property (nonatomic, assign) NSInteger steps;
/// 卡路里
@property (nonatomic, assign) double calories;
/// 距离
@property (nonatomic, assign) double distance;

@end

// 尿检仪
@interface MCUroscopy : MCData

//pro    String    蛋白质 +/-
@property (nonatomic , copy) NSString *_Nullable pro;
//ph    Float    酸碱度
@property (nonatomic , assign) float ph;
//bld    String    潜血 +/-
@property (nonatomic , copy) NSString *_Nullable bld;
//sg    Float    尿比重
@property (nonatomic , assign) float sg;
//ma    Integer    微量白蛋白 单位mg/L
@property (nonatomic , assign) NSInteger ma;
//cr    Float    肌酐 单位mmol/L
@property (nonatomic , assign) float cr;
//acr    Float    微量白蛋白与肌酐的比值
@property (nonatomic , assign) float acr;
@end

