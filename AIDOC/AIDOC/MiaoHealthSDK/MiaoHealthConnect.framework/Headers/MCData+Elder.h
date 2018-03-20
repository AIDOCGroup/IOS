//
//  MCData+Elder.h
//  MiaoHealthConnect
//
//  Created by 罗志平 on 17/2/10.
//  Copyright © 2017年 Miao Health. All rights reserved.
//

#import "MCData.h"

/*
 * 联系人
 */
@interface MCElderRelation : MCData
/// 关联Id
@property (nonatomic, assign) long rid;
/// 真实姓名
@property (nonatomic, strong) NSString *_Nullable name;
/// 昵称
@property (nonatomic, strong) NSString *_Nullable nickname;
/// 电话
@property (nonatomic, strong) NSString *_Nullable mobile;

@end

/*
 * 亲情提醒
 */
@interface MCElderRemind : MCData
/// 关联Id
@property (nonatomic, assign) long rid;
/// 提醒开始日期
@property (nonatomic, strong) NSString *_Nullable start_at;
/// 提醒开始时间
@property (nonatomic, strong) NSString *_Nullable start_time;
/// 提醒类型(0.无, 1.睡觉, 2.起床, 3.活动, 4.休息, 5.吃药)
@property (nonatomic, assign) NSInteger remind_type;
/// 提醒重复类型(0.不重复, 1.按天重复)
@property (nonatomic, assign) NSInteger repeat_type;
/// 提醒内容
@property (nonatomic, strong) NSString *_Nullable content;

@end


/*
 * 日报
 */
@interface MCElderDayReport : NSObject
/// 全天累计步数
@property (nonatomic, assign) NSInteger step_sum;
/// 久坐次数
@property (nonatomic, assign) NSInteger sit_long;
/// 行走次数
@property (nonatomic, assign) NSInteger liveness;
/// 健康评分
@property (nonatomic, assign) NSInteger point_today;
/// 睡眠时长（秒）
@property (nonatomic, assign) NSInteger sleep_time;
/// 佩戴有效时长（秒）
@property (nonatomic, assign) NSInteger valid_wear;
/// 步频（步/分钟）
@property (nonatomic, assign) NSInteger step_freq;

@end

/*
 * 佩戴信息
 */
@interface MCElderWearInfo : NSObject
/// 开始时间
@property (nonatomic, assign) long start_time;
/// 结束时间
@property (nonatomic, assign) long end_time;
/// 位置信息
@property (nonatomic, strong) NSString *_Nullable position;
/// 佩戴状态(sellp:睡觉,dot:室内,none:未佩戴,out:室外,charge:充电)
@property (nonatomic, strong) NSString *_Nullable wear_state;
/// 行为状态
@property (nonatomic, strong) NSString *_Nullable behavior_state;
/// 文字说明
@property (nonatomic, strong) NSString *_Nullable remark;

@end

/*
 * 位置信息
 */
@interface MCElderPosition : NSObject
/// 纬度
@property (nonatomic, assign) long latitude;
/// 经度
@property (nonatomic, assign) long longitude;
/// 位置信息
@property (nonatomic, strong) NSString *_Nullable position;
/// 位置时间
@property (nonatomic, strong) NSString *_Nullable position_time;
/// 状态(sellp:睡觉,dot:室内,none:未佩戴,out:室外,charge:充电)
@property (nonatomic, strong) NSString *_Nullable state;
/// 精度
@property (nonatomic, assign) NSInteger accuracy;
/// 坐标系（1：高德地图GCJ02）
@property (nonatomic, assign) NSInteger coordinate_system;

@end


/*
 * 警告信息
 */
@interface MCElderCaution : NSObject
/// 纬度
@property (nonatomic, assign) long latitude;
/// 经度
@property (nonatomic, assign) long longitude;
/// 位置信息
@property (nonatomic, strong) NSString *_Nullable position;
/// 报警时间
@property (nonatomic, assign) long alert_time;
/// 报警类型描述
@property (nonatomic, strong) NSString *_Nullable alert_type;
/// 真实姓名
@property (nonatomic, strong) NSString *_Nullable name;
/// 处理状态：1未处理 2已处理
@property (nonatomic, assign) NSInteger status;

typedef void (^OperateSuccessBlock) (id _Nullable result);
typedef void (^OperateFailureBlock)(NSInteger status, NSString *_Nullable msg, NSError *_Nullable error);

@end

