//
//  MeDetailViewController.m
//  AIDOC
//
//  Created by app on 18/1/17.
//  Copyright © 2018年 app. All rights reserved.
//

#import "MeDetailViewController.h"
#import "SettingCell.h"
#import "ChagePersonViewController.h"

@interface MeDetailViewController ()<UITableViewDelegate,UITableViewDataSource>
@property (strong, nonatomic) UITableView *tableView;
@end

@implementation MeDetailViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = @"个人资料";
    _tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, kScreenHeight+64) style:UITableViewStyleGrouped];
    _tableView.backgroundColor = rgbColor(0xf2f2f2);
    
    _tableView.delegate =self;
    _tableView.dataSource = self;
    [self.view addSubview:_tableView];

}

#pragma -UITableViewDelegate
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 40;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    if (section == 0) {
        return 50;
    }
    return 0;
}

-(UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section{
    
    if (section == 0) {
        
        UIView *_view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, 50)];
        UITapGestureRecognizer *tapGesturRecognizer=[[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(tapAction:)];
        
        [_view addGestureRecognizer:tapGesturRecognizer];
        _view.backgroundColor = [UIColor whiteColor];
        
        UILabel *_itemName = [[UILabel alloc] initWithFrame:CGRectMake(20, 15, 100, 20)];
        _itemName.font = [UIFont systemFontOfSize:12.0f];
        _itemName.textColor = rgbColor(0x999999);
        _itemName.text = @"头像";
        _itemName.textAlignment = NSTextAlignmentLeft;
        [_view addSubview:_itemName];
        
        UIImageView *avaImgView = [[UIImageView alloc] initWithFrame:CGRectMake(kScreenWidth - 68, 5, 40, 40)];
        avaImgView.backgroundColor = [UIColor redColor];
        avaImgView.layer.cornerRadius = avaImgView.frame.size.height/2.0;//设置矩形四个圆角半径
        avaImgView.layer.borderWidth = 1.0;//边框宽度
        avaImgView.layer.borderColor = [UIColor lightGrayColor].CGColor;

        [_view addSubview:avaImgView];
//        avaImg.image = [UIImage imageNamed:@"my_icon18_@x2"];
        //向右的箭头
        UIImage *rightImage = [UIImage imageNamed:@"my_rightjd"];
        UIImageView *rirhtImgView = [[UIImageView alloc] initWithFrame:CGRectMake(kScreenWidth - 28, 17, 16, 16)];
        rirhtImgView.image = rightImage;
        [_view addSubview:rirhtImgView];
        return _view;

    }
    return nil;
}


//修改头像
-(void)tapAction:(id)tap

{
    
    ChagePersonViewController *changePer = [[ChagePersonViewController alloc] init];
    //修改生日
    changePer.changeID = 1;
    [self.navigationController pushViewController:changePer animated:YES];
    

    
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
    
    return 3;
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
            
            cell.itemName.text = @"昵称";
            cell.detailLabel.text = model.nickname;
            
        }else if (indexPath.row == 1){
            cell.itemName.text = @"个性签名";
//            cell.detailLabel.text = model.
        }
        
        
        
    }else  if (indexPath.section == 1){
        
        if (indexPath.row == 0) {
            
            cell.itemName.text = @"性别";
            cell.detailLabel.text = @"保密";
        }else if (indexPath.row == 1){
            
            cell.itemName.text = @"生日";
            cell.detailLabel.text = @"未填写";

            
        }else if (indexPath.row == 2) {
            cell.itemName.text = @"地区";
            cell.detailLabel.text = @"未填写";

            
        }
    }
    
    
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    ChagePersonViewController *changePer = [[ChagePersonViewController alloc] init];
    if (indexPath.section == 0) {
        if (indexPath.row == 0) {
            //修改昵称
            changePer.changeID = 2;
            [self.navigationController pushViewController:changePer animated:YES];
            
        }else if (indexPath.row ==1){
            //修改个性签名
            changePer.changeID = 3;
            [self.navigationController pushViewController:changePer animated:YES];
            
        }
    }else if (indexPath.section ==1){
        if (indexPath.row == 0) {
            //修改性别
            changePer.changeID = 4;
            [self.navigationController pushViewController:changePer animated:YES];

            
        }else if (indexPath.row == 1){
            
            //修改生日
            changePer.changeID = 5;
            [self.navigationController pushViewController:changePer animated:YES];

            
        }else if (indexPath.row == 2) {
            
            //修改地区
            changePer.changeID = 6;
            [self.navigationController pushViewController:changePer animated:YES];

            
        }        
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
