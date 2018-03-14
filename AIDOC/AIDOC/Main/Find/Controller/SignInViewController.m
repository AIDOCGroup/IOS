//
//  SignInViewController.m
//  AIDOC
//
//  Created by app on 18/1/17.
//  Copyright © 2018年 app. All rights reserved.
//

#import "SignInViewController.h"

@interface SignInViewController ()
@property (nonatomic,copy) NSMutableSet *nextTimeSetArr;
@property (nonatomic,strong) VRGCalendarView *calendarView;
@property (nonatomic,assign) int currentTime;

@end

@implementation SignInViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = rgbColor(0xf2f2f2);
    self.title = @"签到统计";
    
    [self initView];
}
- (void)initView {
    
    self.title = @"签到统计";
    
    UIView *_headView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, 70)];
    _headView.backgroundColor = rgbColor(0x4fa4f4);
    [self.view addSubview:_headView];
    
    //头像
    UIImageView *avaView = [[UIImageView alloc] initWithFrame:CGRectMake(15, 14, 42, 42)];
    //设置圆角
    //    [avaView setClipsToBounds:YES];
    //    avaView.layer.cornerRadius = avaView.height/2.0;//设置矩形四个圆角半径
    [avaView sd_setImageWithURL:[NSURL URLWithString:@""] placeholderImage:[UIImage imageNamed:@"头像_@x2"]];
    [_headView addSubview:avaView];
    
    UserInfoModel *usermodel = [CommonFunc getUserInformation];
    //用户名
    UILabel *nameLabel = [[UILabel alloc] initWithFrame:CGRectMake(avaView.right + 10, avaView.top+5, 200, 15)];
    nameLabel.text = usermodel.username;
    nameLabel.font = [UIFont systemFontOfSize:12];
    nameLabel.textColor = rgbColor(0xffffff);
    [_headView addSubview:nameLabel];
    //日期
    UILabel *dateLabel = [[UILabel alloc] initWithFrame:CGRectMake(avaView.right + 10, nameLabel.bottom, 200, 15)];
    dateLabel.text = @"已连续签到3天,连续签到999天";
    dateLabel.font = [UIFont systemFontOfSize:12];
    dateLabel.textColor = rgbColor(0xffffff);
    [_headView addSubview:dateLabel];
    
    UIButton *signBtn = [[UIButton alloc] initWithFrame:CGRectMake(kScreenWidth - 80, 18, 70, 34)];
    [signBtn setTitle:@"签到" forState:UIControlStateNormal];
    [signBtn setTitleColor:rgbColor(0x4fa4f4) forState:UIControlStateNormal];
    signBtn.titleLabel.font = [UIFont boldSystemFontOfSize:13];
    [signBtn setBackgroundImage:[UIImage imageNamed:@"qd_btnbg_@x2"] forState:UIControlStateNormal];
    [_headView addSubview:signBtn];
    

    //已经签到 btn_sign_in_l_h
    _calendarView = [[VRGCalendarView alloc] init];
    _calendarView.frame = CGRectMake(0, _headView.bottom + 10, kScreenWidth, 300);
    _calendarView.delegate=self;
    [_calendarView setAccessibilityLanguage:@"chinise"];
    
    [self.view addSubview:_calendarView];
    
//    self.partyManager = [[PMPartyManager alloc] init];
    
}


/**
 *  用户签到
 */
- (void)signClick {
//    self.loadingView.hidden = NO;
//    [self.partyManager userSignWithType:PMSignTypeNormal threeLessonId:0 completed:^(NSError *error) {
//        self.loadingView.hidden = YES;
//        if(!error){
//            self.currentTime = 0;
//            [_calendarView reset];
//            
//            [ProgressHUD showSuccess:@"签到成功"];
//        }
//    }];
    
}

- (void)calendarView:(VRGCalendarView *)calendarView currentDay:(NSString *)currentDay nextTime:(NSString *)nextTime {
    self.calendarView = calendarView;
    
    if (self.currentTime != [nextTime intValue]) {
//        [self.partyManager getUserSignWithType:PMSignTypeNormal threeLessonId:0 month:[nextTime intValue] completed:^(NSArray *list, NSError *error) {
//            
//            self.nextTimeSetArr = [NSMutableSet setWithArray:list];
//            
//            if (self.currentTime == 0) {
//                NSDate *date = [NSDate date];
//                NSCalendar *calendar = [NSCalendar currentCalendar];
//                NSDateComponents *dateComponent = [calendar components:NSDayCalendarUnit fromDate:date];
//                NSInteger day = [dateComponent day];
//                
//                if ([self.nextTimeSetArr containsObject:@(day)]) {
//                    [self.rightButton setImage:[UIImage imageNamed:@"btn_sign_in_r_h"] forState:UIControlStateNormal];
//                    [self.rightButton setImage:[UIImage imageNamed:@"btn_sign_in_r_h"] forState:UIControlStateHighlighted];
//                    [self.rightButton removeTarget:self action:@selector(signClick) forControlEvents:UIControlEventTouchUpInside];
//                    
//                    [PMChatAccount sharedInstance].partyInfo.isSign = YES;
//                    
//                }
//                
//                
//            }
//            
//            
//            self.currentTime = [nextTime intValue];
//        }];
    }
    
    
}
- (void)setNextTimeSetArr:(NSMutableSet *)nextTimeSetArr {
    _nextTimeSetArr = nextTimeSetArr;
    [self.calendarView markDates:[nextTimeSetArr allObjects]];
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
