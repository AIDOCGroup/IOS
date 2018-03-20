
//
//  MIODeviceInfo.h
//
//  Created by Toling on 13年11月09日.
//  Copyright (c) 2013年 MIO Physical. All rights reserved.
//

#import "MIOCommonType.h"


@interface MIODeviceInfo : NSObject
{
    
    
}

/**
 * Specifies the BTLE Device UUID String
 */
@property (nonatomic, readonly) NSString     *DeviceUUID;

/**
 * Specifies the BTLE Device name String
 */
@property (nonatomic, readonly) NSString     *DeviceName;

/**
 * Specifies the device's identify ID String
 */
@property (nonatomic, readonly) NSString     *MACaddress;

/**
 * Specifies the device's company ID String
 */
@property (nonatomic, readonly) NSString     *CompanyID;


/**
 * Specifies the sensor alias name String, allow user to edit.
 */
@property (nonatomic, readwrite) NSString     *AliasName;


@property (nonatomic, readonly) NSString     *ManuName;
@property (nonatomic, readonly) NSString     *ModelNumber;
@property (nonatomic, readonly) NSString     *SerialNumber;
@property (nonatomic, readonly) NSString     *HardwareRev;


@property (nonatomic, readonly) NSString     *UIFirmwareRev;

@property (nonatomic, readonly) NSString     *OHRFirmwareRev;

@property (nonatomic, readonly) NSString     *SystemID;

@property (nonatomic, readonly) int         BatteryLevel;



@end








