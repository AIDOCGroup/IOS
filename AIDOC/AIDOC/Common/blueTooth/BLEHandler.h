//
//  BLEHandler.h
//  TestTxt
//
//  Created by zhuoting on 15-4-9.
//  Copyright (c) 2015年 zhuoting. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <UIKit/UIKit.h>
#import "LongSitInfo.h"
#import "NotDisturbInfo.h"
#import "Timing.h"



/*!
 *  @enum YCDevicesSate
 *
 *  @discussion 设备状态
 *
 *  @constant YCDevicesSateConnected             设备已经连接状态
 *  @constant YCDevicesSateDisconnected          设备已经断开状态，如有错误码，请查看YCErrorCode
 */
typedef NS_ENUM(NSInteger, YCDevicesSate) {
    YCDevicesSateConnected = 0,
    YCDevicesSateDisconnected,
};


/*!
 *  @enum YCBluetoothSate
 *
 *  @discussion 手机蓝牙状态
 *
 *  @constant YCBluetoothSateOpen       手机蓝牙打开
 *  @constant YCBluetoothSateClose      手机蓝牙关闭
 *  @constant YCBluetoothSateResetting  手机蓝牙重启
 */
typedef NS_ENUM(NSInteger, YCBluetoothSate) {
    YCBluetoothSateOpen = 0,
    YCBluetoothSateClose,
    YCBluetoothSateResetting,
};


/*
 *
 *
 */
typedef NS_ENUM(NSInteger, YCSate) {
    YCSuccess = 0,
    YCFail,
    YCBusy,
};


/*
 *
 *
 */
typedef NS_ENUM(NSInteger, YCSportType) {
    YCSportWalk = 0,
    YCSportRun,
    YCSportRiding,
    YCSportBodybuilding,
};



/*!
 *  @enum YCQueryType
 *
 *  @discussion 查找数据类型
 *
 *  @constant YCQueryTypeSport      运动数据
 *  @constant YCQueryTypeSleep      睡眠数据
 *  @constant YCQueryTypeHRM        心率数据
 *  @constant YCQueryTypeBoold      血压数据
 */
typedef NS_ENUM(NSInteger, YCQueryType) {
    YCQueryTypeSport = 0,
    YCQueryTypeSleep,
    YCQueryTypeHRM,
    YCQueryTypeBoold,
};

typedef NS_ENUM(NSInteger, YCSetType) {
    YCSetSyncTime = 0,
    YCSetUserInfo,
    YCSetStepTarget,
    YCSetSleepTarget,
};

/*!
 *  @enum YCWeightUnit
 *
 *  @discussion 重量单位
 *
 *  @constant YCWeightKg
 *  @constant YCWeightIb
 */
typedef NS_ENUM(NSInteger, YCWeightUnit) {
    YCWeightKg = 0,
    YCWeightIb,
    YCWeightSt,
};

/*!
 *  @enum YCTimeUnit
 *
 *  @discussion 时间单位
 *
 *  @constant YCTime12
 *  @constant YCTime24
 */
typedef NS_ENUM(NSInteger, YCTimeUnit) {
    YCTime24 = 0,
    YCTime12,
};

/*!
 *  @enum YCLengthUnit
 *
 *  @discussion 长度单位
 *
 *  @constant YCLengthKm
 *  @constant YCLengthMile
 */
typedef NS_ENUM(NSInteger, YCLengthUnit) {
    YCLengthKm = 0,
    YCLengthMile,
};

/*!
 *  YCManagerDelegate 代理
 */

@protocol YCManagerDelegate <NSObject>

@optional

/**
 *  @discussion 每找到一个设备，就会调用一次
 *
 *  @param peripheral 设备属性模型
 */
- (void)YCManagerDiscoverDevices:(CBPeripheral *)peripheral;

/**
 *  @discussion 时时监听了已连接设备状态
 *
 *  @param devicesState 设备状态
 *  @param error        错误码
 */
- (void)YCManagerDevicesSate:(YCDevicesSate)devicesState error:(NSError *)error;

