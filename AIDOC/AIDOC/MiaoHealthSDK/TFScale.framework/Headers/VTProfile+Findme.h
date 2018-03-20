/** @file VTProfile+Findme.h
 * @brief category of BLE findme profile
 * @author Kim.Yuan
 * [@author <Kim.yuan email:Kim.yuan@vtrump.com>]
 * @date 2013.04.15
 * @version 0.91
 * @copyright Vtrump
 */

#import "VTProfile.h"

/**
 *	@brief	findme extension of VTProfile. 
 */
@interface VTProfile (Findme)

#pragma mark -
#pragma mark private method declaration
/**
 *	@brief	check if findme profile is supported
 *
 *	@return	YES or NO
 */
- (BOOL)hasFindmeProfile;

#pragma mark -
#pragma mark public method declaration

/**
 *	@brief	set immediate alert level to the device
 *
 *	@param 	device 	device to set
 *	@param 	alertLevel 	alert level of immeidate alert. Three candidate values, BLE_IMMEDIATE_ALERT_HIGH_VAL, BLE_IMMEDIATE_ALERT_MILD_VAL, BLE_IMMEDIATE_ALERT_OFF_VAL.
 */
- (void)immediateAlert:(VTDeviceModel *)device alertLevel:(char)alertLevel;



@end
