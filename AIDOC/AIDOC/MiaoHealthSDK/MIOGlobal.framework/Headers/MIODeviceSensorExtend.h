

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

#import "MIODeviceSensor.h"



@interface MIODeviceSensor ()


@property (nonatomic, readwrite) NSString           *DeviceUUID;
@property (nonatomic, readwrite) NSString           *DeviceName;
@property (nonatomic, readwrite) MIOSensorType_t    sensorType;
@property (nonatomic, readwrite) BOOL               IsMIODevice;

@property (nonatomic, readwrite) NSString           *MACaddress;
@property (nonatomic, readwrite) NSString           *CompanyID;

// extend:
@property (nonatomic, readwrite) CBPeripheral  *curPeripheral;


@end






