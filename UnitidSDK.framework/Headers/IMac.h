//
//  IMac.h
//  MultiKey
//
//  Created by 张鹤 on 2018/12/6.
//  Copyright © 2018 张鹤. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IElement.h"
#import "resultCode.h"

/**
 * 消息鉴别码运算接口
 *
 */
NS_ASSUME_NONNULL_BEGIN

@protocol IMac <IElement>

/**
 * 计算消息鉴别码并输出结果
 *
 * @param data 待计算的数据
 * @return 消息鉴别码
 * @throws SecureCoreException 计算中出现的异常
 */
-(NSData*)SKF_Mac:(NSData*)data err:(NSError**)err;
/**
 * 计算消息鉴别码（不输出结果）
 *
 * @param data 待计算的数据
 * @return 结果码
 */
-(ResultCode)SKF_MacUpdate:(NSData*)data;
/**
 * 完成消息鉴别码计算，输出消息鉴别码
 *
 * @return 消息鉴别码
 * @throws SecureCoreException 计算中出现的异常
 */
-(NSData*)SKF_MacFinal:(NSError**)err;



@end

NS_ASSUME_NONNULL_END
