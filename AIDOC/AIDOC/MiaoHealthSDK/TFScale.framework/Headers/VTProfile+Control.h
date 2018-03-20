/** @file VTProfile+Control.h
 * @brief category of Control profile. 
 * @author Kim.Yuan
 * [@author <Kim.yuan email:Kim.yuan@vtrump.com>]
 * @date 2013.04.15
 * @version 0.91
 * @copyright Vtrump
 */

#import "VTProfile.h"

/**
 *	@brief	control extension of VTProfile. It's available for all VTM30 capatible devices.
 */
@interface VTProfile(Control)

/**
 *	@brief	check if Control Profile is supported
 *
 *	@return	YES or NO
 */
- (BOOL) hasControlProfile;


@end
