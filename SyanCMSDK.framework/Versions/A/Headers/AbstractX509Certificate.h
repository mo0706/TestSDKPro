//
//  AbstractX509Certificate.h
//  OpenSSLEx
//
//  Created by jobs on 2/25/15.
//  Copyright (c) 2015 jobs. All rights reserved.
//
#include <openssl/x509.h>
#import <Foundation/Foundation.h>


@interface AbstractX509Certificate : NSObject

@property (nonatomic,retain)NSString *alias;

@property (nonatomic,assign)bool privateKeyAccessible;

@property (nonatomic,assign)X509 *x509Certificate;

@property (nonatomic,copy)NSMutableArray *keyUsage;

@property (nonatomic,retain)NSString *algorithm;

@property (nonatomic,assign)NSInteger keyLength;

/**
 * 获得X509对象
 *
 * @return X509
 */
- (void)setX509Certificate:(X509 *)x509Cert;


+ (X509*)getX509CertificateWithBase64:(NSString*)base64;

+ (NSString*)getBase64CertificateWithX509:(X509*)x509;

- (NSString*)toBase64String;

- (NSString*) toPEMString;

-(NSString *) getExtension:(NSString *) oid;

-(NSData *) getExtensionData:(NSString *)oid;


/**
 * 使用公钥加密数据
 *
 * @param data 带加密数据
 * @return 密文
 *
 */
- (NSData *)publicEncrypt:(NSData*)data;

- (bool)isCA;

/**
 * 获得证书的密钥用法
 *
 * @return 密钥用法
 */
- (NSArray*)getKeyUsage;

/**
 * 该证书是否包含指定密钥用法
 *
 * @param _keyUsage 指定的密钥用法，see {@link org.spongycastle.asn1.x509.KeyUsage}
 * @return 结果
 */


- (bool)hasKeyUsageEx:(NSArray *)keyUsage;



/**
 * 获得证书名称，默认取CN项，如果没有CN项，取主题项中的第一项
 *
 * @return 证书名称
 */                                                                                                                                                               
- (NSString*)getCertificateName;

/**
 * 获得证书的使用者DN
 *
 * @return 证书的主题项
 * @throws CertificateEncodingException
 */
- (NSString*)getSubjectDN;

/**
 * 获得证书的颁发者DN
 *
 * @return 证书的颁发者
 * @throws CertificateEncodingException
 */
- (NSString*)getIssuerDN;


//- (NSString*)getAlias;
//
//- (void)setAlias:(NSString*)alias;

//获取证书有效期
//RETURN epoch time (seconds since 1970)
- (NSTimeInterval)getNotBefore;

- (NSTimeInterval)getNotAfter;


- (NSString*)getFingerprint:(NSString*)hashAlgo;

- (NSString*)getSerialNumber;


@end
