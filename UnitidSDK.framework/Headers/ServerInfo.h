//
//  ServerInfo.h
//  MultiKey
//
//  Created by 张鹤 on 2018/12/6.
//  Copyright © 2018 张鹤. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ServerInfo : NSObject
@property(copy,nonatomic)NSString *ip;
@property(assign,nonatomic)int port;
@end

NS_ASSUME_NONNULL_END
