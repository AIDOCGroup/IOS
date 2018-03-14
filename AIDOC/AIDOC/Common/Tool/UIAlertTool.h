//
//  UIAlertTool.h
//  AIDOC
//
//  Created by app on 18/1/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UIAlertTool : NSObject<UIAlertViewDelegate>

-(void)showAlertView:(UIViewController *)viewController :(NSString *)title :(NSString *)message :(NSString *)cancelButtonTitle :(NSString *)otherButtonTitle :(void (^)())confirm :(void (^)())cancle;

-(void)showShareAlertView:(NSString *)title :(NSString *)desc :(void (^)())confirm;

-(void)showAlertViewOne:(UIViewController *)viewController :(NSString *)title :(NSString *)message :(NSString *)cancelButtonTitle :(NSString *)otherButtonTitle :(void (^)())confirm :(void (^)())cancle;

-(void)showAlertViewOne:(NSString *)title :(NSString *)desc :(void (^)())confirm;

-(void)showHtmlDialog:(NSString *)title :(NSString *)desc :(NSString *)confirmTitle :(NSString *)jsFunction :(void (^)())confirm;

-(void)showMapAlertView:(NSString *)title :(NSString *)desc :(NSString *)buttonLeftTitle :(NSString *)buttonRightTitle :(void (^)())confirm :(void (^)())cancle;

-(void)showStaySuccessView:(NSString *)name;

@end
