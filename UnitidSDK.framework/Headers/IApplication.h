//
//  IApplication.h
//  MultiKey
//
//  Created by 张鹤 on 2018/12/6.
//  Copyright © 2018 张鹤. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "resultCode.h"
#import "IElement.h"
#import "IContainer.h"
@class PINInfo;
NS_ASSUME_NONNULL_BEGIN

/**
 * 应用管理接口
 *
 */

@protocol IApplication <IElement>

//region Application Interface

/**
 * 关闭应用并释放句柄
 *
 * @return 结果码
 */
-(ResultCode)SKF_CloseApplication;
/**
 * 修改应用PIN码
 *
 * @param pinType    PIN码类型
 * @param oldPin     旧PIN码
 * @param newPin     新PIN码
 * @param retryCount 重试次数（OUT）
 * @return 结果码
 */
-(ResultCode)SKF_ChangePIN:(NSInteger*) pinType oldPin:(NSString*) oldPin newPin:(NSString*)newPin retryCount:(NSInteger*)retryCount;
/**
 * 获取PIN相关信息
 *
 * @param pinType PIN码类型
 * @param pinInfo PIN码信息
 * @return 结果码
 */
-(ResultCode)SKF_GetPINInfo:(NSInteger*)pinType pinInfo:(PINInfo**)pinInfo;

/**
 * 校验PIN
 *
 * @param pinType    PIN码类型
 * @param pin        PIN码
 * @param retryCount 重试次数（OUT）
 * @return 结果码
 */
-(ResultCode)SKF_VerifyPIN:(NSInteger*)pinType pin:(NSString*)pin retryCount:(NSInteger*)retryCount;

/**
 * 解锁PIN
 *
 * @param adminPIN   管理员PIN码
 * @param newUserPIN 新的用户PIN码
 * @param retryCount 重试次数（OUT）
 * @return 结果码
 */
-(ResultCode)SKF_UnblockPIN:(NSString*)adminPIN newUserPIN:(NSString*)newUserPIN retryCount:(NSInteger*) retryCount;
/**
 * 清除应用安全状态
 *
 * @return 结果码
 */
-(ResultCode)SKF_ClearSecureState;

//endregion

//region Container Manage


/**
 * 删除容器
 *
 * @param containerName 容器名称
 * @return 结果码
 */
-(ResultCode)SKF_DeleteContainer:(NSString*)containerName;

/**
 * 枚举容器
 *
 * @param containerNameList 容器名称列表
 * @return 结果码
 */
-(ResultCode)SKF_EnumContainer:(NSArray<NSString *>**)containerNameList;
/**
 * 创建容器
 *
 * @param containerName 容器名称
 * @return 容器接口
 * @throws SecureCoreException 运算中的异常
 */
-(id<IContainer>)SKF_CreateContainer:(NSString*)containerName err:(NSError**)err;
/**
 * 打开容器
 *
 * @param containerName 容器名称
 * @return 容器接口
 * @throws SecureCoreException 运算中的异常
 */
-(id<IContainer>)SKF_OpenContainer:(NSString*)containerName err:(NSError**)err;





@end

NS_ASSUME_NONNULL_END
