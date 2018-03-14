//
//  BQDataService.m
//  AIDOC
//
//  Created by app on 18/1/8.
//  Copyright © 2018年 app. All rights reserved.
//

#import "BQDataService.h"

@implementation BQDataService

+ (instancetype)shareBQDataService {
    
    static BQDataService *tool;
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        tool = [[self alloc] init];
    });
    
    return tool;
}

- (void)request:(NSString *)URLString parameters:(id)parameters requestType:(RequestType)type success:(void (^)(id))success failure:(void (^)( NSString *))failure {
    
    NSString *tokenStr = [CommonFunc getUserInformation].token;
//    NSString *userIdStr = [NSString stringWithFormat:@"%@",[CommonFunc getUserInformation].userId];
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] init];
//    [request setValue:userIdStr forHTTPHeaderField:@"userId"];
    [request setValue:tokenStr forHTTPHeaderField:@"X-Token"];
    [request setValue:@"IOS" forHTTPHeaderField:@"X-Client"];
    [request setURL:[NSURL URLWithString:URLString]];
    
    NSString *httpMethod;
    
    switch (type) {
        case RequestTypeGet:
            httpMethod = @"GET";
            break;
        case RequestTypePut:
            httpMethod = @"PUT";
            break;
        case RequestTypeDelete:
            httpMethod = @"DELETE";
            break;
        case RequestTypePost:
            httpMethod = @"POST";
            break;
            
        default:
            httpMethod = @"POST";
            break;
    }
    
    request.HTTPMethod  = httpMethod;
    
    if (parameters != nil) {
        
        //NSData *data = [NSJSONSerialization dataWithJSONObject:parameters options:NSJSONWritingPrettyPrinted error:nil];
        request.HTTPBody = parameters;
    }
    
    [[[NSURLSession sharedSession] dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        NSHTTPURLResponse *rp = (NSHTTPURLResponse *)response;
        
        dispatch_async(dispatch_get_main_queue(), ^{
            NSLog(@"%@",rp.URL);
            if(rp.statusCode == 200){
                
                success(data);
                
            }else {
                
                if (rp == nil) {
                    
                    failure(@"服务器错误");
                    
                }else
                {
                    NSDictionary *DIC = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
                    
                    NSString *err_msg = [DIC valueForKey:@"err_msg"];
                    
                    failure(err_msg);
                    
                }
                
            }
        });
        
        
    }] resume];
    
}

- (void)uploadFileWithData:(NSData *)aData fileName:(NSString *)afileName completed:(void (^)(NSString *))completed failure:(void (^)(NSString *))failure{
    
    NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
    [dict setValue:afileName forKey:@"file_name"];
//    NSString *urlStr = [NSString stringWithFormat:@"%@%@",IABaseURL,IABaseURL];
//    [[BQDataService shareBQDataService] request:urlStr parameters:dict requestType:RequestTypePost success:^(id responseObject) {
//        
//        NSDictionary *result = [NSJSONSerialization JSONObjectWithData:responseObject options:0 error:nil];
//        
//        // 上传大小
//        NSMutableURLRequest *request = [[NSMutableURLRequest alloc] init];
//        request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:[result valueForKey:@"upload_url"]]];
//        [request setHTTPMethod:@"PUT"];
//        [request setHTTPBody:aData];
//        
//        [request setValue:[[NSNumber numberWithInteger:[aData length]] description] forHTTPHeaderField:@"Content-Length"];
//        
//        [NSURLConnection sendAsynchronousRequest:request queue:[NSOperationQueue mainQueue] completionHandler:^(NSURLResponse *response, NSData *data, NSError *connectionError) {
//            
//            NSHTTPURLResponse *rp = (NSHTTPURLResponse *)response;
//            dispatch_async(dispatch_get_main_queue(), ^{
//                
//                if (rp.statusCode == 200) {
//                    completed([result valueForKey:@"pic_url"]);
//                }
//            });
//            
//        }];
//        
//    } failure:^(NSString *error) {
//        
//        NSLog(@"error %@",error);
//        
//        dispatch_async(dispatch_get_main_queue(), ^{
//            
//            failure(error);
//        });
//        
//        
//    }];
//    
    
}
@end
