//
//  DataBaseTool.m
//  FMDB
//
//  Created by gcf on 16/7/26.
//  Copyright © 2016年 CBayel. All rights reserved.
//

#import "DataBaseTool.h"
#import <objc/runtime.h>


@interface DataBaseTool ()
{
    //多线程查询及更新
    FMDatabaseQueue *_queue;
}

@end

@implementation DataBaseTool
/**
 *  在某路径创建数据库并打开
 *
 *  @param path 路径
 *
 *  @return 数据库队列
 */
-(instancetype)initWithPath:(NSString *)path{
    if (self = [super init]) {
        //创建数据库
        _queue = [FMDatabaseQueue databaseQueueWithPath:path];
    }
    return self;
}
/**
 *  判断某表是否存在
 *
 *  @param tableName 表名
 *
 *  @return 是否存在
 */
-(BOOL)tableExists:(NSString *)tableName{
    __block BOOL result = NO;
    [_queue inDatabase:^(FMDatabase *db) {
        result = [db tableExists:tableName];
    }];
    return result;
}
/**
 *  更新，除了查询，其他操作均会走这个方法
 *
 *  @param sql   数据库语句
 *  @param param 参数
 *
 *  @return 是否更新成功
 */
-(BOOL)executeUpdate:(NSString *)sql param:(NSArray *)param{
    //确保result可以被重新赋值
    __block BOOL result = NO;
    [_queue inDatabase:^(FMDatabase *db) {
        if (param && param.count > 0) {
            result = [db executeUpdate:sql withArgumentsInArray:param];
        }
        else
        {
            result = [db executeUpdate:sql];
        }
    }];
    return result;
}
/**
 *  查询第一行第一列的数据
 *
 *  @param sql   数据库语句
 *  @param param 参数
 *
 *  @return 查询结果
 */
-(id)executeScalar:(NSString *)sql param:(NSArray *)param{
    __block id result;
    [_queue inDatabase:^(FMDatabase *db) {
        FMResultSet *rs = [db executeQuery:sql withArgumentsInArray:param];
        if ([rs next]) {
            result = rs[0];
        }
        else
        {
            result = 0;
        }
    }];
    return result;
}
/**
 *  查询数据行数
 *
 *  @param tableName 表名
 *
 *  @return 行数
 */
-(NSInteger)rowCount:(NSString *)tableName{
    NSNumber *num =  (NSNumber *)[self executeScalar:[NSString stringWithFormat: @"select count(*) from %@",tableName] param:nil];
    return [num longValue];
}

/**
 *  删除表
 *
 *  @param tableName 表名
 *
 *  @return 是否成功
 */
-(BOOL)dropTable:(NSString *)tableName{
    NSString *sql = [NSString stringWithFormat: @"drop table %@",tableName];
    return [self executeUpdate:sql param:nil];
}

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
-(NSArray *)executeQuery:(NSString *)sql withArgumentsInArray:(NSArray *)arguments modelClass:(Class)modelClass{
    return [self executeQuery:sql withArgumentsInArray:arguments modelClass:modelClass performBlock:nil];
}

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
-(NSArray *)executeQuery:(NSString *) sql withArgumentsInArray:(NSArray *) arguments modelClass:(Class) modelClass performBlock:(void (^)(id model, FMResultSet *rs)) block
{
    __block NSMutableArray *modelArr = [NSMutableArray new];
    [_queue inDatabase:^(FMDatabase *db) {
        NSDictionary *mapping = nil;
        FMResultSet *rs = [db executeQuery:sql withArgumentsInArray:arguments];
        while([rs next]){
            id model = [[modelClass alloc]init];
            if(!mapping && [model conformsToProtocol:@protocol(ColumnPropertyMappingDelegate)]){
                //实现了列 - 属性转换协议
                mapping = [model columnPropertyMapping];
            }
            int count = [rs columnCount];
            for(int i = 0; i < count; i++){
                //列名
                NSString *columnName = [rs columnNameForIndex:i];
                //进行数据库列名到model之间的映射转换，拿到属性名
                NSString *propertyName;
                if(mapping){
                    //propertyName = mapping[columnName];
                    propertyName = mapping[columnName];
                    if(propertyName == nil){
                        //如果映射未定义，则视为相同
                        propertyName = columnName;
                    }
                }
                else
                {
                    //如果映射未定义，则视为相同
                    propertyName = columnName;
                }
                // 获取指定的属性
                objc_property_t objProperty = class_getProperty(modelClass, propertyName.UTF8String);
                //如果属性不存在，则不操作
                if(objProperty){
                    if(![rs columnIndexIsNull:i]){
                        [self setProperty:model value:rs columnName:columnName propertyName:propertyName property:objProperty];
                    }
                }
                NSAssert(![propertyName isEqualToString:@"description"], @"description为自带方法，不能对description进行赋值，请使用其他属性名或请ColumnPropertyMappingDelegate进行映射");
            }
            //执行自定义操作
            if(block){
                block(model, rs);
            }
            [modelArr addObject:model];
        }
        [rs close];
    }];
    return modelArr;
}
/**
 *  查询结果集取得model集合，无自定义操作
 *
 *  @param rs         数据库查询结果集
 *  @param modelClass 结果集model类型
 *
 *  @return 查询结果集
 */
