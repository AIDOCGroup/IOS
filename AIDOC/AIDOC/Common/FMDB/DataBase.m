//
//  DataBase.m
//  FMDBDemo
//
//  Created by Zeno on 16/5/18.
//  Copyright © 2016年 zenoV. All rights reserved.
//

#import "DataBase.h"
#import <FMDB.h>
#import "UserHealthModel.h"

static DataBase *_DBCtl = nil;

@interface DataBase()<NSCopying,NSMutableCopying>{
    FMDatabase  *_db;
    
}




@end

@implementation DataBase

+(instancetype)sharedDataBase{
    
    if (_DBCtl == nil) {
        
        _DBCtl = [[DataBase alloc] init];
        
        [_DBCtl initDataBase];
        
    }
    
    return _DBCtl;
    
}

+(instancetype)allocWithZone:(struct _NSZone *)zone{
    
    if (_DBCtl == nil) {
        
        _DBCtl = [super allocWithZone:zone];
        
    }
    
    return _DBCtl;
    
}

-(id)copy{
    
    return self;
    
}

-(id)mutableCopy{
    
    return self;
    
}

-(id)copyWithZone:(NSZone *)zone{
    
    return self;
    
}

-(id)mutableCopyWithZone:(NSZone *)zone{
    
    return self;
    
}


-(void)initDataBase{
    // 获得Documents目录路径
    
    NSString *documentsPath = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
    
    // 文件路径
    
    NSString *filePath = [documentsPath stringByAppendingPathComponent:@"UserHealthModel.plist"];
    NSLog(@"%@",filePath);
    // 实例化FMDataBase对象
    
    _db = [FMDatabase databaseWithPath:filePath];
    
    [_db open];
    

        // 初始化数据表
    NSString *personSql = @"CREATE TABLE 'UserHealthModel' ('hisId' int(11) NOT NULL AUTO_INCREMENT,'kalStr' varchar(255) DEFAULT NULL,'goalStepCount' varchar(255) DEFAULT NULL,'stepCountFinally' varchar(255) DEFAULT NULL,'userId' varchar(255) DEFAULT NULL,'stepCount' varchar(255) DEFAULT NULL,'saveCurrentDeviceStepCount' varchar(255) DEFAULT NULL,'currentDeviceStepCount' varchar(255) DEFAULT NULL,'latestDate' varchar(255) DEFAULT NULL,'latestDateWithHMS' varchar(255) DEFAULT NULL,'dynamicStepCount' varchar(255) DEFAULT NULL,'otherEquipmentStepCount' varchar(255) DEFAULT NULL,'otherEquipmentInitialStepCount' varchar(255) DEFAULT NULL,'equipmentType' varchar(255) DEFAULT NULL,'equipmentName' varchar(255) DEFAULT NULL,'deviceTypeId' varchar(255) DEFAULT NULL,'deviceUUID' varchar(255) DEFAULT NULL,'equipmentBloodSugarValue' varchar(255) DEFAULT NULL,'equipmentBloodPressureHighValue' varchar(255) DEFAULT NULL,'equipmentBloodPressureLowValue' varchar(255) DEFAULT NULL,'equipmentBodyFatValue' varchar(255) DEFAULT NULL,'equipmentHeartRateValue' varchar(255) DEFAULT NULL,PRIMARY KEY ('hisId'))";
    [_db executeUpdate:personSql];
    
    [_db close];

}
#pragma mark - 接口

