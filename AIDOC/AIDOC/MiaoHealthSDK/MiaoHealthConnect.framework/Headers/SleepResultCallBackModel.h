//
//  SleepResultCallBackModel.h
//  sleep
//
//  Created by 123 on 2017/9/7.
//  Copyright © 2017年 SHNSKJ-sleep. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SleepResultCallBackModel : NSObject

/**
 * 开始睡眠时间
 * @param startSleepTime 开始睡眠时间戳
 * @param startSleepDuration 入睡时长，秒 换算小时除以3600
 * @param sleepDuration 总的睡眠时长，秒 换算小时3600
 * @param ambientNoise 环境噪音 BOOL YES正常  NO不正常
 * @param deepSleep 深睡时间 秒 换算小时除以3600
 * @param lightSleep 浅睡时间 秒 换算小时除以3600
 * @param wakeDream 醒/梦时间 秒 换算小时除以3600
 * @param bodyMovement 体动次数
 * @param sleepGrade 睡眠评分
 *
 * @param detailDatasqliteAddress 详细数据的数据库保存地址
 * @param totleDataAddress        统计后的数据库保存地址
 * @param wavAddress              录音的保存地址
 */

@property (nonatomic,assign) int startSleepTime;
@property (nonatomic,assign) int endSleepTime;
@property (nonatomic,assign) int startSleepDuration;
@property (nonatomic,assign) int sleepDuration;
@property (nonatomic,assign) BOOL ambientNoise;
@property (nonatomic,assign) int deepSleep;
@property (nonatomic,assign) int lightSleep;
@property (nonatomic,assign) int wakeDream;
@property (nonatomic,assign) int bodyMovement;
@property (nonatomic,assign) int sleepGrade;

@property (nonatomic,copy) NSString *detailDatasqliteAddress;
@property (nonatomic,copy) NSString *totleDataAddress;
@property (nonatomic,copy) NSString *wavAddress;

@property (nonatomic,assign) int sleepDay;
@property (nonatomic,assign) int sleepMonth;
@property (nonatomic,assign) int sleepYear;

@end
