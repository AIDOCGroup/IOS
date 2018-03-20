/** @file VTAdvertise.h
 * @brief advertisement data model
 * @author Kim.Yuan
 * [@author <Kim.yuan email:Kim.yuan@vtrump.com>]
 * @date 2013.04.14
 * @version 0.91
 * @copyright Vtrump
 */

#import <UIKit/UIKit.h>

/**
 *	@brief	data model of advertisement. 
 */
@interface VTAdvertise : NSObject


/**
 *	@brief	manufacture id of advertisement data
 */
@property (nonatomic) UInt32 manufactureId;


/**
 *	@brief	type of advertisement data
 */
@property (nonatomic) UInt8 type;
 

/**
 *	@brief	data of advertisement
 */
@property (nonatomic, retain) NSData* data;


@end
