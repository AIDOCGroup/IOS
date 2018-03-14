//
//  SportsViewController.m
//  AIDOC
//
//  Created by app on 18/1/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import "SportsViewController.h"
#import "GoalSetViewController.h"
#import "ZFChart.h"
#import "ShareSportsViewController.h"
#import "HistoryViewController.h"

@interface SportsViewController ()<GoalSetViewControllerDelegate,ZFCirqueChartDataSource, ZFCirqueChartDelegate>
{
    UIButton *goalButton;
    UIView *goalView;//1.目标背景
    UIView *midView;//2.连接天医手环视图
    UIView *incomeView;//3.收益视图
    UILabel *todayLabel;//今日步数
    UILabel *goalLabel;//目标步数；
    UILabel *kmeterLabel;//步行距离
    UILabel *kilocalorieLabel;//步行距离
    UILabel *timeLabel;//步行距离
    
}

@property (nonatomic, strong) ZFCirqueChart * cirqueChart;

@end

@implementation SportsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = rgbColor(0xeeeeef);
    [self _initNavBar];
    [self _initView1];
    [self _initView2];
    [self _initView3];
    
}

- (void)_initNavBar{
    //1.数据来源:手机
    UIButton *dataFromBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    dataFromBtn.frame = CGRectMake(0, 7, 120, 30);   //#1#硬编码设置UIButton位置、大小
    //设置图片
    [dataFromBtn setImage:[UIImage imageNamed:@"来源icon_@x2"] forState:UIControlStateNormal];
    dataFromBtn.imageEdgeInsets = UIEdgeInsetsMake(8, 0, 8, 106);
    //设置文字
    NSString *buttonTitleStr = @" 数据来源：手机 >";
    [dataFromBtn setTitle:buttonTitleStr forState:UIControlStateNormal];
    [dataFromBtn setTitleColor:rgbColor(0x555) forState:UIControlStateNormal];
    dataFromBtn.titleLabel.font = [UIFont systemFontOfSize:12];
    //button标题的偏移量，这个偏移量是相对于图片的
    dataFromBtn.titleEdgeInsets = UIEdgeInsetsMake(0, -6, 0, 0);
    [dataFromBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    //leftBarButtonItem设置左边距
    UIBarButtonItem *backBtnI = [[UIBarButtonItem alloc] initWithCustomView:dataFromBtn];
    UIBarButtonItem *negativeSpacer = [[UIBarButtonItem alloc]
                                       initWithBarButtonSystemItem:UIBarButtonSystemItemFixedSpace
                                       target:nil action:nil];
    negativeSpacer.width = 30;
    self.navigationItem.leftBarButtonItems = @[negativeSpacer,backBtnI];
    

    //分享一下按钮
    UIButton *rightbutton = [UIButton buttonWithType:UIButtonTypeCustom];
    rightbutton.frame = CGRectMake(0, 8, 75, 26);
    //设置圆角
    [rightbutton setClipsToBounds:YES];
    rightbutton.layer.cornerRadius = rightbutton.height/2.0;//设置矩形四个圆角半径
    rightbutton.layer.borderWidth = 1.0;//边框宽度
    rightbutton.layer.borderColor = rgbColor(0x0091cb).CGColor;
    //设置button图片
    [rightbutton setImage:[UIImage imageNamed:@"炫耀icon_@x2"] forState:UIControlStateNormal];
    //button图片的偏移量，距上左下右分别(10, 10, 10, 60)像素点
    rightbutton.imageEdgeInsets = UIEdgeInsetsMake(6, 6, 6, 54);
    [rightbutton setTitle:@"炫耀一下" forState:UIControlStateNormal];
    rightbutton.titleLabel.font = [UIFont systemFontOfSize:10];
    //button标题的偏移量，这个偏移量是相对于图片的
    rightbutton.titleEdgeInsets = UIEdgeInsetsMake(0, -5, 0, 0);
    //设置button正常状态下的标题颜色
    [rightbutton setTitleColor:rgbColor(0x0091cb) forState:UIControlStateNormal];
    [rightbutton addTarget:self action:@selector(shareSportAction) forControlEvents:UIControlEventTouchUpInside];
    UIBarButtonItem *rightBtnItem = [[UIBarButtonItem alloc] initWithCustomView:rightbutton];
    negativeSpacer.width = - 10;
    self.navigationItem.rightBarButtonItems = @[negativeSpacer,rightBtnItem];


}

- (void)_initView1{
    
    //1目标视图
    goalView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, 240)];
    goalView.backgroundColor = [UIColor whiteColor];

    //1.1天气
    UILabel *weatherLabel = [[UILabel alloc] initWithFrame:CGRectMake(10, 10, 100, 20)];
    weatherLabel.text = @"5℃~10℃ 空气 优";
    weatherLabel.textColor = rgbColor(0x999999);
    weatherLabel.font = [UIFont systemFontOfSize:10];
    [goalView addSubview:weatherLabel];
    [self.view addSubview:goalView];
    
    //1.2设置目标按钮
    goalButton = [UIButton buttonWithType:UIButtonTypeCustom];
    goalButton.frame = CGRectMake(kScreenWidth - 80, 8, 70, 20);
    //设置button图片
    [goalButton setImage:[UIImage imageNamed:@"设置icon_@x2"] forState:UIControlStateNormal];
    //button图片的偏移量，距上左下右分别(10, 10, 10, 60)像素点
    goalButton.imageEdgeInsets = UIEdgeInsetsMake(4, 0, 4, 58);
    [goalButton setTitle:@"设置目标" forState:UIControlStateNormal];
    goalButton.titleLabel.font = [UIFont systemFontOfSize:11];
    //button标题的偏移量，这个偏移量是相对于图片的
    goalButton.titleEdgeInsets = UIEdgeInsetsMake(0, -35, 0, 0);
    //设置button正常状态下的标题颜色
    [goalButton setTitleColor:rgbColor(0x999999) forState:UIControlStateNormal];
    
    [goalButton addTarget:self action:@selector(goalBtnAction) forControlEvents:UIControlEventTouchUpInside];
    
    [goalView addSubview:goalButton];
    
    //1.3查看历史圆形图
    self.cirqueChart = [[ZFCirqueChart alloc] initWithFrame:CGRectMake(10, weatherLabel.bottom + 22, 125, 125)];
    self.cirqueChart.dataSource = self;
    self.cirqueChart.delegate = self;
    self.cirqueChart.textLabel.textColor = rgbColor(0x019fe0);
    self.cirqueChart.textLabel.font = [UIFont boldSystemFontOfSize:12.f];
    self.cirqueChart.isResetMaxValue = YES;
    //    self.cirqueChart.textLabel.text = [NSString stringWithFormat:@"%.f%%",(6500.f / 10000.f) * 100];
    self.cirqueChart.textLabel.text = @"45%";
    //    self.cirqueChart.isAnimated = NO;
    //    self.cirqueChart.cirquePatternType = kCirquePatternTypeNone;
    [goalView addSubview:self.cirqueChart];
    [self.cirqueChart strokePath];
    //1.4查看历史
    UIButton *historyBtn = [[UIButton alloc] initWithFrame:CGRectMake(self.cirqueChart.left+25 , self.cirqueChart.bottom - 50, self.cirqueChart.width-50, 20)];
    [historyBtn setTitle:@"查看历史" forState:UIControlStateNormal];
    [historyBtn setTitleColor:rgbColor(0x999999) forState:UIControlStateNormal];
    historyBtn.titleLabel.font = [UIFont systemFontOfSize:10];
    [historyBtn addTarget:self action:@selector(historyBtnClick) forControlEvents:UIControlEventTouchUpInside];
    //1.5今日步数
    UILabel *label1 = [[UILabel alloc] initWithFrame:CGRectMake(self.cirqueChart.right + 20, self.cirqueChart.top, 100, 20)];
    label1.textColor = rgbColor(0x999999);
    label1.font = [UIFont systemFontOfSize:11.0f];
    label1.text = @"今日步数:";
    [goalView addSubview:label1];
    
    todayLabel = [[UILabel alloc] initWithFrame:CGRectMake(self.cirqueChart.right + 20, label1.bottom + 10, 60, 30)];
    todayLabel.textColor = rgbColor(0x019fe0);
    todayLabel.font = [UIFont boldSystemFontOfSize:24.0f];
    todayLabel.text = @"2780";
    [goalView addSubview:todayLabel];
    
    UILabel *label2 = [[UILabel alloc] initWithFrame:CGRectMake(todayLabel.right+5, label1.bottom + 20, 20, 20)];
    label2.textColor = rgbColor(0x999999);
    label2.font = [UIFont systemFontOfSize:11.0f];
    label2.text = @"步";
    [goalView addSubview:label2];
    
    goalLabel = [[UILabel alloc] initWithFrame:CGRectMake(kScreenWidth - 100, label2.top, 80, 20)];
    goalLabel.textColor = rgbColor(0x999999);
    goalLabel.font = [UIFont systemFontOfSize:11.0f];
    goalLabel.text = @"目标:6000步";
    [goalView addSubview:goalLabel];
    
    float vWidth = (kScreenWidth - self.cirqueChart.right -30)/3.0;
    
    //运动里程
    kmeterLabel = [[UILabel alloc] initWithFrame:CGRectMake(self.cirqueChart.right+10, todayLabel.bottom  + 10, vWidth, 30)];
    kmeterLabel.textColor = rgbColor(0x555);
    kmeterLabel.text = @"1.8";
    kmeterLabel.textAlignment = NSTextAlignmentCenter;
    kmeterLabel.font = [UIFont boldSystemFontOfSize:24];
    [goalView addSubview:kmeterLabel];
    
    
    UILabel *label11 = [[UILabel alloc] initWithFrame:CGRectMake(kmeterLabel.left, kmeterLabel.bottom, vWidth, 20)];
    label11.textColor = rgbColor(0x555555);
    label11.text = @"公里";
    label11.textAlignment = NSTextAlignmentCenter;
    label11.font = [UIFont systemFontOfSize:11];
    [goalView addSubview:label11];

    
    //千卡
    kilocalorieLabel = [[UILabel alloc] initWithFrame:CGRectMake(kmeterLabel.right, kmeterLabel.top, vWidth, 30)];
    kilocalorieLabel.textColor = rgbColor(0x555);
    kilocalorieLabel.text = @"267";
    kilocalorieLabel.textAlignment = NSTextAlignmentCenter;
    kilocalorieLabel.font = [UIFont boldSystemFontOfSize:24];
    [goalView addSubview:kilocalorieLabel];
    
    
    UILabel *label12 = [[UILabel alloc] initWithFrame:CGRectMake(kilocalorieLabel.left, kilocalorieLabel.bottom, vWidth, 20)];
    label12.textColor = rgbColor(0x555555);
    label12.text = @"千卡";
    label12.textAlignment = NSTextAlignmentCenter;
    label12.font = [UIFont systemFontOfSize:11];
    [goalView addSubview:label12];

    
    //分钟
    timeLabel = [[UILabel alloc] initWithFrame:CGRectMake(kilocalorieLabel.right, kmeterLabel.top, vWidth, 30)];
    timeLabel.textColor = rgbColor(0x555);
    timeLabel.text = @"25";
    timeLabel.textAlignment = NSTextAlignmentCenter;
    timeLabel.font = [UIFont boldSystemFontOfSize:24];
    [goalView addSubview:timeLabel];
    
    UILabel *label13 = [[UILabel alloc] initWithFrame:CGRectMake(timeLabel.left, timeLabel.bottom, vWidth, 20)];
    label13.textColor = rgbColor(0x555555);
    label13.text = @"分钟";
    label13.textAlignment = NSTextAlignmentCenter;
    label13.font = [UIFont systemFontOfSize:11];
    [goalView addSubview:label13];


    //设置圆角
    [historyBtn setClipsToBounds:YES];
    historyBtn.layer.cornerRadius = historyBtn.height/2.0;//设置矩形四个圆角半径
    historyBtn.layer.borderWidth = 0.7;//边框宽度
    historyBtn.layer.borderColor = [UIColor lightGrayColor].CGColor;
    [goalView addSubview:historyBtn];
    
    //分割线
    UIView *lineView = [[UIView alloc] initWithFrame:CGRectMake(20, self.cirqueChart.bottom+20, kScreenWidth-40, 1.5f)];
    lineView.backgroundColor = rgbColor(0xf5f5f5);
    [goalView addSubview:lineView];
    
    UILabel *footLabel = [[UILabel alloc] initWithFrame:CGRectMake(20, lineView.bottom, kScreenWidth-40, 40)];
    footLabel.text = @"今天消耗了三个哈根达斯，赶紧向朋友们炫耀一下!";
    footLabel.font = [UIFont systemFontOfSize:11];
    footLabel.textColor = rgbColor(0x999999);
    [goalView addSubview:footLabel];

}

