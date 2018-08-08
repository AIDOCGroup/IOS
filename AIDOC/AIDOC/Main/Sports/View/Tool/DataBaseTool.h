//
//  DataBaseTool.h
//  FMDB
//
//  Created by gcf on 16/7/26.
//  Copyright © 2016年 CBayel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ColumnPropertyMappingDelegate.h"
@class FMResultSet;
@interface DataBaseTool : NSObject

/**
 *  在某路径创建数据库并打开
 *
 *  @param path 路径
 *
 *  @return 数据库队列
 */
-(instancetype)initWithPath:(NSString *)path;
/**
 *  判断某表是否存在
 *
 *  @param tableName 表名
 *
 *  @return 是否存在
 */
-(BOOL)tableExists:(NSString *)tableName;
/**
 *  更新
 *
 *  @param sql   数据库语句
 *  @param param 参数
 *
 *  @return 是否更新成功
 */
-(BOOL)executeUpdate:(NSString *)sql param:(NSArray *)param;
/**
 *  查询第一行第一列的数据
 *
 *  @param sql   数据库语句
 *  @param param 参数
 *
 *  @return 查询结果
 */
-(id)executeScalar:(NSString *)sql param:(NSArray *)param;
/**
 *  查询数据行数
 *
 *  @param tableName 表名
 *
 *  @return 行数
 */
-(NSInteger)rowCount:(NSString *)tableName;
/**
 *  删除表
 *
 *  @param tableName 表名
 *
 *  @return 是否成功
 */
-(BOOL)dropTable:(NSString *)tableName;
#pragma mark ---自动创建Model查询方法---
/**
 *  执行查询操作，自定构造models集合，无自定义操作
 *
 *  @param sql        数据库语句
 *  @param arguments  参数
 *  @param modelClass 结果集model类型
 *
 *  @return 查询结果集
 */
-(NSArray *)executeQuery:(NSString *)sql withArgumentsInArray:(NSArray *)arguments modelClass:(Class)modelClass;
/**
 *  执行查询操作，自定构造models集合，可自定义操作
 *
 *  @param sql        数据库语句
 *  @param arguments  参数
 *  @param modelClass 结果集model类型
 *  @param block      对model执行自定义操作
 *
 *  @return 查询结果集
 */
-(NSArray *)executeQuery:(NSString *) sql withArgumentsInArray:(NSArray *) arguments modelClass:(Class) modelClass performBlock:(void (^)(id model, FMResultSet *rs)) block;
/**
 *  查询结果集取得model集合，无自定义操作
 *
 *  @param rs         数据库查询结果集
 *  @param modelClass 结果集model类型
 *
 *  @return 查询结果集
 */
- (NSArray *)resultForModels:(FMResultSet *)rs modelClass:(Class)modelClass;
/**
 *  查询结果集取得model集合，可自定义操作
 *
 *  @param rs         数据库查询结果集
 *  @param modelClass 结果集model类型
 *  @param block      对model执行自定义操作
 *
 *  @return 查询结果集
 */
- (NSArray *)resultForModels:(FMResultSet *)rs modelClass:(Class)modelClass performBlock:(void (^)(id model, FMResultSet *rs))block;
@end
