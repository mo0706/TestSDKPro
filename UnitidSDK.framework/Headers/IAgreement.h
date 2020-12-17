//
//  IAgreement.h
//  MultiKey
//
//  Created by 张鹤 on 2018/12/6.
//  Copyright © 2018 张鹤. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IElement.h"
#import "ISessionKey.h"
@class ECCPublicKeyBlob;

NS_ASSUME_NONNULL_BEGIN

@protocol IAgreement <IElement>

/*
 * ECC计算会话密钥
 
 * @param pin PIN码
 * @param pubKeyBlob 公钥
 * @param tempECCPubKeyBlob 临时公钥
 * @param ID 身份标识
 * @return 会话密钥接口
 * @throws SecureCoreException 运算中的异常
 */
-(id<ISessionKey>)SKF_GenerateKeyWithECC:(NSString*)pin pubKeyBlob:(ECCPublicKeyBlob*)pubKeyBlob tempPubKeyBlob:(ECCPublicKeyBlob*)tempPubKeyBlob  ID:(NSData*)ID err:(NSError**)err;


@end

NS_ASSUME_NONNULL_END
