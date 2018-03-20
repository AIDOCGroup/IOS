/** @file VTProfile+Proximity.h
 * @brief category of BLE proximity profile.
 * @author Kim.Yuan
 * [@author <Kim.yuan email:Kim.yuan@vtrump.com>]
 * @date 2013.04.15
 * @version 0.91
 * @copyright Vtrump
 */

#import "VTProfile.h"

/**
 *	@brief	proximity extension of VTProfile. 
 */
@interface VTProfile (Proximity)
#pragma mark -
#pragma mark private method declaration
/**
 *	@brief	check if proximity profile is supported.
 *
 *	@return	YES or NO
 */
- (BOOL)hasProximityProfile;


#pragma mark -
#pragma mark public method declaration

/**
 *	@brief	read tx power of device. The result will be got from didTxPowerUpdated.
 *
 *	@param 	device 	device to read
 */
- (void)readTxPower:(VTDeviceModel *)device;


/**
 *	@brief	read link loss alert level from device. The result will be got from didLinkLossAlertLevelUpdated.
 *
 *	@param 	device 	device to read
 */
- (void)readLinkLossAlertLevel:(VTDeviceModel *)device;


/**
 *	@brief	write link loss alert level to the device.
 *
 *	@param 	device 	device to write
 *	@param 	alertLevel 	alert level to write, three candidate values, BLE_IMMEDIATE_ALERT_HIGH_VAL, BLE_IMMEDIATE_ALERT_MILD_VAL, BLE_IMMEDIATE_ALERT_OFF_VAL
 */
- (void)writeLinkLossAlertLevel:(VTDeviceModel *)device alertLevel:(char)alertLevel;



// immediateAlert method is defined in VTProfile+Findme.h

@end
