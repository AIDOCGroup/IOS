//
//  MiaoHealthConnectManager.h
//  MiaoHealthConnect
//
//  Created by JinZhengxuan on 2016/10/31.
//  Copyright © 2016年 Miao Health. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MCBLEDevice.h"
#import "MCDevice.h"
#import "MMPeripheralsProvider.h"
#import "MCData.h"
#import "SleepSDK.h"
#import "MHWebViewController.h"

typedef NS_ENUM(NSInteger, OfficialVersionType) { //运行环境
    OfficialVersionTypePro, //预生产&正式环境
    OfficialVersionTypeTest, //测试环境
    OfficialVersionTypeDev, //开发环境
};

typedef NS_ENUM(NSInteger, EncryptType) { //运行环境
    EncryptTypeMD5, //md5加密
    EncryptTypeSHA, //SHA加密
};

typedef NS_ENUM(NSInteger, GetLocalSportDataEnum) { //运行环境
    GetLocalSportDataEnumToday, //当天
    GetLocalSportDataEnumHistory, //历史数据（七天内）
};

@interface MiaoHealthConnectManager : NSObject

typedef void (^RequestCompleteBlock) (NSInteger summary_rst, NSError *_Nullable error);
typedef void (^InitSDKResultBlock) (NSError *_Nullable error);
typedef void (^RegisterResultBlock) (NSError *_Nullable error);
typedef void (^QueryCompleteBlock) (NSMutableArray *_Nullable queryResponse, NSError *_Nullable error);
typedef void (^CheckBindHandlerBlock) (BindDeviceStatus bindDeviceStatus, NSError *_Nullable error);
typedef void (^BindHandlerBlock) (NSInteger isSuccess, id _Nullable result, NSError *_Nullable error);
typedef void (^BluetoothStatusChangeBlock) (BluetoothStatus status);
typedef void (^ScanedDevicesBlock) (NSMutableArray<MCBLEDevice *> *_Nullable deviceList);
typedef void (^BluetoothDataChangeBlock)(PeripheralsDataType peripheralsDataType, id _Nullable result, NSError *_Nullable error);
typedef void (^FetchDeviceTypeBlock)(NSMutableArray<MCDeviceType *> *_Nullable deviceTypeArray,NSError *_Nullable error);
typedef void (^FetchDeviceBlock)(NSMutableArray<MCDevice *> *_Nullable deviceArray,NSError *_Nullable error);
typedef void (^FetchDeviceDetailBlock)(NSDictionary *_Nullable deviceDetail,NSError *_Nullable error);
typedef void (^FetchUserDeviceBlock)(NSMutableArray<MCUserDevice *> *_Nullable userDeviceArray,NSError *_Nullable error);

//- (nonnull instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (nonnull instancetype)new UNAVAILABLE_ATTRIBUTE;
/**
 初始化对象
 */
+ (nonnull instancetype)shareInstance;

/**
 初始化接口

 @param appid  appid
 @param appkey appkey
 @param officialVersionType 0:正式环境  1:测试环境
 */
- (void)initWithAppid:(NSString *_Nonnull)appid
               appkey:(NSString *_Nonnull)appkey officialVersion:(OfficialVersionType)officialVersionType ;

/**
 初始化接口
 
 @param appid  appid
 @param appkey appkey
 @param officialVersionType 0:正式环境  1:测试环境
 */
- (void)initWithAppid:(NSString *_Nonnull)appid
               appkey:(NSString *_Nonnull)appkey officialVersion:(OfficialVersionType)officialVersionType resultBlock:(InitSDKResultBlock _Nonnull)resultBlock;

/**
 注册用户回调

 @param userIdentify 用户Id
 @param error        错误消息
 */
- (void)registerUserIdentity:(NSString *_Nonnull) userIdentify
                       error:(__autoreleasing NSError *_Nullable*_Nullable) error;

/**
 注册用户回调 -- Block方式返回成功失败（推荐这个方法）
 
 @param userIdentify 用户Id
 @param error        错误消息
 */
- (void)registerUserIdentity:(NSString *_Nonnull) userIdentify resultBlock:(RegisterResultBlock _Nonnull)resultBlock;



#pragma mark - 数据列表
/**
 获取设备类型列表
 
 @param fetchDeviceTypeBlock 返回数据列表和错误信息
 */
- (void)fetchDeviceTypeList:(FetchDeviceTypeBlock _Nonnull) fetchDeviceTypeBlock;


/**
 获取设备列表

 @param type_id 设备关联ID
 @param page_no 当前页码，默认每次返回10条数据
 @param fetchDeviceBlock 返回数据列表和错误信息
 */
