//
//  Reston_HistoryData.h
//  SDK
//
//  Created by Martin on 2017/8/1.
//  Copyright © 2017年 Martin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BluetoothManager/BluetoothManager.h>

typedef NS_ENUM(NSInteger,Reston_ScoreDeductibleTypes) {
    Reston_ScoreDeductibleType_BodyMoveToomuch = 0,//躁动不安
    Reston_ScoreDeductibleType_LeftBedToomany,//睡觉起夜， 离床次数过多
    Reston_ScoreDeductibleType_AwakeTooFrequent,//睡觉易醒 , 清醒次数过多
    Reston_ScoreDeductibleType_SleepToolate,//太晚睡觉
    Reston_ScoreDeductibleType_DifficultToSleep,//太难入睡
    Reston_ScoreDeductibleType_DeepSleepNotEnough,//深睡眠不足
    Reston_ScoreDeductibleType_SleepTooLong,//实际睡眠时长过长
    Reston_ScoreDeductibleType_SleepTooShort,//实际睡眠时长太短
    Reston_ScoreDeductibleType_BreathPause,//呼吸暂停
    Reston_ScoreDeductibleType_HeartbeatPause,//心跳暂停
    Reston_ScoreDeductibleType_HeartbeatLow,//心跳过缓
    Reston_ScoreDeductibleType_HeartbeatHigh,//心跳过速
    Reston_ScoreDeductibleType_BreathLow,//呼吸过缓
    Reston_ScoreDeductibleType_BreathHight,//呼吸过速
    Reston_ScoreDeductibleType_optimumSleepPercentTooLow,//良性睡眠比例低
    
    Reston_ScoreDeductibleType_Invalid,
};

@interface Z1_HistoryDataDetail : HistoryDataDetail
@property (nonatomic,strong) NSArray *sleepStatusArray;//睡眠状态数组
@property (nonatomic,strong) NSArray *sleepStatusValueArray;//睡眠状态附加数组
@property (nonatomic,strong) NSArray *heartBeatRateValueArray;//心跳数组
@property (nonatomic,strong) NSArray *breathRateValueArray;//呼吸速率数组


@end

@interface Z4T_HistoryDataDetail : Z1_HistoryDataDetail
@property (nonatomic,strong) NSArray *temperatureAry;//温度
@property (nonatomic,strong) NSArray *humidityAry;//湿度
@end

@interface Z1_HistoryDataAnalysis : HistoryDataAnalysis
/*呼吸暂停
 0：代表没有出现呼吸暂停
 其他代表呼吸暂停的时间 单位：秒
 */
@property (nonatomic,strong) NSArray<NSNumber *> *breathRateStatusAry;
/*心跳状态
 0：代表没有没有出现心跳暂停
 其他代表心跳暂停的时间 单位：秒
 */
@property (nonatomic,strong) NSArray<NSNumber *> *heartRateStatusAry;
/*离床
 0：代表没有离床
>0：代表离床的时间 单位：秒 一般为60
 */
@property (nonatomic,strong) NSArray<NSNumber *> *leftBedStatusAry;//离床状态
/*翻身的次数
 0：代表没有翻身
 其他代表翻身的次数
 */
@property (nonatomic,strong) NSArray<NSNumber *> *turnOverStatusAry;//翻身

@property (nonatomic,assign) NSInteger averageBreathRate; //平均呼吸率
@property (nonatomic,assign) NSInteger averageHeartBeatRate;  //平均心率
@property (nonatomic,assign) NSInteger leaveBedTimes;//离床次数
@property (nonatomic,assign) NSInteger trunOverTimes; //翻身次数
@property (nonatomic,assign) NSInteger bodyMovementTimes; //体动次数
@property (nonatomic,assign) NSInteger heartBeatPauseTimes;  //心跳暂停次数
@property (nonatomic,assign) NSInteger breathPauseTimes;  //呼吸暂停次数
@property (nonatomic,assign) NSInteger breathPauseAllTime;  //呼吸暂停时长
@property (nonatomic,assign) NSInteger heartBeatPauseAllTime;  //心跳暂停时长
@property (nonatomic,assign) NSInteger leaveBedAllTime;  //离床时长
@property (nonatomic,assign) NSInteger maxHeartBeatRate;  //最高心率
@property (nonatomic,assign) NSInteger maxBreathRate;  //最高呼吸率
@property (nonatomic,assign) NSInteger minHeartBeatRate;  //最低心率
@property (nonatomic,assign) NSInteger minBreathRate ; //最低呼吸率
@property (nonatomic,assign) NSInteger heartBeatRateFastAllTime ; //心率过速时长
@property (nonatomic,assign) NSInteger heartBeatRateSlowAllTime ; //心率过缓时长
@property (nonatomic,assign) NSInteger breathRateFastAllTime ; //呼吸率过速时长
@property (nonatomic,assign) NSInteger breathRateSlowAllTime ; //呼吸率过缓时长

@end
