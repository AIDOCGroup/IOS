//
//  ICTBandBasisInfo.h
//  ICTBleSDKFramework
//
//  Created by MikeZhou on 15/6/19.
//  Copyright (c) 2015年 iCareTech_MAC01. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ICTBleSDKBandInfoEntity : NSObject

/**
 *	@brief	初始化
 *
 *	@param 	bandName 	手环名称
 *	@param 	capability 	设备支持能力
 *	@param 	hwVersion 	硬件版本号
 *	@param 	serialNumber 	手环序列号
 *	@param 	manufacter 	制造商
 *	@param 	pVersion 	协议版本
 *	@param 	MAVersion 	固件A版本号
 *	@param 	MBVersion 	固件B版本号
 *	@param 	MCVersion 	固件C版本号
 *	@param 	MDVersion 	固件D版本号
 *	@param 	MEVersion 	固件E版本号
 *
 *	@return	返回设备信息
 */
- (instancetype)initWithBandName:(NSString *)bandName
                      capability:(NSInteger)capability
                 hardwareVersion:(NSString *)hwVersion
                bandSerialNumber:(NSString *)serialNumber
                      manufacter:(NSString *)manufacter
                 protocolVersion:(NSString *)pVersion
               firmwareMAVersion:(NSString *)MAVersion
               firmwareMBVersion:(NSString *)MBVersion
               firmwareMCVersion:(NSString *)MCVersion
               firmwareMDVersion:(NSString *)MDVersion
               firmwareMEVersion:(NSString *)MEVersion;


@property (assign, nonatomic) NSInteger bandCapability;
@property (copy, nonatomic)   NSString *bandName;
@property (copy, nonatomic)   NSString *hardwareVersion;
@property (copy, nonatomic)   NSString *bandSerialNumber;
@property (copy, nonatomic)   NSString *manufacter;
@property (copy, nonatomic)   NSString *protocolVersion;
@property (copy, nonatomic)   NSString *firmwareMAVersion;
@property (copy, nonatomic)   NSString *firmwareMBVersion;
@property (copy, nonatomic)   NSString *firmwareMCVersion;
@property (copy, nonatomic)   NSString *firmwareMDVersion;
@property (copy, nonatomic)   NSString *firmwareMEVersion;

@end
