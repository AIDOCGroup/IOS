//
//  MiaoHealthElderManager.h
//  MiaoHealthConnect
//
//  Created by 罗志平 on 17/2/9.
//  Copyright © 2017年 Miao Health. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MCData+Elder.h"

typedef void (^BindDeviceBlock) (NSInteger isSuccess, NSError *_Nullable error);
typedef void (^QueryResultBlock) (NSMutableArray *_Nullable result, NSError *_Nullable error);



@interface MiaoHealthElderManager : NSObject

//- (nonnull instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (nonnull instancetype)new UNAVAILABLE_ATTRIBUTE;
/**
 初始化对象
 */
+ (nonnull instancetype)shareInstance;

/**
 进行设备绑定   会直接绑定设备，建议先查询是否需要绑定设备
 
 @param device_sn 设备sn
 @param device_no 设备标号
 @param bindBlock 绑定回调
 */
- (void)bindDevice:(NSString *_Nonnull) device_sn
          deviceNO:(NSString *_Nonnull) device_no
              name:(NSString *_Nonnull) name
          nickname:(NSString *_Nonnull) nickname
            mobile:(NSString *_Nonnull) mobile
              bind:(BindDeviceBlock _Nullable)bindBlock;

/**
 解除设备绑定
 
 @param device_sn 设备sn
 @param device_no 设备标号
 @param bindBlock 绑定回调
 */
- (void)unbindDevice:(NSString *_Nonnull) device_sn
            deviceNO:(NSString *_Nonnull) device_no
                bind:(BindDeviceBlock _Nullable)bindBlock;


/**
 添加联系人
 
 @param relation  联系人Model
 */
- (BOOL)addRelation:(MCElderRelation *_Nonnull) relation success:(OperateSuccessBlock)operationSuccessBlock failure:(OperateFailureBlock)operationFailureBlock;

/**
 修改联系人
 
 @param relation  联系人Model
 */
- (BOOL)editRelation:(MCElderRelation *_Nonnull) relation success:(OperateSuccessBlock)operationSuccessBlock failure:(OperateFailureBlock)operationFailureBlock;;

/**
 删除联系人
 
 @param relation  联系人Model
 
 @return
 */
- (BOOL)deleteRelation:(MCElderRelation *_Nonnull) relation success:(OperateSuccessBlock)operationSuccessBlock failure:(OperateFailureBlock)operationFailureBlock;;

/**
 查询联系人
 
 @param device_sn   设备sn
 @param device_no   设备编号
 @param queryResult 查询结果集 返回NSMutableArray<MCElderRelation *>
 */
- (void)fetchRelation:(NSString *_Nonnull) device_sn
             deviceNO:(NSString *_Nonnull) device_no
          queryResult:(QueryResultBlock _Nonnull) queryResult;

/**
 添加亲情提醒
 
 @param remind  亲情提醒Model
 */
- (BOOL)addRemind:(MCElderRemind *_Nonnull) remind success:(OperateSuccessBlock)operationSuccessBlock failure:(OperateFailureBlock)operationFailureBlock;;
/**
 修改亲情提醒
 
 @param remind  亲情提醒Model
 */
- (BOOL)editRemind:(MCElderRemind *_Nonnull) remind success:(OperateSuccessBlock)operationSuccessBlock failure:(OperateFailureBlock)operationFailureBlock;;
/**
 删除亲情提醒
 
 @param remind  亲情提醒Model
 */
- (BOOL)deleteRemind:(MCElderRemind *_Nonnull) remind success:(OperateSuccessBlock)operationSuccessBlock failure:(OperateFailureBlock)operationFailureBlock;;

/**
 查询亲情提醒
 
 @param device_sn   设备sn
 @param device_no   设备编号
 @param queryResult 查询结果集 返回NSMutableArray<MCElderRemind *>
 */
- (void)fetchRemind:(NSString *_Nonnull) device_sn
           deviceNO:(NSString *_Nonnull) device_no
        queryResult:(QueryResultBlock _Nonnull) queryResult;

/**
 查询日报
 
 @param device_sn   设备sn
 @param device_no   设备编号
 @param queryResult 查询结果集 返回NSMutableArray<MCElderDayReport *>
 */
- (void)fetchDayReport:(NSString *_Nonnull) device_sn
              deviceNO:(NSString *_Nonnull) device_no
           queryResult:(QueryResultBlock _Nonnull) queryResult;

/**
 查询佩戴信息
 
 @param device_sn   设备sn
 @param device_no   设备编号
 @param queryResult 查询结果集 返回NSMutableArray<MCElderWearInfo *>
 */
- (void)fetchWearInfo:(NSString *_Nonnull) device_sn
             deviceNO:(NSString *_Nonnull) device_no
          queryResult:(QueryResultBlock _Nonnull) queryResult;

/**
 查询位置信息
 
 @param device_sn   设备sn
 @param device_no   设备编号
 @param queryResult 查询结果集 返回NSMutableArray<MCElderPosition *>
 */
- (void)fetchPosition:(NSString *_Nonnull) device_sn
             deviceNO:(NSString *_Nonnull) device_no
          queryResult:(QueryResultBlock _Nonnull) queryResult;

/**
 查询告警信息
 
 @param device_sn   设备sn
 @param device_no   设备编号
 @param queryResult 查询结果集 返回NSMutableArray<MCElderCaution *>
 */
- (void)fetchWarningMessage:(NSString *_Nonnull) device_sn
                   deviceNO:(NSString *_Nonnull) device_no
                queryResult:(QueryResultBlock _Nonnull) queryResult;

/**
 鼓励老人
 
 @param device_sn   设备sn
 @param device_no   设备编号
 @param type        鼓励类型 （1：您今天的表现真棒，您的孩子为您热情鼓掌、2：您的孩子为您献上一枝花、3：您的孩子给您一个拥抱）
 */
- (BOOL) encourageElder:(NSString *_Nonnull) device_sn
               deviceNO:(NSString *_Nonnull) device_no
                   type:(NSInteger) type;


@end
