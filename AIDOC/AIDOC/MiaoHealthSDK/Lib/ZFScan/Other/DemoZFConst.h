//
//  ZFConst.h
//  ScanBarCode
//
//  Created by apple on 16/3/7.
//  Copyright © 2016年 apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "DemoZFColor.h"
#import "UIImage+DemoZirkfied.h"

#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height

/**
 *  导航栏高度
 */
extern CGFloat const DemoNAVIGATIONBAR_HEIGHT;

/**
 *  tabBar高度
 */
extern CGFloat const DemoTABBAR_HEIGHT;

/**
 *  扫描透明框比例
 */
extern CGFloat const DemoZFScanRatio;

@interface DemoZFConst : NSObject

@end
