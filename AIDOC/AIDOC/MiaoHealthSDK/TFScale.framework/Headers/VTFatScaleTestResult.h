/** @file VTFatScaleTestResult.h
 * @brief test result data model of scale
 * @author Kim.Yuan
 * [@author <Kim.yuan email:Kim.yuan@vtrump.com>]
 * @date 2013.04.14
 * @version 0.91
 * @copyright Vtrump
 */


#import <Foundation/Foundation.h>
#import "VTScaleTestResult.h"

/**
 *	@brief	data model of VScale Test result. It's only available for VScale compatible devices.
 */
@interface VTFatScaleTestResult : VTScaleTestResult


/**
 *	@brief	user id 0~15
 */
@property (nonatomic) UInt8 userID;

/**
 *	@brief	user gender, 0 is male, 1 is female, 2 male athelete, 3 female athelete
 */
@property (nonatomic) UInt8 gender;

/**
 *	@brief	user age as input
 */
@property (nonatomic) UInt8 age;

/**
 *	@brief	user input heigh， unit is CM
 */
@property (nonatomic) UInt8 height;

/**
 *	@brief	test result of body fat content, uint is percentage
 */
@property (nonatomic) float fatContent;

/**
 *	@brief	test result of body water content, uint is percentage
 */
@property (nonatomic) float waterContent;

/**
 *	@brief	test result of body bone, uint is kg
 */
@property (nonatomic) float boneContent;

/**
 *	@brief	test result of body muscle content, uint is percentage
 */
@property (nonatomic) float muscleContent;

/**
 *	@brief	test result of body visceral fat content, uint is percentage
 */
@property (nonatomic) UInt8 visceralFatContent;


/**
 *	@brief	test result of calorie
 */
@property (nonatomic) int calorie;


/**
 *	@brief	test result of bmi
 */
@property (nonatomic) float bmi;




@end
