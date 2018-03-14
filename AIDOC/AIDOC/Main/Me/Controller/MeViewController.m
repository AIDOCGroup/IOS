//
//  MeViewController.m
//  AIDOC
//
//  Created by app on 18/1/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import "MeViewController.h"
#import "SettingViewController.h"
#import "MeDetailViewController.h"
#import "MeDetailViewController.h"
#import "HelpCenterViewController.h"
#import "AboutUsViewController.h"
#import "SpoilAdviseViewController.h"

#import "SettingCell.h"
#import "MeCell.h"
@interface MeViewController ()<UITableViewDelegate,UITableViewDataSource,MeCellDelegate>

{
    UIButton *_setButton; //设置按钮
}
@property (strong, nonatomic) UITableView *tableView;

@end

@implementation MeViewController
- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    self.navigationController.navigationBarHidden = YES;
    
}
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.view.backgroundColor = rgbColor(0xf2f2f2);
    
    [self _initView1];
    
    
    [self _initView2];


}


/**
 *  初始化_initView1
 */

- (void)_initView1{
    
    UIView *bgVIew = [[UIView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth,150)];
    bgVIew.backgroundColor = rgbColor(0x0db2f6);
    [self.view addSubview:bgVIew];
    
    //标题
    UILabel *titleLbl = [[UILabel alloc] initWithFrame:CGRectMake(0, 30, kScreenWidth, 30)];
    titleLbl.textAlignment = NSTextAlignmentCenter;
    titleLbl.text = @"我的";
    titleLbl.textColor = [UIColor whiteColor];
    titleLbl.font = [UIFont boldSystemFontOfSize:18];
    [bgVIew addSubview:titleLbl];
    
    // 设置按钮
    _setButton = [[UIButton alloc] initWithFrame:CGRectMake(kScreenWidth - 50, 26, 30, 30)];
    _setButton.contentHorizontalAlignment = UIControlContentHorizontalAlignmentRight;
    [_setButton setImage:[UIImage imageNamed:@"my_icon1_@x2"] forState:UIControlStateNormal];
    [_setButton addTarget:self action:@selector(_setBtnAvtion) forControlEvents:UIControlEventTouchUpInside];
    [bgVIew addSubview:_setButton];

}

//设置
- (void)_setBtnAvtion{
    SettingViewController *settingVC = [[SettingViewController alloc] init];
    [self.navigationController pushViewController:settingVC animated:YES];
}
- (void)_initView2{
    
    self.title = @"个人资料";
    _tableView = [[UITableView alloc] initWithFrame:CGRectMake(10, 80, kScreenWidth - 20, kScreenHeight + 64 - 80) style:UITableViewStyleGrouped];
//    _tableView.backgroundColor = [UIColor whiteColor];
    _tableView.delegate =self;
    _tableView.dataSource = self;
    [self.view addSubview:_tableView];
}

