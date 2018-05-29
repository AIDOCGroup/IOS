//
//  DeviceTypeCell.m
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/7/13.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import "DeviceTypeCell.h"

@interface DeviceTypeCell ()

@property (nonatomic , weak) UIImageView *iconView;

@property (nonatomic , weak) UILabel *titleLabel;
@end

@implementation DeviceTypeCell

+ (DeviceTypeCell *)deviceTypeCell:(UICollectionView *)collectionView indexPath:(NSIndexPath *)indexPath{
    DeviceTypeCell *cell = (DeviceTypeCell *)[collectionView dequeueReusableCellWithReuseIdentifier:@"DeviceTypeCell" forIndexPath:indexPath];
    return cell;
}

- (instancetype)initWithFrame:(CGRect)frame{
    if (self = [super initWithFrame:frame]) {
        self.layer.masksToBounds = YES;
        self.layer.cornerRadius = 10;
        UIImageView *imageView = [[UIImageView alloc] init];
        [self.contentView addSubview:imageView];
        self.iconView = imageView;
        
        UILabel *titleLabel = [[UILabel alloc] init];
        titleLabel.textAlignment = NSTextAlignmentCenter;
        titleLabel.numberOfLines = 2;
        titleLabel.textColor = [UIColor lightGrayColor];
        titleLabel.font = [UIFont systemFontOfSize:15];
        [self.contentView addSubview:titleLabel];
        self.titleLabel = titleLabel;
        
        //masonry
        [self.iconView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.centerX.mas_equalTo(self.mas_centerX);
            make.top.mas_equalTo(5);
            make.size.mas_equalTo(CGSizeMake(65, 65));
        }];
        
        [self.titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.centerX.mas_equalTo(self.mas_centerX);
            make.top.mas_equalTo(self.iconView.mas_bottom).offset(0);
            make.size.mas_equalTo(CGSizeMake(100, 20));
        }];
    }
    return self;
}

- (void)setDeviceType:(MCDeviceType *)deviceType{
    _deviceType = deviceType;
    [self.iconView sd_setImageWithURL:[NSURL URLWithString:deviceType.logo] placeholderImage:nil options:SDWebImageRefreshCached];
    self.titleLabel.text = deviceType.type_name;
}
@end
