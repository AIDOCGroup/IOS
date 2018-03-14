//
//  ShareSportsViewController.m
//  AIDOC
//
//  Created by app on 18/1/16.
//  Copyright © 2018年 app. All rights reserved.
//

#import "ShareSportsViewController.h"

@interface ShareSportsViewController ()
{
    UIImageView *bgView;
    UILabel *kilocalorieLabel;//卡路里
    UILabel *timeLabel;//活跃时间
    UILabel *numLabel;//运动步数
}
@end

@implementation ShareSportsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
//    self.navigationController.navigationBarHidden = YES;
    [self _initView];
    [self _initFootView];
    
}

- (void)_initView{

    bgView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, kScreenHeight - 40)];
    bgView.image = [UIImage imageNamed:@"炫耀bg"];
    [self.view addSubview:bgView];
    
    //头像
    UIImageView *avaView = [[UIImageView alloc] initWithFrame:CGRectMake(30, 35, 42, 42)];
    //设置圆角
//    [avaView setClipsToBounds:YES];
//    avaView.layer.cornerRadius = avaView.height/2.0;//设置矩形四个圆角半径
    [avaView sd_setImageWithURL:[NSURL URLWithString:@""] placeholderImage:[UIImage imageNamed:@"头像_@x2"]];
    [bgView addSubview:avaView];
    
     UserInfoModel *usermodel = [CommonFunc getUserInformation];
    //用户名
    UILabel *nameLabel = [[UILabel alloc] initWithFrame:CGRectMake(avaView.right + 10, avaView.top+5, 200, 15)];
    nameLabel.text = usermodel.username;
    nameLabel.font = [UIFont systemFontOfSize:12];
    nameLabel.textColor = rgbColor(0xffffff);
    [bgView addSubview:nameLabel];
    //日期
    UILabel *dateLabel = [[UILabel alloc] initWithFrame:CGRectMake(avaView.right + 10, nameLabel.bottom, 200, 15)];
    dateLabel.text = @"2018-1-16";
    dateLabel.font = [UIFont systemFontOfSize:12];
    dateLabel.textColor = rgbColor(0xffffff);
    [bgView addSubview:dateLabel];

    float width = kScreenWidth/3.0;
    //千卡
    kilocalorieLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, bgView.bottom - 80, width, 30)];
    kilocalorieLabel.text = @"18";
    kilocalorieLabel.textColor = rgbColor(0xffffff);
    kilocalorieLabel.textAlignment = NSTextAlignmentCenter;
    kilocalorieLabel.font = [UIFont boldSystemFontOfSize:18];
    [bgView addSubview:kilocalorieLabel];
    
    UILabel *label11 = [[UILabel alloc] initWithFrame:CGRectMake(kilocalorieLabel.left, kilocalorieLabel.bottom, width, 20)];
    label11.text = @"卡路里";
    label11.textColor = rgbColor(0xffffff);
    label11.textAlignment = NSTextAlignmentCenter;
    label11.font = [UIFont systemFontOfSize:11];
    [bgView addSubview:label11];


    //活跃时间
    timeLabel = [[UILabel alloc] initWithFrame:CGRectMake(kilocalorieLabel.right, bgView.bottom - 80, width, 30)];
    timeLabel.text = @"01:10:56";
    timeLabel.textColor = rgbColor(0xffffff);
    timeLabel.textAlignment = NSTextAlignmentCenter;
    timeLabel.font = [UIFont boldSystemFontOfSize:18];
    [bgView addSubview:timeLabel];
    
    UILabel *label12 = [[UILabel alloc] initWithFrame:CGRectMake(timeLabel.left, timeLabel.bottom, width, 20)];
    label12.text = @"活跃时间";
    label12.textColor = rgbColor(0xffffff);
    label12.textAlignment = NSTextAlignmentCenter;
    label12.font = [UIFont systemFontOfSize:11];
    [bgView addSubview:label12];

    
    //千卡
    numLabel = [[UILabel alloc] initWithFrame:CGRectMake(timeLabel.right, bgView.bottom - 80, width, 30)];
    numLabel.text = @"2376";
    numLabel.textColor = rgbColor(0xffffff);
    numLabel.textAlignment = NSTextAlignmentCenter;
    numLabel.font = [UIFont boldSystemFontOfSize:18];
    [bgView addSubview:numLabel];
    
    UILabel *label13 = [[UILabel alloc] initWithFrame:CGRectMake(numLabel.left, numLabel.bottom, width, 20)];
    label13.text = @"步数";
    label13.textColor = rgbColor(0xffffff);
    label13.textAlignment = NSTextAlignmentCenter;
    label13.font = [UIFont systemFontOfSize:11];
    [bgView addSubview:label13];

}

- (void)_initFootView{
    //头像
    UIImageView *logoImgView = [[UIImageView alloc] initWithFrame:CGRectMake(20, bgView.bottom + 17, 50, 50)];
    //设置圆角
    logoImgView.image = [UIImage imageNamed:@"炫耀LOGO_@x2"];
    [self.view addSubview:logoImgView];
    
    UILabel *tYLabel = [[UILabel alloc] initWithFrame:CGRectMake(logoImgView.right + 10, logoImgView.top+5, 200, 15)];
    tYLabel.text = @"天医AIDOC";
    tYLabel.font = [UIFont boldSystemFontOfSize:18];
    tYLabel.textColor = rgbColor(0x0cb2f5);
    [self.view addSubview:tYLabel];
    //日期
    UILabel *descLabel = [[UILabel alloc] initWithFrame:CGRectMake(logoImgView.right + 10, tYLabel.bottom + 10, 200, 15)];
    descLabel.text = @"用行动，构建自己的智慧医生";
    descLabel.font = [UIFont systemFontOfSize:11];
    descLabel.textColor = rgbColor(0xd9d9d9);
    [self.view addSubview:descLabel];
    
    //二维码图片
    UIImageView *codeView = [[UIImageView alloc] initWithFrame:CGRectMake(kScreenWidth - 75, bgView.bottom + 17, 55, 55)];
    //设置圆角
    codeView.image = [UIImage imageNamed:@"炫耀LOGO_@x2"];
    [self.view addSubview:codeView];


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
