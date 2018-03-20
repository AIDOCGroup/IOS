//
//  SLPBLESentPacketV_1.h
//  Sleepace
//
//  Created by Martin on 6/7/16.
//  Copyright © 2016 com.medica. All rights reserved.
//

#import "SLPBLEBaseSendPacket.h"

@interface SLPBLESendPacketV_1 : SLPBLEBaseSendPacket
//新协议才有的
@property (nonatomic,assign) SLPDeviceTypes deviceType;//设备类型

@end
