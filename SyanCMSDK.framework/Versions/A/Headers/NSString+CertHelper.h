//
//  NSString+Helper.h
//  SyanCMSDK
//
//  Created by 张鹤 on 2018/6/14.
//  Copyright © 2018年 XianAn. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (CertHelper)

//DEBUG 模式下打印日志,当前行
#ifdef DEBUG

#define DLog(format, ...) printf("%s [Line %d]  \n%s\n", __PRETTY_FUNCTION__, __LINE__, [[NSString stringWithFormat:(format), ##__VA_ARGS__] UTF8String])

#else

#define DLog(...)

#endif


+ (NSDictionary *)dictionaryWithJsonString:(NSString *)jsonString;
+ (NSString*)dictionaryToJson:(NSDictionary *)dic;

+(NSString *)ret32bitString;

+ (NSString *)getSignValueWithStamp:(NSString *)stamp andRandomStr:(NSString *)random;
+ (NSString*)md5OfString:(NSString*)s;
+ (NSString *)getCurrentTimeStamp;


@end
