

//
//  MIO_GLOBAL_SDK.h
//  MIO_GLOBAL_SDK
//
//  Created by Toling on 13年11月09日.
//  Copyright (c) 2013年 MIO Physical. All rights reserved.
//

//#import <Foundation/Foundation.h>
//#import <CoreBluetooth/CoreBluetooth.h>
//#import <CoreBluetooth/CBService.h>

#import "MIODeviceInfo.h"



@interface MIODeviceInfo ()


@property (nonatomic, readwrite) NSString           *DeviceUUID;
@property (nonatomic, readwrite) NSString           *DeviceName;

@property (nonatomic, readwrite) NSString     *MACaddress;
@property (nonatomic, readwrite) NSString     *CompanyID;

@property (nonatomic, readwrite) NSString     *ManuName;
@property (nonatomic, readwrite) NSString     *ModelNumber;
@property (nonatomic, readwrite) NSString     *SerialNumber;
@property (nonatomic, readwrite) NSString     *HardwareRev;
@property (nonatomic, readwrite) NSString     *UIFirmwareRev;
@property (nonatomic, readwrite) NSString     *OHRFirmwareRev;
@property (nonatomic, readwrite) NSString     *SystemID;



@property (nonatomic, readwrite) int         BatteryLevel;


@end






