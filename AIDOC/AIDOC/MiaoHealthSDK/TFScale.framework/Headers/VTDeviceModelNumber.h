//
//  VTDeviceModelNumber.h
//  vtble
//
//  Created by yuan jing on 13-7-11.
//  Copyright (c) 2013年 VTrump. All rights reserved.
//

#import <Foundation/Foundation.h>


/*version 1: 1 byte each for type/sub type/vendor id */
#define VT_DEVICE_MODEL_VERSION_1      (0x01)
/*version 1: 1 byte each for type/sub type/vendor id */
#define VT_DEVICE_MODEL_VERSION_2      (0x02)

/**
 *	@brief	model to identify the device number, including the version, type, subtype and verdors.
 */

@interface VTDeviceModelNumber : NSObject

/**
 *	@brief	common data to identify the device
 */
@property (nonatomic, retain) NSData * data;

/**
 *	@brief	version of the device identification protocol. currently, it should be 0x01.
 */
@property (nonatomic, assign) UInt8 version;

/**
 *	@brief	type of the device
 */
@property (nonatomic, assign) UInt8 type;

/**
 *	@brief	subtype of the device
 */
@property (nonatomic, assign) UInt8 subType;

/**
 *	@brief	vendor of the device
 */
@property (nonatomic, assign) UInt8 vendor;


/**
 *	@brief	init VTDeviceModelNumber with the manufacture data
 *
 *	@param 	manufactureData 	manufacture data
 *
 *	@return	instance of VTDeviceModelNumber
 */
-(id) initWithManufactureData:(NSData *)manufactureData;


@end
