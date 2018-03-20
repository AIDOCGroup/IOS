//
//  TargetController.h
//  nRF Loader
//
//  Created by Ole Morten on 10/8/13.
//  Copyright (c) 2013 Nordic Semiconductor. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <CoreBluetooth/CBService.h>


#import "MIOCommonType.h"
#import "MIODeviceSensor.h"
#import "MIOOTAControllerDelegate.h"


//
// class: DFUTargetAdapter
//
@interface MIOOTAController : NSObject 
{
    //NSNumber    *RSSI;
    
    //NSString    *osVersion;
}

//@property (nonatomic, retain) NSTimer * _pTimeoutTimer;
//@property (nonatomic) CBPeripheral *peripheral;


@property (nonatomic, weak) id<MIOOTAControllerDelegate> delegate;

/**
 * Gets the current DFU status.
 */
@property (nonatomic, readonly) MIO_OTAState_t DFUstate;


/**
 * Gets the current upload progress.
 */
@property (nonatomic, readonly) float progress;



/**
 * Specifies the BTLE Device UUID String
 */
@property (nonatomic, readonly) NSString*   deviceUUIDString;


/**
 * Specifies the BTLE Device name String
 */
@property (nonatomic, readonly) NSString     *DeviceName;


@property (nonatomic, readonly)    MIODeviceType_t     MioDeviceType;


//
// scanning DFU sensor.
//
-(BOOL)ScanOTASensor_MIO:(int) timeout;


//
// connect to DFU sensor for update firmware.
//
-(BOOL)ConnectOTASensor_MIO: (MIODeviceSensor*)sensor fileURLstring:(NSString*)fileURLstring;


/**
 * set the firmware data.
 */
- (void) SetFirmwareData_MIO:(NSData *) data;


/**
 * start to transfer firmware to MIO device.
 */
//- (void) StartTransfer_MIO;



/**
 * cancel upload firmware.
 */
//- (void) CancelTransfer_MIO;



- (NSString *) StringFromState_MIO:(MIO_OTAState_t) state;



@end
