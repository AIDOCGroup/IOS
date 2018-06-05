//
//  DisplayCell.m
//  SDKTest
//
//  Created by 刘云梦 on 16/12/21.
//  Copyright © 2016年 miao.cn. All rights reserved.
//

#import "DisplayCell.h"
#import "Masonry.h"
#import "UIImageView+WebCache.h"
#import "UITableViewCell+HYBMasonryAutoCellHeight.h"

@implementation DisplayCell

+ (DisplayCell *)displayCellWithTableView:(UITableView *)tableView{
    DisplayCell *cell = (DisplayCell *)[tableView dequeueReusableCellWithIdentifier:@"DisplayCell"];
    if (!cell) {
        cell = [[DisplayCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"DisplayCell"];
    }
    return cell;
}

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier{
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
        //图片
        UIImageView *imageView = [[UIImageView alloc] init];
        [self.contentView addSubview:imageView];
        self.displayIv = imageView;
        
        //名称
        UILabel *nameLabel = [[UILabel alloc] init];
        nameLabel.numberOfLines = 0;
        nameLabel.font = [UIFont systemFontOfSize:15];
        [self.contentView addSubview:nameLabel];
        self.deviceNameLb = nameLabel;
        [self.deviceNameLb sizeToFit];
        //描述
        UILabel *descLabel = [[UILabel alloc] init];
        descLabel.numberOfLines = 0;
        descLabel.font = [UIFont systemFontOfSize:13];
        [self.contentView addSubview:descLabel];
        self.deviceDescLb = descLabel;
        [self.deviceDescLb sizeToFit];
        
        //绑定平台
        UILabel *platLabel = [[UILabel alloc] init];
        platLabel.numberOfLines = 0;
        platLabel.font = [UIFont systemFontOfSize:15];
        [self.contentView addSubview:platLabel];
        self.bindPlat = platLabel;
        [self.bindPlat sizeToFit];
        
        //masonry
        [self.displayIv mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(self.contentView.mas_left).offset(15);
            make.centerY.mas_equalTo(self.contentView);
            make.size.mas_equalTo(CGSizeMake(80, 80));
        }];
        
        [self.deviceNameLb mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(self.displayIv.mas_right).offset(20);
            make.top.mas_equalTo(self.displayIv.mas_top).offset(10);
            make.right.mas_lessThanOrEqualTo(self.contentView.mas_right).offset(-15);
        }];
        self.deviceNameLb.preferredMaxLayoutWidth = kMainScreenWidth - 80 - 20 - 30;

        
        [self.deviceDescLb mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(self.deviceNameLb.mas_left);
            make.top.mas_equalTo(self.deviceNameLb.mas_bottom).offset(10);
            make.right.mas_lessThanOrEqualTo(self.contentView.mas_right).offset(-15);
        }];
        self.deviceDescLb.preferredMaxLayoutWidth = kMainScreenWidth - 80 - 20 - 30;
        
        [self.bindPlat mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(self.deviceDescLb.mas_left);               make.top.mas_equalTo(self.deviceDescLb.mas_bottom).offset(10);
            make.right.mas_lessThanOrEqualTo(self.contentView.mas_right).offset(-15);
        }];
        self.bindPlat.preferredMaxLayoutWidth = kMainScreenWidth - 80 - 20 - 30;
        
        self.hyb_bottomOffsetToCell = 50;

    }
    return self;
}


- (void)setDisplayModel:(DisplayModel *)displayModel{
    _displayModel = displayModel;
    [self.displayIv sd_setImageWithURL:[NSURL URLWithString:displayModel.imageUrl]];
    self.deviceNameLb.text = displayModel.name;
    switch (displayModel.link_type) {
        case PeripheralsAttendedModeBluetooth:
            self.deviceDescLb.text = @"蓝牙设备";
            break;
        case PeripheralsAttendedModeQRCode:
            self.deviceDescLb.text = @"二维码设备";
            break;
        case PeripheralsAttendedModeWebAuthority:
            self.deviceDescLb.text = @"Web授权设备";
            break;
        case PeripheralsAttendedModePort:
            self.deviceDescLb.text = @"API设备";
            break;
        default:
            self.deviceDescLb.text = @"未知设备";
            break;
    }
    self.bindPlat.text = displayModel.descr;
}

@end
