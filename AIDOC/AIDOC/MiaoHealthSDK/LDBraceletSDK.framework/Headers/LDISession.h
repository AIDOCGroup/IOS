//
//  LDISession.h
//  LDSmartCardAPI
//
//  Created by houhm on 17/1/12.
//  Copyright © 2017年 houhm. All rights reserved.
//

#import "LDIChannel.h"

@protocol LDIReader;

@protocol LDISession

- (id<LDIChannel>)openBasicChannel:(NSData*)aid error:(NSError**)err;

- (id<LDIChannel>)openLogicalChannel:(NSData*)aid error:(NSError**)err;

- (void)close;

- (BOOL)isClosed;

- (NSData*)getATR;

- (id<LDIReader>)getReader;

- (void)closeChannels;

@end