/**
 *  @discussion 时时监听了蓝牙连接状态
 *
 *  @param bluetoothState 蓝牙状态
 */
- (void)YCManagerBluetoothState:(YCBluetoothSate)bluetoothState;


/**
 *数据同步
 */

- (void)YCManagerSyncMsg:(NSMutableArray *)msgList dataType:(YCQueryType)type state:(YCSate)state;


/**
 *实时数据
 *距离单位米
 */
- (void)YCManagerSyncStep:(int)step kcal:(int)kcal des:(int)des;


/**
 *设置信息回调
 */
- (void)YCManagerSyncSet:(YCSate)state;

/**
 *power,0正常电量，1低电量，2正在充电
 *
*/
- (void)YCPower:(int)deviceID subVersion:(int)subVersion mainverison:(int)mainverison electricityStatus:(int)electricityStatus electricity:(int)electricity bindstatus:(int)bindstatus synchronizedFlag:(int)synchronizedFlag;


/**
 *mac地址
 *
*/
- (void)YCMac:(NSString *)Mac;
    
    
/**
 *设备名字
 *
*/
- (void)YCDevName:(NSString *)name;

/**
 *设备支持功能
 *fun1,主要功能 1
 *fun2,主要功能 2
 *fun3,闹钟个 数
 *fun4,闹钟 醒 支持类型
 *fun5,信息 醒 1
 *fun6,信息 醒 2
 *fun7,其它功能
 *转化成二进制，功能对应文档
 */

- (void)YCSupportFunctions:(NSInteger)fun1 fun2:(NSInteger)fun2 fun3:(NSInteger)fun3 fun4:(NSInteger)fun4 fun5:(NSInteger)fun5 fun6:(NSInteger)fun6 fun7:(NSInteger)fun7;

/**
 *ecg回调
 *
 */
- (void)YCECG:(NSData *)data;

/**
 *心电血压回调
 *
 */
- (void)YCECGBlood:(NSInteger)hr mmHg1:(NSInteger)mmHg1 mmHg2:(NSInteger)mmHg2;
    
    
    
/**
*运动心率上报
 *
*/
- (void)YCSportHr:(NSInteger)hr;

/**
 *查询闹钟列表
 */
- (void)YCManagerSyncAlarm:(NSMutableArray *)msgList state:(YCSate)state;
@end


@interface BLEHandler : NSObject<CBCentralManagerDelegate,CBPeripheralDelegate,UIAlertViewDelegate>


+ (BLEHandler *)sharedBLEHandler;

@property (weak,nonatomic) id<YCManagerDelegate> delegate;

/**
 *当前链接的设备
 */
@property (strong,nonatomic) CBPeripheral *cbPeripheral;

/**
 *  设备连接状态
 */
@property (nonatomic,assign) BOOL     isConnected;

/**
 *  设备是否在同步数据（步数、睡眠、心率）
 */
@property (nonatomic,assign,readonly) BOOL  isSyncDevices;

-(void)send:(NSData *)data;

-(void)conBle:(CBPeripheral *)peripheral;


-(void)startScan;

-(void)stopScan;

-(void)closeBLE;


//同步运动
-(void)syncSport:(BOOL)isDele;

//同步睡眠
-(void)syncSleep:(BOOL)isDele;

//同步心率
-(void)syncHeart:(BOOL)isDele;

//同步血压
-(void)syncBlood:(BOOL)isDele;


//同步时间
-(void)syncCurrentTime;

//发送ios端
-(void)sendIosDev;

//关闭实时步数
-(void)closeSyncStep;

//实时同步步数
-(void)openSyncStep;

//个人信息
/**
 * age,6-120
 * sex,0男，1女
 * height，100-250cm
 * weight,30-200kg
 */
-(void)sendPerson:(NSInteger)height weight:(NSInteger)weight sex:(NSInteger)sex age:(NSInteger)age;

//设置目标步数
-(void)stepTarget:(NSInteger)step;

/**
 *hour,0-23
 *min,0-59
 */
