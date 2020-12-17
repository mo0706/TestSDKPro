//
//  PrivateKey.h
//  OpenSSLEx
//
//  Created by jobs on 2/25/15.
//  Copyright (c) 2015 jobs. All rights reserved.
//

#include <openssl/x509.h>
#include <openssl/ossl_typ.h>

@protocol IPrivateKey;


@interface PrivateKey : NSObject<IPrivateKey>

- (instancetype)initWithPublicKey:(X509_PUBKEY*)publicKey withPrivateKey:(NSString *)ppPrivateKey withLastUpdateTime:(NSString*)lastUpdateTime;

- (instancetype)initWithX509Cert:(X509*)x509Certificate withPrivateKey:(NSString *)ppPrivateKey withLastUpdateTime:(NSString*)lastUpdateTime;

/**
 * 修改PIN码
 *
 * @param oldPin 旧的PIN口令
 * @param newPin 新的PIN口令
 * @throws InvalidPinException 如果旧口令错误
 * @throws JCEECMException
 */
- (void)updatePin:(NSString*)oldPin withNewPin:(NSString *)newPin;


- (Boolean)hasPinUpdated;

- (NSString*)getLastUpdateTime;


/**
 * 对数据进行私钥加密
 *
 * @param data 待加密数据
 * @param pin  私钥保护口令
 * @return 签名数据
 * @throws cn.com.syan.jcee.cm.exception.InvalidPinException 如果PIN口令错误
 * @throws cn.com.syan.jcee.cm.exception.JCEECMException
 */
- (NSData*)encrypt:(NSData*)data withPinL:(NSString*)pin;


- (EVP_PKEY*)derivePrivateKey:(NSString*)pin;

- (NSString*)getPrivateKey;


+ (Boolean)validate:(EVP_PKEY*)privateKey withPubKey:(X509_PUBKEY*)publicKey;

@end
