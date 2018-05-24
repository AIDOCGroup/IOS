//
//  DeviceSectionCell.m
//  MiaoHealthConnectNewDemo
//
//  Created by 罗志平 on 2017/10/17.
//  Copyright © 2017年 MiaoHealth. All rights reserved.
//

#import "DeviceSectionCell.h"

@interface DeviceSectionCell()

@property (weak, nonatomic) IBOutlet UILabel *titleLabel;

@end

@implementation DeviceSectionCell

+ (DeviceSectionCell *)deviceSectionCellWithTableView:(UITableView *)tableView{
    return (DeviceSectionCell *)[[[NSBundle mainBundle] loadNibNamed:@"DeviceSectionCell" owner:nil options:nil] lastObject];
}

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier{
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        
    }
    return self;
}

- (void)awakeFromNib {
    [super awakeFromNib];
    self.mj_w = kMainScreenWidth;
    // Initialization code
}

- (void)setTitle:(NSString *)title{
    _title = title;
    self.titleLabel.text = title;
}
@end
