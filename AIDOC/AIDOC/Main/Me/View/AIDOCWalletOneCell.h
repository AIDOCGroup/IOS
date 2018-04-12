//
//  AIDOCWalletOneCell.h
//  AIDOC
//
//  Created by 董剑 on 2018/4/10.
//  Copyright © 2018年 app. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AIDOCWalletOneCell : UITableViewCell

#pragma mark - UI
@property (strong, nonatomic) UIImageView *showDataImageView;//背景图
@property (strong, nonatomic) UILabel *titleLabel;//标题
@property (strong, nonatomic) UIButton *backBtn;//返回按钮
@property (strong, nonatomic) UIImageView *backImageView;//返回图

@property (strong, nonatomic) UILabel *line;//

@property (strong, nonatomic) UIButton *collectAIDOCBtn;//
@property (strong, nonatomic) UIImageView *collectAIDOCImageView;
@property (strong, nonatomic) UILabel *collectAIDOCLabel;//收AIDOC

@property (strong, nonatomic) UIButton *payAIDOCBtn;//
@property (strong, nonatomic) UIImageView *payAIDOCImageView;
@property (strong, nonatomic) UILabel *payAIDOCLabel;//付AIDOC

@property (strong, nonatomic) UILabel *showAIDOCLabel;//
@property (strong, nonatomic) UILabel *showAIDOCInfoLabel;//
@property (strong, nonatomic) UIButton *lookBtn;//查看按钮
@property (strong, nonatomic) UIImageView *lookImageView;//查看图

#pragma mark - data
- (void)setUpCell:(NSMutableArray *)dataArray;
@property (assign, nonatomic) BOOL isShowAIDOC;
#pragma mark - CellHeight
+(CGFloat)tableView:(UITableView *)tableView
heightForRowAtIndexPath:(NSIndexPath *)indexPath;

@end
