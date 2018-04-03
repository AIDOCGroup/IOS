//
//  PMImagePickerController.m
//  PMChat
//
//  Created by Eason on 15/8/11.
//  Copyright (c) 2015年 Eason. All rights reserved.
//

#import "PMImagePickerController.h"
#import <AVFoundation/AVFoundation.h>
@interface PMImagePickerController ()

@end

@implementation PMImagePickerController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
//    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
//    [[UINavigationBar appearance] setBarTintColor:rgbColor(0xdd443f)];
//    [self.navigationBar setTintColor:[UIColor whiteColor]];
//    [self.navigationBar setTitleTextAttributes:@{NSForegroundColorAttributeName: [UIColor whiteColor]}];
//    
    if (self.sourceType == UIImagePickerControllerSourceTypeCamera) {

        NSString *mediaType = AVMediaTypeVideo;
        AVAuthorizationStatus authStatus = [AVCaptureDevice authorizationStatusForMediaType:mediaType];
        if(authStatus == AVAuthorizationStatusRestricted || authStatus == AVAuthorizationStatusDenied){

            NSString *cameraTips = @"请再iPhone的“设置-隐私-相机”选项中，允许天医访问你的相机";
            UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:cameraTips
                                                                message:nil delegate:self
                                                      cancelButtonTitle:@"好" otherButtonTitles: nil];
            [alertView show];
        }
    }
    
}
- (void)navigationController:(UINavigationController *)navigationController willShowViewController:(UIViewController *)viewController animated:(BOOL)animated
{
    self.navigationItem.leftBarButtonItem.tintColor = [UIColor blackColor];
    self.navigationItem.rightBarButtonItem.tintColor = [UIColor blackColor];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
