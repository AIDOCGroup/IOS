//
//  LDIReader.h
//  LDSmartCardAPI
//
//  Created by houhm on 17/1/12.
//  Copyright © 2017年 houhm. All rights reserved.
//

#import "LDIService.h"

@protocol LDISession;

@protocol LDIReader

- (NSString*)getName;

- (id<LDISession>)openSession:(NSError**)err;

- (BOOL)isSecureElementPresent;

- (id<LDIService>)getSEService;

- (void)closeSessions;

@end

