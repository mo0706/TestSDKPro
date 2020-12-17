//
//  ICertificate.h
//  OpenSSLEx
//
//  Created by jobs on 2/25/15.
//  Copyright (c) 2015 jobs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PrivateKey.h"

@protocol ICertificate <NSObject>
@required
/**
 * 对数据进行PKCS1签名
 *
 * @param data 待签名的原文数据
 * @param pin  私钥保护口令
 * @return 签名数据
 * @throws InvalidPinException
 * @throws SignatureException
 * @throws PrivateKeyNotAccessibleException
 * @throws JCEECMException
 */
- (NSData*) pkcs1String:(NSString*) data withPin:(NSString*) pin;

/**
 * 对数据进行PKCS1签名
 *
 * @param data 待签名的原文数据
 * @param pin  私钥保护口令
 * @return 签名数据
 * @throws InvalidPinException
 * @throws SignatureException
 * @throws PrivateKeyNotAccessibleException
 * @throws JCEECMException
 */
- (NSData*) pkcs1Byte:(NSData*) data withPin:(NSString*) pin;

/**
 * 对数据进行PKCS7签名
 *
 * @param data 待签名数据
 * @param pin  私钥保护口令
 * @return CMSSignedData
 * @throws InvalidPinException
 * @throws SignatureException
 * @throws PrivateKeyNotAccessibleException
 * @throws JCEECMException
 */
- (NSData*) pkcs7String:(NSString*) data withPin:(NSString*) pin;

/**
 * 对数据进行PKCS7签名
 *
 * @param data 待签名数据
 * @param pin  私钥保护口令
 * @return CMSSignedData
 * @throws InvalidPinException
 * @throws SignatureException
 * @throws PrivateKeyNotAccessibleException
 * @throws JCEECMException
 */
- (NSData*) pkcs7Byte:(NSData*) data withPin:(NSString*) pin;

/**
 * 使用私钥解密数据
 *
 * @param data 带解密数据（公钥加密之后的数据，经Base64编码）
 * @param pin  私钥保护口令
 * @return 明文
 * @throws InvalidPinException
 * @throws PrivateKeyNotAccessibleException
 * @throws JCEECMException
 */
- (NSData*) privateDecryptString:(NSString*) data withPin:(NSString*) pin;

/**
 * 使用私钥解密数据
 *
 * @param data 带解密数据（公钥加密之后的数据）
 * @param pin  私钥保护口令
 * @return 明文
 * @throws InvalidPinException
 * @throws PrivateKeyNotAccessibleException
 * @throws JCEECMException
 */
- (NSData*) privateDecryptByte:(NSData*) data withPin:(NSString*) pin;

/**
 * 获得该公钥证书对应的私钥对象
 *
 * @return 私钥对象
 */
- (PrivateKey*) getPrivateKey;

/**
 * 获得证书的状态
 *
 * @return 证书的状态:{0:证书请求,1:证书已签发...}
 */
- (NSInteger) getStatus;
@end
