//
//  YZSocketProtocol.h
//  YZBaseSDK
//
//  Created by 宫城 on 2018/5/31.
//  Copyright © 2018 Youzan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YZMessageModel.h"

@protocol YZSocketDelegate <NSObject>

@optional
/**
 *  接收到消息
 */
- (void)socketReceivedMessage:(nullable YZMessageModel *)message;

/**
 *  连接已建立
 */
- (void)socketDidConnect;

/**
 *  建立连接时检测到 token 失效
 */
- (void)connectionAuthAppraisalFailedWithErorr:(NSError *)error;

/**
 *  重连失败或者无网络导致失去连接
 */
- (void)lostConnection;

@end
