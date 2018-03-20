//
//  SleepSDK.h
//  sleep
//
//  Created by 123 on 2017/9/6.
//  Copyright © 2017年 SHNSKJ-sleep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SleepResultCallBackModel.h"
#import <AVFoundation/AVFoundation.h>

@protocol SleepSDKDelegate <NSObject>
//打印出来方便查看录音哪个时间断掉的
- (void)callBackThisTimeRecordingIsActive:(int)time;

@end

@interface SleepSDK : NSObject

/**
 * 使用说明
 * 使用前先在controller的初始化viewDidLoad里面检测麦克风权限是否有打开（必须，下面一行代码）
 *[AVCaptureDevice requestAccessForMediaType:AVMediaTypeAudio completionHandler:^(BOOL granted) {
 NSLog(@"%@",granted ? @"麦克风准许":@"麦克风不准许");
 }];
 * 单例初始化
 * 设置需求参数
 * 打开重力检测器
 * 打开声音检测器
 * 停止检测并返回所有数据
 */

/**
* 判断SDK是否正在录音
*/
@property (nonatomic,assign) BOOL isRecording;
/**
* SDK用到的录音类
*/
@property (nonatomic,strong) AVAudioRecorder    * recorder;
/**
* 回调检测的代理
*/
@property (nonatomic, assign) id<SleepSDKDelegate>delegate;
/**
* 是否开启梦话记录功能 默认不开启 值为NO
*/
@property (nonatomic,assign) BOOL isRecordDaydream;

/**
* 设置默认的用户唯一识别码  后面的增删改查都针对这一个用户操作  要操作谁的数据  这里重新设置一下唯一识别码即可
*/
@property (nonatomic,copy) NSString * userIdentifier;

/**
 * 环境噪音阀值（分贝 这里默认的70 当长时间超过这个分贝值会判断环境噪音不正常 根据实际需求调节）
 */
@property (nonatomic,assign) double noiseAbnormalValue;

/**
 * 当录音时间小于这个值的时候不进行数据统计 根据实际需求调节 (秒) 默认3600秒
 */
@property (nonatomic,assign) int noStatisticsValue;

/**
 * 单例初始化
 */
+(instancetype)shareSleepSDK;

/**
 * 打开重力检测器 success判断是否有成功打开
 */
- (void)openCoreMotionIsSuccess:(void (^)(BOOL))success;

/**
 * 打开环境声音检测器 success判断是否有成功打开
 */
- (void)starRecordIsSuccess:(void (^)(BOOL))success;

/**
 * 如果数据搜集停止 可以调用这个方法接着之前已保存的数据继续搜集
 */
- (void)reAgainRecordIsSuccess:(void (^)(BOOL))success;

/**
  停止检测并返回所有参数
  startSleepTime 开始睡眠时间戳
  startSleepDuration 入睡时长，后面的统一为秒 转换小时除以3600
  sleepDuration 总的睡眠时长
  ambientNoise 环境噪音 BOOL
  deepSleep 深睡时间
  lightSleep 浅睡时间
  wakeDream 醒/梦时间
  bodyMovement 体动次数
  sleepGrade 睡眠评分
 
  detailDatasqliteAddress 详细数据的数据库保存地址
  totleDataAddress        统计后的数据库保存地址
  wavAddress              录音的保存地址
 */
- (void)stopRecordAndBackData:(void (^)(SleepResultCallBackModel *model))callBackData;


/**
 * 查询某一天的睡眠质量  查询的时间段是当天0点到24点
 * 传入年月日  YYYY-MM-dd
   startSleepTime 开始睡眠时间戳
   endSleepTime 结束睡眠时间戳
   startSleepDuration 入睡时长，后面的统一为秒 转换小时除以3600
   sleepDuration 总的睡眠时长
   ambientNoise 环境噪音 BOOL
   deepSleep 深睡时间
   lightSleep 浅睡时间
   wakeDream 醒/梦时间
   bodyMovement 体动次数
   sleepGrade 睡眠评分
 
   detailDatasqliteAddress 详细数据的数据库保存地址
   totleDataAddress        统计后的数据库保存地址
   wavAddress              录音的保存地址
 
   isExist                 回调判断是否有当天的数据
 */
- (void)SearchYearMonthDay:(NSString *)day AndBackData:(void (^)(SleepResultCallBackModel *model,BOOL isExist))callBackData;

/**
 * 返回数据模型数组 day传每周第一天0点的时间戳
 */
- (void)SearchWeek:(NSString *)day AndBackData:(void (^)(NSMutableArray *dayMutableArray,BOOL isExist))callBackData;

/**
 * 返回数据模型数组 day传月内某一天时间戳
 */
- (void)SearchMonth:(NSString *)day AndBackData:(void (^)(NSMutableArray *dayMutableArray,BOOL isExist))callBackData;

/**
 * 清除本地的音频文件
 */
- (void)cleanRecording;


@end
