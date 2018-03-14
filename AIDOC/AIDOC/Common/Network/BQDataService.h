//
//  BQDataService.h
//  AIDOC
//
//  Created by app on 18/1/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import <Foundation/Foundation.h>
//请求类型
typedef NS_ENUM(NSInteger,RequestType) {
    RequestTypeGet    = 0,
    RequestTypePut    = 1,
    RequestTypeDelete = 2,
    RequestTypePost   = 3,
    
};

@interface BQDataService : NSObject

+ (instancetype)shareBQDataService;

- (void)request:(NSString *)URLString
     parameters:(id)parameters requestType:(RequestType)type
        success:(void (^)(id responseObject))success
        failure:(void (^)(NSString *error))failure;

/**
 *  上传文件到OSS
 *
 *  @param aData     文件二进制数据
 */
- (void)uploadFileWithData:(NSData *)aData fileName:(NSString *)afileName completed:(void (^)(NSString *url))completed failure:(void (^)(NSString *))failure;

@end
