//
//  FindViewController.m
//  AIDOC
//
//  Created by app on 18/1/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import "FindViewController.h"
#import "FindHeadCell.h"
#import "FindCell.h"
#import "MoreNewsViewController.h"
#import "NewsDetailViewController.h"
#import "SignInViewController.h"
#import "ExampleViewController.h"
@interface FindViewController ()<UITableViewDelegate,UITableViewDataSource,FindHeadCellDelegate>
@property (strong, nonatomic) UITableView *tableView;

@end

@implementation FindViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.title = @"发现";
    
    [self _initView];
    
}

- (void)_initView{
    
    _tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, kScreenHeight + 64) style:UITableViewStyleGrouped];
    _tableView.delegate =self;
    _tableView.dataSource = self;
    [self.view addSubview:_tableView];
}

#pragma -UITableViewDelegate
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (indexPath.section == 0) {
        if (indexPath.row == 0) {
            
            return 87;
        }
        
    }
    
    return 230;
}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section{

    return 10.0f;
}
- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    if (section == 0) {
        return 155;
    }else if (section == 1){
        
        return 40;
    }
    return 0;
}
-(UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section{
    
    if (section == 0) {
        
        UIView *_view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, 155)];
        
        _view.backgroundColor = rgbColor(0xf2f2f2);
        
        UIImageView *findView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, 150)];
        findView.backgroundColor = [UIColor redColor];
//        UITapGestureRecognizer *tapGesturRecognizer=[[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(tapAction:)];
//        [_view addGestureRecognizer:tapGesturRecognizer];
        [_view addSubview:findView];
        
        return _view;
        
    }else if (section == 1){
        
        UIView *_view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, 38)];
        _view.backgroundColor = [UIColor whiteColor];
        UILabel *_label = [[UILabel alloc] initWithFrame:CGRectMake(10, 9, 100, 20)];
        _label.font = [UIFont systemFontOfSize:14];
        _label.textColor = rgbColor(0x555555);
        _label.text = @"最新资讯";
        [_view addSubview:_label];
        
        UIButton *moreBtn = [[UIButton alloc] initWithFrame:CGRectMake(_view.right - 90, 9, 80, 20)];
        //设置button正常状态下的图片
        [moreBtn setImage:[UIImage imageNamed:@"my_rightjd"] forState:UIControlStateNormal];
        [moreBtn setTitle:@"更多" forState:UIControlStateNormal];
        //button标题的偏移量，这个偏移量是相对于图片的
        moreBtn.titleEdgeInsets = UIEdgeInsetsMake(0, -15, 0, 15);
        //button图片的偏移量，距上左下右分别(10, 10, 10, 60)像素点
        moreBtn.imageEdgeInsets = UIEdgeInsetsMake(15, 65, 15, 0);
        //设置button正常状态下的标题颜色
        [moreBtn setTitleColor:rgbColor(0x999999) forState:UIControlStateNormal];
        moreBtn.titleLabel.font = [UIFont systemFontOfSize:12];
        [moreBtn addTarget:self action:@selector(moreBtnAction) forControlEvents:UIControlEventTouchUpInside];
        [_view addSubview:moreBtn];
        
        return _view;
        
    }
    return nil;
}
/**
 * 更多新闻
 */
#pragma mark -moreBtnAction

- (void)moreBtnAction{
    
    MoreNewsViewController *moreNews = [[MoreNewsViewController alloc] init];
    [self.navigationController pushViewController:moreNews animated:YES];
}


#pragma mark -UITableViewDataSource
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 2;
}
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    if (section == 0) {
        return 1;
    }
    return 10;
}



- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    
    if (indexPath.section == 0) {
       
        static NSString *identify = @"FindHeadCell";
        FindHeadCell *cell = [tableView dequeueReusableCellWithIdentifier:identify];
        if (cell == nil) {
            cell = [[FindHeadCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:identify];
        }
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        tableView.separatorStyle = UITableViewCellSeparatorStyleSingleLine;
        cell.delegate = self;
        
        if (indexPath.section == 0){
            if (indexPath.row == 0) {
                
                NSArray *imgArr = @[@"fx_icon1_@x2",@"fx_icon2_@x2",@"fx_icon3_@x2",@"fx_icon4_@x2"];
                NSArray *titleArr = @[@"每日签到",@"达人榜",@"科学运动",@"区块链"];
                cell.imgArr = imgArr;
                cell.titleArr = titleArr;
                
            }
            
        }
        return cell;

    }else{
        
        static NSString *identify = @"FindCell";
        FindCell *cell = [tableView dequeueReusableCellWithIdentifier:identify];
        if (cell == nil) {
            cell = [[FindCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:identify];
        }
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        tableView.separatorStyle = UITableViewCellSeparatorStyleSingleLine;
        FindModel *model = [[FindModel alloc] init];
        if (indexPath.section == 0){
            cell.findModel = model;
        }
        return cell;
        
    }

    return nil;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{

    NewsDetailViewController *newdetail = [[NewsDetailViewController alloc] init];
    [self.navigationController pushViewController:newdetail animated:YES];
}


#pragma mark -FindHeadCellDelegate
-(void)clickCellBtn:(NSInteger)tag{
    
    if (tag == 1) {
        //每日签到
        SignInViewController *signInVC = [[SignInViewController alloc] init];
        [self.navigationController pushViewController:signInVC animated:YES];

        
    }else if (tag ==2){
        //达人榜
        ExampleViewController *exampleVC = [[ExampleViewController alloc] init];
        [self.navigationController pushViewController:exampleVC animated:YES];
        

        
    }else if (tag ==3){
        //科学运动
        
    }else if (tag == 4){
        //区块链
        
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