- (void)addUserHealthModel:(UserHealthModel *)userHealthModel{
   
    [_db open];
    NSNumber *maxID = @(0);
    FMResultSet *res = [_db executeQuery:@"SELECT * FROM UserHealthModel"];
    //获取数据库中最大的ID
    while ([res next]) {
        if ([maxID integerValue] < [[res stringForColumn:@"hisId"] integerValue]) {
            maxID = @([[res stringForColumn:@"hisId"] integerValue] ) ;
        }
        
    }
    maxID = @([maxID integerValue] + 1);

    [_db executeUpdate:@"INSERT INTO UserHealthModel(kalStr,goalStepCount,stepCountFinally,userId,saveCurrentDeviceStepCount,currentDeviceStepCount,latestDate,latestDateWithHMS,dynamicStepCount,otherEquipmentStepCount,otherEquipmentInitialStepCount,equipmentType,equipmentName,deviceTypeId,deviceUUID,equipmentBloodSugarValue,equipmentBloodPressureHighValue,equipmentBloodPressureLowValue,equipmentBodyFatValue,equipmentHeartRateValue) VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)",userHealthModel.kalStr,userHealthModel.goalStepCount,userHealthModel.stepCountFinally,userHealthModel.userId,userHealthModel.saveCurrentDeviceStepCount,userHealthModel.currentDeviceStepCount,userHealthModel.latestDate,userHealthModel.latestDateWithHMS,userHealthModel.dynamicStepCount,userHealthModel.otherEquipmentStepCount,userHealthModel.otherEquipmentInitialStepCount,userHealthModel.equipmentType,userHealthModel.equipmentName,userHealthModel.deviceTypeId,userHealthModel.deviceUUID,userHealthModel.equipmentBloodSugarValue,userHealthModel.equipmentBloodPressureHighValue,userHealthModel.equipmentBloodPressureLowValue,userHealthModel.equipmentBodyFatValue,userHealthModel.equipmentHeartRateValue];
    [_db close];
}

- (void)deleteUserHealthModel:(UserHealthModel *)userHealthModel{
    [_db open];
    
    
//    [_db executeUpdate:@"DELETE FROM UserHealthModel WHERE LEFT(latestDate,10)<LEFT(now(),10)"];

    [_db close];
}

- (void)updateUserHealthModel:(UserHealthModel *)userHealthModel{
    [_db open];
    
//    [_db executeUpdate:@"UPDATE 'UserHealthModel' SET kalStr = ?  WHERE person_id = ? ",person.name,person.ID];
//    [_db executeUpdate:@"UPDATE 'UserHealthModel' SET person_age = ?  WHERE person_id = ? ",@(person.age),person.ID];
//    [_db executeUpdate:@"UPDATE 'UserHealthModel' SET person_number = ?  WHERE person_id = ? ",@(person.number + 1),person.ID];
//
    [_db close];
}

- (NSMutableArray *)getAllStepCount{
    [_db open];
    NSMutableArray *dataArray = [[NSMutableArray alloc] init];
    FMResultSet *res = [_db executeQuery:@"SELECT * FROM UserHealthModel"];
    while ([res next]) {
        UserHealthModel *healthModel = [[UserHealthModel alloc] init];
        healthModel.kalStr = [res stringForColumn:@"kalStr"];
        healthModel.goalStepCount = [res stringForColumn:@"goalStepCount"];
        healthModel.stepCountFinally = [res stringForColumn:@"stepCountFinally"];
        healthModel.userId = [res stringForColumn:@"userId"];
        healthModel.saveCurrentDeviceStepCount = [res stringForColumn:@"saveCurrentDeviceStepCount"];
        healthModel.currentDeviceStepCount = [res stringForColumn:@"currentDeviceStepCount"];
        healthModel.latestDate = [res stringForColumn:@"latestDate"];
        healthModel.latestDateWithHMS = [res stringForColumn:@"latestDateWithHMS"];
        healthModel.dynamicStepCount = [res stringForColumn:@"dynamicStepCount"];
        healthModel.otherEquipmentStepCount = [res stringForColumn:@"otherEquipmentStepCount"];
        healthModel.otherEquipmentInitialStepCount = [res stringForColumn:@"otherEquipmentInitialStepCount"];
        healthModel.equipmentType = [res stringForColumn:@"equipmentType"];
        healthModel.equipmentName = [res stringForColumn:@"equipmentName"];
        healthModel.deviceTypeId = [res stringForColumn:@"deviceTypeId"];
        healthModel.deviceUUID = [res stringForColumn:@"deviceUUID"];
        healthModel.equipmentBloodSugarValue = [res stringForColumn:@"equipmentBloodSugarValue"];
        healthModel.equipmentBloodPressureHighValue = [res stringForColumn:@"equipmentBloodPressureHighValue"];
        healthModel.equipmentBloodPressureLowValue = [res stringForColumn:@"equipmentBloodPressureLowValue"];
        healthModel.equipmentBodyFatValue = [res stringForColumn:@"equipmentBodyFatValue"];
        healthModel.equipmentHeartRateValue = [res stringForColumn:@"equipmentHeartRateValue"];
        
        [dataArray addObject:healthModel];
    }
    
    [_db close];
    
    
    return dataArray;
    
}

@end
