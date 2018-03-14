//
//  UIImage+Category.h
//  PMChat
//
//  Created by 中组智库 on 15/7/21.
//  Copyright (c) 2015年 Eason. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Category)
/**
 *  图片拉伸
 *
 *  @param imageName 图片名称
 *  @param w         宽
 *  @param h         高
 *
 *  @return 拉伸后的图像
 */
+ (UIImage *)imageName:(NSString *)imageName stretchableImageWithLeftCapWidth:(CGFloat)w topCapHeight:(CGFloat)h;
/**
 *  图片裁剪
 *
 *  @param image   被采集图片
 *  @param newSize 大小
 *
 *  @return NSData
 */
- (NSData *)imageWithImage:(UIImage*)image scaledToSize:(CGSize)newSize;

/**
 *  修复拍照图片90°问题
 */
- (UIImage *)fixOrientation;

/**
 *  获取视频缩略图
 */
+(UIImage *)getThumbWithVideo:(NSString *)videoURL;

/**
 *  从颜色创建图片
 */
+(UIImage *)createImageWithColor:(UIColor*)color;

@end
