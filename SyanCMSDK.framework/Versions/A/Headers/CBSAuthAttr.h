//
//  CBSAuthAttr.h
//  Spark-new
//
//  Created by 卢义思 on 2018/1/22.
//  Copyright © 2018年 XianAn. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CBSAuthAttr : NSObject

@property(strong, nonatomic) NSString *attr;
@property(strong, nonatomic) NSString *type;
@property(strong, nonatomic) NSString *certificate;
@property(strong, nonatomic) NSString *privateKey;
@property(strong, nonatomic) NSString *alias;
@property(nonatomic) long long lastUpdateTime;

- (instancetype)initFromJson:(NSDictionary *)json;
- (NSDictionary *)toJson;
@end
