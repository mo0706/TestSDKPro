//
//  ECCSignatureBlob.h
//  MultiKey
//
//  Created by 张鹤 on 2018/12/6.
//  Copyright © 2018 张鹤. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ECCSignatureBlob : NSObject
@property(nonatomic,strong,readonly)NSData *s;
@property(nonatomic,strong,readonly)NSData *r;


/**
 判断当前对象是否合法
 
 @return yes合法，no不合法
 */
-(BOOL) isValid;
/**
 设置r
 
 @param r r
 */
-(void)setR:(NSData *)r;
/**
 设置s
 
 @param s s
 */
-(void)setS:(NSData *)s;
/**
 将当前对象转为字符串
 
 @return 对象的字符串输出
 */
-(NSString*)toString;


@end

NS_ASSUME_NONNULL_END
