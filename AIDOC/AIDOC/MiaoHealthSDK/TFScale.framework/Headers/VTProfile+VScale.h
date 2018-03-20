/** @file VTProfile+VScale.h
 * @brief category of VScale profile. Client could access Vscale compatible device capability with this category.
 * @author Kim.Yuan
 * [@author <Kim.yuan email:Kim.yuan@vtrump.com>]
 * @date 2013.04.15
 * @version 0.91
 * @copyright Vtrump
 */

#import "VTProfile.h"
#import "VTScaleUser.h"

/**
 *	@brief	delegate of VTProfile and its extended categories.
 */
@protocol VTProfileScaleDelegate <VTProfileDelegate>

@optional
/* vscale notification */
/**
 *	@brief	notification of test result value updated after setTestResultNotification is on (YES) or readTestResult. This method is only available for VScale compatible device.
 *
 *	@param 	device 	device is notified.
 *	@param 	result 	test result of scale with type VTFatScaleTestResult.
 */
- (void) didTestResultValueUpdate:(VTDeviceModel *)device scaleType:(UInt8)scaleType result:(id)result;

/**
 *	@brief	notification of user info value updated after setUserInfoNotification is on (YES) or readUserInfo. This method is only available for VScale compatible device.
 *
 *	@param 	device 	device is notified.
 *	@param 	userInfo 	user info array with type VTScaleUser
 *	@param 	currentUserID 	current user id
 */
- (void) didUserInfoValueUpdate:(VTDeviceModel *)device userInfo:(NSMutableArray *)userInfo currentUserID:(UInt8)currentUserID;

@end


/**
 *	@brief	vscale extension of VTProfile. It's available for all Vscale compatible device.
 */
@interface VTProfile (VScale)

#pragma mark -
#pragma mark private method declaration
/**
 *	@brief	check if vscale profile is supported.
 *
 *	@return	YES or NO.
 */
- (BOOL) hasScaleProfile;


#pragma mark -
#pragma mark public method declaration
/**
 *	@brief	set notification of test result. Client could get test result notification from didTestResultValueUpdate.
 *	@param 	device 	device to set
 *	@param 	on 	YES to enable, NO to disable.
 */
- (void) setTestResultNotification:(VTDeviceModel*)device on:(BOOL)on;

/**
 *	@brief	read test result. Clent could get test result from didTestResultValueUpdate.
 *	@param 	device 	device to read 
 */
- (void) readTestResult:(VTDeviceModel*)device;

/**
 *	@brief	set user info notification. Client could get user info arrays from didUserInfoValueUpdate.
 *	@param 	device 	device to set
 *	@param 	on 	YES to enable, NO to disable.
 */
- (void) setUserInfoNotification:(VTDeviceModel*)device on:(BOOL)on;


/**
 *	@brief	read user info notification. Client could get user info arrays from didUserInfoValueUpdate.
 *	@param 	device 	device to read 
 */
- (void) readUserInfo:(VTDeviceModel*) device;

/**
 *	@brief	caculate test result according to the user info. the caculated result will be notified by didTestResultValueUpdate.
 *
 *	@param 	device 	device to caculate
 *	@param 	user 	user to caculate result
 */
- (void) caculateResult:(VTDeviceModel *)device user:(VTScaleUser *)user;

/**
 *	@brief	refresh user info from the scale model to bt model.
 *
 *	@param 	device 	device to read.
 */
- (void) refreshUserInfo:(VTDeviceModel *)device;

/**
 *	@brief	set the current user with user Id
 *
 *	@param 	device 	device to set
 *	@param 	userId 	user id to set
 */
- (void) setCurrentUser:(VTDeviceModel *)device userId:(UInt8)userId;

/**
 *	@brief	set user info array.
 *
 *	@param 	device 	device to set
 *	@param 	user 	user info array to set
 */
- (void) setUserInfo:(VTDeviceModel *)device user:(VTScaleUser *)user;


/* vscale notification */
/**
 *	@brief	notification of test result value updated after setTestResultNotification is on (YES) or readTestResult. This method is only available for VScale compatible device.
 *
 *	@param 	device 	device is notified.
 *	@param 	result 	test result of scale with type VTFatScaleTestResult.
 */
- (void) didTestResultValueUpdate:(VTDeviceModel *)device scaleType:(UInt8)scaleType result:(id)result;

/**
 *	@brief	notification of user info value updated after setUserInfoNotification is on (YES) or readUserInfo. This method is only available for VScale compatible device.
 *
 *	@param 	device 	device is notified.
 *	@param 	userInfo 	user info array with type VTScaleUser
 *	@param 	currentUserID 	current user id
 */
- (void) didUserInfoValueUpdate:(VTDeviceModel *)device userInfo:(NSMutableArray *)userInfo currentUserID:(UInt8)currentUserID;
@end
