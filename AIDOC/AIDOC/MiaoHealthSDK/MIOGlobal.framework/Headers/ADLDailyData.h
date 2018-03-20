//
//  ADLDailyData.h
//  MIOBleDemo
//
//  Created by Loong on 8/18/14.
//  Copyright (c) 2014 MIOGlobal. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ADLDailyData : NSObject
{
    //Time stamp.
    unsigned short	year;
    UInt8           month;
    UInt8           day;
    
    //rest HR.
    unsigned short	rmr;
    
    //TTL step.
    unsigned int	step;   //unit: 1step
    //TTL Dist
    unsigned int	dist;   //unit: meter
    //TTL kcal.
    unsigned short	calorie; //unit: kcal
    
    
    unsigned int	actTimeOfWalk;
    unsigned int	actTimeOfRun;
    
    //Goal value.
    unsigned int	dailyGoalValue;
    
    //Goal type.
    UInt8           dailyGoalType;
}

//@property (nonatomic, assign)UInt8	year;
@property (nonatomic, assign)unsigned short	year;
@property (nonatomic, assign)UInt8	month;
@property (nonatomic, assign)UInt8	day;

@property (nonatomic, assign)unsigned short	rmr;

@property (nonatomic, assign)unsigned int	step;
@property (nonatomic, assign)unsigned int	dist;
@property (nonatomic, assign)unsigned short	calorie;

@property (nonatomic, assign)unsigned int	actTimeOfWalk;
@property (nonatomic, assign)unsigned int	actTimeOfRun;

@property (nonatomic, assign)unsigned int	dailyGoalValue;
@property (nonatomic, assign)UInt8          dailyGoalType;


@end
