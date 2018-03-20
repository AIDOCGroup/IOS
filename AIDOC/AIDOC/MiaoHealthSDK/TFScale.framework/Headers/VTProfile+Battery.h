/** @file VTProfile+Battery.h
 * @brief category of BLE battery service.
 * @author Kim.Yuan
 * [@author <Kim.yuan email:Kim.yuan@vtrump.com>]
 * @date 2013.04.15
 * @version 0.91
 * @copyright Vtrump
 */
#import "VTProfile.h"

/**
 *	@brief	battery extension of VTProfile. 
 */
@interface VTProfile (Battery)
#pragma mark -
#pragma mark private method declaration
/**
 *	@brief	check if battery service is supported.
 *
 *	@return	YES or NO
 */
- (BOOL)hasBatteryService;


#pragma mark -
#pragma mark public method declaration

/**
 *	@brief	read battery level. The result will be got from didBatteryLevelUpdate.
 *
 *	@param 	device 	device to read
 */
- (void)readBattery:(VTDeviceModel *)device;

/**
 *	@brief	set battery notification. The notification will be got from didBatteryLevelUpdate.
 *
 *	@param 	device 	device to read
 *	@param 	on 	YES to enable, NO to disable
 */
- (void) setBatteryNotification:(VTDeviceModel*)device on:(BOOL)on;

@end
