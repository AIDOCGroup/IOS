//
//  VTViBeacon.h
//  vtble
//
//  Created by Ben on 13-12-17.
//  Copyright (c) 2013年 VTrump. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *	@brief	data model of advertisement.
 */
@interface VTViBeacon : NSObject


/**
 *	@brief	manufacture id of iBeacon
 */
@property (nonatomic) UInt16 manufactureId;


/**
 *	@brief	iBeacon sevice uuid
 */
@property (nonatomic) NSString *serviceUUID ;

/**
 *	@brief	major data of iBeacon
 */
@property (nonatomic) UInt16 majorData;

/**
 *	@brief	minor data of iBeacon
 */
@property (nonatomic) UInt16 minorData;

/**
 *	@brief	power data of iBeacon
 */
@property (nonatomic) UInt8 power;


@end
