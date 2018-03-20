//
//  DataConvert.h
//  BleSDKDemo
//
//  Created by MikeZhou on 15/7/13.
//  Copyright (c) 2015年 iCareTech_MAC01. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ICTBleSDKDataConvert : NSObject

+ (instancetype)sharedDataConvert;

/**
 *	@brief	将字节流数据转换成整数，适用于大于等于2字节的流数据
 *
 *	@param 	data 	字节流数据
 *	@param 	length 	字节长度（>=2）
 *
 *	@return	返回转换后的整数
 */
- (NSUInteger)convertDataToInt:(NSData *)data
                        length:(NSUInteger)length;

/**
 *	@brief	将指定的数据转换为NSUInteger
 *
 *	@param 	start 	起始位置
 *	@param 	length 	需要获取的数据长度
 *	@param 	data 	需要进行转换的字节数据
 *
 *	@return	转化出来的数值
 */
- (NSUInteger)convertToIntFrom:(NSUInteger)start
                    withLength:(NSUInteger)length
                          Data:(NSData *)data;


//将整数转换成16位流字节数据
+ (NSData *)convertIntToData16:(NSInteger)intValue;

/**
 *	@brief	16进制数据式的字符串转换成对应的16进制数
 *
 *	@param 	hexString 	16进制式字符串
 */
+ (NSData *)dataWithHexString:(NSString *)hexString;

//crc校验值
- (NSData *)uint16CRCResultWithData:(NSData *)data;

//16进制数据直接转为16进制字符串
- (NSString *)hexadecimalString:(NSData *)data;

//将流字节数据转换成整数的字符串
- (NSString *)convertToIntStrWithHexData:(NSData *)hexData;

@end
