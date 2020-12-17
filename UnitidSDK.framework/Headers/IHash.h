//
//  IHash.h
//  MultiKey
//
//  Created by 张鹤 on 2018/12/6.
//  Copyright © 2018 张鹤. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IElement.h"
#import "resultCode.h"

NS_ASSUME_NONNULL_BEGIN

@protocol IHash <IElement>

/**
 * 杂凑计算并输出结果
 *
 * @param data 待计算的数据
 * @return 杂凑值
 * @throws SecureCoreException 运算中的异常
 */
-(NSData*)SKF_Digest:(NSData*)data err:(NSError**)err;
/**
 * 杂凑计算，不输出结果
 *
 * @param data 待计算的数据
 * @return 结果码
 */
-(ResultCode)SKF_DigestUpdate:(NSData*)data;
/**
 * 完成杂凑计算，输出结果
 *
 * @return 杂凑值
 * @throws SecureCoreException 运算中的异常
 */
-(NSData*)SKF_DigestFinal:(NSError**)err;


@end

NS_ASSUME_NONNULL_END
