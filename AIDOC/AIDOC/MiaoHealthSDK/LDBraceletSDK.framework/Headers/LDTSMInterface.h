//
//  LDTSMInterface.h
//  LDBraceletSDK
//
//  Created by 田峻岐 on 17/8/10.
//  Copyright © 2017年 houhm. All rights reserved.
//

#ifndef LDTSMInterface_h
#define LDTSMInterface_h

@protocol LDLDUPTChannelDelegate <NSObject>
- (NSInteger)channelID;
- (NSString*)slectResp;
- (NSData*)transmitWithCommand:(NSData *)command error:(NSError**)error;
@end

@protocol LDBluetoothDelegate <NSObject>
- (NSInteger)establishWithError:(NSError **)error;
- (id <LDLDUPTChannelDelegate>)openLogicChannelWithCommand:(NSData*)command error:(NSError **)error;
- (NSInteger)closeLogicChannelWithChannelId:(NSInteger)channelId error:(NSError **)error;
- (NSString *)bleSEStatusWithError:(NSError **)error;
- (NSData *)btcInfoWithError:(NSError **)error;
- (NSData *)cplcInfoWithError:(NSError **)error;
@end

#endif /* LDTSMInterface_h */
