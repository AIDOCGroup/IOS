//
//  BaseNavigationController.h
//  AIDOC
//
//  Created by app on 18/1/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BaseNavigationController : UINavigationController<UINavigationControllerDelegate>
/**
 * 添加了移除从左向右滑动的手势
 */
-(void) removeViewGesture;
-(void)AddViewGesture;


@end
