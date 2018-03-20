//
//  LDBraceletEMVOperationDelegate.h
//  LDBraceletSDK
//
//  Created by houhm on 16/12/13.
//  Copyright © 2016年 houhm. All rights reserved.
//

#ifndef LDBraceletEMVOperationDelegate_h
#define LDBraceletEMVOperationDelegate_h



@protocol LDBraceletEMVOperationDelegate

- (void)emvContinueTrade:(int)aid;

- (void)emvSecondIssuance:(NSString *)issCode;

@end

#endif /* LDBraceletEMVOperationDelegate_h */
