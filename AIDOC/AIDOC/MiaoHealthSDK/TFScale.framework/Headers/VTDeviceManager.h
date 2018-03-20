/** @file VTDeviceManager.h
 * @brief vtble devie management. VTDeviceManager is a singleton and the entry of vtble SDK. Client could 1) Scan the unknown devices. 2) Retrieve the connected devices. 3) Get/Set the active device list. 4) Get/set the history list. Active list includes all the devices that have connected after the app is launched. History list includes all the devices that have been connected after the app is installed.
 * @author Kim.Yuan
 * [@author <Kim.yuan email:Kim.yuan@vtrump.com>]
 * @date 2012.09.14
 * @version 0.91
 * @copyright Vtrump
 */

#import "VTCoreBluetoothDelegate.h"
#import "VTDeviceModel.h"
#import "VTAdvertise.h"
#import <CoreLocation/CoreLocation.h>

@protocol VTDeviceManagerDelegate;

/** @brief enum type of VTDeviceManagerStatus */
typedef enum {
    VTDMNone,
    VTDMScanning,
} VTDeviceManagerStatus;

/**
 *	@brief	device manager for all VTDeviceModel. It's a singleton. Client could access all the active and history devices.
 */
@interface VTDeviceManager:NSObject<VTPeripheralDelegate, CLLocationManagerDelegate>

/**
 *	@brief	protocol delegate of VTDeviceManagerDelegate
 */
@property (nonatomic, retain) id<VTDeviceManagerDelegate> delegate;

/**
 *	@brief	devices list near the handsets.
 */
@property (nonatomic, retain) NSMutableArray * currentList;
/**
 *	@brief	all devices have been connected before.
 */
@property (nonatomic, retain) NSMutableArray * historyList;

/**
 *	@brief	VTDeviceManager status
 */
@property (nonatomic) VTDeviceManagerStatus dmStatus;

//@property (nonatomic, retain) VTSettingModel *settingModel;



/**
 *	@brief	singleton entry of VTDeviceManager
 *
 *	@return	the singleton instance of VTDeviceManager
 */
+ (VTDeviceManager *)sharedInstance;

/**
 *	@brief	get the device list that's discovered since the app started.
 *
 *	@return	device list
 */
- (NSMutableArray *)getCurrentList;

/**
 *	@brief	get the dicovered device with the UUID
 *
 *	@param 	UUID 	UUID of device
 *
 *	@return	the device with the specific UUID, nil if no device is found.
 */
- (VTDeviceModel *) getCurrentDevice:(NSString* )UUID;

/**
 *	@brief	update the device to the discovered device list.
 *
 *	@param 	device 	device that will be updated. If there isn't such device in the discovered device list, nothing will happen.
 */
- (void) updateCurrentList:(VTDeviceModel *)device;


/**
 *	@brief	remove the device stored in the current device list.
 *
 *	@param 	device 	device to be removed.
 */
- (void) removeCurrentList:(VTDeviceModel *)device;


/**
 *	@brief	get the recorded device list int the database.
 *
 *	@return	return all the recored devices in the database.
 */
- (NSMutableArray *)getHistoryList;

/**
 *	@brief	get the recorded device with the UUID
 *
 *	@param 	UUID 	UUID of device
 *
 *	@return	the recorded device with the UUID. nil if no device is found in the database.
 */
- (VTDeviceModel *) getHistoryDevice:(NSString* )UUID;

/**
 *	@brief	update the device to the recorded devices database.
 *
 *	@param 	device 	device to be updated.
 */
- (void) updateHistoryList:(VTDeviceModel *)device;


/**
 *	@brief	remove the device stored in devices database.
 *
 *	@param 	device 	device to be removed
 */
- (void) removeHistoryList:(VTDeviceModel*)device;



/**
 *	@brief	get the recorded advertise list
 *
 *	@return	all advertise list
 */
- (NSMutableArray *) getAdvertiseList;


/**
 *	@brief	get the recoreded advertise list by type
 *
 *	@param 	type 	the type of advertisement
 *
 *	@return	advertisement list according to the type
 */
- (NSMutableArray *) getAdvertiseListByType:(UInt8)type;



/**
 *	@brief	insert advertise to the record list
 *
 *	@param 	advertise 	advertise to be inserted
 */
- (void) insertAdvertiseList:(VTAdvertise *)advertise;



/**
 *	@brief	remove advertise from the record list
 *
 *	@param 	advertise 	advertise to be removed
 */
- (void) removeAdvertiseList:(VTAdvertise *)advertise;



/**
 *	@brief	scan the devices with the service UUIDs.
 */