-(void)sleepTarget:(NSInteger)hour min:(NSInteger)min;

/**
 *0,英文，1中文
 */
-(void)sendLanguage:(NSInteger)index;

/**
 *还原出厂
 */

-(void)sendReset;

/**
 *翻腕,1打开，0关闭
 */
-(void)sendFw:(NSInteger)index;


/**
 *佩带,1右手，0左手
 */
-(void)sendPdHand:(NSInteger)index;

//自动心率检测设置，time=0时关闭
-(void)autoHeard:(NSInteger )time;


//关闭通知
-(void)sendNotClose;
//手机防丢，调用手表震动
-(void)sendDeviceLost;


//防丢报警,0关闭，1打开
-(void)sendPhoneLost:(NSInteger)index;


/**
 *危险心率警报，isopen是否打开，heartTimes警报心跳次数
 */
-(void)sendDanHeart:(BOOL)isopne heartTimes:(NSInteger)heartTimes;

//屏幕亮度设置0，1，2
-(void)sendBrightness:(NSInteger)index;

//肤色设置
//0:白色,1:白黄色,2:黄色,3:棕色,4:褐色,5:黑色
-(void)SkinColour:(NSInteger)index;

//通知
//NSMutableArray 添加[NSNumber numberWithBool:YES]15个,位置开关对应下面
//0位推送总开关，1:来电，2:短信,3:邮件,4:微信,5:QQ,6:新浪微博,7:facebook,8:twitter,9:Messenger,10:WhatsAPP,11:Linked in,12:Instagram,13:Skype,14:Line
-(void)sendNotopen:(NSMutableArray *)alist;


//久坐提醒
-(void)sendLongSit:(LongSitInfo *)longsitinfo;

//勿扰时段
-(void)sendNotDistur:(BOOL)isopen notDistur:(NotDisturbInfo *)notDistur;

//翻腕,1打开，0关闭
-(void)setWristSense:(NSInteger)open;

//闹钟查询
-(void)checkAlarmInfo;

//删除闹钟
-(void)delClock:(Timing *)tim;

//设置闹钟
-(void)setClock:(Timing *)tim;

//修改闹钟
-(void)changeClock:(Timing *)otim ntim:(Timing *)ntim;

//断开链接
-(void)disconnect;
    
//单位设置
-(void)setUnit:(YCLengthUnit)length weight:(YCWeightUnit)weight time:(YCTimeUnit)time;

//获取电量，版本号
-(void)getPowerAndVersion;
    
//获取Mac地址
-(void)getMac;
    
//获取设备名字
-(void)getDevName;

//获取设备信息
-(void)getDevMsg;

//有氧教练
-(void)aerobicCoach:(int)type index:(int)index time:(int)time maxhr:(int)maxhr minhr:(int)minhr;

//血压设定
-(void)BPCalibration:(int)mmHg1 mmHg2:(int)mmHg2;

//血压测量
//    0x00: 关闭 0x01: 单次测试 0x02: 监测模式
-(void)BPmeasure:(int)type;

//心率测量
//    0x00: 关闭 0x01: 单次测试 0x02: 监测模式
-(void)HRMeasure:(int)type;

//获取设备支持列表
-(void)getSupportFunctions;

//解除绑定
-(void)unbindDevice;
    
//设置运动模式,1开始，0结束
-(void)setSportType:(YCSportType)type open:(int)open;

//设置系统版本号
-(void)setmobileOSindevice;

//ecg波形，2打开，0关闭
-(void)startECG:(NSInteger)open;
/**
 *day日期
 *fengli风力
 *high高温
 *low低温
 *fengxiang风向
 *type天气类型，如晴，多云，小雨...
 *
 */
-(void)setWeather:(NSString *)day fengli:(NSString *)fengli high:(NSString *)high low:(NSString *)low fengxiang:(NSString *)fengxiang type:(NSString *)type;


//消息提醒
-(void)sendMesAlert:(NSInteger)mesAlert title:(NSString *)title content:(NSString *)content;
    
    
@end
