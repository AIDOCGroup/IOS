//
//  ICTBleDatabase.h
//  ICTBleSDKFramework
//
//  Created by MikeZhou on 15/6/29.
//  Copyright (c) 2015年 iCareTech. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMDB.h"
#import "ICTBleSDKBodyDataEntity.h"

@interface ICTBleSDKDatabase : NSObject

@property (strong, nonatomic) FMDatabaseQueue * database;

+ (instancetype)sharedBleSDKDatabase;

///**
// *	@brief	判断某db文件是否存在
// *
// *	@param 	dbName 	db文件名
// */
//+(BOOL)isDataBaseExistForName:(NSString *)dbName;

///**
// *	@brief	db文件绝对路径
// *
// *	@param 	dbName 	db文件名
// */
//+(NSString *)databasePathName:(NSString *)dbName;

/**
 *	@brief	保存体征数据
 *
 *	@param 	datas 	体征数据数组 元素是ICTBleBodyDataEntity
 */
- (void)replaceWithBodyDatas:(NSArray *)datas;

/**
 *	@brief	查找体征数据
 *
 *	@param 	type 	体征参数类型
 *	@param 	from 	开始时间
 *	@param 	limit 	查询体征数据条数
 *	@param 	searchDirect 	向前或向后查询
 *	@param 	order 	排序方式
 *
 *	@return	返回查找到的体征数据数组，数组元素是:ICTBleBodyDataEntity
 */
- (NSArray*)ICTBleSDKfoundBodyDataWithType:(ICTBleSDKBodyParameterType)type
                                  fromTime:(NSDate*)from
                                     limit:(NSInteger)limit
                              searchDirect:(ICTDaoSearchDirect)searchDirect
                                     order:(ICTDaoSearchOrder)order;

/**
 *	@brief	存储已同步的数据的时间
 *
 *	@param 	syncedTime   已同步的数据的时间
 */
- (void)replaceWithSyncedTime:(NSDate *)syncedTime;

/**
 *	@brief	获取最后同步时间
 */
- (NSDate *)ICTBleSDKFetchSyncedTime;





@end
