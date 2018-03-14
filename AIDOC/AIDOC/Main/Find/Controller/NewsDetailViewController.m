//
//  NewsDetailViewController.m
//  AIDOC
//
//  Created by app on 18/1/17.
//  Copyright © 2018年 app. All rights reserved.
//

#import "NewsDetailViewController.h"

@interface NewsDetailViewController ()

@end

@implementation NewsDetailViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.title = @"资讯详情";
    
    UIButton *shareNewsBtn = [[UIButton alloc] initWithFrame:CGRectMake(kScreenWidth - 30, 12, 20, 20)];
//    shareNewsBtn.imageEdgeInsets = UIEdgeInsetsMake(6, -30, 6, 0);
    [shareNewsBtn setImage:[UIImage imageNamed:@"shareNews_@x2"] forState:UIControlStateNormal];
    [shareNewsBtn addTarget:self action:@selector(shareNews) forControlEvents:UIControlEventTouchUpInside];
    shareNewsBtn.contentHorizontalAlignment = UIControlContentHorizontalAlignmentRight;
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:shareNewsBtn];
    
}


//分享新闻
- (void)shareNews{

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
