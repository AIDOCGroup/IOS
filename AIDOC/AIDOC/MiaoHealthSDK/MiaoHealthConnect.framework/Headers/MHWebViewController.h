//
//  ViewController.h
//  OC与JS交互之WKWebView
//
//  Created by user on 16/8/18.
//  Copyright © 2016年 rrcc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

typedef NS_ENUM(NSInteger, ComeFromEnum) { //首页 or 子页
    ComeFromEnumHome, //首页
    ComeFromEnumChild, //子页
};

@interface MHWebViewController : UIViewController

@property (nonatomic , copy) NSString *openSecret;

@property (nonatomic , copy) NSString *url;

@property (nonatomic, strong) WKWebView *wkWebView;

//YES: 用网页的title作为控制器的title
@property (nonatomic , assign) BOOL useWebTitle;

//YES: 需要进度条
@property (nonatomic , assign) BOOL needProgress;

// 首页 or 子页 进来
@property (nonatomic , assign) ComeFromEnum comeFromEnum;
//
//@property (nonatomic , assign) BOOL hiddenNavgationBar;
// 首页状态栏颜色
//@property (nonatomic , copy) UIColor *homeStatusBarColor;

@end


