//
//  SLPBLEManager+Connect.h
//  Sleepace
//
//  Created by Martin on 7/13/16.
//  Copyright © 2016 com.medica. All rights reserved.
//

#import "SLPBLEManager.h"
#import "SLPBLEDef.h"
#import "SLPDataTransferDef.h"
#import <Foundation/Foundation.h>

@class CBPeripheral;
@interface SLPBLEManager (Connect)
- (BOOL)connectPeripheral:(CBPeripheral *)peripheral deviceCode:(NSString *)deviceCode timeout:(CGFloat)timeout completion:(SLPBLEConnectHandle)handle;
@end
