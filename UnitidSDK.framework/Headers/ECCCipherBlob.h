//
//  ECCCipherBlob.h
//  MultiKey
//
//  Created by 张鹤 on 2018/12/6.
//  Copyright © 2018 张鹤. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ECCCipherBlob : NSObject
@property(nonatomic,strong,readonly)NSData* Hash;
@property(nonatomic,strong,readonly)NSData *xCoordinate;
@property(nonatomic,strong,readonly)NSData *yCoordinate;
@property(nonatomic,strong,readonly)NSData *cipher;

+ (BOOL)isValid:(ECCCipherBlob *)paramECCCipherBlob;
/**
 判断当前实例是否合法
 
 @return yes合法，no非法
 */
-(BOOL)isValid;

/**
 设置密文
 
 @param cipher 密文
 */
-(void)setcipher:(NSData *) cipher;



/**
 设置哈希
 
 @param hash 哈希值
 */
-(void) sethash:(NSData *) hash;

/**
 设置xCoordinate
 
 @param xCoordinate xCoordinate
 */
-(void) setxCoordinate:(NSData *)xCoordinate ;
/**
 设置yCoordinate
 
 @param yCoordinate yCoordinate
 */
-(void) setyCoordinate:(NSData *)yCoordinate;

/**
 将当前实例变成字节串
 
 @return 字节串
 */
-(NSData *)toByteArray;

/**
 将字节串变为当前实例
 
 @param cipher 字节串
 @return 当前实例
 */
-(BOOL) readFromByteArray:(NSData *)cipher;
/**
 将当前对象转为字符串
 
 @return 对象的字符串输出
 */
-(NSString*)toString;

@end

NS_ASSUME_NONNULL_END
