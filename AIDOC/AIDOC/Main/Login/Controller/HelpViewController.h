//
//  HelpViewController.h
//  AIDOC
//
//  Created by app on 18/1/10.
//  Copyright © 2018年 app. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KIImagePager.h"

@interface HelpViewController : UIViewController
<
KIImagePagerDelegate,
KIImagePagerDataSource
>
{
    KIImagePager *_imagePager;
    NSMutableArray *_images;
    UIButton *_enterBtn;
}

@end
