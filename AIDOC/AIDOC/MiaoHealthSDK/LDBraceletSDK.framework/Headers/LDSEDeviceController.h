//
//  LDSEDeviceController.h
//  LDSmartCardAPI
//
//  Created by houhm on 17/1/12.
//  Copyright © 2017年 houhm. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LDIService.h"
#import "LDBraceletOutType.h"

@class LDAccountInfo;


@interface LDSEDeviceController : NSObject
+ (instancetype)sharedInstance;

- (id<LDIService>)iseService;

- (EMVResult *)fetchAcctInfo:(NSData*)requestAid;

- (void)setPiCiNum:(NSString*)piciNumFirstSix error:(NSError**)err;

- (void)setAutoBTspeed:(BOOL)autoBTspeedEnable;

- (void)setBTEventCBFlag:(BOOL)flag;
@end

