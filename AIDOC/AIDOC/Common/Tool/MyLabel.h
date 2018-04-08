//
//  MyLabel.h
//  AIDOC
//
//  Created by app on 2018/3/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum
{
    VerticalAlignmentTop=0,
    VerticalAlignmentMiddle,//default
    VerticalAlignmentBottom,
    
}VerticalAlignment;

@interface MyLabel : UILabel
{
@private
    VerticalAlignment _verticalAlignment;
}

@property(nonatomic)VerticalAlignment verticalAlignment;

@end

