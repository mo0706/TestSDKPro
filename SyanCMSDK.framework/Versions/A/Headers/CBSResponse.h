//
//  CBSResponse.h
//  SyanCMSDK
//
//  Created by 卢义思 on 2018/3/14.
//  Copyright © 2018年 XianAn. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CBSResponse : NSObject

@property(nonatomic) int ret;
@property(strong, nonatomic) NSString *message;
@property(strong, nonatomic) NSString *result;
@property(strong, nonatomic) NSString *extention;
@end
