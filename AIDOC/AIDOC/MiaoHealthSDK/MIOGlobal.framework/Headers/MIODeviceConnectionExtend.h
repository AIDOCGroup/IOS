

//
//  MIO_GLOBAL_SDK.h
//  MIO_GLOBAL_SDK
//
//  Created by Toling on 13年11月09日.
//  Copyright (c) 2013年 MIO Physical. All rights reserved.
//

#import "MIODeviceConnection.h"
#import "MIODeviceManagerExtend.h"

#import "MIODeviceSensor.h"
#import "MIODeviceSensorExtend.h"

#import "CBCPeripheralCtrl.h"

#import <CoreBluetooth/CoreBluetooth.h>


@interface MIODeviceConnection () <CBCPCtrlDelegate>
{
    
    MIODeviceInfo   *_deviceInfo;
    BOOL            _isDevInfoReady;
    

    unsigned short  _curHRMdata;
    BOOL            _isFreshData;
    
    //id<MIODeviceConnectionDelegate> delegate;
}


@property (atomic, readwrite) MIODeviceConnectionStatus_t connectionStatus;

@property (nonatomic, readwrite) NSString* deviceUUIDString;

@property (nonatomic, readwrite) BOOL didTimeout;

@property (nonatomic, readwrite) MIODeviceConnectionError_t error;

@property (nonatomic, readwrite) BOOL isConnected;

@property (nonatomic, readwrite) BOOL isValid;

@property (nonatomic, readwrite) BOOL hasError;

@property (nonatomic, readwrite) MIOSensorType_t sensorType;

@property (nonatomic, readwrite) BOOL IsMIODevice;

@property (nonatomic, readwrite) BOOL IsUnlocked;

@property (nonatomic, readwrite) BOOL IsSupportHRZone;

@property (nonatomic, readwrite) BOOL IsSupportANTPlus;

@property (nonatomic, readwrite)    MIODeviceType_t     MioDeviceType;

@property (atomic, readwrite) BOOL hasHRdata;

@property (atomic, readwrite) BOOL IsGPSmode;

@property (atomic, readwrite) BOOL IsWorkoutMode;

//extend:
//@property (nonatomic, retain) MIODeviceSensor  *deviceSensor;
@property (nonatomic, readwrite) MIODeviceSensor  *deviceSensor;    //changed by zb,2013-12-28.

@property (nonatomic, retain) CBPeripheral     *cbPeripheral;

@property (nonatomic, retain) CBCPeripheralCtrl  *ctrlPeripheral;


@property (nonatomic, retain) MIODeviceManager  *ctrlManager;


@property (nonatomic)         BOOL    bDisconnectByApp;     //add by 2014-09-09.

@property (nonatomic)         BOOL    bDiscoveredServices;     //add by 2014-09-09.

/**
 *  init the connection instance.
 *
 * @return not used.
 *
 */
- (void)InitConnection;


/**
 *  deinit the connection instance.
 *
 * @return not used.
 *
 */
- (void)DeinitConnection;

/**
 *  SET the device information.
 *
 * @return <c>TRUE</c> if have got the device information, otherwise <c>FALSE</c>.
 *
 */
//-(BOOL) SetDeviceInfo_MIO:(MIODeviceInfo*)pInfo;

/**
 *  GET the device information.
 */
//-(BOOL) GetDeviceInfo_MIO:(MIODeviceInfo *)pInfo;


/**
 *  get the latest HRM data.
 */
- (void) updateWithHRMData:(NSData *)data;

/**
 *  start the read RSSI timer.
 */
- (void)StartRSSItimer;

/**
 *  start the read RSSI timer.
 */
- (void)StopRSSItimer;

-(MIOErrorCode_t) innerGetRTCTime_MIO;

- (void)SetSystemConnected:(BOOL)bConnected;

@end






