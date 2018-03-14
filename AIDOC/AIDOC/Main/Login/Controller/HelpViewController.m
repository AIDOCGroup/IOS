//
//  HelpViewController.m
//  AIDOC
//
//  Created by app on 18/1/10.
//  Copyright © 2018年 app. All rights reserved.
//

#import "HelpViewController.h"

@interface HelpViewController ()

@end

@implementation HelpViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    _imagePager = [[KIImagePager alloc] initWithFrame:self.view.bounds];
    _imagePager.hidePageControl                     = YES;
    _imagePager.slideshowTimeInterval               = 1000;
    _imagePager.slideshowShouldCallScrollToDelegate = YES;
    _imagePager.dataSource                          = self;
    _imagePager.delegate                            = self;
    
    _enterBtn = [[UIButton alloc] initWithFrame:CGRectMake(0, 400*(self.view.width/320), self.view.width, 80*(self.view.width/320))];
    _enterBtn.backgroundColor = [UIColor colorWithWhite:0 alpha:0];
    _enterBtn.hidden = YES;
    
    [_enterBtn addTarget:self action:@selector(hideViewController) forControlEvents:UIControlEventTouchUpInside];
    
    [self.view addSubview:_imagePager];
    [self.view addSubview:_enterBtn];
    
}

- (NSArray *)arrayWithImages:(KIImagePager*)pager{
    
    _images = [NSMutableArray new];
    
    [_images addObject:[UIImage imageNamed:@"page1"]];
    [_images addObject:[UIImage imageNamed:@"page2"]];
    [_images addObject:[UIImage imageNamed:@"page3"]];
    [_images addObject:[UIImage imageNamed:@"page4"]];
    
    
    return _images;
}

- (UIViewContentMode)contentModeForImage:(NSUInteger)image inPager:(KIImagePager *)pager{
    return UIViewContentModeScaleAspectFill;
}
- (NSString *) captionForImageAtIndex:(NSUInteger)index inPager:(KIImagePager *)pager{
    return nil;
}
- (void) imagePager:(KIImagePager *)imagePager didSelectImageAtIndex:(NSUInteger)index
{
    NSLog(@"click: %zd", index);
}
- (void)imagePager:(KIImagePager *)imagePager didScrollToIndex:(NSUInteger)index{
    
    _enterBtn.hidden = (index != _images.count-1);
    
}

- (void)hideViewController{
    
    [self dismissViewControllerAnimated:YES completion:^{
        [[CommonFunc sharedCommonFunc] setInitial:PM_CHAT_INITIAL];
    }];
    
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
