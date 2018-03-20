//
//  TFScale.h
//  TFScale
//
//  Created by Yalin on 16/4/9.
//  Copyright © 2016年 tongfang. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for TFScale.
FOUNDATION_EXPORT double TFScaleVersionNumber;

//! Project version string for TFScale.
FOUNDATION_EXPORT const unsigned char TFScaleVersionString[];


/*
 注意1，此framework为动态库, 需要在项目的 Target -> 项目名 -> General -> Embedded Binaries 中点击“+“号 -> Add Other 添加此库，不然会报Image not found或者引入此头文件会找不到的错误。记得勾选 Copy Items if need，这样会自动添加引用framework的HeaderPath。
 
 注意2，在项目中需要设置 Target -> 项目名 -> Build Setting 中，将 Embedded Content Contains Swift Code 设置为YES
 
 注意3，此库需要依赖的系统库 CoreBluetooth。
 */


// SDK主入口
#import <TFScale/TFScaleManager.h>
#import <CoreBluetooth/CoreBluetooth.h> // 需引入蓝牙








// 以下是 umbrella header  忽略
#import <TFScale/VTFatScaleTestResult.h>
#import <TFScale/VScaleManager.h>
#import <TFScale/VTBTDefines.h>
#import <TFScale/VTEventModel.h>
#import <TFScale/VTProfile+Battery.h>
#import <TFScale/VTProfile+Control.h>
#import <TFScale/VTProfile+Findme.h>
#import <TFScale/VTProfile+Proximity.h>
#import <TFScale/VTViBeacon.h>
