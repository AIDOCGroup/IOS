//
//  LandiCustom.h
//  LandiReader
//
//  Created by HudongFang on 15/5/17.
//  Copyright (c) 2015年 LANDI. All rights reserved.
//

#import "LandiBandBase.h"

@interface LandiCustom : LandiBandBase

+ (id) sharedInstance;

-(void)LDA_DemoCommand:(onVoidCB)successCB
           failedBlock:(onErrorCB)failedCB;

@end
