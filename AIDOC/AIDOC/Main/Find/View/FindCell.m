//
//  FindCell.m
//  AIDOC
//
//  Created by app on 18/1/17.
//  Copyright © 2018年 app. All rights reserved.
//

#import "FindCell.h"
#import "NSString+Category.h"
#import "UIImageView+WebCache.h"


@interface FindCell ()
@property (nonatomic, strong) UIView *boxView;
/**
 *  背景view
 */
@property (nonatomic, strong) UIView *bgView;
/**
 *  主图
 */
@property (nonatomic, strong) UIImageView *picView;
/**
 *  title
 */
@property (nonatomic, strong) UILabel *title;
/**
 *  创建时间
 */
@property (nonatomic ,strong) UIImageView *createdOnLblIcon;
/**
 *  创建时间lbl
 */
@property (nonatomic ,strong) UILabel *createdOnLbl;


/**
 *  分享图标
 */
@property (nonatomic ,strong) UIImageView *favouritesCountLblIcon;
/**
 *  分享文字
 */
@property (nonatomic ,strong) UILabel *favouritesCountLbl;

/**
 *  观看次数icon
 */
@property (nonatomic ,strong) UIImageView *watchIcon;
/**
 *  观看次数
 */
@property (nonatomic ,strong) UILabel *watchLbl;

/**
 *  barView
 */
@property (nonatomic, strong) UIView *barView;

/**
 * 浏览量
 */

//@property (nonatomic, strong) UILabel *viewIconLbl;
//@property (nonatomic,strong) UIImageView *imgPlView;
@end

@implementation FindCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}
- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        
        {
            
            UIView *boxView = [[UIView alloc] init];
            boxView.backgroundColor = [UIColor whiteColor];
            
            UIView *barView = [[UIView alloc] init];
            //主图
            UIImageView *picView = [[UIImageView alloc] init];
            picView.contentMode =  UIViewContentModeScaleToFill;
            picView.backgroundColor = [UIColor redColor];
//            
//            UIImageView *imgPlView = [[UIImageView alloc] init];
//            imgPlView.backgroundColor = [UIColor redColor];
//            imgPlView.hidden = YES;
//            [picView addSubview:imgPlView];
//            self.imgPlView = imgPlView;
//            
            self.picView = picView;
            [boxView addSubview:picView];
            
            //title
            UILabel *title = [[UILabel alloc] init];
            [title setFont:[UIFont systemFontOfSize:14]];
            [title setTextColor:rgbColor(0x333333)];
            title.numberOfLines = 0;
            self.title = title;
            
            [boxView addSubview:title];
            
            
            //创建时间
            UIImageView *createdOnLblIcon = [[UIImageView alloc] init];
            createdOnLblIcon.image = [UIImage imageNamed:@"fx_icon5_@x2"];
            self.createdOnLblIcon = createdOnLblIcon;
            [barView addSubview:createdOnLblIcon];
            
            //创建时间lbl
            UILabel *createdOnLbl = [[UILabel alloc] init];
            [createdOnLbl setFont:[UIFont systemFontOfSize:11]];
            createdOnLbl.text = @"12月21日";
            self.createdOnLbl = createdOnLbl;
            createdOnLbl.textColor = rgbColor(0xcccccc);
            [barView addSubview:createdOnLbl];
                        
            
            //分享图标
            UIImageView *favouritesCountLblIcon = [[UIImageView alloc] init];
            favouritesCountLblIcon.image = [UIImage imageNamed:@"fx_icon6_@x2"];
            self.favouritesCountLblIcon = favouritesCountLblIcon;
            [barView addSubview:favouritesCountLblIcon];
            
            //分享文字
            UILabel *favouritesCountLbl = [[UILabel alloc] init];
            [favouritesCountLbl setFont:[UIFont systemFontOfSize:11]];
            favouritesCountLbl.text = @"78";
            self.favouritesCountLbl = favouritesCountLbl;
            favouritesCountLbl.textColor = rgbColor(0xcccccc);
            [barView addSubview:favouritesCountLbl];
            
            
            //浏览量
            UIImageView *watchIcon = [[UIImageView alloc] init];
            watchIcon.image = [UIImage imageNamed:@"fx_icon7_@x2"];
            self.watchIcon = watchIcon;
            [barView addSubview:watchIcon];
            
            //浏览量文字
            UILabel *watchLbl = [[UILabel alloc] init];
            [watchLbl setFont:[UIFont systemFontOfSize:11]];
            watchLbl.text = @"178";
            self.watchLbl = watchLbl;
            watchLbl.textColor = rgbColor(0xcccccc);
            [barView addSubview:watchLbl];
            
            self.barView = barView;
            [boxView addSubview:barView];
            
            self.boxView = boxView;
            [self.contentView addSubview:boxView];
            
        }
    }
    return self;
}



