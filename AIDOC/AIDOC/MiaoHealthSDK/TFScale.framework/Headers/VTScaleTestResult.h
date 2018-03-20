/** @file VTScaleTestResult.h
 * @brief test result data model of scale
 * @author Kim.Yuan
 * [@author <Kim.yuan email:Kim.yuan@vtrump.com>]
 * @date 2013.08.23
 * @version 0.91
 * @copyright Vtrump
 */


#import <Foundation/Foundation.h>

/**
 *	@brief	data model of VScale Test result. It's only available for VScale compatible devices.
 */
@interface VTScaleTestResult : NSObject



/**
 *	@brief	type of the test result
 */
@property (nonatomic) UInt8 dataType;



/**
 *	@brief	test result of weight scale
 */
@property (nonatomic) float weight;




@end