#pragma -UITableViewDelegate
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (indexPath.section == 3) {
       
        return 50;
    }
    
    return 70;
}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section{
    if (section == 0 || section==2) {
        return 0.1f;
    }
    
    return 10.0f;
}
- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    if (section == 0) {
        return 74;
    }else if (section == 2){
        
        return 45;
    }
    return 10.0f;
}
-(UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section{
    
    if (section == 0) {
        
        UIView *_view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth-20, 74)];
      
        _view.backgroundColor = [UIColor whiteColor];
        
        UIImageView *avaImgView = [[UIImageView alloc] initWithFrame:CGRectMake(10, _view.bottom - 67, 57, 57)];
        avaImgView.backgroundColor = [UIColor redColor];
        
        [avaImgView setClipsToBounds:YES];
        avaImgView.layer.cornerRadius = avaImgView.frame.size.height/2.0;//设置矩形四个圆角半径
        avaImgView.layer.borderWidth = 1.0;//边框宽度
        avaImgView.layer.borderColor = [UIColor lightGrayColor].CGColor;
        
        UITapGestureRecognizer *tapGesturRecognizer=[[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(tapAction:)];
        
        [_view addGestureRecognizer:tapGesturRecognizer];
        [_view addSubview:avaImgView];

        UILabel *_nickNameLabel = [[UILabel alloc] initWithFrame:CGRectMake(avaImgView.right+10, avaImgView.top+10, 100, 20)];
        _nickNameLabel.font = [UIFont systemFontOfSize:14.0f];
        _nickNameLabel.textColor = rgbColor(0x555);
        _nickNameLabel.text = @"璀璨夏花";
        _nickNameLabel.textAlignment = NSTextAlignmentLeft;
        [_view addSubview:_nickNameLabel];
        
        UILabel *signLabel = [[UILabel alloc] initWithFrame:CGRectMake(avaImgView.right+10, _nickNameLabel.bottom, 200, 20)];
        signLabel.font = [UIFont systemFontOfSize:11.0f];
        signLabel.textColor = rgbColor(0x999999);
        signLabel.text = @"运动就像生活一样,没什么条件";
        signLabel.textAlignment = NSTextAlignmentLeft;
        [_view addSubview:signLabel];

        
        //向右的箭头
        UIImage *rightImage = [UIImage imageNamed:@"my_rightjd"];
        UIImageView *rirhtImgView = [[UIImageView alloc] initWithFrame:CGRectMake(_view.right - 28, 29, 16, 16)];
        rirhtImgView.image = rightImage;
        [_view addSubview:rirhtImgView];

        
        
        return _view;
        
    }else if (section == 2){
    
        UIView *_view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth-20, 45)];
        _view.backgroundColor = [UIColor whiteColor];
        UILabel *_label = [[UILabel alloc] initWithFrame:CGRectMake(10, 12.5, 100, 20)];
        _label.font = [UIFont systemFontOfSize:14];
        _label.textColor = rgbColor(0x555555);
        _label.text = @"我的订单";
        [_view addSubview:_label];
        
        UIButton *orderAllBtn = [[UIButton alloc] initWithFrame:CGRectMake(_view.right - 110, 12.5, 100, 20)];
        //设置button正常状态下的图片
        [orderAllBtn setImage:[UIImage imageNamed:@"my_rightjd"] forState:UIControlStateNormal];
        [orderAllBtn setTitle:@"全部订单" forState:UIControlStateNormal];
        //button标题的偏移量，这个偏移量是相对于图片的
        orderAllBtn.titleEdgeInsets = UIEdgeInsetsMake(0, -15, 0, 15);

        //button图片的偏移量，距上左下右分别(10, 10, 10, 60)像素点
        orderAllBtn.imageEdgeInsets = UIEdgeInsetsMake(15, 85, 15, 0);
        //设置button正常状态下的标题颜色
        [orderAllBtn setTitleColor:rgbColor(0x999999) forState:UIControlStateNormal];
        orderAllBtn.titleLabel.font = [UIFont systemFontOfSize:11];
        [_view addSubview:orderAllBtn];

        return _view;

    }
    return nil;
}


//个人资料
-(void)tapAction:(id)tap

{
    MeDetailViewController *meDetail = [[MeDetailViewController alloc] init];
    [self.navigationController pushViewController:meDetail animated:YES];
    
}



#pragma mark -UITableViewDataSource
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 4;
}
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    if (section == 3) {
        return 3;
    }
    
    return 1;
}



- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    
    if (indexPath.section == 3) {
        
        static NSString *identify = @"SettingCell";
        SettingCell *cell = [tableView dequeueReusableCellWithIdentifier:identify];
        if (cell == nil) {
            cell = [[SettingCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:identify];
        }
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        tableView.separatorStyle = UITableViewCellSeparatorStyleSingleLine;
        
        cell.isIcon = YES;
        
        if (indexPath.row == 0) {
            
            cell.itemName.text = @"帮助中心";
            cell.iconImgView.image = [UIImage imageNamed:@"my_icon15_@x2"];
            
            
        }else if (indexPath.row == 1) {
            
            cell.itemName.text = @"关于我们";
            cell.iconImgView.image = [UIImage imageNamed:@"my_icon16_@x2"];
            
        }else if (indexPath.row == 2) {
            
            cell.itemName.text = @"有奖建议";
            cell.iconImgView.image = [UIImage imageNamed:@"my_icon17_@x2"];
            
        }
        
        return cell;
        
    }else{
        
        
        static NSString *identify = @"MeCell";
        MeCell *cell = [tableView dequeueReusableCellWithIdentifier:identify];
        if (cell == nil) {
            cell = [[MeCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:identify];
        }
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        tableView.separatorStyle = UITableViewCellSeparatorStyleSingleLine;
        cell.delegate = self;
        
        if (indexPath.section == 0){
            if (indexPath.row == 0) {
                
                NSArray *imgArr = @[@"my_icon2_@x2",@"my_icon3_@x2",@"my_icon4_@x2"];
                NSArray *titleArr = @[@"我的设备",@"我的步数",@"有奖邀请"];
                cell.imgArr = imgArr;
                cell.titleArr = titleArr;
                
            }
            
        }else  if (indexPath.section == 1){
            
            if (indexPath.row == 0) {
                
                NSArray *imgArr = @[@"my_icon6_@x2",@"my_icon7_@x2",@"my_icon8_@x2",@"my_icon9_@x2"];
                NSArray *titleArr = @[@"AIDOC钱包",@"收AIDOC",@"付AIDOC",@"充值中心"];
                cell.imgArr = imgArr;
                cell.titleArr = titleArr;
                
            }
            
        }else  if (indexPath.section == 2){
            
            if (indexPath.row == 0) {
                
                NSArray *imgArr = @[@"my_icon10_@x2",@"my_icon11_@x2",@"my_icon12_@x2",@"my_icon13_@x2",@"my_icon14_@x2"];
                NSArray *titleArr = @[@"购物车",@"待付款",@"待发货",@"待收货",@"待评价"];
                cell.imgArr = imgArr;
                cell.titleArr = titleArr;
                
            }
            
        }
        
        
        
        return cell;
    }
    return nil;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (indexPath.section == 3) {
        if (indexPath.row == 0) {
            //帮助中心
            HelpCenterViewController *heleCetner = [[HelpCenterViewController alloc] init];
            [self.navigationController pushViewController:heleCetner animated:YES];

        }else if (indexPath.row == 1){
            //关于我们
            AboutUsViewController *aboutUs = [[AboutUsViewController alloc] init];
            [self.navigationController pushViewController:aboutUs animated:YES];

            
        }else if (indexPath.row ==2){
           
            //有奖建议
            SpoilAdviseViewController *adviseVC = [[SpoilAdviseViewController alloc] init];
            [self.navigationController pushViewController:adviseVC animated:YES];

        }
    }
}


#pragma mark -MeCellDelegate
-(void)clickCellBtn:(NSInteger)tag andCellNum:(NSInteger)cellNum{
    
    NSLog(@"%ld %ld",(long)tag,(long)cellNum);
    
    if (cellNum==3) {
        
        if (tag == 1) {
            //我的设备
            
        }else if (tag ==2){
            //我的步数
            
        }else if (tag ==3){
            //有奖邀请
            
        }
    }else if(cellNum == 4){
        
        if (tag == 1) {
            //AIDOC钱包
            
        }else if (tag ==2){
            //收AIDOC
            
        }else if (tag ==3){
            //付AIDOC
            
        }else if (tag == 4){
            //充值中心
            
        }

    
    }else if (cellNum == 5){
        
        if (tag == 0) {
            //购物车
            
        }else if (tag ==1){
            //待付款
            
        }else if (tag ==2){
            //待发货
            
        }}else if (tag == 4){
            //待收货
            
        }else if (tag ==5){
            //待评价
            
        }


    
}
//cell 分割线 两端封头 实现这个两个方法 1
-(void)viewDidLayoutSubviews
{
    [super viewDidLayoutSubviews];
    if ([_tableView respondsToSelector:@selector(setSeparatorInset:)]) {
        [_tableView setSeparatorInset:UIEdgeInsetsMake(0, 10, 0, 10)];
    }
    
    if ([_tableView respondsToSelector:@selector(setLayoutMargins:)]) {
        [_tableView setLayoutMargins:UIEdgeInsetsMake(0, 10, 0, 10)];
    }
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