- (void)_initView2{
    //2.连接天医手环视图
    midView = [[UIView alloc] initWithFrame:CGRectMake(0, goalView.bottom + 10, kScreenWidth, 110)];
    midView.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:midView];
    
    UIImageView *view1 = [[UIImageView alloc] initWithFrame:CGRectMake(10, 15, (kScreenWidth-20)/2.0, 80)];
    [view1 setImage:[UIImage imageNamed:@"手环bg_@x3"]];
    [midView addSubview:view1];
    UILabel *label1 = [[UILabel alloc] initWithFrame:CGRectMake(10, 20, view1.width-70, 40)];
    label1.numberOfLines = 2;
    label1.text = @"连接天医智能手环\n立刻自动获取AIDOC";
    label1.font = [UIFont systemFontOfSize:10];
    label1.textColor = [UIColor whiteColor];
    [view1 addSubview:label1];
    // 创建Attributed
    NSMutableAttributedString *noteStr = [[NSMutableAttributedString alloc] initWithString:label1.text];
    NSMutableParagraphStyle * paragraphStyle1 = [[NSMutableParagraphStyle alloc] init];
    [paragraphStyle1 setLineSpacing:5];
    [noteStr addAttribute:NSParagraphStyleAttributeName value:paragraphStyle1 range:NSMakeRange(0, [label1.text length])];
    [label1 setAttributedText:noteStr];
    // 需要改变的区间
    NSRange range = NSMakeRange(0, 8);
    // 改变字体大小及类型
    [noteStr addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:12] range:range];
    // 为label添加Attributed
    [label1 setAttributedText:noteStr];
    
    UIButton *button1 = [[UIButton alloc] initWithFrame:CGRectMake(view1.width-40, 10, 32, 32)];
    [button1 setBackgroundImage:[UIImage imageNamed:@"手环icon_@x2"] forState:UIControlStateNormal];
    [view1 addSubview:button1];

    UIImageView *view2 = [[UIImageView alloc] initWithFrame:CGRectMake(view1.right, 15, (kScreenWidth-20)/2.0, 80)];
    [view2 setImage:[UIImage imageNamed:@"运动bg_@x3"]];
    [midView addSubview:view2];
    
    UILabel *label2 = [[UILabel alloc] initWithFrame:CGRectMake(25, 20, view2.width-70, 40)];
    label2.numberOfLines = 2;
    label2.text = @"科学运动\n科学运动,身体才健康";
    label2.font = [UIFont systemFontOfSize:10];
    label2.textColor = [UIColor whiteColor];
    [view2 addSubview:label2];
    // 创建Attributed
    noteStr = [[NSMutableAttributedString alloc] initWithString:label2.text];
    [paragraphStyle1 setLineSpacing:5];
    [noteStr addAttribute:NSParagraphStyleAttributeName value:paragraphStyle1 range:NSMakeRange(0, [label2.text length])];
    [label2 setAttributedText:noteStr];
    // 需要改变的区间
    range = NSMakeRange(0, 4);
    // 改变字体大小及类型
    [noteStr addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:12] range:range];
    // 为label添加Attributed
    [label2 setAttributedText:noteStr];
    
    UIButton *button2 = [[UIButton alloc] initWithFrame:CGRectMake(view2.width-40, 10, 32, 32)];
    [button2 setBackgroundImage:[UIImage imageNamed:@"运动icon_@x2"] forState:UIControlStateNormal];
    [view2 addSubview:button2];



}

