

//
//  MIODeviceSensor.h
//
//
//  Created by Toling on 13年11月09日.
//  Copyright (c) 2013年 MIO Physical. All rights reserved.
//


#import "MIOCommonType.h"


@interface MIODeviceSensor : NSObject
{
    
    
}

/**
 * Specifies the BTLE Device UUID String
 */
@property (nonatomic, readonly) NSString     *DeviceUUID;


/**
 * Specifies the device's identify ID String
 */
@property (nonatomic, readonly) NSString     *MACaddress;


/**
 * Specifies the device's company ID String
 */
@property (nonatomic, readonly) NSString     *CompanyID;

/**
 * Specifies the BTLE Device name String
 */
@property (nonatomic, readonly) NSString     *DeviceName;


/**
 * Specifies the sensor alias name String, allow user to edit.
 */
@property (nonatomic, readwrite) NSString     *AliasName;  


@property (nonatomic, assign) int      RSSI;

/**
 * Gets the BLE sensor type .
 */
@property (nonatomic, readonly) MIOSensorType_t sensorType;

/**
 * <c>TRUE</c> if this device is a MIO sensor device.
 */
@property (nonatomic, readonly) BOOL IsMIODevice;



@end








