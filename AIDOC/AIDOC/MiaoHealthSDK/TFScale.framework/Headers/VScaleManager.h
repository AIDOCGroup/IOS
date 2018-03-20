//
//  VScaleManager.h
//  VScale_Sdk_Demo
//
//  Created by Ben on 13-10-10.
//  Copyright (c) 2013年 Vtrump. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VTScales.h"

@protocol  VScaleManagerDelegate;

typedef NS_ENUM(NSUInteger, VCStatus) {
    VCStatusDisconnected,
    VCStatusDiscovered,
    VCStatusConnecting,
    VCStatusConnected,
    VCStatusServiceReady,
    VCStatusCaculate,
    VCStatusHolding,
};


@interface VScaleManager : NSObject<VTDeviceManagerDelegate, VTDeviceDelegate, VTProfileScaleDelegate>

@property (nonatomic, readonly) NSString *deviceUUID;
@property (nonatomic, readonly) NSString *name;

/*用于指示应用状态*/
@property (nonatomic,assign)  VCStatus curStatus;
/*测量数据*/
@property (nonatomic,retain)  VTFatScaleTestResult *scaleResult;
@property (nonatomic,retain)  id<VScaleManagerDelegate> delegate;

//人物数据
@property (nonatomic, readonly) UInt8 userID;   // Use slot 9 for caculate
@property (nonatomic, readonly) UInt8 gender;   //0代表男性、1代表女性
@property (nonatomic, readonly) UInt8 age;      //年龄
@property (nonatomic, readonly) UInt8 height;   //身高
- (void)setCalulateDataWithUserID:(UInt8)userID gender:(UInt8)gender age:(UInt8)age height:(UInt8)height;

+ (VScaleManager *)sharedInstance;
- (void)scan;
- (void)scanDevice:(void (^)(NSError *error))complete;
- (void)scale:(void (^)(VTFatScaleTestResult *result, NSError *error))complete;
- (void)connect;
- (void)disconnect;
@end


@protocol VScaleManagerDelegate <NSObject>

@required
-(void)updateDeviceStatus:(VCStatus)status;
-(void)updateUIDataWithFatScale:(VTFatScaleTestResult*)result;
-(void)updateUIDataWithWeightScale:(VTScaleTestResult*)result;

@end