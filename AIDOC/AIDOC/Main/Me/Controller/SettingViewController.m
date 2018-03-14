//
//  SettingViewController.m
//  AIDOC
//
//  Created by app on 18/1/17.
//  Copyright © 2018年 app. All rights reserved.
//

#import "SettingViewController.h"
#import "SettingCell.h"
#import "LoginViewController.h"
#import "ChangePassViewController.h"
#import "ChangePhoneViewController.h"
@interface SettingViewController ()<UITableViewDelegate,UITableViewDataSource,UIActionSheetDelegate>
@property (strong, nonatomic) UITableView *tableView;
@end

@implementation SettingViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.navigationController.navigationBarHidden = NO;
    self.title = @"设置";
    
    _tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, kScreenHeight+64) style:UITableViewStyleGrouped];
    _tableView.backgroundColor = rgbColor(0xf2f2f2);
    
    _tableView.delegate =self;
    _tableView.dataSource = self;
    [self.view addSubview:_tableView];
    
    
    //退出登录按钮
    UIButton *logOut = [UIButton buttonWithType:UIButtonTypeCustom];
    [logOut setTitle:@"退出登录" forState:UIControlStateNormal];
    [logOut setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    logOut.titleLabel.font = [UIFont systemFontOfSize:14];
    [logOut addTarget:self action:@selector(logoutinClick) forControlEvents:UIControlEventTouchUpInside];
    logOut.frame = CGRectMake(20, kScreenHeight - 80,kScreenWidth - 40, 40);
    logOut.backgroundColor = rgbColor(0x0db2f6);
    
    //设置圆角
    [logOut setClipsToBounds:YES];
    logOut.layer.cornerRadius = logOut.height/2.0;//设置矩形四个圆角半径
    logOut.layer.borderWidth = 1.0;//边框宽度
    logOut.layer.borderColor = [UIColor whiteColor].CGColor;
    
    [_tableView addSubview:logOut];

}
#pragma -UITableViewDelegate
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 40;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    return 39;
}

-(UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section{
    
    UIView *_view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, 39)];
    _view.backgroundColor = [UIColor whiteColor];
    UILabel *_label = [[UILabel alloc] initWithFrame:CGRectMake(10, 10, 100, 20)];
    _label.font = [UIFont systemFontOfSize:12.5f];
    _label.textColor = rgbColor(0x555555);
    
    if (section == 0) {
        _label.text = @"安全设置";
    }else if (section == 1){
        _label.text = @"绑定设置";
    }
    [_view addSubview:_label];
    return _view;
}
#pragma mark -UITableViewDataSource
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 2;
}
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    if (section == 0) {
        return 2;
    }
    
    return 5;
}



- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    
    static NSString *identify = @"SettingCell";
    SettingCell *cell = [tableView dequeueReusableCellWithIdentifier:identify];
    if (cell == nil) {
        cell = [[SettingCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:identify];
    }
    
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    
    tableView.separatorStyle = UITableViewCellSeparatorStyleSingleLine;
    
    UserInfoModel *model = [CommonFunc getUserInformation];
    
    if (indexPath.section == 0){
        if (indexPath.row == 0) {
            
            cell.itemName.text = @"修改手机号";
            cell.detailLabel.text = [NSString stringWithFormat:@"%@****%@",[model.username substringToIndex:3],[model.username substringFromIndex:8]];
    
        }else if (indexPath.row == 1){
            cell.itemName.text = @"修改密码";
            cell.detailLabel.text = @"修改登录密码";
        }
        
        
        
    }else  if (indexPath.section == 1){
        
        if (indexPath.row == 0) {
            
            cell.itemName.text = @"微信";
            cell.detailLabel.text = [NSString stringWithFormat:@"%@****%@",[model.username substringToIndex:3],[model.username substringFromIndex:8]];
            
            
        }else if (indexPath.row == 1){
            
            cell.itemName.text = @"QQ";
            cell.detailLabel.text = @"未绑定";
            
        }else if (indexPath.row == 2) {
            
            cell.itemName.text = @"微博";
            cell.detailLabel.text = @"未绑定";
            
        }else if (indexPath.row == 3){
            
            cell.itemName.text = @"Facebook";
            cell.detailLabel.text = @"未绑定";
            
        }else if (indexPath.row == 4){
            
            cell.itemName.text = @"推特";
            cell.detailLabel.text = @"未绑定";
            
        }

    }
    
    
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (indexPath.section == 0) {
        if (indexPath.row == 0) {
            //修改手机号
            ChangePhoneViewController *changePhone = [[ChangePhoneViewController alloc] init];
            [self.navigationController pushViewController:changePhone animated:YES];
            
        }else if (indexPath.row ==1){
            //修改密码
            ChangePassViewController *changePass = [[ChangePassViewController alloc] init];
            [self.navigationController pushViewController:changePass animated:YES];

        }
    }else if (indexPath.section ==1){
        if (indexPath.row == 0) {
            //绑定微信
            
        }else if (indexPath.row == 1){
            
            //绑定@@
            
        }else if (indexPath.row == 2) {
            
            //绑定微博
            
        }else if (indexPath.row == 3){
            
            //绑定Facebook
            
        }else if (indexPath.row == 4){
            
            //绑定推特
            
        }

    }
}


#pragma mark -UIActionSheetDelegate
- (void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex {
    
    if(buttonIndex == 0){
         [[NSNotificationCenter defaultCenter] postNotificationName:KNOTIFICATION_LOGINCHANGE object:@"NO"];;
                
    }
}


/**
 *  退出按钮
 */
-(void)logoutinClick{
    UIActionSheet *action = [[UIActionSheet alloc] initWithTitle:@"确定退出当前账号?" delegate:self cancelButtonTitle:@"取消" destructiveButtonTitle:nil otherButtonTitles:@"确定", nil];
    
    [action showInView:self.view];
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
