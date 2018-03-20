/** @file VTProfileDelegate.h
 * @brief delegate of VTProfile. Client's Manager or UI Controller should implement this delegate to get all the notification.
 * @author Kim.Yuan
 * [@author <Kim.yuan email:Kim.yuan@vtrump.com>]
 * @date 2012.09.14
 * @version 0.91
 * @copyright Vtrump
 */

#import <Foundation/Foundation.h>
#import "VTTypes.h"

@class VTDeviceModel;

/**
 *	@brief	delegate of VTProfile and its extended categories. 
 */
@protocol VTProfileDelegate <NSObject>


@optional
/* general notification */
/**
 *	@brief	value of the charactristic is notified
 *
 *	@param 	device 	device is notified
 *	@param 	characteristic 	characteristic is notified
 */
- (void)didValueUpdated:(VTDeviceModel *)device characteristic:(CBCharacteristic *)characteristic;

/**
 *	@brief	notify if the write operation is successed
 *
 *	@param 	device 	device is notified
 *	@param 	characteristic 		characteristic is notified
 *	@param 	success 	YES to write success, NO to write failed.
 */
- (void) didWriteValue:(VTDeviceModel *)device characteristic:(CBCharacteristic *)characteristic success:(BOOL)success;


/* proximity notification */
/**
 *	@brief	notify the tx power value update after called readTxPower.
 *
 *	@param 	device 	device is notified
 *	@param 	txPower 	txPower value of notification
 */
-(void) didTxPowerUpdated:(VTDeviceModel*)device txPower:(char)txPower;

/**
 *	@brief	notify the link loss alert level updated after writeLinkLossAlertLevel is called.
 *
 *	@param 	device 	device is notified
 *	@param 	alertLevel 	alert level value of notification.
 */
-(void) didLinkLossAlertLevelUpdated:(VTDeviceModel*)device alertLevel:(char)alertLevel;


/* battery notification */
/**
 *	@brief	notify the battery updated after readBattery is called or setBatteryNotification is On(YES).
 *
 *	@param 	device 	device is notified
 *	@param 	batteryLevel 	battery level value of notification.
 */
- (void) didBatteryLevelUpdate:(VTDeviceModel*)device batteryLevel:(UInt8)batteryLevel;


@end
