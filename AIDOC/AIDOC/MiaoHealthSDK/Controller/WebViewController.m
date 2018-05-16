//
//  WebViewController.m
//  MiaoHealthConnectDemo
//
//  Created by 刘云梦 on 17/2/22.
//  Copyright © 2017年 刘云梦. All rights reserved.
//

#import "WebViewController.h"

@interface WebViewController ()
@property (weak, nonatomic) UIWebView *webView;

@end

@implementation WebViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = self.device.device_name;
    self.automaticallyAdjustsScrollViewInsets = NO;
    self.view.backgroundColor = [UIColor whiteColor];
    UIWebView *webView = [[UIWebView alloc] initWithFrame:CGRectMake(0, kNavH, SCREEN_WIDTH, SCREEN_HEIGHT-kNavH)];//CGRectMake(0, kNavigationHeight.floatValue, kMainScreenWidth, kMainScreenHeight - kNavigationHeight.floatValue)
    webView.opaque = NO;
    webView.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:webView];
    self.webView = webView;
    __weak typeof(self) weakSelf = self;
    [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    [[MiaoHealthConnectManager shareInstance] bindWebDevice:_device.device_sn displayView:_webView bind:^(NSInteger isSuccess, id  _Nullable result, NSError * _Nullable error)  {
        [MBProgressHUD hideHUDForView:self.view animated:YES];
        NSString *content = isSuccess ? @"绑定成功" :  [NSString stringWithFormat:@"绑定失败:%@",error];
        self.showMessage(content,result);
        __strong typeof(self) srtongSelf = weakSelf;
        [srtongSelf.navigationController popViewControllerAnimated:YES];
    } networkStatusBlock:^(NetworkRequestStatus status) {
        [MBProgressHUD hideHUDForView:self.view animated:YES];
    }];
}

@end
