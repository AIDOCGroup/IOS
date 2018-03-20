

//
//
//  Created by Toling on 13年11月09日.
//  Copyright (c) 2013年 MIO Physical. All rights reserved.
//
#import "MIODeviceManager.h"
#import "CBCManagerCtrl.h"
//#import "CBCPeripheralCtrl.h"

@class MIODeviceConnection;


@interface MIODeviceManager () <CBCMCtrlDelegate>
{
    //NSString* apiVersion;
    //BOOL isBTLESupport;
    //BOOL isBTLEEnabled;
    
    //private var:
    //CBCManagerCtrl  *_CtrlManager;
    //NSMutableArray  *_CtrlPeripherals;
}


#pragma mark -
#pragma mark  Property Declarations

/**
 * Gets the current SDK API version string.
 */
@property (nonatomic, readwrite) NSString* apiVersion;


/**
 * Gets a boolean value indicating whether the device has hardware support for BTLE.
 */
@property (nonatomic, readwrite) BOOL isBTLESupport;

/**
 * Gets a boolean value indicating whether the BTLE hardware is enabled and ready
 * for a connection.
 *
 */
@property (nonatomic, readwrite) BOOL isBTLEEnabled;

@property (nonatomic, readwrite) BOOL isConnectedSensorReady;

@property (nonatomic, strong) CBCManagerCtrl  *CtrlManager;


#pragma mark -
#pragma mark  Method Declarations

/**
 * Disconnects the sensor.
 */
- (void)ExtDisconnectFromSensor:(MIODeviceConnection*)parm;


@end










