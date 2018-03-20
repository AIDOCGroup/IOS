

//
//  MIOBikeANTSensor.h
//
//
//  Created by Toling on 13年11月09日.
//  Copyright (c) 2013年 MIO Physical. All rights reserved.
//



#import "MIOCommonType.h"


@interface MIOBikeANTSensor : NSObject
{

}

@property (nonatomic, readonly) MIOBikeSensorChannel_t SensorType;

@property (nonatomic, readonly) unsigned short  manufacturerID;
@property (nonatomic, readonly) unsigned short  deviceNumber;

@end









