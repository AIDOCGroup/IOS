
//
//  MIODeviceManager.h
//
//
//  Created by Toling on 13年11月09日.
//  Copyright (c) 2013年 MIO Physical. All rights reserved.
//

#import <Foundation/Foundation.h>


#import "MIOCommonType.h"
#import "MIOServiceAndCharactUUID.h"
#import "MIOSportsProtocol.h"


#import "MIODeviceManagerDelegate.h"
#import "MIODeviceSensor.h"
#import "MIODeviceSensorExtend.h"


@class MIODeviceConnection;
@class MIODFUController;
@class MIOOTAController;

@interface MIODeviceManager: NSObject {

}


#pragma mark -
#pragma mark  Property Declarations
/**
 * 
 */
@property (nonatomic,retain) id <MIODeviceManagerDelegate> delegate;


/**
 * Gets the current SDK API version string.
 */
@property (nonatomic, readonly) NSString* apiVersion;


/**
 * Gets a boolean value indicating whether the device has hardware support for BTLE.
 */
@property (nonatomic, readonly) BOOL isBTLESupport;

/**
 * Gets a boolean value indicating whether the BTLE hardware is enabled and ready
 * for a connection.
 *
 */
@property (nonatomic, readonly) BOOL isBTLEEnabled;

/**
 * Gets a boolean value indicating whether any connected BLE sensor is available.
 *
 * This property will return <c>TRUE</c> if the BTLE hardware is enabled and sensor is connected.
 * If no sensor is available and connected,this property returns <c>FALSE</c>.
 */
@property (nonatomic, readonly) BOOL isConnectedSensorReady;


/**
 * Gets or sets the sample rate in seconds.
 *
 * The value of this property will determine how often data updates are sent
 * to the delegate.  The MIODeviceManagerDelegate::DeviceHasData
 * method will be invoked at the sample rate.
 */
@property (nonatomic, assign) NSTimeInterval sampleRate;


#pragma mark -
#pragma mark  Method Declarations

/**
 * Returns the number of unallocated communication channels.
 *
 * @return The number of unallocated channels.
 */
- (unsigned char)AvailableChannelCount_MIO;



/**
 * Returns the current state of the MIODeviceManager.
 *
 * @return The current state.
 * <br /><br />
 * The return value is a bit-field representing the current state. 
 *
 */
- (MIOHardwareState_t) CurrentState_MIO;


/**
 * Initiates device discovery .
 *
 *
 * @param eSensorType The ::MIOSensorType_t to discover.  If this value is
 * ::MIO_SENSORTYPE_NONE, a wildcard discovery is performed.
 *
 *
 * @param timeout The timeout for the discovery process, in seconds.  If this
 * value is <c>0</c> the discovery will continue indefinitely.  The device discovery
 * continues until the <c>timeout</c> period has elapsed, or the
 * MIODeviceManager::CancelFindDevices_MIO: method is invoked.
 *
 * @return <c>TRUE</c> if the discovery was successfully initiated, otherwise <c>FALSE</c>.
 * If a discovery is currently in progress  or if any connections exist,
 *  or if the specified sensor type is not supported, the return will be <c>FALSE</c>.
 */
-(int) FindBLEDevices_MIO:(MIOSensorType_t)eSensorType timeout:(int) timeout;

/**
 * Cancels device discovery.
 *
 *
 * @return An <c>NSArray</c> containing zero or more MIODeviceSensor instances
 * representing all devices discovered up to the point the discovery was cancelled.
 */
//- (NSMutableArray*)CancelFindBLEDevices_MIO;
- (NSArray*)CancelFindBLEDevices_MIO;

/**
 * Returns an array of MIODeviceConnection instances for all connected sensors
 * of the specified type.
 *
 * @param sensorType The type of sensor for which to get connections.  If this
 * parameter is <c>MIO_SENSORTYPE_NONE</c>, all connections for any type are returned.
 *
 * @return An NSArray containing the matching sensorType.
 */
//- (NSMutableArray*)GetSensorConnections_MIO:(MIOSensorType_t)sensorType;
- (NSArray*)GetSensorConnections_MIO:(MIOSensorType_t)sensorType;


/**
 * Initializes a sensor connection request based on the specified parameters.
 *
 * @param params A MIODeviceInfo instance which specifies the device.
 *
 * @return If a device matching the connection parameters is already connected,
 * the existing MIODeviceConnection instance is returned, and no new connection
 * is initialized.  If an error occurs (such as no unallocated communication
 * channels available), the return is <c>nil</c>.  Otherwise, the value returned
 * is a MIODeviceConnection instance which may be used to manage the connection.
 */
- (MIODeviceConnection*)RequestDeviceConnection_MIO:(MIODeviceSensor*)sensor;



/**
 * reconnect to a sensor base on the sensor's UUID.
 *
 * @param params A array contain some Sensor's UUID string .
 *
 * @return the value returned is a MIODeviceConnection instance which may be used 
 * to manage the connection. if the connection is created then HardwareManager_MIO:hwManager:connectedSensor be called.
 *
 */
- (MIODeviceConnection*)ReconnectToSensor_MIO:(NSArray*)UUID sensorType:(MIOSensorType_t)sensorType;



/**
 * reconnect to a sensor base on the sensor's MAC address.
 *
 * @param params  MAC address string .
 *
 * @return the value returned is a MIODeviceConnection instance which may be used
 * to manage the connection. if the connection is created then HardwareManager_MIO:hwManager:connectedSensor be called.
 *
 */
- (MIODeviceConnection*)ReconnectToSensor_MIO:(NSString*)MACaddress ;


/**
 * Init a DFU controller with delegate class, there must isn't any other device connection before initing DFU controller.
 * and there is only one controller for DFU operation.
 *
 * @param params A delegate class of MIODFUControllerDelegate.
 *
 * @return the value returned is a MIODFUController instance which may be used
 * to manage the DFU operation.
 *
 */
//- (MIODFUController *) requestDFUController_MIO;
- (MIODFUController *) requestDFUController_MIO:(NSString*)deviceUUID;


//
// Deinit the controller when completed the OTA update.
//
- (void) ReleaseDFUController_MIO;


// OTA for Alpha2 device.
- (MIOOTAController *) requestOTAController_MIO:(NSString*)deviceUUID;


- (void) ReleaseOTAController_MIO;


/**
 * Returns the singleton MIODeviceManager instance.
 *
 * This method may be used to obtain a reference to that instance.  If the
 * instance does not yet exist when this method is invoked, it will be created.
 *
 * @return The MIODeviceManager singleton instance.
 */
+ (MIODeviceManager*)SharedManager_MIO;


@end










