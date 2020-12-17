//
//  Tool.h
//  MultiKey
//
//  Created by 张鹤 on 2018/12/6.
//  Copyright © 2018 张鹤. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Tool : NSObject

+ (NSMutableData *)convertHexStrToData:(const NSString *)str;
+(NSString *)parseByteArray2HexString:(const Byte*) bytes length:(int)length;
//10进制转16进制
+(NSString *)ToHex:(long long int)tmpid;
+ (NSString *)convertDataToHexStr:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