- (void)_initView3{
    //3.收益视图
    incomeView = [[UIView alloc] initWithFrame:CGRectMake(0, midView.bottom + 10, kScreenWidth, 200)];
    incomeView.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:incomeView];
    
    //@"今日预估收益:0.01AID"
    UILabel *label1 = [[UILabel alloc] initWithFrame:CGRectMake(10, 14, 130, 20)];
    label1.text = @"今日预估收益:0.01AID";
    label1.font = [UIFont systemFontOfSize:12];
    label1.textColor = rgbColor(0x555555);
    [incomeView addSubview:label1];

    //AID秘籍立刻领取
    UIButton *getAIDLabel= [UIButton buttonWithType:UIButtonTypeCustom];
    getAIDLabel.frame = CGRectMake(kScreenWidth - 120, 14, 110, 20);
    //设置圆角
    [getAIDLabel setClipsToBounds:YES];
    getAIDLabel.layer.cornerRadius = getAIDLabel.height/2.0;//设置矩形四个圆角半径
    getAIDLabel.layer.borderWidth = 0.7;//边框宽度
    getAIDLabel.layer.borderColor = rgbColor(0x5cc3e6).CGColor;
    [getAIDLabel setTitle:@"AID秘籍立刻领取" forState:UIControlStateNormal];
    getAIDLabel.titleLabel.font = [UIFont systemFontOfSize:11];
    //设置button正常状态下的标题颜色
    [getAIDLabel setTitleColor:rgbColor(0x999999) forState:UIControlStateNormal];
    [incomeView addSubview:getAIDLabel];
    
    
    //AID总额
    UILabel *aidLabelDec = [[UILabel alloc] initWithFrame:CGRectMake(20, getAIDLabel.bottom + 30, kScreenWidth-40, 20)];
    aidLabelDec.text = @"AID总额";
    aidLabelDec.font = [UIFont systemFontOfSize:12];
    aidLabelDec.textAlignment = NSTextAlignmentCenter;
    aidLabelDec.textColor = rgbColor(0x999999);
    [incomeView addSubview:aidLabelDec];
    
    UILabel *aidTotalLabel = [[UILabel alloc] initWithFrame:CGRectMake(20, aidLabelDec.bottom + 10, kScreenWidth-40, 20)];
    aidTotalLabel.text = @"12.22";
    aidTotalLabel.font = [UIFont boldSystemFontOfSize:18];
    aidTotalLabel.textAlignment = NSTextAlignmentCenter;
    aidTotalLabel.textColor = rgbColor(0x08a4d8);
    [incomeView addSubview:aidTotalLabel];

    
    //进入AID钱包
    UIButton *goWalletBtn = [[UIButton alloc] initWithFrame:CGRectMake(20, aidTotalLabel.bottom+30, kScreenWidth - 40, 20)];
    [goWalletBtn.titleLabel setFont:[UIFont systemFontOfSize:12]];
    [goWalletBtn addTarget:self action:@selector(goWalletBtnClick) forControlEvents:UIControlEventTouchUpInside];
    
    NSMutableAttributedString* regString = [[NSMutableAttributedString alloc] initWithString:@"进入AIDOC钱包,获得更多利益"];
    
    //设置下划线...
    /*
     NSUnderlineStyleNone                                    = 0x00, 无下划线
     NSUnderlineStyleSingle                                  = 0x01, 单行下划线
     NSUnderlineStyleThick NS_ENUM_AVAILABLE(10_0, 7_0)      = 0x02, 粗的下划线
     NSUnderlineStyleDouble NS_ENUM_AVAILABLE(10_0, 7_0)     = 0x09, 双下划线
     */
    [regString addAttribute:NSUnderlineStyleAttributeName
                      value:@(NSUnderlineStyleSingle)
                      range:(NSRange){0,[regString length]}];
    //此时如果设置字体颜色要这样
    [regString addAttribute:NSForegroundColorAttributeName value:rgbColor(0x5cc3e6) range:NSMakeRange(0,[regString length])];
    
    //设置下划线颜色...
    [regString addAttribute:NSUnderlineColorAttributeName value:rgbColor(0x5cc3e6) range:(NSRange){0,[regString length]}];
    [goWalletBtn setAttributedTitle:regString forState:UIControlStateNormal];
    [incomeView addSubview:goWalletBtn];

    

}

