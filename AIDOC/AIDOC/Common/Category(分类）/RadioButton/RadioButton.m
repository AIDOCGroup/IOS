//
//  RadioButton.m
//  RadioButton
//
//  Created by ohkawa on 11/03/23.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "RadioButton.h"

@interface RadioButton()



@end

@implementation RadioButton

@synthesize groupId=_groupId;
@synthesize index=_index;

static const NSUInteger kRadioButtonWidth  = 20;
static const NSUInteger kRadioButtonHeight = 20;

static NSMutableArray *rb_instances=nil;
static NSMutableDictionary *rb_observers=nil;

#pragma mark - Observer

+(void)addObserverForGroupId:(NSString*)groupId observer:(id)observer{
    if(!rb_observers){
        rb_observers = [[NSMutableDictionary alloc] init];
    }
    
    if ([groupId length] > 0 && observer) {
        [rb_observers setObject:observer forKey:groupId];
        // Make it weak reference
    }
}

#pragma mark - Manage Instances

+(void)registerInstance:(RadioButton*)radioButton{
    if(!rb_instances){
        rb_instances = [[NSMutableArray alloc] init];
    }
    
    [rb_instances addObject:radioButton];
    // Make it weak reference
}

#pragma mark - Class level handler

+(void)buttonSelected:(RadioButton*)radioButton{
    
    // Notify observers
    if (rb_observers) {
        id observer= [rb_observers objectForKey:radioButton.groupId];
        
        if(observer && [observer respondsToSelector:@selector(radioButtonSelectedAtIndex:inGroup:)]){
            [observer radioButtonSelectedAtIndex:radioButton.index inGroup:radioButton.groupId];
        }
    }
    
    // Unselect the other radio buttons
    if (rb_instances) {
        for (int i = 0; i < [rb_instances count]; i++) {
            RadioButton *button = [rb_instances objectAtIndex:i];
            if (![button isEqual:radioButton] && [button.groupId isEqualToString:radioButton.groupId]) {
                [button otherButtonSelected:radioButton];
            }
        }
    }
}

#pragma mark - Object Lifecycle

-(id)initWithGroupId:(NSString*)groupId index:(NSUInteger)index{
    self = [self init];
    if (self) {
        _groupId = groupId;
        _index = index;
    }
    return  self;
}

- (id)init{
    self = [super init];
    if (self) {
        [self defaultInit];
    }
    return self;
}

#pragma mark - Tap handling
-(void)handleButtonTap:(id)sender{
    
    [_button setSelected:YES];
    [RadioButton buttonSelected:self];
}

- (void)setSelectedSexBtn:(BOOL)selectedSexBtn {
    
    _selectedSexBtn = selectedSexBtn;
    
    [_button setSelected:YES];
    [RadioButton buttonSelected:self];
    
}

-(void)otherButtonSelected:(id)sender{
    // Called when other radio button instance got selected
    if(_button.selected){
        [_button setSelected:NO];
    }
}

#pragma mark - RadioButton init

-(void)defaultInit{
    //sexImg
    _sexImgView = [[UIImageView alloc] init];
    [self addSubview:_sexImgView];
    //sexName
    _sexName = [[UILabel alloc] init];
    _sexName.font = [UIFont systemFontOfSize:16];
    _sexName.textColor = [UIColor colorWithRed:77/255.0 green:77/255.0 blue:77/255.0 alpha:1];
    [self addSubview:_sexName];
    
    // Customize UIButton
    self.backgroundColor = [UIColor whiteColor];
    _button = [UIButton buttonWithType:UIButtonTypeCustom];
    
    _button.adjustsImageWhenHighlighted = NO;
    
    [_button setImage:[UIImage imageNamed:@"btn_no_select_me"] forState:UIControlStateNormal];
    
    [_button setImage:[UIImage imageNamed:@"btn_select_me"] forState:UIControlStateSelected];
    
    [_button addTarget:self action:@selector(handleButtonTap:) forControlEvents:UIControlEventTouchUpInside];
    
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleButtonTap:)];
    
    [self addGestureRecognizer:tap];
    [self addSubview:_button];
    [RadioButton registerInstance:self];
    
}


- (void)layoutSubviews {
    [super layoutSubviews];
    
    CGFloat frameW = self.frame.size.width;
    CGFloat frameH = self.frame.size.height;
    
    CGFloat margin = 10.;
    CGFloat btnX = frameW - kRadioButtonWidth - margin;
    CGFloat btnY = (frameH - kRadioButtonHeight) / 2;
    _button.frame = CGRectMake(btnX, btnY,kRadioButtonWidth, kRadioButtonHeight);
    
    
    CALayer *layer = [[CALayer alloc] init];
    layer.frame = CGRectMake(0,frameH - 1, frameW, 1);
    layer.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent:0.05].CGColor;
    
    [self.layer addSublayer:layer];
    
    //sexImg
    _sexImgView.image = [UIImage imageNamed:self.sexImg];
    _sexImgView.frame = CGRectMake(10,(frameH - 16) /2, 17, 16);
    //sexName
    _sexName.text = self.sex;
    [_sexName sizeToFit];
    
    _sexName.frame = CGRectMake(CGRectGetMaxX(_sexImgView.frame) + 10, (frameH - _sexName.frame.size.height) / 2 , _sexName.frame.size.width,_sexName.frame.size.height );
    
    [_button setImage:[UIImage imageNamed:@"btn_select_me"] forState:UIControlStateSelected];
}

@end
