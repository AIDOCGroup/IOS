

//
//  MIO_GLOBAL_SDK.h
//  MIO_GLOBAL_SDK
//
//  Created by Toling on 13年11月09日.
//  Copyright (c) 2013年 MIO Physical. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <CoreBluetooth/CBService.h>

#import "MIOBikeANTSensor.h"


@interface MIOBikeANTSensor ()
{
    
}

@property (nonatomic, readwrite) MIOBikeSensorChannel_t SensorType;

@property (nonatomic, readwrite) unsigned short  manufacturerID;
@property (nonatomic, readwrite) unsigned short  deviceNumber;

@end



