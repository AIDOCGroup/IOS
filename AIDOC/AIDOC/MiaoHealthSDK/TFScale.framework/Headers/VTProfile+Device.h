/** @file VTProfile+Device.h
 * @brief category of BLE device service.  * @author Kim.Yuan
 * [@author <Kim.yuan email:Kim.yuan@vtrump.com>]
 * @date 2013.04.15
 * @version 0.91
 * @copyright Vtrump
 */

#import "VTProfile.h"


/**
 *	@brief	delegate of VTProfile and its extended categories.
 */
@protocol VTProfileDeviceDelegate <VTProfileDelegate>

@optional
/* device info notification */
/**
 *	@brief	notify the manufacture name updated after readManufactureName is called.
 *
 *	@param 	device 	device is notified.
 *	@param 	name 	manufacture name value of notification.
 */
- (void) didManufactureNameUpdated:(VTDeviceModel *)device name:(NSString *)name;

/**
 *	@brief	notify the model number updated after readModelNumber is called.
 *
 *	@param 	device 	device is notified
 *	@param 	modelNumer model number value of notification.
 */
- (void) didModelNumberUpdated:(VTDeviceModel *)device modelNumber:(NSData *)modelNumber;

/**
 *	@brief	notify the serial number updated after readSerialNumber is called.
 *
 *	@param 	device 	device is notified
 *	@param 	serialNumber 	serial number value of notification.
 */
- (void) didSerialNumberUpdated:(VTDeviceModel *)device serialNumber:(id)serialNumber;

/**
 *	@brief	notify the hardware version updated after readHardwareVersion is called.
 *
 *	@param 	device 	device is notified
 *	@param 	version 	hardware version value of notification
 */
- (void) didHardwareVersionUpdated:(VTDeviceModel *)device version:(NSString *)version;

/**
 *	@brief	notify the firmware version updated after readFirmwareVersion is called.
 *
 *	@param 	device 	device is notified
 *	@param 	version firmware version value of notification
 */
- (void) didFirmwareVersionUpdated:(VTDeviceModel *)device version:(NSString *)version;

/**
 *	@brief	notify the software version updated after readSoftwareVersion is called.
 *
 *	@param 	device 	device is notified
 *	@param 	version 	software version value of notification
 */
- (void) didSoftwareVersionUpdated:(VTDeviceModel *)device version:(NSString *)version;

/**
 *	@brief	notify of the system id updated after readSystemId is called.
 *
 *	@param 	device 	device is notified
 *	@param 	systemId 	system id value of notification
 */
- (void) didSystemIdUpdated:(VTDeviceModel *)device systemId:(id)systemId;

/**
 *	@brief	notify of IEEE updated after readIEEE is called.
 *
 *	@param 	device 	device is notified
 *	@param 	ieeeNumber 	IEEE nubmer of notification
 */
- (void) didIEEEUpdated:(VTDeviceModel *)device ieeeNumber:(id)ieeeNumber;


/**
 *	@brief	notify of pnp id updated after readPnpId is called.
 *
 *	@param 	device 	device is notified
 *	@param 	pnpId 	pnp id value of notification
 */
- (void) didPnpIdUpdated:(VTDeviceModel *)device pnpId:(id)pnpId;

@end


/**
 *	@brief	device extension of VTProfile. 
 */
@interface VTProfile (Device)
#pragma mark -
#pragma mark private method declaration
/**
 *	@brief	check if device info service is supported.
 *
 *	@return	YES or NO
 */
- (BOOL)hasDeviceInfoService;


#pragma mark -
#pragma mark public method declaration

/**
 *	@brief	read manufacture name of the deivce. the result will be got from didManufactureNameUpdated.
 *
 *	@param 	device 	device to read
 */
- (void)readManufactureName:(VTDeviceModel *)device;

/**
 *	@brief	read model number of the device. the result will be got from didModelNumberUpdated.
 *
 *	@param 	device 	device to read
 */
- (void)readModelNumber:(VTDeviceModel *)device;


/**
 *	@brief	read serial number fo the device. the result will be got from didSerialNumberUpdated.
 *
 *	@param 	device 	device to read
 */
- (void)readSerialNumber:(VTDeviceModel *)device;


/**
 *	@brief	read hardware version of the device. the result will be got from didHardwareVersionUpdated.
 *
 *	@param 	device 	device to read
 */
- (void)readHardwareVersion:(VTDeviceModel *)device;

/**
 *	@brief	read firmware version from the device. the result will be got from didFirmwareVersionUpdated.
 *
 *	@param 	device 	device to read
 */
- (void)readFirmwareVersion:(VTDeviceModel *)device;

/**
 *	@brief	read software version from the device. the result will be got from didSoftwareVersionUpdated.
 *	@param 	device 	device to read
 */
- (void)readSoftwareVersion:(VTDeviceModel *)device;

/**
 *	@brief	read system id from the device. the result will be got from didSystemIdUpdated.
 *
 *	@param 	device 	device to read
 */
- (void)readSystemId:(VTDeviceModel *)device;

/**
 *	@brief	read IEE from the device. the result will be got from didIEEEUpdated.
 *
 *	@param 	device 	device to read
 */
- (void)readIEEE:(VTDeviceModel *)device;

/**
 *	@brief	read pnp id from the device. the result will be got from didPnpIdUpdated.
 *
 *	@param 	device 	device to read
 */
- (void)readPnpId:(VTDeviceModel *)device;


@end
