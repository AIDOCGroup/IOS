//
//  HWSlider.m
//  HWSlider
//
//  Created by wangqibin on 2018/1/3.
//  Copyright © 2018年 wqb. All rights reserved.
//

#import "HWSlider.h"
#import "UIView+Additions.h"

@interface HWSlider ()

@property (nonatomic, weak) UILabel *scoreLabel;
@property (nonatomic, weak) UIImageView *arrowImage;
@property (nonatomic, weak) UIView *backView;
@property (nonatomic, weak) UIView *trackView;
@property (nonatomic, weak) UIImageView *thumb;

@end

@implementation HWSlider

- (instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame]) {
        self.backgroundColor = [UIColor whiteColor];
        
        UILabel *scoreLabel = [[UILabel alloc] initWithFrame:CGRectMake(self.bounds.size.width - 40, 0, 40, 17)];
        scoreLabel.font = [UIFont fontWithName:@"PingFangSC-Regular" size:12];
        scoreLabel.textColor = [UIColor whiteColor];
        scoreLabel.textAlignment = NSTextAlignmentCenter;
        scoreLabel.hidden = YES;
        [self addSubview:scoreLabel];
        _scoreLabel = scoreLabel;
        //气泡箭头
        UIImageView *arrowImage = [[UIImageView alloc] initWithFrame:CGRectMake(self.bounds.size.width - 8, scoreLabel.bottom+3, 8, 8)];
        [arrowImage setImage:[UIImage imageNamed:@"icon_sy_sj"]];
        [self addSubview:arrowImage];
        _arrowImage = arrowImage;
        
        //轨道背景
        UIView *backView = [[UIView alloc] initWithFrame:CGRectMake(0, arrowImage.bottom+4, self.bounds.size.width, 8)];
        backView.backgroundColor = rgbColor(0xF5F7FA);
        backView.layer.cornerRadius = 4.0f;
        backView.layer.masksToBounds = YES;
        [self addSubview:backView];
        _backView = backView;
        
        //轨道前景
        UIView *trackView = [[UIView alloc] initWithFrame:CGRectMake(1, 2, self.bounds.size.width-2, 4)];
        trackView.backgroundColor = rgbColor(0x73B0FC);
        trackView.layer.cornerRadius = 2.0f;
        trackView.layer.masksToBounds = YES;
        [backView addSubview:trackView];
        _trackView = trackView;
    }
    
    return self;
}

- (void)setScore:(float)score
{
    _score = score;
    NSNumber *scoreNum = [NSNumber numberWithFloat:_score];
    _scoreLabel.text = [NSString stringWithFormat:@"%d%%",[scoreNum intValue]*10];
    //刷新视图
    [self reloadViewWithThumbCeneterX:_score / 10.0 * self.bounds.size.width];
}

- (void)reloadViewWithThumbCeneterX:(CGFloat)thumbCeneterX
{
    //更新轨道前景色
    _trackView.frameWidth = thumbCeneterX;
    
    //更新箭头位置
    _arrowImage.centerX = thumbCeneterX;
    _scoreLabel.centerX = thumbCeneterX;
}

- (void)setHideScoreLabel:(BOOL)hideScoreLabel{
    _hideScoreLabel = hideScoreLabel;
    if (!_hideScoreLabel) {
        _scoreLabel.hidden = NO;
    }else{
        _scoreLabel.hidden = YES;
        _arrowImage.frame = CGRectMake(self.bounds.size.width - 8, 0, 8, 8);
        _backView.frame = CGRectMake(0, _arrowImage.bottom+4, self.bounds.size.width, 8);
    }
}
@end
