//
//  PINInfo.h
//  MultiKey
//
//  Created by 张鹤 on 2018/12/6.
//  Copyright © 2018 张鹤. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PINInfo : NSObject
@property(nonatomic,assign,readonly)int mMaxRetryCount;

@property(nonatomic,assign,readonly)int mRemainRetryCount;

@property(nonatomic,assign,readonly)BOOL mDefaultPIN;
-(instancetype)initWithMaxretry:(int)retrycount remainRetrycount:(int)remaincount defaultPin:(BOOL)defaultPin;

@end

NS_ASSUME_NONNULL_END
