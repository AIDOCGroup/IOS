//
//  MyLabel.m
//  AIDOC
//
//  Created by app on 2018/3/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import "MyLabel.h"

#import "MyLabel.h"

@implementation MyLabel

@synthesize verticalAlignment=_verticalAlignment;

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        self.verticalAlignment=VerticalAlignmentMiddle;
    }
    return self;
}
-(void)setVerticalAlignment:(VerticalAlignment)verticalAlignment
{
    _verticalAlignment=verticalAlignment;
    [self setNeedsDisplay];//重绘一下
}

-(CGRect)textRectForBounds:(CGRect)bounds limitedToNumberOfLines:(NSInteger)numberOfLines
{
    CGRect textRect=[super textRectForBounds:bounds limitedToNumberOfLines:numberOfLines];
    switch(self.verticalAlignment)
    {
        case VerticalAlignmentTop:
            textRect.origin.y=bounds.origin.y;
            break;
        case VerticalAlignmentMiddle:
            textRect.origin.y=bounds.origin.y+(bounds.size.height-textRect.size.height)/2.0;
            break;
        case VerticalAlignmentBottom:
            textRect.origin.y=bounds.origin.y+bounds.size.height-textRect.size.height;
            break;
        default:
            textRect.origin.y=bounds.origin.y+(bounds.size.height-textRect.size.height)/2.0;
            break;
    }
    return textRect;
}
-(void)drawTextInRect:(CGRect)rect
{
    CGRect actualRect=[self textRectForBounds:rect limitedToNumberOfLines:self.numberOfLines];//重新计算位置
    [super drawTextInRect:actualRect];
}

@end
