/** @file VTDeviceDelegate.h
 * @brief delegate of VTDeviceModel.
 * @author Kim.Yuan
 * [@author <Kim.yuan email:Kim.yuan@vtrump.com>]
 * @date 2012.09.14
 * @version 0.91
 * @copyright Vtrump
 */

#import <Foundation/Foundation.h>


//#import "VTConnectionModel.h"
@class VTDeviceModel;

/**
 *	@brief	delegate of VTDeviceModel. The class that implemented VTDeviceDelegate could get all the notification of this device.
 */
@protocol VTDeviceDelegate <NSObject>



@optional


/**
 *	@brief	notification of RSSI value changed
 *
 *	@param 	device 	device of RSSI value changed
 *	@param 	rssi 	rssi value
 */
- (void) didUpdateRssi: (VTDeviceModel *)device;


@end
