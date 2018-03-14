//
//  GoalSetViewController.h
//  AIDOC
//
//  Created by app on 18/1/15.
//  Copyright © 2018年 app. All rights reserved.
//

#import "BaseViewController.h"


@class GoalSetViewController;

@protocol GoalSetViewControllerDelegate <NSObject>

/**
 *  设置运动目标
 */
- (void)setSportGoal:(NSString *)sportgoal;

@end


@interface GoalSetViewController : BaseViewController

@property (nonatomic,weak) id <GoalSetViewControllerDelegate> delegate;

@end
