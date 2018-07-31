//
//  SolveViewController.m
//  AlarmDemo
//
//  Created by apple on 16/7/6.
//  Copyright © 2016年 apple. All rights reserved.
//

#import "SolveViewController.h"
#import "SolveModel.h"
#import "SolVeMapVIew.h"
#import "SolveCallViewController.h"
#import "SolveDetailViewController.h"
#import "TroubleDetailViewController.h"
@interface SolveViewController ()<BMKPoiSearchDelegate,BMKMapViewDelegate,BMKLocationServiceDelegate>
{
//    BMKPoiSearch *_searcher;
    BMKMapView *_bmkmapView;
//    BMKLocationService *_locService;
    BMKUserLocation *_myLocation;
    NSMutableArray *solveArr;
    int searchFlag;
}
@end
@implementation SolveViewController

-(void)viewWillAppear:(BOOL)animated    
{    
    [super viewWillAppear:animated];
    
}    
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.navigationItem.title  =@"北斗消防平台";
    
    //刷新
    UIButton *refreshBtn = [[UIButton alloc] initWithFrame:CGRectMake(0, 7, 30, 30)];
    [refreshBtn setImage:[UIImage imageNamed:@"refresh_img"] forState:UIControlStateNormal];
    [refreshBtn addTarget:self action:@selector(refreshBtnAction:) forControlEvents:UIControlEventTouchUpInside];
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:refreshBtn];
    
    searchFlag = 0;
    
    //地图
    _bmkmapView = [[BMKMapView alloc]initWithFrame:CGRectMake(0, 0, kScreenWidth, kScreenHeight)];
    
    [_bmkmapView setZoomLevel:20];
    [self.view addSubview:_bmkmapView];  
    
    
    _myLocation = [[BMKUserLocation alloc] init];
    //普通态  
    //以下_mapView为BMKMapView对象  
    _bmkmapView.showsUserLocation = YES;//显示定位图层  
    _bmkmapView.userTrackingMode = BMKUserTrackingModeNone;//设置定位的状态
    
    
    _bmkmapView.delegate = self; // 此处记得不用的时候需要置nil，否则影响内存的释放
    

    
    //请求数据
    [self _loadData];
    
    
}

//请求数据
- (void)_loadData{

    
    [YTNetworkRequest loadSolveWithUserID:[[CommonFunc getUserInformation].userId intValue] success:^(id result) {
        
        NSLog(@"%@",result);

        NSMutableArray *arr = [result valueForKey:@"data"];
        
        for (NSDictionary *dic in arr) {
            solveArr = [NSMutableArray array];
            SolveModel *solve = [[SolveModel alloc] initContentWithDic:dic];
            solve.buildID = [dic valueForKey:@"id"];
            [solveArr addObject:solve];
            BMKPointAnnotation* annotation = [[BMKPointAnnotation alloc]init];    
            CLLocationCoordinate2D coor; 
            coor.latitude = [solve.lat floatValue];   
            coor.longitude = [solve.lng floatValue];
            annotation.coordinate = coor;    
            annotation.title = @"这里是北京";   
            
            if (searchFlag == 0) {
                [_bmkmapView setCenterCoordinate:coor animated:YES]; 
                searchFlag ++;
            }
            
            [_bmkmapView addAnnotation:annotation];    
        }
        
        if ([[result valueForKey:@"ret"] intValue] == -1) {
            
            [[NSNotificationCenter defaultCenter] postNotificationName:KNOTIFICATION_LOGINCHANGE object:@NO];
        }
    } failure:^(NSString *error) {
        
    }];
}

- (void)refreshBtnAction:(UIButton *)sender{
      
    [self _loadData];
}

    
//不使用时将delegate设置为 nil    
-(void)viewWillDisappear:(BOOL)animated    
{
//    _bmkmapView.delegate = nil;
//    _locService.delegate = nil;
//    _searcher.delegate = nil;  

}

#pragma mark -
#pragma mark implement BMKMapViewDelegate

/**
 *根据anntation生成对应的View
 *@param mapView 地图View
 *@param annotation 指定的标注
 *@return 生成的标注View
 */
