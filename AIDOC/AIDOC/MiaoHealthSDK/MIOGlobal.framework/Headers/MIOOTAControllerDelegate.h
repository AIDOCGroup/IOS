

//
//  MIODFUControllerDelegate.h
//
//
//  Created by Toling on 13年11月09日.
//  Copyright (c) 2013年 MIO Physical. All rights reserved.
//


#import "MIOCommonType.h"


@class MIOOTAController;


/**
 * Provides the interface for callback methods used by the MIODeviceConnection.
 */
@protocol MIOOTAControllerDelegate <NSObject>


@required

/**
 * Alerts the delegate that a device has been discovered.
 *
 * @param hwManager The MIODeviceManager instance.
 *
 * @param DeviceParams An <c>NSMutableArray</c> instance containing zero or more ble device.
 *
 * @param bCompleted <c>TRUE</c> if the discovery is finished, otherwise <c>FALSE</c>.
 */
- (void)didFoundDFUDevices:(MIODeviceSensor*)DeviceParams searchCompleted:(BOOL)bCompleted;

/**
 * Invoked when the device is ready for upload firmware.
 *
 * @param connectionInfo The MIODeviceConnection instance.
 */
- (void)ReadyToTransfer_MIO;


/**
 * Alerts the delegate that update the progress.
 *
 * @param
 */
- (void) didFinishTransfer_MIO;


/**
 * Alerts the delegate that update the progress.
 *
 * @param
 */
//- (void) didCancelTransfer_MIO;


/**
 * Alerts the delegate that update the progress.
 *
 * @param
 */
- (void) didDisconnect_MIO: (BOOL) hasError;


/**
 * Invoked when MIODeviceConnectionOTA fails to connect to a device before
 * the specified timeout period ellapses.
 *
 * @param connectionInfo The MIODeviceConnectionOTA instance.
 */
- (void)ConnectionDidTimeout_MIO;


/**
 * Alerts the delegate that the device state is changed.
 *
 * @param
 */
- (void) didChangeState_MIO:(MIO_OTAState_t) state;


/**
 * Alerts the delegate that update the progress.
 *
 * @param
 */
- (void) didUpdateProgress_MIO:(float) progress;

@end




