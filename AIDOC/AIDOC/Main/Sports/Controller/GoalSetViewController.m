//
//  GoalSetViewController.m
//  AIDOC
//
//  Created by app on 18/1/15.
//  Copyright © 2018年 app. All rights reserved.
//

#import "GoalSetViewController.h"
@interface GoalSetViewController ()<UIPickerViewDataSource,UIPickerViewDelegate>
@property(nonatomic,copy)NSString *selectedStr;
@property(nonatomic,strong)NSArray *listArr;


@end

@implementation GoalSetViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = @"运动目标";
    self.view.backgroundColor = [UIColor whiteColor];
    _selectedStr = @"4000";
    _listArr = @[@"4000",@"5000",@"6000",@"7000",@"8000",@"9000",@"10000",@"11000",@"12000"];
    [self _initView];
    
}

- (void)_initView{
    
    //描述
    UILabel *labelDesc = [[UILabel alloc] initWithFrame:CGRectMake(20, 35, kScreenWidth-40, 60)];
    labelDesc.numberOfLines = 2;
    labelDesc.font = [UIFont systemFontOfSize:12];
    labelDesc.textColor = rgbColor(0x797979);
    labelDesc.textAlignment = NSTextAlignmentCenter;
    labelDesc.text = @"世界卫生组纪念品将走路设定为“设街上最好的运动“\n有关专家表示:每天6000步是走路最健康的步数";
    [self.view addSubview:labelDesc];
    //画虚线
    //要显示虚线的view
    UIView *lineView = [[UIView alloc] initWithFrame:CGRectMake(10, labelDesc.bottom + 32, kScreenWidth-20, 1)];
    lineView.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:lineView];
    
    CAShapeLayer *shapeLayer = [CAShapeLayer layer];
    [shapeLayer setBounds:lineView.bounds];
    [shapeLayer setPosition:CGPointMake(CGRectGetWidth(lineView.frame) / 2, CGRectGetHeight(lineView.frame))];
    [shapeLayer setFillColor:[UIColor clearColor].CGColor];
    //  设置虚线颜色为lightGrayColor
    [shapeLayer setStrokeColor:rgbColor(0xcccccc).CGColor];
    //  设置虚线宽度
    [shapeLayer setLineWidth:CGRectGetHeight(lineView.frame)];
    [shapeLayer setLineJoin:kCALineJoinRound];
    //  设置线宽，线间距
    [shapeLayer setLineDashPattern:[NSArray arrayWithObjects:[NSNumber numberWithInt:2], [NSNumber numberWithInt:2], nil]];
    //  设置路径
    CGMutablePathRef path = CGPathCreateMutable();
    CGPathMoveToPoint(path, NULL, 0, 0);
    CGPathAddLineToPoint(path, NULL, CGRectGetWidth(lineView.frame), 0);
    [shapeLayer setPath:path];
    CGPathRelease(path);
    //  把绘制好的虚线添加上来
    [lineView.layer addSublayer:shapeLayer];
    
    //正在修改运动目标
    UILabel *labelGoal = [[UILabel alloc] initWithFrame:CGRectMake(20, lineView.bottom + 25, kScreenWidth - 40, 20)];
    labelGoal.font = [UIFont boldSystemFontOfSize:16];
    labelGoal.textColor = rgbColor(0x0cb2f5);
    labelGoal.textAlignment = NSTextAlignmentCenter;
    labelGoal.text = @"正在修改运动目标";
    [self.view addSubview:labelGoal];
    
    // 选择框
    UIPickerView *pickerView = [[UIPickerView alloc] initWithFrame:CGRectMake(0, labelGoal.bottom + 20, kScreenWidth, 240)];
    // 显示选中框
    pickerView.showsSelectionIndicator=YES;
    pickerView.dataSource = self;
    pickerView.delegate = self;
    [self.view addSubview:pickerView];
    
    //设置按钮
    UIButton *setBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    [setBtn setTitle:@"设置" forState:UIControlStateNormal];
    [setBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    setBtn.titleLabel.font = [UIFont systemFontOfSize:16];
    [setBtn addTarget:self action:@selector(setBtnAction) forControlEvents:UIControlEventTouchUpInside];
    setBtn.frame = CGRectMake(40, kScreenHeight - 80,kScreenWidth - 80, 40);
    setBtn.backgroundColor = rgbColor(0x33b5e7);
    //设置圆角
    [setBtn setClipsToBounds:YES];
    setBtn.layer.cornerRadius = setBtn.height/2.0;//设置矩形四个圆角半径
    setBtn.layer.borderWidth = 1.0;//边框宽度
    setBtn.layer.borderColor = [UIColor whiteColor].CGColor;

    [self.view addSubview:setBtn];
    


}
#pragma Mark -- UIPickerViewDataSource
// pickerView 列数
- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView {
    return 1;
}

// pickerView 每列个数
- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component {
    
    return _listArr.count;
}

#pragma Mark -- UIPickerViewDelegate
// 每列宽度
- (CGFloat)pickerView:(UIPickerView *)pickerView widthForComponent:(NSInteger)component {
    
    return kScreenWidth;
}

- (CGFloat)pickerView:(UIPickerView *)pickerView rowHeightForComponent:(NSInteger)component
{
    return 40;
}
// 返回选中的行
- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component
{
    _selectedStr = [_listArr objectAtIndex:row];
}

//返回当前行的内容,此处是将数组中数值添加到滚动的那个显示栏上
-(NSString*)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    NSString  *_proNameStr = [_listArr objectAtIndex:row];
    return _proNameStr;
    
}
- (UIView *)pickerView:(UIPickerView *)pickerView viewForRow:(NSInteger)row forComponent:(NSInteger)component reusingView:(UIView *)view{
    //设置分割线的颜色
    for(UIView *singleLine in pickerView.subviews)
    {
        if (singleLine.frame.size.height < 2)
        {
            singleLine.backgroundColor = [UIColor colorWithRed:0.75f green:0.75f blue:0.75f alpha:1.00f];
        }
    }
    //设置文字的属性（改变picker中字体的颜色大小）
    UILabel *reasonLabel = [UILabel new];
    reasonLabel.textAlignment = NSTextAlignmentCenter;
    reasonLabel.text =[_listArr objectAtIndex:row];
    reasonLabel.font = [UIFont systemFontOfSize:22];
    reasonLabel.textColor = [UIColor darkGrayColor];
    //改变选中行颜色（设置一个全局变量，在选择结束后获取到当前显示行，记录下来，刷新picker）

    return reasonLabel;
}


- (void)setBtnAction{
    
    [YTNetworkRequest setSportsGoalWithTarget:_selectedStr success:^(id result) {
        
        dispatch_async(dispatch_get_main_queue(), ^{
           
            if ([self.delegate respondsToSelector:@selector(setSportGoal:)]) {
                [self.delegate setSportGoal:_selectedStr];
            }
            
            [self.navigationController popViewControllerAnimated:YES];

        
        });
        
        
    } failure:^(NSString *error) {
        
         [ProgressHUD showError:error];
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
