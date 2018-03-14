//
//  HistoryViewController.m
//  AIDOC
//
//  Created by app on 18/1/16.
//  Copyright © 2018年 app. All rights reserved.
//

#import "HistoryViewController.h"

@interface HistoryViewController ()

@end

@implementation HistoryViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //1.返回
    UIButton *backBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    backBtn.frame = CGRectMake(0, 7, 120, 30);   //#1#硬编码设置UIButton位置、大小
    //设置图片
    [backBtn setImage:[UIImage imageNamed:@"back_icon"] forState:UIControlStateNormal];
    backBtn.imageEdgeInsets = UIEdgeInsetsMake(6, -50, 8, 100);
    [backBtn addTarget:self action:@selector(backAction) forControlEvents:UIControlEventTouchUpInside];
    //设置文字
    NSString *buttonTitleStr = @"历史记录";
    [backBtn setTitle:buttonTitleStr forState:UIControlStateNormal];
    [backBtn setTitleColor:rgbColor(0x555555) forState:UIControlStateNormal];
    backBtn.titleLabel.font = [UIFont systemFontOfSize:18];
    //button标题的偏移量，这个偏移量是相对于图片的
    backBtn.titleEdgeInsets = UIEdgeInsetsMake(0, -80, 0, 0);
    [backBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    //leftBarButtonItem设置左边距
    UIBarButtonItem *backBtnI = [[UIBarButtonItem alloc] initWithCustomView:backBtn];
    UIBarButtonItem *negativeSpacer = [[UIBarButtonItem alloc]
                                       initWithBarButtonSystemItem:UIBarButtonSystemItemFixedSpace
                                       target:nil action:nil];
    negativeSpacer.width = 30;
    self.navigationItem.leftBarButtonItems = @[negativeSpacer,backBtnI];
    

}

//返回

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
