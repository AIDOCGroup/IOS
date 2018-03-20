

//
//  MIODeviceManagerDelegate.h
//
//
//  Created by Toling on 13年11月09日.
//  Copyright (c) 2013年 MIO Physical. All rights reserved.
//

#import "MIOCommonType.h"


@class MIODeviceManager;
@class MIODeviceConnection;
@class MIODeviceSensor;

/**
 * The MIODeviceManagerDelegate protocol declares the interface that
 * MIODeviceManager delegates must implement.
 *
 */
@protocol MIODeviceManagerDelegate <NSObject>

@required

/**
 * Alerts the delegate that a sensor connection has been established.
 *
 * The <i>connectionInfo</i> parameter may be used to determine the type
 * and identification of the sensor which was connected.
 *
 *
 * @param hwManager The MIODeviceManager instance.
 *
 * @param connectionInfo A MIODeviceConnection instance that may be used to
 * determine the sensor type and manage the connection.
 */
- (void)HardwareManager_MIO:(MIODeviceManager*)hwManager connectedSensor:(MIODeviceConnection*)connectionInfo;

/**
 * Alerts the delegate that a device has been discovered.
 *
 * @param hwManager The MIODeviceManager instance.
 *
 * @param DeviceParams An <c>NSMutableArray</c> instance containing zero or more ble device.
 *
 * @param bCompleted <c>TRUE</c> if the discovery is finished, otherwise <c>FALSE</c>.
 */
- (void)HardwareManager_MIO:(MIODeviceManager*)hwManager didFoundDevices:(NSMutableArray*)DeviceParams searchCompleted:(BOOL)bCompleted;

/**
 * Alerts the delegate that a sensor connection has ended.
 *
 * The <i>connectionInfo</i> parameter may be used to determine the type
 * and identification of the sensor which was disconnected.
 *
 *
 * @param hwManager The MIODeviceManager instance.
 *
 */
- (void)HardwareManager_MIO:(MIODeviceManager*)hwManager disconnectedSensor:(MIODeviceConnection*)connectionInfo;

/**
 * Alerts the delegate that the state of the device manager has changed.
 *
 *
 * @param hwManager The MIODeviceManager instance.
 * @param currentState  The current state of the device manager.
 *
 */
- (void)HardwareManager_MIO:(MIODeviceManager*)hwManager stateChanged:(MIOHardwareState_t)currentState;




@end



