//
//  CBSCertificate.h
//  Spark-new
//
//  Created by 卢义思 on 2018/1/22.
//  Copyright © 2018年 XianAn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "X509Certificate.h"
@interface CBSCertificate : NSObject
@property(nonatomic, strong) NSString *certificateId;
@property(nonatomic, strong) X509Certificate *x509Certificate;
@property(nonatomic, strong) AbstractX509Certificate *absCertificate;
@property(nonatomic, strong) NSString *name;
@property(nonatomic, strong) NSString *alias;
@property(nonatomic, strong) NSDate *notAfter;
@property(nonatomic, strong) NSDate *notBefore;
@property(nonatomic, strong) NSString *serialNumber;
@property(nonatomic, strong) NSString *subject;
@property(nonatomic, strong) NSString *issuer;
@property(nonatomic, strong) NSString *fingerPrint;
@property(nonatomic) BOOL isCa;
@property(nonatomic) BOOL isPrivateKeyAccessible;
@property(nonatomic, strong) NSString *algorithm;
@property(nonatomic,strong)NSString *usage;

-(NSData *) extensionData:(NSString *)oid;
-(NSString *) extension:(NSString *) oid;

// 获取证书扩展项
- (NSString *) getCardNumber;


- (instancetype)init:(X509Certificate *)x509Certificate;
- (instancetype)initAbstractX509Certificate:(AbstractX509Certificate *)x509Certificate;
@end
