//
//  TZVideoPlayerController.m
//  TZImagePickerController
//
//  Created by 谭真 on 16/1/5.
//  Copyright © 2016年 谭真. All rights reserved.
//

#import "TZVideoPlayerController.h"
#import <MediaPlayer/MediaPlayer.h>
#import "UIView+Layout.h"
#import "TZImageManager.h"
#import "TZAssetModel.h"
#import "TZImagePickerController.h"
#import "TZPhotoPreviewController.h"

@interface TZVideoPlayerController ()<UIAlertViewDelegate> {
    AVPlayer *_player;
    UIButton *_playButton;
    UIImage *_cover;
    
    UIView *_toolBar;
    UIButton *_okButton;
    UIProgressView *_progress;
    //
    UIView *_navBar;
    UILabel *_titleLabel;
    UIButton *_backButton;
    UIButton *_deleteButton;
}
@end

@implementation TZVideoPlayerController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor blackColor];
    self.navigationItem.title = [NSBundle tz_localizedStringForKey:@"Preview"];
    [self configMoviePlayer];
}

- (void)configMoviePlayer {

    [[TZImageManager manager] getPhotoWithAsset:_model.asset completion:^(UIImage *photo, NSDictionary *info, BOOL isDegraded) {
        _cover = photo;
    }];
    
    [[TZImageManager manager] getVideoWithAsset:_model.asset completion:^(AVPlayerItem *playerItem, NSDictionary *info) {
        dispatch_async(dispatch_get_main_queue(), ^{
            _player = [AVPlayer playerWithPlayerItem:playerItem];
            AVPlayerLayer *playerLayer = [AVPlayerLayer playerLayerWithPlayer:_player];
            playerLayer.frame = self.view.bounds;
            [self.view.layer addSublayer:playerLayer];
            [self addProgressObserver];
            [self configPlayButton];
            [self configBottomToolBar];
            [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(pausePlayerAndShowNaviBar) name:AVPlayerItemDidPlayToEndTimeNotification object:_player.currentItem];
        });
    }];
}

/// Show progress，do it next time / 给播放器添加进度更新,下次加上
- (void)addProgressObserver{

    AVPlayerItem *playerItem = _player.currentItem;
    UIProgressView *progress = _progress;
    [_player addPeriodicTimeObserverForInterval:CMTimeMake(1.0, 1.0) queue:dispatch_get_main_queue() usingBlock:^(CMTime time) {
        float current = CMTimeGetSeconds(time);
        float total = CMTimeGetSeconds([playerItem duration]);
        if (current) {
            [progress setProgress:(current/total) animated:YES];
        }
    }];
}

