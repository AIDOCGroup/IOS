//
//  BaseViewController.m
//  AIDOC
//
//  Created by app on 18/1/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import "BaseViewController.h"

@interface BaseViewController ()

@end

@implementation BaseViewController


- (void)viewDidLoad {
    
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.navigationController.navigationBarHidden = NO;
    
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];

    if ([self respondsToSelector:@selector(setEdgesForExtendedLayout:)])
    {
        [self setEdgesForExtendedLayout:UIRectEdgeNone];
        self.automaticallyAdjustsScrollViewInsets = NO;
        
    }
    
    //设置标题字体大小及颜色
    [self.navigationController.navigationBar setTitleTextAttributes:
     @{NSFontAttributeName:[UIFont systemFontOfSize:18],
       NSForegroundColorAttributeName:[UIColor darkGrayColor]}];

    
    int count = (int)self.navigationController.viewControllers.count;
    if (count > 1) {
        UIImage *backImg = [UIImage imageNamed:@"back_icon"];
        _button = [[UIButton alloc] initWithFrame:CGRectMake(0, 7, 30, 30)];
        _button.imageEdgeInsets = UIEdgeInsetsMake(6, -30, 6, 0);
        [_button setImage:backImg forState:UIControlStateNormal];
        [_button addTarget:self action:@selector(backAction) forControlEvents:UIControlEventTouchUpInside];
        UIBarButtonItem *backItem = [[UIBarButtonItem alloc] initWithCustomView:_button];
        self.navigationItem.leftBarButtonItem = backItem;
    }
    
}

- (void)backAction
{
    [self.navigationController popViewControllerAnimated:YES];
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
