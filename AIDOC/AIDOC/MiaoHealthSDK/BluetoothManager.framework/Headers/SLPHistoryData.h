//
//  SLPHistoryData.h
//  SDK
//
//  Created by Martin on 2017/7/31.
//  Copyright © 2017年 Martin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger,HistoryDataStopMode) {
    HistoryDataStopMode_Normal,//正常结束
    HistoryDataStopMode_Auto,//自动结束
    HistoryDataStopMode_Force,//强制结束(如:关机)
    HistoryDataStopMode_Wrong,//错误结束(如:供电不足、系统异常)
};
@class HistoryDataSummary;
@class HistoryDataDetail;
@class HistoryDataAnalysis;
@interface SLPHistoryData : NSObject
@property (nonatomic,strong) HistoryDataSummary *summary;
@property (nonatomic,strong) HistoryDataDetail *detail;
@property (nonatomic,strong) HistoryDataAnalysis *analysis;
@end

@interface HistoryDataSummary : NSObject
@property (nonatomic,assign) NSInteger deviceType;//设备类型
@property (nonatomic,assign) NSInteger startTime;//开始睡觉的时间戳
@property (nonatomic,assign) NSInteger recordCount;//睡觉总时间 单位:分钟
@property (nonatomic,assign) NSInteger reportFlag;//长、短报告标识，1长报告  2短报告
@property (nonatomic,assign) HistoryDataStopMode stopMode;//报告结束方式
@end

@interface HistoryDataDetail : NSObject

@end

@class HistoryDataScoreDeduction;
@interface HistoryDataAnalysis : NSObject
@property (nonatomic,copy) NSString *algorithmVer;//算法版本
@property (nonatomic,strong) NSArray<HistoryDataScoreDeduction *> *scoreDeductionAry;//扣分项
@property (nonatomic,assign) NSInteger fallsleepTimeStamp;//入睡的时间戳
@property (nonatomic,assign) NSInteger wakeupTimeStamp;//最后清醒的时间戳
@property (nonatomic,strong) NSArray *sleepCurveArray;//睡眠周期曲线，用来绘制曲线
@property (nonatomic,strong) NSArray *sleepCurveStatusArray;//睡眠周期曲线状态中的各种状态
@property (nonatomic,assign) NSInteger fallAlseepAllTime;//入睡时长 单位:分钟
@property (nonatomic,assign) NSInteger wakeAndLeaveBedBeforeAllTime ;//醒来和起床之间的那段时间 单位:分钟
@property (nonatomic,readonly) NSInteger duration;//实际睡觉总时长，除掉入睡时间和清醒时间。
@property (nonatomic,assign) NSInteger deepSleepPerc;  //深睡百分比
@property (nonatomic,assign) NSInteger inSleepPerc ; //中睡百分比
@property (nonatomic,assign) NSInteger lightSleepPerc;  //浅睡百分比
@property (nonatomic,assign) NSInteger wakeSleepPerc;  //清醒百分比
@property (nonatomic,assign) NSInteger wakeAllTime;//清醒时长
@property (nonatomic,assign) NSInteger lightSleepAllTime;//浅睡时长
@property (nonatomic,assign) NSInteger inSleepAllTime;//中睡时长
@property (nonatomic,assign) NSInteger deepSleepAllTime;//深睡时长
@property (nonatomic,assign) NSInteger sleepEfficient;//有效睡眠比例 (0~100)
@property (nonatomic,assign) NSInteger sleepScore;//得分 (0 ~ 100)
@property (nonatomic,assign) NSInteger wake_Times;//睡中清醒次数

@end

@interface HistoryDataScoreDeduction : NSObject
@property (nonatomic,assign) NSInteger type;//扣分类型
@property (nonatomic,assign) NSInteger score;//扣除的分数
@end
