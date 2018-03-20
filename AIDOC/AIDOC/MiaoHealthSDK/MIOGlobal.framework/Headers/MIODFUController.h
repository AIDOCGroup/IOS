

//
//  MIODFUController.h
//
//
//  Created by Toling on 13年11月09日.
//  Copyright (c) 2013年 MIO Physical. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <CoreBluetooth/CBService.h>


#import "MIOCommonType.h"
#import "MIODeviceSensor.h"
#import "MIODFUControllerDelegate.h"




@interface MIODFUController : NSObject
{
    
    
}




/**
 * Gets the current DFU status.
 */
@property (nonatomic, readonly) MIO_DFUControllerState_t DFUstate;


/**
 * Gets the current upload progress.
 */
@property (nonatomic, readonly) float progress;

/**
 * Specifies the MIODeviceConnectionDelegate instance which will handle callback
 * methods for this MIODeviceConnection.
 */
@property (nonatomic, weak) id<MIODFUControllerDelegate> delegate;



/**
 * Specifies the BTLE Device UUID String
 */
@property (nonatomic, readonly) NSString*   deviceUUIDString;


/**
 * Specifies the BTLE Device name String
 */
@property (nonatomic, readonly) NSString     *DeviceName;


// can identify the device type when enter OTA mode.
@property (nonatomic, readonly)    MIODeviceType_t     MioDeviceType;

//
// scanning DFU sensor.
//
-(BOOL)ScanDFUSensor_MIO:(int) timeout;


//
// connect to DFU sensor for update firmware.
//
-(BOOL)ConnectDFUSensor_MIO: (MIODeviceSensor*)sensor;


/**
 * set the firmware data.
 */
- (void) SetFirmwareData_MIO:(NSData *) data;


/**
 * start to transfer firmware to MIO device.
 */
- (void) StartTransfer_MIO;



/**
 * cancel upload firmware.
 */
- (void) CancelTransfer_MIO;



- (NSString *) StringFromState_MIO:(MIO_DFUControllerState_t) state;





@end