- (void)scan: (NSArray*) serviceUUIDs;

/**
 *	@brief	scan the devices allow duplicate with the service UUIDs .
 */
- (void)scanWithDuplicate: (NSArray*) serviceUUIDs;

/**
 *	@brief	stop scanning.
 */
- (void)stopScan;

/**
 *	@brief	connect the history devices.
 */
- (void)connectHistoryDevices;


/**
 *	@brief	connect the active devices.
 */
- (void)connectActiveDevices;


/**
 *	@brief	retrieve connected devices.
 */
- (void)retrievedConnectedDevices;


/**
 *	@brief	notify device manager that app enter background. Should be called in applicationDidEnterBackground.
 */
- (void)enterBackground;


/**
 *	@brief	notify device manager that app become active. Should be called in applicationDidBecomeActive.
 */
- (void)becomeActive;


/**
 *	@brief	set if to connect to the unknonw device, connect when not set.
 *
 *	@param 	toConnect 	YES to connect, NO to ignore
 */
- (void)setConnectToUnknownDevice:(Boolean)connect;


/**
 *	@brief	set if require pairing process. If set YES, didPaired should be called to finish the whole process. The default value is NO.
 *
 *	@param 	toConnect 	YES to pair, NO to ignore
 */
- (void)setPairRequired:(Boolean)pair;


@end

/**
 * @brief	the class implemented VTDeviceManagerDelegate could monitor all the notification of VTBLE.
 */
@protocol VTDeviceManagerDelegate <NSObject>

@required

/**
 *	@brief	this method notify the implementer that a Bluetooth4.0 device is discovered. the implementer could get the device information for paramter device.
 *
 *	@param 	dm 	device manager
 *	@param 	device 	discovered device
 *  @return indate if the device should be connected automatically. vtble will connect the discovered device automatically if return YES. If return NO, client should invoke connection to device.
 */
- (Boolean) didDiscovered:(VTDeviceManager*)dm device:(VTDeviceModel *)device;

/**
 *	@brief	this method notify the implementer that a Bluetooth4.0 device will autoReconnect if they connected before. the implementer could get the device information for paramter device.
 *
 *	@param 	dm 	device manager
 *	@param 	device 	discovered device
 *  @return 
 */
- (Boolean) didAutoReConnect:(VTDeviceManager*)dm device:(VTDeviceModel *)device;

/**
 *	@brief	this method notify the implementer that a Bluetooth4.0 device will scan Allow Duplicates Key.
 *
 *	@param 	dm 	device manager
 *	@param 	device 	discovered device
 *  @return
 */
- (Boolean) didScanOptionAllowDuplicatesKey:(VTDeviceManager*)dm;


/**
 *	@brief	this method notify the implementer that a Bluetooth4.0 device is detected. the implementer could get the device information for paramter device.
 *
 *	@param 	dm 	device manager
 *	@param 	device 	discovered device
 */
- (void) didConnected:(VTDeviceManager*)dm device:(VTDeviceModel *)device;

/**
 * @brief
 */
- (void) didStatusUpdate:(CBCentralManagerState) status;

@optional

/**
 *	@brief	this method notify the implementer that a Bluetooth4.0 device is connected with VTBLE. the implementer could get the device information for paramter device.
 *
 *	@param 	dm 	device manager
 *	@param 	device 	disconnected device
 */
- (void) didDisconnected:(VTDeviceManager*)dm device:(VTDeviceModel *)device;


/**
 *	@brief	this method notify the implementer that a Bluetooth4.0 device is connected and service ready by VTBLE. the implementer could get the device information for paramter device.
 *
 *	@param 	dm 	device manager
 *	@param 	device 	device of service ready
 */
- (void) didServiceReady:(VTDeviceManager*)dm device:(VTDeviceModel *)device;


/**
 *	@brief	this method notify the implementer that the vtag device is paired.
 *
 *	@param 	dm 	device manager
 *	@param 	device 	device of service ready
 */
- (void) didPaired:(VTDeviceManager*)dm device:(VTDeviceModel *)device;


/**
 *	@brief	this method notify the implementer that the vtag device is entered advertising.
 *
 *	@param 	dm 	device manager
 *	@param 	device 	device of advertised
 */
- (void) didAdvertised:(VTDeviceManager*)dm device:(VTDeviceModel *)device;


/**
 *	@brief	this method notify the implementer that some advitisement data are pushed by the device.
 *
 *	@param 	dm 	device manager
 *	@param 	advertise 	pushed advertise
 */
- (void) didDataPushed:(VTDeviceManager *)dm device:(VTDeviceModel *)device advertise:(VTAdvertise *)advertise;

@end
