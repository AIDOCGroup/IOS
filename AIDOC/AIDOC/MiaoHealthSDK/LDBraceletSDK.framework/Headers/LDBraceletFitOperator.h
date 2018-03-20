//
//  LDBraceletFitOperator.h
//  LDBraceletSDK
//
//  Created by houhm on 16/11/24.
//  Copyright © 2016年 houhm. All rights reserved.
//

#ifndef LDBraceletFitOperator_h
#define LDBraceletFitOperator_h
#import "CommonClass.h"
#import "LDBraceletOutType.h"

@protocol LDBraceletFitOperator

- (double)getCalorie:(bool)sex height:(u_long)height weight:(u_long)weight age:(u_long)age run:(u_long)run walk:(u_long)walk;

-(void)setPersonalParams:(LDPersonal *)params;

-(LDPersonal *)personalParams;

-(void)setCurSportTarget:(NSInteger)target;

-(NSInteger)curSportTarget;

- (void)setCurSleepTarget:(NSInteger)target;

- (NSInteger)curSleepTarget;

- (void)setStepLenght:(LDStepLength *)stepLenght;

-(void)setAlarmClock:(int)tag data:(NSMutableDictionary *)data;

-(NSMutableDictionary *)alarmClock:(int)tag;
/**
 *设置提醒开关
 * byte数组，目前有8位
 * Byte1 手机来电提醒
 * Byte2 短信
 * Byte3 抬手亮屏
 * Byte4 手环来电
 * Byte5 久坐提醒
 * Byte6 手机防丢
 * Byte7 蓝牙速率切换
 * Byte8 微信运动开关
 * Byte9 心率开关
 * Byte10 微信提醒
 * Byte11 微博提醒
 * Byte12 QQ提醒
 * 每位值有三种：0x01 打开；0x00 关闭；0x03及其他 不设置
 *
 **/
-(void)setRemind:(NSData *)flags;


-(NSData *)remind;



/*
 * 获取久坐提醒数据
 *
 * 返回数据包含以下：
 * @param start 提醒起始时间
 * @param end   提醒中止时间
 * @param flag  1:打开；0：关闭
 * @param 久坐提醒时间 单位：分钟
 *
 */
-(NSMutableDictionary *)sittingRemind;

/* 设置久坐提醒选项
 * @param start    提醒起始时间   例如：如设置09：30 则值为 930
 * @param end     提醒中止时间  例如：如设置18：30 则值为  1830
 *@param  interval  提醒间隔   单位：分钟
 * @param start1  禁用提醒起始时间 例如：如设置12：00 则值为  1200
 * @param end1   禁用提醒中止时间 例如：如设置14：00 则值为  1400
 * @param flag  1:打开；0：关闭
 *
 **/
-(void)setSittingRemindOptions:(int)start end:(int)end interval:(int)interval start1:(int)start1 end1:(int)end1 open:(int)flag;

/**
 * 获取久坐提醒数据禁用设置
 *
 * 返回数据包含以下：
 * {start 提醒起始时间
 *  end   提醒中止时间
 *  start1 禁用提醒起始时间
 *  end1  禁用提醒中止时间
 *  flag  1:打开；0：关闭
 *  }
 *
 **/
-(NSMutableDictionary *)sittingRemindOptions;
/**
 *
 * 返回数据包含以下属性：
 * 日期：date
 * 走路步长：walkStep
 * 跑步步长：runStep
 * 卡路里：calorie
 * 总距离：distance;
 * 每5分钟列表：sportlist
 **/
-(NSDictionary *)currentSportRecord;

/*
 [
 {
 date:日期
 time:时间
 walkCount:步行步数
 walkDistance:步行距离
 walkTime:步行时间
 runCount:跑步步数
 runDistance:跑步距离
 runTime:跑步时间
 calorie:卡路里
 distance:总距离
 },
 {
 date:日期
 time:时间
 walkCount:步行步数
 walkDistance:步行距离
 walkTime:步行时间
 runCount:跑步步数
 runDistance:跑步距离
 runTime:跑步时间
 calorie:卡路里
 distance:总距离
 }
 ];
 
 */
