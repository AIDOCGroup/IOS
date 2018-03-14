//
//  MainViewController.m
//  AIDOC
//
//  Created by app on 18/1/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import "MainViewController.h"
#import "SportsViewController.h"
#import "StoreViewController.h"
#import "BaseNavigationController.h"
#import "TianyiViewController.h"
#import "FindViewController.h"
#import "MeViewController.h"


@interface MainViewController ()
{
    SportsViewController *_sportsVC;
    StoreViewController *_storeVC;
    TianyiViewController *_tianyiVC;
    FindViewController *_findVC;
    MeViewController *_meVC;
}

@end

@implementation MainViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
//    self.tabBar.backgroundColor = [UIColor redColor];

    self.view.backgroundColor = [UIColor whiteColor];
    //创建Tabbar
    [self setupSubviews];

}

- (void)setupSubviews
{
    self.tabBar.tintColor = rgbColor(0x08a4d8);
    
    _sportsVC = [[SportsViewController alloc] initWithNibName:nil bundle:nil];
    _sportsVC.tabBarItem = [[UITabBarItem alloc] initWithTitle:@"运动"
                                                        image:nil
                                                          tag:0];
    [_sportsVC.tabBarItem setFinishedSelectedImage:[UIImage imageNamed:@"tab_icon_01_h"]
                      withFinishedUnselectedImage:[UIImage imageNamed:@"tab_icon_01"]];
    [self unSelectedTapTabBarItems:_sportsVC.tabBarItem];
    [self selectedTapTabBarItems:_sportsVC.tabBarItem];
    
    _storeVC = [[StoreViewController alloc] initWithNibName:nil bundle:nil];
    _storeVC.tabBarItem = [[UITabBarItem alloc] initWithTitle:@"商城"
                                                       image:nil
                                                         tag:1];
    [_storeVC.tabBarItem setFinishedSelectedImage:[UIImage imageNamed:@"tab_icon_02_h"]
                     withFinishedUnselectedImage:[UIImage imageNamed:@"tab_icon_02"]];
    [self unSelectedTapTabBarItems:_storeVC.tabBarItem];
    [self selectedTapTabBarItems:_storeVC.tabBarItem];
    
    

    
    
    _tianyiVC = [[TianyiViewController alloc] initWithNibName:nil bundle:nil];
    _tianyiVC.tabBarItem = [[UITabBarItem alloc] initWithTitle:@"天医"
                                                           image:nil
                                                             tag:2];
    [_tianyiVC.tabBarItem setFinishedSelectedImage:[UIImage imageNamed:@"tab_icon_04_h"]
                         withFinishedUnselectedImage:[UIImage imageNamed:@"tab_icon_04"]];
    [self unSelectedTapTabBarItems:_tianyiVC.tabBarItem];
    [self selectedTapTabBarItems:_tianyiVC.tabBarItem];
    
    
    _findVC = [[FindViewController alloc] initWithNibName:nil bundle:nil];
    //        [_findVC networkChanged:_connectionState];
    _findVC.tabBarItem = [[UITabBarItem alloc] initWithTitle:@"发现"
                                                       image:nil
                                                         tag:3];
    [_findVC.tabBarItem setFinishedSelectedImage:[UIImage imageNamed:@"tab_icon_03_h"]
                     withFinishedUnselectedImage:[UIImage imageNamed:@"tab_icon_03"]];
    [self unSelectedTapTabBarItems:_findVC.tabBarItem];
    [self selectedTapTabBarItems:_findVC.tabBarItem];
    
    
    _meVC = [[MeViewController alloc] init];
    _meVC.tabBarItem = [[UITabBarItem alloc] initWithTitle:@"我"
                                                     image:nil
                                                       tag:4];
    [_meVC.tabBarItem setFinishedSelectedImage:[UIImage imageNamed:@"tab_icon_05_h"]
                   withFinishedUnselectedImage:[UIImage imageNamed:@"tab_icon_05"]];
    _meVC.view.autoresizingMask = UIViewAutoresizingFlexibleHeight;
    
    [self unSelectedTapTabBarItems:_meVC.tabBarItem];
    [self selectedTapTabBarItems:_meVC.tabBarItem];
    
    self.viewControllers = @[_sportsVC,_storeVC,_tianyiVC,_findVC, _meVC];
    
    for (UIViewController *vc in self.viewControllers) {
        //        vc.hidesBottomBarWhenPushed = YES;
        BaseNavigationController *navigation = [[BaseNavigationController alloc]
                                                initWithRootViewController:vc];
        
        //将导航控制器作为当前控制器的子控制器
        [self addChildViewController:navigation];
        
        //        navigation.delegate = self;
        float height = kScreenHeight - 20;
        //调整自控制器视图的framed
        navigation.view.frame = CGRectMake(0, 0, kScreenWidth, height);
    }
}


//为选中时字体的颜色
-(void)unSelectedTapTabBarItems:(UITabBarItem *)tabBarItem
{
    
    [tabBarItem setTitleTextAttributes:[NSDictionary dictionaryWithObjectsAndKeys:
                                        [UIFont systemFontOfSize:11], UITextAttributeFont,[UIColor lightGrayColor],UITextAttributeTextColor,
                                        nil] forState:UIControlStateNormal];
}

//选中时字体的颜色
-(void)selectedTapTabBarItems:(UITabBarItem *)tabBarItem
{
    [tabBarItem setTitleTextAttributes:[NSDictionary dictionaryWithObjectsAndKeys:
                                        [UIFont systemFontOfSize:11],
                                        UITextAttributeFont,rgbColor(0x08a4d8),UITextAttributeTextColor,
                                        nil] forState:UIControlStateSelected];
}

- (void)jumpToChatList{

}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
