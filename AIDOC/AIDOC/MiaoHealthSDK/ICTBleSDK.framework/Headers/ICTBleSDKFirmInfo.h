//
//  ICTFirmPackageInfo.h
//  ICTBleSDKFramework
//
//  Created by MikeZhou on 15/7/2.
//  Copyright (c) 2015年 iCareTech. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICTBleSDKEnums.h"

@interface ICTBleSDKFirmInfo : NSObject

- (instancetype)initWithServerContent:(NSDictionary *)serverContent;

/**
 *	@brief	根据orderNO排序
 */
- (NSComparisonResult)compareByOrderNO:(ICTBleSDKFirmInfo *)entity;

@property (nonatomic, assign) NSInteger orderNO;
@property (nonatomic, assign) NSInteger checkSum;
@property (nonatomic, assign) ICTBleSDKFWType firmType;

@property (nonatomic, copy) NSString *fileName;
@property (nonatomic, copy) NSString *destVersion;
@property (nonatomic, copy) NSString *downURL;

@end