- (BMKAnnotationView *)mapView:(BMKMapView *)view viewForAnnotation:(id <BMKAnnotation>)annotation
{
    
    if ([annotation isKindOfClass:[BMKPointAnnotation class]]) {  
       
        BMKAnnotationView *newAnnotationView = [[BMKAnnotationView alloc] initWithAnnotation:annotation reuseIdentifier:@"myAnnotation"]; 
        newAnnotationView.enabled = YES;
        SolveModel *solve = solveArr[0];
//        newAnnotationView.tag = [solve.buildID intValue];
        newAnnotationView.userInteractionEnabled = YES;
        if ([solve.flag intValue]==0) {
            newAnnotationView.frame = CGRectMake(0, 0, 60, 90);
            newAnnotationView.backgroundColor =[UIColor clearColor];
            SolVeMapVIew *map = [[SolVeMapVIew alloc] initWithFrame:CGRectMake(0, 0, 60, 90)];
            map.userInteractionEnabled = YES;
            map.tag = [solve.buildID intValue];
            UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tapClicked:)];
            [map addGestureRecognizer:tap];    
            
            map.backgroundColor = [UIColor clearColor];
            map.arr = solveArr;
            [newAnnotationView addSubview:map];   
        }else if ([solve.flag intValue] == 1){
        
            newAnnotationView.frame = CGRectMake(0, 0, 40, 40);
            newAnnotationView.backgroundColor =[UIColor clearColor];
            UIButton *btn = [[UIButton alloc] initWithFrame:CGRectMake(0, 0, 40, 40)];
            [btn setBackgroundImage:[UIImage imageNamed:@"map_no_alarm"] forState:UIControlStateNormal];
            btn.tag = [solve.buildID intValue];
            [btn addTarget:self action:@selector(btnAction:) forControlEvents:UIControlEventTouchUpInside];
            [newAnnotationView addSubview:btn]; 
        
        }else if ([solve.flag intValue] == 2){
            
            newAnnotationView.frame = CGRectMake(0, 0, 40, 40);
            newAnnotationView.backgroundColor =[UIColor clearColor];
            UIButton *troubleBtn = [[UIButton alloc] initWithFrame:CGRectMake(0, 0, 40, 40)];
//            [btn setBackgroundImage:[UIImage imageNamed:@"map_no_alarm"] forState:UIControlStateNormal];
            troubleBtn.backgroundColor = [UIColor redColor];
            troubleBtn.tag = [solve.buildID intValue];
            [troubleBtn addTarget:self action:@selector(troubleBtnAction:) forControlEvents:UIControlEventTouchUpInside];
            [newAnnotationView addSubview:troubleBtn]; 
            
        }

         
        return newAnnotationView;
    }  
    return nil;  
}

- (void)tapClicked:(UITapGestureRecognizer *)gesture
{
    UIView *viewTag = (UIView *)gesture.view;
    SolveCallViewController *solveCall =[[SolveCallViewController alloc] init];
    solveCall.build_ID = [NSString stringWithFormat:@"%ld",(long)viewTag.tag];
    [self.navigationController pushViewController: solveCall animated:YES];
 
}
//
- (void)btnAction:(UIButton *)sender
{

    SolveDetailViewController *solveCall =[[SolveDetailViewController alloc] init];
    solveCall.build_ID = [NSString stringWithFormat:@"%ld",(long)sender.tag];
    [self.navigationController pushViewController: solveCall animated:YES];

}

//隐患详情
- (void)troubleBtnAction:(UIButton *)sender
{
    TroubleDetailViewController *troubleDetail = [[TroubleDetailViewController alloc] init];
    
    troubleDetail.dangerID =  [NSString stringWithFormat:@"%ld",(long)sender.tag];
    [self.navigationController pushViewController:troubleDetail animated:YES];

}
- (void)mapView:(BMKMapView *)mapView didSelectAnnotationView:(BMKAnnotationView *)view
{
    view.paopaoView.hidden = YES;
    [mapView setNeedsDisplay];

//    SolveCallViewController *solveCall =[[SolveCallViewController alloc] init];
//    solveCall.build_ID = [NSString stringWithFormat:@"%ld",(long)view.tag];
//    [self.navigationController pushViewController: solveCall animated:YES];
}

- (void)mapView:(BMKMapView *)mapView didAddAnnotationViews:(NSArray *)views
{
//    NSLog(@"didAddAnnotationViews");
}

#pragma mark -
#pragma mark implement BMKLocationServiceDelegate

//实现相关delegate 处理位置信息更新  
//处理方向变更信息  
- (void)didUpdateUserHeading:(BMKUserLocation *)userLocation  
{  
//     [_bmkmapView updateLocationData:userLocation];
//    _myLocation = userLocation;
}  
//处理位置坐标更新  
- (void)didUpdateBMKUserLocation:(BMKUserLocation *)userLocation  
{  
    
//    if (searchFlag == 0) {
        [_bmkmapView updateLocationData:userLocation];
       
  
//    }
//    searchFlag++;
    
}
//
//#pragma mark - UIGestureRecognizerDelegate
//- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldReceiveTouch:(UITouch *)touch
//{
//    // 若为UITableViewCellContentView（即点击了tableViewCell），则不截获Touch事件
//    if ([NSStringFromClass([touch.view class]) isEqualToString:@"UITableViewCellContentView"]) {
//        return NO;
//    }
//    return  YES;
//}
//#pragma -mark SolVeMapVIewDelegate
//- (void)toSloveCall:(NSString *)build_ID
//{
//    SolveCallViewController *solveCall =[[SolveCallViewController alloc] init];
//    solveCall.build_ID = build_ID;
//    [self.navigationController pushViewController: solveCall animated:YES];
//}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
@end
