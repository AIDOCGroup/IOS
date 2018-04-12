//
//  AIDOCWalletOneCell.m
//  AIDOC
//
//  Created by 董剑 on 2018/4/10.
//  Copyright © 2018年 app. All rights reserved.
//

#import "AIDOCWalletOneCell.h"

@implementation AIDOCWalletOneCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        self.backgroundColor = [UIColor whiteColor];
        [self setupSubviews];
    }
    return self;
}

#pragma mark - UI
- (void)setupSubviews  {
    [self.contentView addSubview:self.showDataImageView];//背景图
    [self.showDataImageView addSubview:self.titleLabel];//标题
    [self.showDataImageView addSubview:self.backBtn];//返回按钮
    [self.backBtn addSubview:self.backImageView];//返回图
    
    [self.showDataImageView addSubview:self.line];
    
    [self.showDataImageView addSubview:self.collectAIDOCBtn];
    [self.collectAIDOCBtn addSubview:self.collectAIDOCImageView];
    [self.collectAIDOCBtn addSubview:self.collectAIDOCLabel];
    
    [self.showDataImageView addSubview:self.payAIDOCBtn];
    [self.payAIDOCBtn addSubview:self.payAIDOCImageView];
    [self.payAIDOCBtn addSubview:self.payAIDOCLabel];
    
    [self.showDataImageView addSubview:self.showAIDOCLabel];
    [self.showDataImageView addSubview:self.showAIDOCInfoLabel];
    [self.showDataImageView addSubview:self.lookBtn];
    [self.lookBtn addSubview:self.lookImageView];
}

#pragma mark - public
- (void)setUpCell:(NSMutableArray *)dataArray {
    
}

#pragma mark - data
- (void)setIsShowAIDOC:(BOOL)isShowAIDOC {
    _isShowAIDOC = isShowAIDOC;
    if (_isShowAIDOC == YES) {
        [_lookImageView setImage:SET_IMAGE(@"icon_隐藏")];
        self.showAIDOCLabel.text = @"57.08";
    }else {
        [_lookImageView setImage:SET_IMAGE(@"icon_显示")];
        self.showAIDOCLabel.text = @"*****";
    }
}

#pragma mark - CellHeight
+(CGFloat)tableView:(UITableView *)tableView
heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 515/2;
}

