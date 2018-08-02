//
//  SleepInfo.h
//  TestTxt
//
//  Created by zhuoting on 15-4-11.
//  Copyright (c) 2015年 zhuoting. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SleepInfo : NSObject{
    NSDate *beginTime;
    NSDate *endTime;
    NSInteger dsCount;//深睡次数
    NSInteger qsCount;//浅睡次数
    
    NSInteger dsTimes;//深睡总时间
    NSInteger qsTimes;//浅睡总时间
    
    NSMutableArray *mlist;
    
    NSString *timeFormet;
    
    NSString *beginFormet;
    NSString *endFormet;
    
}

@property(nonatomic,strong) NSString *beginFormet;
@property(nonatomic,strong) NSString *endFormet;

@property(nonatomic,strong) NSString *timeFormet;
@property(nonatomic,strong) NSMutableArray *mlist;
@property(nonatomic, strong) NSDate *beginTime;
@property(nonatomic, strong) NSDate *endTime;
@property(nonatomic, assign) NSInteger dsCount;//深睡次数
@property(nonatomic, assign) NSInteger qsCount;//浅睡次数

@property(nonatomic, assign) NSInteger dsTimes;//深睡总时间
@property(nonatomic, assign) NSInteger qsTimes;//浅睡总时间


-(SleepInfo*)initWithData:(NSData*)data;



-(void)fameDate;

-(NSString *)sleepAllTime;
-(NSString *)sleeptime:(NSInteger)times;
-(NSString *)sleepFormat:(NSDate *)times;


-(NSString *)makeString;
@end