#pragma mark - ZFCirqueChartDataSource

- (NSArray *)valueArrayInCirqueChart:(ZFCirqueChart *)cirqueChart{
    
    return @[@"4500"];
}

- (id)colorArrayInCirqueChart:(ZFCirqueChart *)cirqueChart{
    return rgbColor(0x019fe0);
    //    return @[ZFRed, ZFOrange, ZFMagenta, ZFBlue, ZFPurple];
}

- (CGFloat)maxValueInCirqueChart:(ZFCirqueChart *)cirqueChart{
    return 10000.f;
}

#pragma mark - ZFCirqueChartDelegate

- (CGFloat)radiusForCirqueChart:(ZFCirqueChart *)cirqueChart{
    return 60;
}


/*
 * 运动炫耀
 */
#pragma -backImgViewAction
- (void)shareSportAction{
    ShareSportsViewController *share = [[ShareSportsViewController alloc] init];
    [self.navigationController pushViewController:share animated:YES];
}
/*
 *设置目标
 */

#pragma -backImgViewAction
- (void)goalBtnAction{
    
    GoalSetViewController *goalSet = [[GoalSetViewController alloc] init];
    goalSet.delegate = self;
    [self.navigationController pushViewController:goalSet animated:YES];
}

/**
 * 进入AID钱包
 */

#pragma mark -goWalletBtnClick
- (void)goWalletBtnClick{
}

/**
 * 查看历史
 */
#pragma mark - historyBtnClick
- (void)historyBtnClick{
    
    HistoryViewController *hisVC = [[HistoryViewController alloc] init];
    [self.navigationController pushViewController:hisVC animated:YES];
}


#pragma mark - GoalSetViewControllerDelegate
- (void)setSportGoal:(NSString *)sportgoal{
    
    goalLabel.text = [NSString stringWithFormat:@"目标:%@步",sportgoal];

    //_cirqueChart.textLabel.text = [NSString stringWithFormat:@"%ld",([todayLabel.text integerValue]/[goal integerValue])*100];
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
