//
//  WebViewController.h
//  MiaoHealthConnectDemo
//
//  Created by 刘云梦 on 17/2/22.
//  Copyright © 2017年 刘云梦. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MiaoHealthConnect/MiaoHealthConnect.h>


@interface WebViewController : BaseViewController<UIWebViewDelegate>

@property (nonatomic, strong) MCDevice *device;

@property (nonatomic , copy) void (^showMessage)(NSString *message,NSString *device_no);

@end
