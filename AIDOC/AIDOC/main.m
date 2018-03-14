//
//  main.m
//  AIDOC
//
//  Created by app on 18/1/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

int main(int argc, char * argv[]) {
    @autoreleasepool {
        [UINavigationBar appearance].barTintColor = [UIColor whiteColor];
        [[UINavigationBar appearance] setBackgroundColor:[UIColor whiteColor]];
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
