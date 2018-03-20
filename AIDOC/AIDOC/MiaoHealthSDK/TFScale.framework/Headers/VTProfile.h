/** @file VTProfile.h
 * @brief VTProfile has the base method to operate characteristic and service of BLE
 * @author Kim.Yuan
 * [@author <Kim.yuan email:Kim.yuan@vtrump.com>]
 * @date 2012.09.14
 * @version 0.91
 * @copyright Vtrump
 */

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <CoreBluetooth/CBService.h>
#import "VTProfileDelegate.h"



/**
 *	@brief	VTProfile is the base class of all ble profiles.
 */
@interface VTProfile : NSObject


/**
 *	@brief	delegate of the profile
 */
@property(retain, nonatomic) id<VTProfileDelegate> delegate;

/**
 *	@brief	service array of the profile
 */
@property(retain, readonly) NSArray *services;

/**
 *	@brief	name array of the profile
 */
@property(retain, readonly) NSArray *profileNames;


#pragma mark -
#pragma mark public method declaration

/**
 *	@brief	init profiles with services
 *
 *	@param 	services 	services array found by BLE
 *
 *	@return	VTProfile
 */
- (id) initWithServices:(NSArray *)services;

/**
 *	@brief	check if the specific profile is supported
 *
 *	@param 	profileName 	profile name
 *
 *	@return	YES to support, NO to not support
 */
- (BOOL) supportProfile:(NSString *)profileName;





@end