- (void)fetchDeviceList:(NSString *_Nullable) type_id
                 pageNO:(NSInteger) page_no
                 result:(FetchDeviceBlock _Nonnull) fetchDeviceBlock;

/**
 获取用户设备列表
 
 @param page_no 当前页码，默认每次返回10条数据
 @param fetchUserDeviceBlock 返回用户设备列表
 */
- (void)fetchUserDeviceList:(NSInteger) page_no
                     result:(FetchUserDeviceBlock _Nonnull) fetchUserDeviceBlock;

#pragma mark - 二维码和蓝牙绑定

/**
 检查设备绑定

 @param device_sn  设备sn
 @param device_no  分为两种 1.数据列表里获取到的是device_no  2.用户获取到的对于蓝牙设备是UUID 对于扫描类设备是扫描后的字符串 device_no = UUID = scanedCode(二维码扫描码)
 @param checkBindBlock 绑定回调
 */
- (void)checkDevice:(NSString *_Nonnull) device_sn
           deviceNO:(NSString *_Nonnull) device_no
          checkBind:(CheckBindHandlerBlock _Nonnull)checkBindBlock;


/**
 进行设备绑定   会直接绑定设备，建议先查询是否需要绑定设备
 
 @param device_sn 设备sn
 @param device_no 分为两种 1.数据列表里获取到的是device_no  2.用户获取到的对于蓝牙设备是UUID 对于扫描类设备是扫描后的字符串 device_no = UUID = scanedCode(二维码扫描码)
 @param bindBlock 绑定回调 回调返回的result 为 device_no 作为解绑的时候用 device_no 不一定等于 scanedCode(二维码扫描码) 和 UUID
 */
- (void)bindDevice:(NSString *_Nonnull) device_sn
          deviceNO:(NSString *_Nonnull) device_no
              bind:(BindHandlerBlock _Nonnull)bindBlock;

/**
 解除设备绑定
 
 @param device_sn 设备sn
 @param device_no 分为两种 1.数据列表里获取到的是device_no 2.绑定设备返回的device_no
 @param bindBlock 绑定回调
 */
- (void)unbindDevice:(NSString *_Nonnull) device_sn
            deviceNO:(NSString *_Nonnull) device_no
                bind:(BindHandlerBlock _Nonnull)bindBlock;

#pragma mark - Web授权绑定
/**
 
 @param device_sn 设备sn
 @param webView   用于展示的WebView    UIWebView OR WKWebView  传入WebView 如果实现代理则会Overriding, 没实现则会实现
 @param bindBlock 绑定回调  结果值回调 isSuccess = true 为绑定成功 失败则error != nil
 */
- (void)bindWebDevice:(NSString *_Nonnull) device_sn
          displayView:(id _Nonnull) webView
                 bind:(BindHandlerBlock _Nonnull) bindBlock networkStatusBlock:(NetworkRequestStatusBlock _Nullable)networkRequestStatus;


#pragma mark - 蓝牙操作

/**
 获取指定设备当前蓝牙状态
 
 @param device_id 设备id
 
 @return BluetoothStatus 当前蓝牙的连接状态
 */
- (BluetoothStatus) bluetoothStatus:(NSString *_Nonnull) device_id;

/**
 开始扫描蓝牙设备

 @param device_id 设备id
 @param timeout   请求超时
 @param bluetoothStatusChangeBlock 蓝牙状态变化回调
 @param scanedDevicesBlock         扫描结果
 */
- (void)scanBLEDevice:(NSString *_Nonnull) device_id
              timeout:(int) timeout
      bluetoothStatus:(BluetoothStatusChangeBlock _Nonnull) bluetoothStatusChangeBlock
              devices:(ScanedDevicesBlock _Nonnull) scanedDevicesBlock;

/**
 连接蓝牙设备并返回数据

 @param device_id 设备id
 @param device_sn 设备sn
 @param uuid      蓝牙设备uuid 1.为我的设备列表里的device_no  2.绑定后返回的device_no   device_no 不一定等于 UUID
 @param userInfo  用户信息数据
 @param timeout   超时时间
 @param bluetoothStatusChangeBlock 蓝牙状态变化回调
 @param bluetoothDataChangeBlock 数据获取回调
 */
- (void)fetchBLEConnect:(NSString *_Nonnull) device_id
               deviceSN:(NSString *_Nonnull) device_sn
                   uuid:(NSString *_Nonnull) uuid
                 params:(MCUserInfo *_Nullable) userInfo
                timeout:(int) timeout
        bluetoothStatus:(BluetoothStatusChangeBlock _Nonnull) bluetoothStatusChangeBlock
            responedata:(BluetoothDataChangeBlock _Nonnull) bluetoothDataChangeBlock;