- (void)configPlayButton {
    _playButton = [UIButton buttonWithType:UIButtonTypeCustom];
    _playButton.frame = CGRectMake(0, 64, self.view.tz_width, self.view.tz_height - 64 - 44);
    [_playButton setImage:[UIImage imageNamedFromMyBundle:@"MMVideoPreviewPlay.png"] forState:UIControlStateNormal];
    [_playButton setImage:[UIImage imageNamedFromMyBundle:@"MMVideoPreviewPlayHL.png"] forState:UIControlStateHighlighted];
    [_playButton addTarget:self action:@selector(playButtonClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_playButton];
}

- (void)configBottomToolBar {
    //
    _navBar = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.tz_width, 64)];
    _navBar.backgroundColor =[UIColor whiteColor];
    [self.view addSubview:_navBar];
    //
    _titleLabel = [[UILabel alloc]init];
    _titleLabel.frame = CGRectMake((self.view.tz_width - 100)/2, 20, 100, 44);
    _titleLabel.font = [UIFont systemFontOfSize:16];
    _titleLabel.textColor = [UIColor blackColor];
    _titleLabel.textAlignment = NSTextAlignmentCenter;
    _titleLabel.text = @"1/1";//[NSBundle tz_localizedStringForKey:@"Preview"]
    [_navBar addSubview:_titleLabel];
    //
    _backButton = [UIButton buttonWithType:UIButtonTypeCustom];
    _backButton.frame = CGRectMake(10, 20, 44, 44);
    [_backButton setImage:[UIImage imageNamed:@"返回按钮"] forState:UIControlStateNormal];
    _backButton.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
    /*[_backButton block:^(id sender) {
        [self dismissViewControllerAnimated:YES completion:^{
            
        }];
    }];*/
    [_navBar addSubview:_backButton];
    //
    _deleteButton = [UIButton buttonWithType:UIButtonTypeCustom];
    _deleteButton.frame =  CGRectMake(self.view.tz_width - 44 - 12, 20, 44, 44);
    [_deleteButton setImage:[UIImage imageNamed:@"发布删除"] forState:UIControlStateNormal];
    /*
    [_deleteButton block:^(id sender) {
        UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"要删除此视频吗?" message:nil delegate:self cancelButtonTitle:@"取消" otherButtonTitles:@"确定", nil];
        [alert show];
    }];*/
    [_navBar addSubview:_deleteButton];
    
    
    _toolBar = [[UIView alloc] initWithFrame:CGRectMake(0, self.view.tz_height - 44, self.view.tz_width, 44)];
    CGFloat rgb = 34 / 255.0;
    _toolBar.backgroundColor = [UIColor colorWithRed:rgb green:rgb blue:rgb alpha:1.0];
    _toolBar.alpha = 0.7;
    
    _okButton = [UIButton buttonWithType:UIButtonTypeCustom];
    _okButton.frame = CGRectMake(self.view.tz_width - 44 - 12, 0, 44, 44);
    _okButton.titleLabel.font = [UIFont systemFontOfSize:16];
    [_okButton addTarget:self action:@selector(okButtonClick) forControlEvents:UIControlEventTouchUpInside];
    [_okButton setTitle:[NSBundle tz_localizedStringForKey:@"Done"] forState:UIControlStateNormal];
    TZImagePickerController *imagePickerVc = (TZImagePickerController *)self.navigationController;
    [_okButton setTitleColor:imagePickerVc.oKButtonTitleColorNormal forState:UIControlStateNormal];
    
    [_toolBar addSubview:_okButton];
    [self.view addSubview:_toolBar];
}

-(void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex{
    if (buttonIndex == 1) {
        if (self.block) {
            self.block();
        }
        [self dismissViewControllerAnimated:YES completion:^{
            
        }];
    }
}

#pragma mark - Click Event

- (void)playButtonClick {
    CMTime currentTime = _player.currentItem.currentTime;
    CMTime durationTime = _player.currentItem.duration;
    if (_player.rate == 0.0f) {
        if (currentTime.value == durationTime.value) [_player.currentItem seekToTime:CMTimeMake(0, 1)];
        [_player play];
        [self.navigationController setNavigationBarHidden:YES];
        _toolBar.hidden = YES;
        _navBar.hidden = YES;
        [_playButton setImage:nil forState:UIControlStateNormal];
        if (iOS7Later) [UIApplication sharedApplication].statusBarHidden = YES;
    } else {
        [self pausePlayerAndShowNaviBar];
    }
}

- (void)okButtonClick {
    TZImagePickerController *imagePickerVc = (TZImagePickerController *)self.navigationController;
    if ([imagePickerVc.pickerDelegate respondsToSelector:@selector(imagePickerController:didFinishPickingVideo:sourceAssets:)]) {
        [imagePickerVc.pickerDelegate imagePickerController:imagePickerVc didFinishPickingVideo:_cover sourceAssets:_model.asset];
    }
    if (imagePickerVc.didFinishPickingVideoHandle) {
        imagePickerVc.didFinishPickingVideoHandle(_cover,_model.asset);
    }
    if (self.navigationController) {
        if (imagePickerVc.autoDismiss) {
            [self.navigationController dismissViewControllerAnimated:YES completion:nil];
        }
    } else {
        [self dismissViewControllerAnimated:YES completion:nil];
    }
}

#pragma mark - Notification Method

- (void)pausePlayerAndShowNaviBar {
    [_player pause];
    _toolBar.hidden = NO;
    _navBar.hidden = NO;
    [self.navigationController setNavigationBarHidden:NO];
    [_playButton setImage:[UIImage imageNamedFromMyBundle:@"MMVideoPreviewPlay.png"] forState:UIControlStateNormal];
    if (iOS7Later) [UIApplication sharedApplication].statusBarHidden = NO;
}

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

@end
