//
//  SLPDataTransferCommon.h
//  Sleepace
//
//  Created by Martin on 5/16/16.
//  Copyright © 2016 com.medica. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SLPDataTransferDef.h"

//TCP或蓝牙的帧类型
typedef enum {
    SLPFramType_ACK = 0,
    SLPFramType_Post,
    SLPFramType_Request,
    SLPFramType_Response
}SLPFramTypes;

typedef NS_ENUM(NSInteger,SLPDeviceCategory) {
    SLPDeviceCategory_None,
    SLPDeviceCategory_Reston,
    SLPDeviceCategory_Pillow,
    SLPDeviceCategory_Milky,
};

//TCP协议和蓝牙新协议的分隔符,每个包用分割符分开
static const Byte kSeparator[4] = {0x24,0x5F,0x40,0x2D};
@interface SLPDataTransferCommon : NSObject

//分包
/*
 data: 总的数据
 separator:分隔符
 index:将separactor的前index数据分割给前一段数据 剩余的分割给后一段数据
 */
+ (NSArray *)cutApart:(NSData *)data by:(NSData *)separator fromSeparatorIndex:(NSInteger)index;
+ (NSData *)convertDeviceDataFromID:(NSString *)deviceID;
+ (NSString *)converDeviceIDFromData:(NSData *)data;

+ (SLPDeviceTypes)deviceTypeFromDeviceCode:(NSString *)deviceCode;
+ (NSInteger)textureFromDeviceCode:(NSString *)deviceCode;
+ (SLPDeviceCategory)deviceCategoryFromDeviceCode:(NSString *)deviceCode;
+ (SLPDeviceCategory)deviceCategoryFromDeviceType:(SLPDeviceTypes)deviceType;
@end
