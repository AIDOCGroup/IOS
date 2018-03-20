//
//  LDBraceletEMVOperator.h
//  LDBraceletSDK
//
//  Created by houhm on 16/11/24.
//  Copyright © 2016年 houhm. All rights reserved.
//

#ifndef LDBraceletEMVOperator_h
#define LDBraceletEMVOperator_h

#import "LDBraceletEMVOperationDelegate.h"

@class EMVResult;

@protocol LDBraceletEMVOperator <NSObject>

- (void)setBalanceRemindInfo:(int)balance;

- (int)balanceRemindInfo;

/**
 *  获取固件存储的消费记录
 *
 * 返回数据格式如下：
 * [
 *  {
 *    aid:986500000000001,
 *    recordList:[
 "DF18889989898978987876",
 "DF18889989898978987876",
 "DF18889989898978987876"
 *      ]
 *  },
 *  {
 *      同上
 *  }
 *
 *  ]
 *
 */
-(NSArray*)localConsumeRecordList;


-(BOOL)flushBalance:(NSArray*)AIDList;

/**
 *  清除固件存储的消费记录
 */
-(BOOL)setLocalConsumeRecords;

-(void)icTransferWithAmout:(NSString*)amount
                       aid:(NSString *)aid
            processingCode:(int)processingCode
       innerProcessingCode:(int)innerProcessingCode
             isForceOnline:(BOOL)isForceOnline
            emvResultBlock:(void(^)(EMVResult *emvResult))emvResultBlock;

- (void)setAid:(int)aid emvResultBlock:(void(^)(EMVResult *emvResult))emvResultBlock;

-(BOOL)doSecondInssuance:(NSDictionary*)onlineResult
        authResponseCode:(NSString*)authResponseCode
          emvResultBlock:(void(^)(EMVResult *emvResult))emvResultBlock;

- (void)emvFinish:(BOOL)isSuccess;

- (NSArray *)getPbocLog;

- (EMVResult *)fetchAcctInfo:(NSData*)requestAid;

- (BOOL)initEMVKernel;

@end

#endif