- (NSArray *)currentSportRecordWithOneHour;

/**
 * 获取有效运动的tag，一天对应一个tag
 *
 **/
-(NSArray *)effectiveSprotTaglist;

/**
 *
 * 获取指定tag的运动记录
 * @param day 指定tag
 *
 * 返回数据包含以下属性：
 * 日期：date
 * 走路步长：walkStep
 * 跑步步长：runStep
 * 卡路里：calorie
 * 总距离：distance;
 * 每5分钟列表：sportlist
 **/
-(NSDictionary *)historySportRecord:(int)day;


/*
 [
 {
 date:日期
 time:时间
 walkCount:步行步数
 walkDistance:步行距离
 walkTime:步行时间
 runCount:跑步步数
 runDistance:跑步距离
 runTime:跑步时间
 calorie:卡路里
 distance:总距离
 },
 {
 date:日期
 time:时间
 walkCount:步行步数
 walkDistance:步行距离
 walkTime:步行时间
 runCount:跑步步数
 runDistance:跑步距离
 runTime:跑步时间
 calorie:卡路里
 distance:总距离
 }
 ];
 
 */
- (NSArray *)historySportRecordWithOneHour:(int)day;
/**
 * 清除指定tag的运动记录
 *
 * @param day 指定tag
 **/
-(void)clearHistorySportRecord:(int)day;

/**
 *
 * 获取当前睡眠记录
 * 包含以下属性：
 * [
 * {
 *  date:日期
 *  starTime:开始时间
 *  endTime:结束时间
 *  status:状态
 *  }
 * {
 *  date:日期
 *  starTime:开始时间
 *  endTime:结束时间
 *  status:状态（睡眠状态，0：深睡眠，1：浅睡眠，2：意识睡眠，3：活动状态）
 *  }
 * ]
 **/
-(NSArray *)currentSleepRecord;

/**
 * 获取有效睡眠的tag，一天对应一个tag
 *
 **/
-(NSArray *)effectiveSleepTaglist;

/**
 *
 * 获取指定tag的睡眠记录
 * 包含以下属性：
 * [
 * {
 *  date:日期
 *  starTime:开始时间
 *  endTime:结束时间
 *  status:状态
 *  }
 * {
 *  date:日期
 *  starTime:开始时间
 *  endTime:结束时间
 *  status:状态（睡眠状态，0：深睡眠，1：浅睡眠，2：意识睡眠，3：活动状态）
 *  }
 * ]
 **/
-(NSArray *)historySleepRecord:(int)day;


/**
 * 清除指定tag的睡眠记录
 *
 **/
-(void)clearHistorySleepRecord:(int)day;

/**
 *获取步长
 *
 **/
-(LDStepLength *)stepLenth;

/**
 *获取心率
 *
 **/
- (int)heartRate;

/**
 开始进入心率实时监听模式
 
 @return 心率实时监听模式进入结果
 */
- (BOOL)startHeartRateRealTimeMonitor;
/**
 退出实时心率实时监听模式
 */
- (BOOL)stopHeartRateRealTimeMonitor;

- (NSArray *)historyHeartRateRecords;

- (BOOL)clearHeartRateRecords;

//清除本地跑步记录
- (BOOL)clearRunningRecords;

//获取本地跑步纪录列表
- (NSArray<LDRunningRecords *> *)localRunningRecords;

//心率预警值设置
- (void)setHeartRateWarnningValue:(int)value;

//获取心率预警值
- (int)heartRateWarnningValue;

/*设置跑步界面显示
* 配速	心率	    步数	    里程  RFU	RFU	    RFU	    RFU
*/
- (void)setRunningDisplayFlag:(NSString *)flag;

/*获取界面跑步显示
* 配速	心率	    步数	    里程  RFU	RFU	    RFU	    RFU
 */
- (NSString *)runningDisplayFlag;

@end

#endif