/**
 停止扫描设备
 
 @param device_id 设备id
 */
- (void)stopScanBLEDevice:(NSString *_Nonnull)device_id;

/**
 断开当前设备连接设备
 ### note: 断开设备的方法并不一定全部有效，当无法再次获取到数据的时候，可以尝试调用断开连接方法或者手动断开连接 重新连接尝试获取数据
 
 @param device_id 设备id
 */
- (void)disconnectBLEDevice:(NSString *_Nonnull) device_id ;

/**
 断开所有连接 有返回蓝牙状态
 */
- (void)disconnectBLEAll;

/**
 断开当前设备连接设备
 ### note: 断开设备的方法并不一定全部有效，当无法再次获取到数据的时候，可以尝试调用断开连接方法或者手动断开连接 重新连接尝试获取数据
 
 @param device_id 设备id
 */
- (void)disconnectBLEDevice:(NSString *_Nonnull) device_id  bluetoothStatus:(BluetoothStatusBlock _Nonnull) bluetoothStatusChangeBlock;

///**
// 断开所有连接 有返回蓝牙状态
// */
//- (void)disconnectBLEAllWithBluetoothStatus:(BluetoothStatusBlock _Nonnull) bluetoothStatusChangeBlock;
//

#pragma mark - 获取设备数据API方式

/**
 获取设备数据
 
 @param device_sn   设备sn
 @param device_no   设备唯一标识符
 @param function_id 获取数据类型
 @param startTime   开始时间  long时间 毫秒时间
 @param endTime     结束时间  long时间 毫秒时间
 @param queryCompleteBlock 响应处理
 
 返回数组 NSMutableArray<MCData *> *   MCData以及子类
 */
- (void)fetchApiDeviceData:(NSString *_Nullable) device_sn
                 device_no:(NSString *_Nullable) device_no
                functionId:(PeripheralsDataType) function_id
                 startTime:(long long) startTime
                       end:(long long) endTime
             queryComplete:(QueryCompleteBlock _Nonnull) queryCompleteBlock;

/**
 获取用户绑定设备最新数据(只返回一条)
 返回数组  NSMutableArray<MCDeviceData *> *
 */

- (void)fetchApiDeviceAllNewData:(QueryCompleteBlock _Nonnull) queryCompleteBlock;

/**
 模糊搜索设备 - 罗志平
 */
-(void)fetchDevice:(NSString *_Nullable)typeId Keyword:(NSString *_Nullable)keyword result:(FetchDeviceBlock _Nonnull) fetchDeviceBlock;

/**
 获取设备详情 - 罗志平
 */
-(void)fetchDeviceDetail:(NSString *_Nullable)deviceSN result:(FetchDeviceDetailBlock _Nonnull) fetchDeviceDetailBlock;

/**
 解除绑定所有设备 - 罗志平
 @param userIdentity 用户ID
 @param device_sn 设备sn
 @param device_no 分为两种 1.数据列表里获取到的是device_no 2.绑定设备返回的device_no
 @param bindBlock 绑定回调
 */
- (void)unbindAllDevice:(NSString *_Nullable)userIdentity resultBlock:(RequestCompleteBlock _Nullable )resultBlock;

#pragma mark - MD5&SHA256签名
- (NSString *_Nullable)paramsForSign:(NSString *_Nullable)paramString encryptType:(EncryptType)encrypt;

#pragma mark - 获取wifi列表
- (NSMutableArray *_Nullable)getWifiNameList;

#pragma mark - wifi连接尿检仪设备（HiPee）
- (void)fetchWifiConnection:(NSString *_Nullable)wifiName wifiPwd:(NSString *_Nullable)wifiPwd  responedata:(BluetoothDataChangeBlock _Nonnull) bluetoothDataChangeBlock;

#pragma mark - 开始录音（请求录音权限）(清享睡眠枕)
- (void)beginRecordResponedata:(BluetoothDataChangeBlock _Nonnull) bluetoothDataChangeBlock;

#pragma mark - 结束录音返回数据(清享睡眠枕)
- (void)stopRecordResponedata:(BluetoothDataChangeBlock _Nonnull) bluetoothDataChangeBlock  deviceSN:(NSString *_Nonnull) device_sn
                         uuid:(NSString *_Nonnull) uuid;

#pragma mark - 获取本机运动数据
- (void)FetchLocalSportData:(GetLocalSportDataEnum)getLocalSportDataEnum bluetoothDataChangeBlock:(BluetoothDataChangeBlock _Nonnull) bluetoothDataChangeBlock;
@end