#pragma mark - Lazy loading
//背景图
- (UIImageView *)showDataImageView {
    if (!_showDataImageView) {
        _showDataImageView = [[UIImageView alloc] init];
        _showDataImageView.frame = CGRectMake(0, 0, SCREEN_WIDTH, 515/2);
        UIColor *topColor = rgbColor(0xFFFF6E6E);
        UIColor *bottomColor = rgbColor(0xFFFFD88A);
        UIImage *bgImg = [UIImage gradientColorImageFromColors:@[topColor, bottomColor] gradientType:GradientTypeTopToBottom imgSize:CGSizeMake(SCREEN_WIDTH, 515/2)];
        _showDataImageView.backgroundColor = [UIColor colorWithPatternImage:bgImg];
        _showDataImageView.userInteractionEnabled = YES;
    }
    return _showDataImageView;
}
//标题
- (UILabel *)titleLabel {
    if (!_titleLabel) {
        _titleLabel = [[UILabel alloc] init];
        _titleLabel.frame = CGRectMake(60, 65/2, SCREEN_WIDTH-60*2, 18);
        _titleLabel.backgroundColor = [UIColor clearColor];
        _titleLabel.textColor = rgbColor(0xFFFFFFFF);
        _titleLabel.font = [UIFont systemFontOfSize:18.0f];
        _titleLabel.textAlignment = NSTextAlignmentCenter;
        _titleLabel.text = @"AIDOC钱包";
    }
    return _titleLabel;
}
//返回按钮
- (UIButton *)backBtn {
    if (!_backBtn) {
        _backBtn = [UIButton buttonWithType:UIButtonTypeCustom];
        _backBtn.frame = CGRectMake(0, 20, 44, 44);
        [_backBtn setBackgroundColor:[UIColor clearColor]];
    }
    return _backBtn;
}
//返回图
- (UIImageView *)backImageView {
    if (!_backImageView) {
        _backImageView = [[UIImageView alloc] init];
        _backImageView.frame = CGRectMake(0, 0, 44, 44);
        [_backImageView setBackgroundColor:[UIColor clearColor]];
        [_backImageView setImage:SET_IMAGE(@"icon_back")];
    }
    return _backImageView;
}
//线条
- (UILabel *)line {
    if (!_line) {
        _line = [[UILabel alloc] init];
        _line.frame = CGRectMake(0, 0, 1, 48);
        _line.center = _showDataImageView.center;
        _line.y = 178/2;
        _line.backgroundColor = [UIColor whiteColor];
    }
    return _line;
}
//收AIDOC按钮
- (UIButton *)collectAIDOCBtn {
    if (!_collectAIDOCBtn) {
        _collectAIDOCBtn = [UIButton buttonWithType:UIButtonTypeCustom];
        _collectAIDOCBtn.frame = CGRectMake(0, 0, (SCREEN_WIDTH-1)/2, 140/2);
        _collectAIDOCBtn.centerY = _line.centerY;
        [_collectAIDOCBtn setBackgroundColor:[UIColor clearColor]];
    }
    return _collectAIDOCBtn;
}
//收AIDOC图
- (UIImageView *)collectAIDOCImageView {
    if (!_collectAIDOCImageView) {
        _collectAIDOCImageView = [[UIImageView alloc] init];
        _collectAIDOCImageView.frame = CGRectMake((_collectAIDOCBtn.width-49)/2, 0, 49, 49);
        [_collectAIDOCImageView setBackgroundColor:[UIColor clearColor]];
        [_collectAIDOCImageView setImage:SET_IMAGE(@"icon_收AIDOC_w")];
    }
    return _collectAIDOCImageView;
}
//收AIDOC
- (UILabel *)collectAIDOCLabel {
    if (!_collectAIDOCLabel) {
        _collectAIDOCLabel = [[UILabel alloc] init];
        _collectAIDOCLabel.frame = CGRectMake(0, _collectAIDOCImageView.bottom+5, _collectAIDOCBtn.width, 14);
        _collectAIDOCLabel.backgroundColor = [UIColor clearColor];
        _collectAIDOCLabel.textColor = rgbColor(0xFFFFFFFF);
        _collectAIDOCLabel.font = [UIFont systemFontOfSize:14.0f];
        _collectAIDOCLabel.textAlignment = NSTextAlignmentCenter;
        _collectAIDOCLabel.text = @"收AIDOC";
    }
    return _collectAIDOCLabel;
}
//付AIDOC按钮
- (UIButton *)payAIDOCBtn {
    if (!_payAIDOCBtn) {
        _payAIDOCBtn = [UIButton buttonWithType:UIButtonTypeCustom];
        _payAIDOCBtn.frame = CGRectMake(_line.right, 0, _collectAIDOCBtn.width, _collectAIDOCBtn.height);
        _payAIDOCBtn.centerY = _line.centerY;
        [_payAIDOCBtn setBackgroundColor:[UIColor clearColor]];
    }
    return _payAIDOCBtn;
}
//付AIDOC图
- (UIImageView *)payAIDOCImageView {
    if (!_payAIDOCImageView) {
        _payAIDOCImageView = [[UIImageView alloc] init];
        _payAIDOCImageView.frame = CGRectMake(_collectAIDOCImageView.x, _collectAIDOCImageView.y, _collectAIDOCImageView.width, _collectAIDOCImageView.height);
        [_payAIDOCImageView setBackgroundColor:[UIColor clearColor]];
        [_payAIDOCImageView setImage:SET_IMAGE(@"icon_收AIDOC_w1")];
    }
    return _payAIDOCImageView;
}
//付AIDOC
- (UILabel *)payAIDOCLabel {
    if (!_payAIDOCLabel) {
        _payAIDOCLabel = [[UILabel alloc] init];
        _payAIDOCLabel.frame = CGRectMake(0, _payAIDOCImageView.bottom+5, _payAIDOCBtn.width, 14);
        _payAIDOCLabel.backgroundColor = [UIColor clearColor];
        _payAIDOCLabel.textColor = rgbColor(0xFFFFFFFF);
        _payAIDOCLabel.font = [UIFont systemFontOfSize:14.0f];
        _payAIDOCLabel.textAlignment = NSTextAlignmentCenter;
        _payAIDOCLabel.text = @"付AIDOC";
    }
    return _payAIDOCLabel;
}
//显示AIDOC
- (UILabel *)showAIDOCLabel {
    if (!_showAIDOCLabel) {
        _showAIDOCLabel = [[UILabel alloc] init];
        _showAIDOCLabel.frame = CGRectMake(15, 374/2, 200, 36);
        _showAIDOCLabel.backgroundColor = [UIColor clearColor];
        _showAIDOCLabel.textColor = rgbColor(0xFFFFFFFF);
        _showAIDOCLabel.font = [UIFont systemFontOfSize:36.0f];
        _showAIDOCLabel.textAlignment = NSTextAlignmentLeft;
        _showAIDOCLabel.text = @"57.08";
    }
    return _showAIDOCLabel;
}

//显示AIDOC信息
- (UILabel *)showAIDOCInfoLabel {
    if (!_showAIDOCInfoLabel) {
        _showAIDOCInfoLabel = [[UILabel alloc] init];
        _showAIDOCInfoLabel.frame = CGRectMake(_showAIDOCLabel.x, _showAIDOCLabel.bottom+2.5, _showAIDOCLabel.width, 12);
        _showAIDOCInfoLabel.backgroundColor = [UIColor clearColor];
        _showAIDOCInfoLabel.textColor = rgbColor(0xFFFFFFFF);
        _showAIDOCInfoLabel.font = [UIFont systemFontOfSize:12.0f];
        _showAIDOCInfoLabel.textAlignment = NSTextAlignmentLeft;
        _showAIDOCInfoLabel.text = @"AIDOC总资产";
    }
    return _showAIDOCInfoLabel;
}
//查看按钮
- (UIButton *)lookBtn {
    if (!_lookBtn) {
        _lookBtn = [UIButton buttonWithType:UIButtonTypeCustom];
        _lookBtn.frame = CGRectMake(SCREEN_WIDTH-60, 403/2 - 30, 60, 60);
        [_lookBtn setBackgroundColor:[UIColor clearColor]];
    }
    return _lookBtn;
}
//查看图
- (UIImageView *)lookImageView {
    if (!_lookImageView) {
        _lookImageView = [[UIImageView alloc] init];
        _lookImageView.frame = CGRectMake((_lookBtn.width-22)/2, (_lookBtn.width-22)/2, 22, 22);
        [_lookImageView setBackgroundColor:[UIColor clearColor]];
    }
    return _lookImageView;
}

@end
