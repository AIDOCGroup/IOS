//
//  SignInViewController.h
//  AIDOC
//
//  Created by app on 18/1/17.
//  Copyright © 2018年 app. All rights reserved.
//

#import "BaseViewController.h"
#import "VRGCalendarView.h"
@interface SignInViewController : BaseViewController <VRGCalendarViewDelegate>
{
    BOOL _todayIsSign;
    VRGCalendarView *_calendarView;
}


@end
