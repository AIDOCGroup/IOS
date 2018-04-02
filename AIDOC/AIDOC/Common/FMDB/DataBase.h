//
//  DataBase.h
//  FMDBDemo
//
//  Created by Zeno on 16/5/18.
//  Copyright © 2016年 zenoV. All rights reserved.
//

#import <Foundation/Foundation.h>

@class UserHealthModel;


@interface DataBase : NSObject

@property(nonatomic,strong) UserHealthModel *userHealthModel;


+ (instancetype)sharedDataBase;


#pragma mark - UserHealthModel
/**
 *  添加UserHealthModel
 *
 */
- (void)addUserHealthModel:(UserHealthModel *)userHealthModel;
/**
 *  删除UserHealthModel
 *
 */
- (void)deleteUserHealthModel:(UserHealthModel *)userHealthModel;
/**
 *  更新UserHealthModel
 *
 */
- (void)updateUserHealthModel:(UserHealthModel *)userHealthModel;

/**
 *  获取所有数据
 *
 */
- (NSMutableArray *)getAllStepCount;


@end
