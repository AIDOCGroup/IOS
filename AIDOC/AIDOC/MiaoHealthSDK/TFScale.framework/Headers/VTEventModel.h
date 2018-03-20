/** @file VTEventModel.h
 * @brief VTEventModel is defined to record the event of ble device. 
 * @author Kim.Yuan
 * [@author <Kim.yuan email:Kim.yuan@vtrump.com>]
 * @date 2012.09.14
 * @version 0.91
 * @copyright Vtrump
 */

#import "VTTypes.h"

#import "VTDeviceModel.h"


/**
 *	@brief	data model of the device event.
 */
@interface VTEventModel : NSObject




/**
 *	@brief	name of the device
 */
@property (nonatomic, retain) NSString* name;



/**
 *	@brief	UUID of the device
 */
@property (nonatomic, retain) NSString* UUID;



/**
 *	@brief	serial number of the device
 */
@property (nonatomic, retain) NSData* serialNumber;


/**
 *	@brief	image url of the device
 */
@property (nonatomic, retain) NSString* imageUrl;



/**
 *	@brief	model type of the device
 */
@property (nonatomic) VTDeviceModelType_t modelType;



/**
 *	@brief	status of the device
 */
@property (nonatomic) VTDeviceStatusType_t statusType;



/**
 *	@brief	owner type of the device
 */
@property (nonatomic) VTDeviceOwnerType_t ownerType;



/**
 *	@brief	scenario type of the device
 */
@property (nonatomic, retain) NSString * scenarioType;



/**
 *	@brief	event type
 */
@property (nonatomic) VTEventType_t eventType;



/**
 *	@brief	time of the event
 */
@property (nonatomic) NSTimeInterval time;



/**
 *	@brief	date of the event
 */
@property (nonatomic, retain) NSString* date;



/**
 *	@brief	latitude of the event
 */
@property (nonatomic) double lat;



/**
 *	@brief	longitude of the event
 */
@property (nonatomic) double lon;



/**
 *	@brief	altitude of the event
 */
@property (nonatomic) double alt;



/**
 *	@brief	init the event for the device
 *
 *	@param 	device 	device to init event
 *	@param 	theEventType 	event type
 *
 *	@return	event
 */
- (id)initWithDevice:(VTDeviceModel*)device theEventType:(VTEventType_t)theEventType;


/**
 *	@brief	event type description
 *
 *	@return	string of event type decription
 */
- (NSString *) stringFormatEventType;


@end
