//
//  LDBraceletOutType.h
//  LDBraceletSDK
//
//  Created by houhm on 16/12/13.
//  Copyright © 2016年 houhm. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CommonClass.h"


@interface AidCandInfo : NSObject

@property(nonatomic,assign)int index;//在硬件的索引
@property(nonatomic,copy)NSData *aidName;
@property(nonatomic,copy)NSString *apnName;
@end

@interface PBOCLog : NSObject

@property(nonatomic,copy)NSString *tradeDate;
@property(nonatomic,copy)NSString *tradeTime;
@property(nonatomic,assign)float authAmount;
@property(nonatomic,assign)float otherAmount;
@property(nonatomic,copy)NSString *countryCode;
@property(nonatomic,copy)NSString *currencyCode;
@property(nonatomic,copy)NSString *merchantName;
@property(nonatomic,copy)NSString * tradeTypeName;
@property(nonatomic,assign)int tradeType;
@property(nonatomic,copy)NSString *ATC;

- (instancetype)initWithData:(NSData *)data;

@end

@interface AccountInfo : NSObject
@property(nonatomic,assign)Byte type;
@property(nonatomic,strong)NSString *ksn;
@property(nonatomic,copy)NSString *cerType;
@property(nonatomic,copy)NSString *cerNO;
@property(nonatomic,copy)NSString *pan;
@property(nonatomic,copy)NSString *panSN;
@property(nonatomic,copy)NSString *panValidDate;
@property(nonatomic,copy)NSString *offlineBalance;
@property(nonatomic,strong)NSData *track2;
@property(nonatomic,copy)NSString *currencyCode;
@property(nonatomic,strong)NSData *area55Data;


@end


@interface EMVResult : NSObject

@property(nonatomic,assign)PBOC_RET_CODE retCode;
@property(nonatomic,readonly)NSArray *candInfoList;//aid列表
@property(nonatomic,readonly)AccountInfo *accountInfo;//账户信息
@property(nonatomic,readonly)NSDictionary *ic55Dic;
@property(nonatomic,copy)NSString *resultInfo;

- (instancetype)initWithCode:(PBOC_RET_CODE)retCode candInfoList:(NSArray *)candInfoList ;
- (instancetype)initWithCode:(PBOC_RET_CODE)retCode accountInfo:(AccountInfo *)accountInfo;
- (instancetype)initWithCode:(PBOC_RET_CODE)retCode resultInfo:(NSString *)resultInfo;
- (instancetype)initWithCode:(PBOC_RET_CODE)retCode ic55Dic:(NSDictionary *)ic55Dic;
@end

@interface LDRunningRateItem : NSObject

@property(nonatomic,assign)NSInteger timeOffset;
@property(nonatomic,assign)NSInteger heartRate;
@end

@interface LDRunningRecords : NSObject

@property(nonatomic,copy)NSString *date;//开始日期,格式：170806
@property(nonatomic,copy)NSString *startTime;//开始时间:123435
@property(nonatomic,copy)NSString *endTime;//结束时间:123435
@property(nonatomic,assign)NSInteger totoalDistance;//总里程数,单位：米
@property(nonatomic,assign)NSInteger totalStepCount;//总步数
@property(nonatomic,assign)NSInteger totalCarlorie;//总卡路里,单位：千卡
@property(nonatomic,assign)NSInteger pace;//配速： 平均速率下的每1KM的跑步耗时，单位：秒
@property(nonatomic,assign)NSInteger rateCount;//心率个数
@property(nonatomic,strong)NSMutableArray<LDRunningRateItem *> *runningRateItems;

@end


