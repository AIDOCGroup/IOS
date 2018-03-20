//
//  Milky_HistoryData.h
//  SDK
//
//  Created by Martin on 2017/8/7.
//  Copyright © 2017年 Martin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BluetoothManager/BluetoothManager.h>

typedef NS_ENUM(NSInteger,Milky_ScoreDeductibleTypes) {
    Milky_ScoreDeductibleType_SleepTooLong = 0,//睡眠时长过长
    Milky_ScoreDeductibleType_SleepTooShort,//睡眠时长太短
    Milky_ScoreDeductibleType_DifficultToSleep,//太难入睡
    Milky_ScoreDeductibleType_AwakeTooFrequent,//清醒次数太频繁
    Milky_ScoreDeductibleType_sleepEfficiencyTooLow,//睡眠效率太低
    Milky_ScoreDeductibleType_optimumSleepPercentTooLow,//良性睡眠比例太低
    Milky_ScoreDeductibleType_bodyMovementTooMuch,//体动太多
    Milky_ScoreDeductibleType_SleepTooLate,//太晚睡觉
    
    Milky_ScoreDeductibleType_Invalid,
};

typedef NS_ENUM(NSInteger,M_HistoryDataTypes) {
    M_HistoryDataType_Invalid = -1,//无效数据
    M_HistoryDataType_Normal = 0,//有效的
    M_HistoryDataType_Exceptional,//异常的
};

typedef NS_ENUM(NSInteger,Milkly_MotionfreqLevels) {
    Milkly_MotionfreqLevel_TooFew = -2,//体动极少
    Milkly_MotionfreqLevel_Few = -1,//体动少
    Milkly_MotionfreqLevel_Normal = 0,//体动正常
    Milkly_MotionfreqLevel_Much,//体动多
    Milkly_MotionfreqLevel_TooMuch,//体动极多
};

@interface M_HistoryDataDetail : HistoryDataDetail
@property (nonatomic,strong) NSArray *flagstatusAry;
@property (nonatomic,strong) NSArray *feature_01Ary;
@property (nonatomic,strong) NSArray *feature_02Ary;
@end

@interface MT_HistoryDataDetail : M_HistoryDataDetail
@property (nonatomic,strong) NSArray *temperatureAry;//温度
@property (nonatomic,strong) NSArray *humidityAry;//湿度
@end

@interface M_HistoryDataAnalysis : HistoryDataAnalysis
@property (nonatomic,assign) M_HistoryDataTypes type;
@property (nonatomic,strong) NSArray<NSNumber *> *motion_intensityAry;/*体动 0-250*/
@property (nonatomic,assign) Milkly_MotionfreqLevels motionfreqLevel;//体动频率
@end
