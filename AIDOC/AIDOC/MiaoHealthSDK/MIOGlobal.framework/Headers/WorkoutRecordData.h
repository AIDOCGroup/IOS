//
//  WorkoutRecordData.h
//
//  Created by Loong on 8/18/14.
//  Copyright (c) 2014 MIOGlobal. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WorkoutRecordData : NSObject
{
    BOOL       isValid;
    
    NSData*     HRdata;     //HR
    NSData*     DistData;   //Distance
    NSData*     CalData;    //Calorie
    NSData*     StepData;   //Step
    

    NSData*     speedData;  //Speed.
    NSData*     paceData;   //Pace
}

@property (nonatomic, assign)BOOL       isValid;

@property (nonatomic, retain)NSData*     HRdata;     //every 1s
@property (nonatomic, retain)NSData*     DistData;   //every 12s
@property (nonatomic, retain)NSData*     CalData;    //every 12s
@property (nonatomic, retain)NSData*     StepData;   //every 1min.

@property (nonatomic, retain)NSData*     speedData;   //unit: KPH
@property (nonatomic, retain)NSData*     paceData;    //unit: second per km

@end
