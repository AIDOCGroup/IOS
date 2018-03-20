

//
//  MIO_GLOBAL_SDK.h
//  MIO_GLOBAL_SDK
//
//  Created by Toling on 13年11月09日.
//  Copyright (c) 2013年 MIO Physical. All rights reserved.
//
#import "MIODFUController.h"
#import "MIODFUControllerExtend.h"

//#import "CBCPeripheralCtrl.h"
#import "CBCManagerCtrl.h"

#import "MIODeviceSensor.h"
#import "MIODeviceSensorExtend.h"

//#import "DFUTargetAdapter.h"
#import <IDTotalibrary/IDTotalibrary.h>

//#define DFUCONTROLLER_MAX_PACKET_SIZE               20
//#define DFUCONTROLLER_DESIRED_NOTIFICATION_STEPS    20

//
//Extend:
//
@interface MIOOTAController ( ) <CBPeripheralDelegate, IDTotaLibraryDelegate>
{
    
}


//@property (nonatomic, readwrite) MIODeviceConnectionStatus_t connectionStatus;

@property (nonatomic, readwrite) NSString* deviceUUIDString;

@property (nonatomic, readwrite) NSString* DeviceName;

@property (nonatomic, readwrite)    MIODeviceType_t     MioDeviceType;

@property (nonatomic, retain) CBCManagerCtrl    *CtrlManager;


//--------------------------------------------------------------------------------------------------//
//@property (nonatomic) MIO_DFUControllerState_t state;
@property (nonatomic, readwrite) MIO_OTAState_t DFUstate;

//@property DFUTargetAdapter *target;

@property NSData *firmwareData;

//@property int firmwareDataBytesSent;
@property unsigned long firmwareDataBytesSent;

//@property int notificationPacketInterval;
@property unsigned long notificationPacketInterval;

//@property (nonatomic) float progress;
@property (nonatomic, readwrite) float progress;

//--------------------------------------------------------------------------------------------------//


+ (CBUUID *) serviceUUID;

/**
 *  init the connection instance.
 *
 * @return not used.
 *
 */
- (void)initPost: (NSString*)osversion;


/**
 *  deinit the connection instance.
 *
 * @return not used.
 *
 */
- (void)Deinit;

//--------------------------------------------------------------------------------------------------//
//- (void) setPeripheral:(CBPeripheral *)peripheral ;
//- (void) setFirmwareURL:(NSURL *) URL;

- (void) didConnect;

- (void) didDisconnect:(NSError *) error;

//--------------------------------------------------------------------------------------------------//

- (void) didScanForBTLEPeripherals:(CBPeripheral *)peripheral uuid:(NSString*)uuid;

- (void) didConnectedPeripheral:(CBPeripheral *)peripheral  result:(BOOL)isSuccess;

- (void)didDisconnectPeripheral:(CBPeripheral *)peripheral isUnexpect:(BOOL)isUnexpect;

+ (CBUUID *) serviceUUID_MIO;

@end