- (NSArray *)resultForModels:(FMResultSet *)rs modelClass:(Class)modelClass
{
    return [self resultForModels:rs modelClass:modelClass performBlock:nil];
}
/**
 *  查询结果集取得model集合，可自定义操作
 *
 *  @param rs         数据库查询结果集
 *  @param modelClass 结果集model类型
 *  @param block      对model执行自定义操作
 *
 *  @return 查询结果集
 */
- (NSArray *)resultForModels:(FMResultSet *)rs modelClass:(Class)modelClass performBlock:(void (^)(id model, FMResultSet *rs))block
{
    NSDictionary *mapping = nil;
    
    NSMutableArray *modelArr = [NSMutableArray array];
    while ([rs next]) {
        id model = [[modelClass alloc] init];
        if(!mapping && [model conformsToProtocol:@protocol(ColumnPropertyMappingDelegate)]) {
            //实现了列-属性转换协议
            mapping = [model columnPropertyMapping];
        }
        
        for (int i = 0; i < [rs columnCount]; i++) {
            //列名
            NSString *columnName = [rs columnNameForIndex:i];
            //进行数据库列名到model之间的映射转换，拿到属性名
            NSString *propertyName;
            
            if(mapping) {
                propertyName = mapping[columnName];
                if (propertyName == nil) {
                    propertyName = columnName;
                }
            } else {
                propertyName = columnName;
            }
            
            objc_property_t objProperty = class_getProperty(modelClass, propertyName.UTF8String);
            //如果属性不存在，则不操作
            if (objProperty) {
                if(![rs columnIndexIsNull:i]) {
                    [self setProperty:model value:rs columnName:columnName propertyName:propertyName property:objProperty];
                }
            }
            
            NSAssert(![propertyName isEqualToString:@"description"], @"description为自带方法，不能对description进行赋值，请使用其他属性名或请ColumnPropertyMappingDelegate进行映射");
        }
        
        //执行自定义操作
        if (block) {
            block(model, rs);
        }
        
        [modelArr addObject:model];
    }
    [rs close];
    
    return modelArr;
}

/**
 *  进行属性赋值
 */
- (void)setProperty:(id)model value:(FMResultSet *)rs columnName:(NSString *)columnName propertyName:(NSString *)propertyName property:(objc_property_t)property
{
    //    @"f":@"float",
    //    @"i":@"int",
    //    @"d":@"double",
    //    @"l":@"long",
    //    @"c":@"BOOL",
    //    @"s":@"short",
    //    @"q":@"long",
    //    @"I":@"NSInteger",
    //    @"Q":@"NSUInteger",
    //    @"B":@"BOOL",
    
    NSString *firstType = [[[[NSString stringWithUTF8String:property_getAttributes(property)] componentsSeparatedByString:@","] firstObject] substringFromIndex:1];
    
    
    if ([firstType isEqualToString:@"f"]) {
        NSNumber *number = [rs objectForColumnName:columnName];
        [model setValue:@(number.floatValue) forKey:propertyName];
        
    } else if([firstType isEqualToString:@"i"]){
        NSNumber *number = [rs objectForColumnName:columnName];
        [model setValue:@(number.intValue) forKey:propertyName];
        
    } else if([firstType isEqualToString:@"d"]){
        [model setValue:[rs objectForColumnName:columnName] forKey:propertyName];
        
    } else if([firstType isEqualToString:@"l"] || [firstType isEqualToString:@"q"]){
        [model setValue:[rs objectForColumnName:columnName] forKey:propertyName];
        
    } else if([firstType isEqualToString:@"c"] || [firstType isEqualToString:@"B"]){
        NSNumber *number = [rs objectForColumnName:columnName];
        [model setValue:@(number.boolValue) forKey:propertyName];
        
    } else if([firstType isEqualToString:@"s"]){
        NSNumber *number = [rs objectForColumnName:columnName];
        [model setValue:@(number.shortValue) forKey:propertyName];
        
    } else if([firstType isEqualToString:@"I"]){
        NSNumber *number = [rs objectForColumnName:columnName];
        [model setValue:@(number.integerValue) forKey:propertyName];
        
    } else if([firstType isEqualToString:@"Q"]){
        NSNumber *number = [rs objectForColumnName:columnName];
        [model setValue:@(number.unsignedIntegerValue) forKey:propertyName];
        
    } else if([firstType isEqualToString:@"@\"NSData\""]){
        NSData *value = [rs dataForColumn:columnName];
        [model setValue:value forKey:propertyName];
        
    } else if([firstType isEqualToString:@"@\"NSDate\""]){
        NSDate *value = [rs dateForColumn:columnName];
        [model setValue:value forKey:propertyName];
        
    } else if([firstType isEqualToString:@"@\"NSString\""]){
        NSString *value = [rs stringForColumn:columnName];
        [model setValue:value forKey:propertyName];
        
    } else {
        [model setValue:[rs objectForColumnName:columnName] forKey:propertyName];
    }
}


@end
