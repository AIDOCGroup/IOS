//
//  Alpha2RecordData.h
//  MIOBleDemo
//
//  Created by Loong on 10/6/14.
//  Copyright (c) 2014 MIOGlobal. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Alpha2RecordData : NSObject
{
    
    UInt16 marker;
    UInt8  recordType;
    UInt16 recordIndex;
    UInt16 packetIndex;
    
    UInt16 dataSize;
    NSMutableData *rawData;
    
    NSMutableArray *recordArray;
}

@property (nonatomic, assign) UInt16 marker;
@property (nonatomic, assign) UInt8  recordType;
@property (nonatomic, assign) UInt16 recordIndex;
@property (nonatomic, assign) UInt16 packetIndex;

@property (nonatomic, assign) UInt16 dataSize;

@property (nonatomic, strong) NSMutableData *rawData;

@property (nonatomic, strong) NSMutableArray *recordArray;

@end

//#define ALPHA2_RECORD_TYPE_SUMMARY      1
#define ALPHA2_RECORD_TYPE_COUNTUP      2
#define ALPHA2_RECORD_TYPE_COUNTDOWN    3
#define ALPHA2_RECORD_TYPE_RECOVERY     4
#define ALPHA2_RECORD_TYPE_REPEAT       5


//
//Struct for workout summary or Lap record.
//
@interface Alpha2SubRecordData : NSObject
{
    BOOL   isSummary;   //Yes: for Summary,  No: for Lap.
    UInt8  type;        //Summary or Lap type.
    
    //Time stamp, used for Summary only, not valid for Lap.
    UInt16  year;
    UInt8  month;
    UInt8  day;
    UInt8  hour;
    UInt8  minute;
    UInt8  second;
    
    //Total laps.
    UInt8  lapTotal;    //Lap total number, used for Summary record.
    UInt8  lapIndex;    //Lap index, 1 - n, used for Lap/Cycle Lap record.
    
    //TTL WO time.
    UInt8  workoutTimeHour;
    UInt8  workoutTimeminute;
    UInt8  workoutTimeSecond;
    
    //TTL Dist.
    UInt16 distanceTotal;   //unit: meter.
    //TTL step.
    UInt32 stepTotal;
    //TTL kcal.
    UInt16 caloriesTotal;
    
    //Avg HR.
    UInt8  averageHeartRate;
    //Max HR.
    UInt8  maxHeartRate;
    UInt8  minHeartRate;
    
    //Avg speed.
    UInt16 averageSpeed;    //unit: 0.01KPH  **only valid for Summary.
    //Max speed.
    UInt16 maxSpeed;        //unit: 0.01KPH  **only valid for Summary.
    
    //Avg Pace.
    UInt16 averagePace;     //unit: second   **only valid for Summary.
    //Best Pace.
    UInt16 maxPace;         //unit: second   **only valid for Summary.
    
    //Time in Zone.
    UInt32  inUpLowZone;    //only valid for Summary.
    
    UInt32  zoneHR1;        //only valid for Summary.
    UInt32  zoneHR2;        //only valid for Summary.
    UInt32  zoneHR3;        //only valid for Summary.
    UInt32  zoneHR4;        //only valid for Summary.
    UInt32  zoneHR5;        //only valid for Summary.
    
    //UInt16  areaStartIndex;
    //UInt16  areaEndIndex;
    
    //reseverd 3 bytes.
}

@property (nonatomic, assign) UInt16  year;
@property (nonatomic, assign) UInt8  month;
@property (nonatomic, assign) UInt8  day;
@property (nonatomic, assign) UInt8  hour;
@property (nonatomic, assign) UInt8  minute;
@property (nonatomic, assign) UInt8  second;

@property (nonatomic, assign) BOOL   isSummary;
@property (nonatomic, assign) UInt8  type;
@property (nonatomic, assign) UInt8  lapTotal;
@property (nonatomic, assign) UInt8  lapIndex;

@property (nonatomic, assign) UInt8  workoutTimeHour;
@property (nonatomic, assign) UInt8  workoutTimeminute;
@property (nonatomic, assign) UInt8  workoutTimeSecond;

@property (nonatomic, assign) UInt16 distanceTotal;
@property (nonatomic, assign) UInt32 stepTotal;
@property (nonatomic, assign) UInt16 caloriesTotal;

@property (nonatomic, assign) UInt8  averageHeartRate;
@property (nonatomic, assign) UInt8  maxHeartRate;
@property (nonatomic, assign) UInt8  minHeartRate;

@property (nonatomic, assign) UInt16 averageSpeed;
@property (nonatomic, assign) UInt16 maxSpeed;

@property (nonatomic, assign) UInt16 averagePace;
@property (nonatomic, assign) UInt16 maxPace;

//@property (nonatomic, assign) UInt8  upZoneHR;
//@property (nonatomic, assign) UInt8  lowZoneHR;
@property (nonatomic, assign) UInt32  inUpLowZone;

@property (nonatomic, assign) UInt32  zoneHR1;
@property (nonatomic, assign) UInt32  zoneHR2;
@property (nonatomic, assign) UInt32  zoneHR3;
@property (nonatomic, assign) UInt32  zoneHR4;
@property (nonatomic, assign) UInt32  zoneHR5;

//@property (nonatomic, assign) UInt16  areaStartIndex;
//@property (nonatomic, assign) UInt16  areaEndIndex;

@end
