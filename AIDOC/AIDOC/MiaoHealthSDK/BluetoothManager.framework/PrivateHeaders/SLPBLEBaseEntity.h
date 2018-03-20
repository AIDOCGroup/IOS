//
//  SLPBLEBaseData.h
//  Sleepace
//
//  Created by Martin on 6/6/16.
//  Copyright © 2016 com.medica. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SLPDataTransferDef.h"

@interface SLPBLEBaseEntity : NSObject
@property (nonatomic,assign) NSInteger messageType;
@property (nonatomic,assign) UInt8 status;
@property (nonatomic,assign) NSInteger uniqType;//消息唯一类型 SLPBLEMessagetUniqTypes
@property (nonatomic,readonly) BOOL isSucceed;

+ (SLPBLEBaseEntity *)entityWithData:(NSData *)data;
- (id)initWithData:(NSData *)data;


//无参数的消息使用
+ (NSData *)content;

//检测是否还有其他的用处
//设备 -> APP post的消息在此处理
- (void)checkReuseableFor:(id)sender;
@end
