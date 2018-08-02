//
//  LongSitInfo.h
//  TestTxt
//
//  Created by zhuoting on 15-5-26.
//  Copyright (c) 2015年 zhuoting. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef enum : NSUInteger {
    longSitRemindGapEnum_15 = 1,
    longSitRemindGapEnum_30,
    longSitRemindGapEnum_45,
    longSitRemindGapEnum_60
}longSitRemindGapEnum_Enum;



@interface LongSitInfo : NSObject{
    int s_hour1;
    int s_min1;
    int e_hour1;
    int e_min1;
    
    int s_hour2;
    int s_min2;
    int e_hour2;
    int e_min2;
    
    longSitRemindGapEnum_Enum remindGap;
    BOOL open;
    NSMutableArray* valueArray;//周一至周日的值
}



@property(nonatomic,assign) int s_hour1;
@property(nonatomic,assign) int s_min1;
@property(nonatomic,assign) int e_hour1;
@property(nonatomic,assign) int e_min1;

@property(nonatomic,assign) int s_hour2;
@property(nonatomic,assign) int s_min2;
@property(nonatomic,assign) int e_hour2;
@property(nonatomic,assign) int e_min2;

@property(nonatomic,assign)longSitRemindGapEnum_Enum remindGap;

@property(nonatomic,assign)BOOL open;

    
//周一到周日例子 = [NSMutableArray arrayWithArray:@[[NSNumber numberWithBool:NO],[NSNumber numberWithBool:NO],[NSNumber numberWithBool:NO],[NSNumber numberWithBool:NO],[NSNumber numberWithBool:NO],[NSNumber numberWithBool:NO],[NSNumber numberWithBool:NO]]];
@property(nonatomic, retain)NSMutableArray* valueArray;//周一至周日的值

-(char)createInfo;

@end
