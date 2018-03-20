//
//  LDISEService.h
//  LDSmartCardAPI
//
//  Created by houhm on 17/1/12.
//  Copyright © 2017年 houhm. All rights reserved.
//


@protocol LDIReader;

@protocol LDIService

- (BOOL)isConnected;

- (NSArray*)getReaders;

- (void)shutdown;

@end


@protocol LDIServiceCallBack <NSObject>

- (void)serviceConnected:(id<LDIServiceCallBack>)service;

@end
