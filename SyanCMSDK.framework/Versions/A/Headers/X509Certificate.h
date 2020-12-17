//
//  X509Certificate.h
//  OpenSSLEx
//
//  Created by jobs on 2/25/15.
//  Copyright (c) 2015 jobs. All rights reserved.
//

#import "AbstractX509Certificate.h"
#import "ICertificate.h"
//#import "PrivateKey.h"
#import "X509CertificateEntity.h"
#import "PrivateKeyEntity.h"

@interface X509Certificate : AbstractX509Certificate <ICertificate>

- (instancetype)init:(X509CertificateEntity *)x509Entity withPrivateKeyEntity:(PrivateKeyEntity *)pkEntity;

- (X509CertificateEntity*)getX509CertificateEntity;

- (NSData*)pkcs7Impl:(NSData*) data withPin:(NSString*) pin;

- (NSData*)decryptImpl:(NSData*) data withPin:(NSString*) pin;

- (NSData*)pkcs1Impl:(NSData*) data withPin:(NSString*) pin;

- (NSData*)pkcs7ImplWithSigndata:(NSData*) data withPin:(NSString*) pin;

- (Boolean)pkcs1Veriry:(NSData*) data withSig:(NSData*)sig;

- (Boolean)pkcs7Veriry:(NSData*) data;

- (Boolean)getPkcs7VeriryData:(NSData*) data andoridata:(NSData **)oridata;

+ (X509_PUBKEY*)derivePublicKey:(NSData*) data;

+ (NSData*)X509PubKey2Data:(X509_PUBKEY*)pubKey;

-(NSData *)ssl_PKCS7_get_Enveloped_data:(NSData *)originalData;

-(NSData *)ssl_PKCS7_get_Original_data:(NSData *)envelopedData withPin:(NSString *)pin;
@end
