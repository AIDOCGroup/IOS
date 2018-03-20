/** @file VTScaleUser.h
 * @brief User data model of scale
 * @author Kim.Yuan
 * [@author <Kim.yuan email:Kim.yuan@vtrump.com>]
 * @date 2013.04.14
 * @version 0.91
 * @copyright Vtrump
 */


#import <Foundation/Foundation.h>

/**
 *	@brief	data model of VScale User. It's only available for VScale compatible devices.
 */
@interface VTScaleUser : NSObject


/**
 *	@brief	user id defined in the scale
 */
@property (nonatomic) UInt8 userID;

/**
 *	@brief	gender of user
 */
@property (nonatomic) UInt8 gender;

/**
 *	@brief	age of user
 */
@property (nonatomic) UInt8 age;

/**
 *	@brief	height of user
 */
@property (nonatomic) UInt8 height;


@end
