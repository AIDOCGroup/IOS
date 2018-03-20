//
//  ICTBleSyncBodyData.h
//  ICTBleSDKFramework
//
//  Created by MikeZhou on 15/7/3.
//  Copyright (c) 2015年 iCareTech. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICTBleSDKBandInfoEntity.h"

typedef void(^kICTBleSDKHttpBlock)(id content, NSError * error);

@interface ICTBleSDKHttpClient : NSObject

+ (instancetype)sharedICTBleSDKHttp;

/**
 *	@brief	开始同步体征数据
 */
- (void)beginSyncBodyData;
 
/**
 *	@brief	请求新固件信息
 *
 *	@param 	band 	    当前连接的手环信息
 *	@param 	success     成功
 *	@param 	failed   	失败
 */
- (void)requestFirmNewWithBandInfo:(ICTBleSDKBandInfoEntity *)band
                           success:(kICTBleSDKHttpBlock)success
                            failed:(kICTBleSDKHttpBlock)failed;

@end