- (void)layoutSubviews {
    [super layoutSubviews];
    
    //图片高度
    CGFloat picH = IS_IPHONE_5_OR_LESS?120:155;
    self.boxView.frame = CGRectMake(10, 12, self.frame.size.width - 20, 230);
    //主图
    self.picView.frame = CGRectMake(0, 0, self.frame.size.width, picH);
    
    //标题
    CGFloat titleFontSize = 16;
    CGFloat titleX = 10;
    CGFloat titleY = CGRectGetMaxY(self.picView.frame) + 14;
    CGFloat titleW = self.frame.size.width - titleX * 2;
    
    CGFloat titleH = [self.title.text sizeWithAttributesFontSize:titleFontSize lineSpacing:1 maxWidth:titleW].height;
    
    self.title.frame = CGRectMake(titleX, titleY, titleW, titleH);
    
    CGFloat barViewX = titleX;
    CGFloat barViewY = CGRectGetMaxY(self.title.frame) + 10;
    CGFloat barViewW = self.frame.size.width - titleX * 2;
    CGFloat barViewH = 20;
    self.barView.frame = CGRectMake(barViewX, barViewY, barViewW, barViewH);
  
    CGFloat iconW = 14.3;
    CGFloat iconH = 14.3;
    CGFloat margin = 10;

    //时间
    self.createdOnLblIcon.frame = CGRectMake(0, 2.5, iconW, iconH);
    [self.createdOnLbl sizeToFit];
    self.createdOnLbl.frame = CGRectMake(CGRectGetMaxX(self.createdOnLblIcon.frame) + 5, 2.5, self.createdOnLbl.frame.size.width, self.createdOnLbl.frame.size.height);
   
    //分享
    CGFloat favouritesCountX = CGRectGetMaxX(self.createdOnLbl.frame) + margin*5;
    self.favouritesCountLblIcon.frame = CGRectMake(favouritesCountX + 5, 2.5,iconW , iconH);
    [self.favouritesCountLbl sizeToFit];
    self.favouritesCountLbl.frame = CGRectMake(CGRectGetMaxX(self.favouritesCountLblIcon.frame) + 5,1, self.favouritesCountLbl.frame.size.width + 5, self.favouritesCountLblIcon.frame.size.height);
    
    //浏览量
    CGFloat viewIconX = CGRectGetMaxX(self.favouritesCountLbl.frame) + margin;
    self.watchIcon.frame = CGRectMake(viewIconX, 2.5,iconW + 3 , iconH);
    [self.watchLbl sizeToFit];
    self.watchLbl.frame = CGRectMake(CGRectGetMaxX(self.watchIcon.frame) + 2,2.5, self.watchIcon.frame.size.width + 60, self.watchIcon.frame.size.height);
    
    CGFloat frameH = CGRectGetMaxY(self.barView.frame) + 20;
    self.boxView.frame = CGRectMake(0, 0, self.frame.size.width, frameH);
}


- (void)setFindModel:(FindModel *)findModel{
    _findModel = findModel;
    //sticky 头条
    
    self.title.text = findModel.title;
    self.title.text = @"佳世客大家好";
    
    //分享格式化
    if ([NSString stringWithFormat:@"%lld",findModel.forward_num].length >= 4) {
        self.favouritesCountLbl.text = @"1000+";
    }else {
        self.favouritesCountLbl.text = [NSString stringWithFormat:@"%lld",findModel.forward_num];
    }
    
    //阅读格式化
    if ([NSString stringWithFormat:@"%lld",findModel.watch_num].length >= 4) {
        self.watchLbl.text = @"1000+";
    }else {
        self.watchLbl.text = [NSString stringWithFormat:@"%lld",findModel.watch_num];
    }
    
    NSDate *createOnDate = [[NSDate alloc] initWithTimeIntervalSince1970:findModel.postCreateOn / 1000.0];
//    self.createdOnLbl.text = createOnDate.timeIntervalDescription;
    
    NSString *url = findModel.url;
    
//    [self.picView sd_setImageWithURL:[NSURL URLWithString:[NSString stringWithFormat:@"%@@600w_90Q.jpg", url]] placeholderImage:[UIImage imageNamed:@"default_news_image"] options:SDWebImageRetryFailed];
    
    [self setNeedsLayout];
    [self setNeedsDisplay];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end
