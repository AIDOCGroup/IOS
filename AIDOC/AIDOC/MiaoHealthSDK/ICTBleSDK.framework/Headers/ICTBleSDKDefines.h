//
//  ICTBleSDKDefines.h
//  ICTBleSDKFramework
//
//  Created by MikeZhou on 15/7/6.
//  Copyright (c) 2015年 iCareTech. All rights reserved.
//

#ifndef iCareTek_ICTBleSDKDefines_h
#define iCareTek_ICTBleSDKDefines_h

//一些文件路径
#define kICTBleDocumentPath [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject]
#define kICTBleDir @"ICTBleSDKDir"
#define kICTSerialNumberPlist @"ICTBleSerial"
#define kICTBleSDKDatabaseName @"blesdk.db"
#define kICTBleSDKDir [kICTBleDocumentPath stringByAppendingPathComponent:kICTBleDir]
#define kICTBleDocumentURL [[NSFileManager defaultManager] URLForDirectory:NSDocumentDirectory\
                                                                  inDomain:NSUserDomainMask\
                                                         appropriateForURL:nil\
                                                                    create:NO\
                                                                     error:nil]
#define kICTBleSDKDirURL [kICTBleDocumentURL URLByAppendingPathComponent:kICTBleDir]

//体征数据表
#define kdatatablename @"bodyData"
#define kdevicesn      @"deviceSerialNumber"     //设备序列号
#define kbodytype      @"type"                   //体征数据类型
#define kgathertime    @"gatherTime"             //数据采集时间
#define kbodyvalue     @"value"                  //体征数据值
#define kgathertype    @"gatherType"             //采集类型
#define ksyncsource    @"syncSource"             //同步源
#define kgatherway     @"gatherWay"              //采集方式
#define kgatherdevice  @"gatherDevice"           //采集设备
#define kdatavalues    @"?,?,?,?,?,?,?,?"

//数据同步控制表
#define kSyncControlTableName  @"syncControl"
#define kSyncControlSyncedTime @"syncedTime"
#define kSyncControlVendorKey  @"vendorKey"

#if DEBUG
#define SDKLog(...) NSLog(__VA_ARGS__)
#else
#define SDKLog(...) {}
#endif


#endif
