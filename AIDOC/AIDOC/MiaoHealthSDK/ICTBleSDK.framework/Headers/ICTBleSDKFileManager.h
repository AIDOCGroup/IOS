//
//  ICTBleSDKFileManager.h
//  ICTBleSDK
//
//  Created by MikeZhou on 16/2/16.
//  Copyright © 2016年 iCareTech_MAC01. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ICTBleSDKFileManager : NSObject

+ (id)sharedICTBleSDKFileManager;

/**
 *	@brief	一次同步未结束的数据需要写入的目录
 */
+ (NSString *)doingSyncDataDir;

/**
 *	@brief  数据同步结束时，数据需要存入的目录
 */
+ (NSString *)doneSyncDataDirWithSerialNumber:(NSString *)serialNumber;

/**
 *	@brief	通用数据格式数据同步结束时，数据存入目录
 *
 *	@param 	serialNumber 	设备序列号
 */
+ (NSString *)universalSyncMethodDoneSyncDataDirWithSerialNumber:(NSString *)serialNumber;

/**
 *	@brief	通用数据格式中，拆分数据文件
 *
 *	@param 	serialNumber 	设备序列号
 */
+ (void)divideUniversalDoneFileWithSerialNumber:(NSString *)serialNumber;

/**
 *	@brief	通用数据格式，拆分后删除被拆分的文件
 *
 *	@param 	serialNumber 	设备序列号
 */
+ (void)deleteBeforeDivideDoneFileWithSerialNumber:(NSString *)serialNumber;

/**
 *	@brief	鼾症类型数据文件从doing目录移到done目录，以便后续上传服务器使用
 *
 *	@param 	serialNumber 	当前连接手环序列号
 *	@param 	startTimeValue 	开始时间
 */
+ (void)moveSnoringTypeDataFromDoingDirToDoneDir:(NSString *)serialNumber
                                       startTime:(NSDate *)startTimeValue;

/**
 *	@brief	通用数据格式鼾症类型数据文件从doing目录移到done目录，以便后续上传服务器使用
 *
 *	@param 	serialNumber 	当前连接手环序列号
 */
+ (void)moveUniversalSyncMethodSnoringTypeDataFromDoingDirToDoneDir:(NSString *)serialNumber;



@end
