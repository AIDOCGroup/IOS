//
//  AppDelegate.m
//  AIDOC
//
//  Created by app on 18/1/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import "AppDelegate.h"
#import "LoginViewController.h"
#import "HelpViewController.h"
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    //注册登录状态监听
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(initApp:)
                                                 name:KNOTIFICATION_LOGINCHANGE
                                               object:nil];

    if ([CommonFunc isLogin]) {//登陆成功加载主窗口控制器
        UINavigationController *navigationController = nil;
        //加载申请通知的数据
        if (self.mainController == nil) {
            //            self.mainController = [[MainViewController alloc] init];
            //            navigationController = [[UINavigationController alloc] initWithRootViewController:self.mainController];
            
            self.mainController = [[MainViewController alloc] init];
            
            [self.window setRootViewController:self.mainController];
            [self.mainController setSelectedIndex:0];
            
        }else{
            navigationController  = self.mainController.navigationController;
            
            self.window.rootViewController = navigationController;
        }
        
    }
    else{
        
        LoginViewController *loginVC = [[LoginViewController alloc] init];
        UINavigationController *loginNav = [[UINavigationController alloc] initWithRootViewController:loginVC];
        self.window.rootViewController = loginNav;
        [self.window makeKeyAndVisible];
    }
    

    //引导图
    if ([[CommonFunc sharedCommonFunc] initial]!= PM_CHAT_INITIAL) {
        
        HelpViewController *helpVC = [HelpViewController new];
        [self.window addSubview:helpVC.view];
        [[self.window rootViewController] presentViewController:helpVC animated:NO completion:^{
            
        }];
        
    }

    return YES;
}


- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
{
    if (_mainController) {
        [_mainController jumpToChatList];
    }
}

- (void)initApp:(NSNotification *)notification{
    BOOL loginSuccess = [notification.object boolValue];
    UINavigationController *navigationController = nil;
    if (loginSuccess) {//登陆成功加载主窗口控制器
        //加载申请通知的数据
        //        [[ApplyViewController shareController] loadDataSourceFromLocalDB];
        if (self.mainController == nil) {
            //            self.mainController = [[MainViewController alloc] init];
            //            navigationController = [[UINavigationController alloc] initWithRootViewController:self.mainController];
            
            self.mainController = [[MainViewController alloc] init];
            
            [self.window setRootViewController:self.mainController];
            [self.mainController setSelectedIndex:0];
            
        }else{
            navigationController  = self.mainController.navigationController;
            
            self.window.rootViewController = navigationController;
        }
    }
    else{//登陆失败加载登陆页面控制器
        if (self.mainController) {
            [self.mainController.navigationController popToRootViewControllerAnimated:NO];
        }
        self.mainController = nil;
        
        LoginViewController *loginController = [[LoginViewController alloc] init];
        navigationController = [[UINavigationController alloc] initWithRootViewController:loginController];
        //        [self clearParse];
        self.window.rootViewController = navigationController;
    }
    
    //设置7.0以下的导航栏
    if ([UIDevice currentDevice].systemVersion.floatValue < 7.0){
        navigationController.navigationBar.barStyle = UIBarStyleDefault;
//        [navigationController.navigationBar setBackgroundImage:[UIImage imageNamed:@"titleBar"]
//                                                 forBarMetrics:UIBarMetricsDefault];
        [navigationController.navigationBar.layer setMasksToBounds:YES];
        self.window.rootViewController = navigationController;
    }
    
    
}
- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
