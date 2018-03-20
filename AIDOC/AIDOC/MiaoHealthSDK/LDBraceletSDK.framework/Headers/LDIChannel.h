//
//  LDIChannel.h
//  LDSmartCardAPI
//
//  Created by houhm on 17/1/12.
//  Copyright © 2017年 houhm. All rights reserved.
//

@protocol LDISession;
@protocol LDIChannel

-(void)close;

- (BOOL)isClosed;

- (int)getChannelNumber;

- (BOOL)isBasicChannel;

- (NSData*)transmit:(NSData*)command error:(NSError**)err;

- (id<LDISession>)session;

- (NSData*)getSelectResponse;

- (long long)handle;

@end
