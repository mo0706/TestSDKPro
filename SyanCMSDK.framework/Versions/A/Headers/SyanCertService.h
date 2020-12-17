//
//  SyanCertService.h
//  SyanCMSDK
//
//  Created by 卢义思 on 2018/1/22.
//  Copyright © 2018年 XianAn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CBSResponse.h"
#import "CBSCertificate.h"


typedef void (^SyanCompletioBlock)(NSDictionary *dic, NSURLResponse *response, NSError *error);
typedef void (^SyanSuccessBlock)(NSDictionary *data);
typedef void (^SyanCertInfoBlock)(NSArray *certArr,NSDictionary *data);

typedef void (^SyanScanSuccessBlock)(NSDictionary *data,NSInteger actionType);

typedef void (^SyanFailureBlock)(NSError *error);
typedef void (^SyanAlertBlock)(CBSResponse *response);
typedef void (^SyanStartBlock)(NSDictionary *dic);

typedef enum : NSUInteger {
    DecryptMode,
    SignModeP1,
    SignModeP7,
    EncryptMode,
    EnvelopMode,
    UnEnvelopMode,
} CertUsage;

typedef enum {
    HASH_ALG_AUTO = 0,     /** 用于RSA签名验签函数内部检测算法 */
    HASH_ALG_SHA384 = 1,  /**< SHA384摘要算法 */
    HASH_ALG_SM3    = 2,  /**< SM3摘要算法 */
    HASH_ALG_SHA256 = 3,   /**< SHA256摘要算法 */
    HASH_ALG_MD5 = 4,        /**< MD5摘要算法 */
    HASH_ALG_ECDSA_SM2 = 5, /**< SM2签名摘要算法，只用于SM2签名，验签作用，不适用HMAC等 */
    HASH_ALG_SHA1 = 6,        /**< SHA1摘要算法 */
    HASH_ALG_SHA512 = 7     /**< SHA512摘要算法 */
} Hash_AlgType;


typedef NS_ENUM(NSInteger, VerifySignType) {
    P1 = 0, P7 = 1
};

typedef NS_ENUM(NSInteger, VerifySignDataType) {
    StringType = 11,   /* 数据类型 字符串 */
    Base64StringType = 12, /* base64 字符串 */
    Base64ArrayType = 13 /* base64 字节数组 */
};

@protocol CertServiceDelegate <NSObject>

@optional

// 注册请求开始
- (void)certIssueRequestDidStartWithparameter:(NSDictionary *)paramDic;
// 注册请求响应
- (void)certIssueRequestFinshWithResponse:(CBSResponse *)response;

// 注销请求开始
- (void)certRevorkRequestDidStartWithparameter:(NSDictionary *)paramDic;
//注销请求响应
- (void)certRevorkRequestDidFinishedWithResponse:(CBSResponse *)response;

// 证书延期请求开始
- (void)certDelayRequestDidStartWithparameter:(NSDictionary *)paramDic;
// 证书延期请求响应
- (void)certDelayRequestDidFinishedWithResponse:(CBSResponse *)response;


@end


@interface SyanCertService : NSObject
@property(nonatomic,strong)NSString *UserID;
@property (nonatomic, copy) NSString *baseSDKURL;
@property (nonatomic, weak)id <CertServiceDelegate> delegate;


+(instancetype)sharedInstance;

//和当前帐号绑定，一般调用一次就行
+(void)bind:(NSString *)uuid;

+(void)clear;

//获取当前证书管理器类型
-(BOOL)getManagerType;


- (BOOL)isPersonalCertWithCertArr:(NSArray *)certArr;






//签发个人证书
- (void)ossPersonalCertIssue:(NSDictionary *)params viewController:(UIViewController *)vc;

//签发企业
- (void)ossCompanyCertIssue:(NSDictionary *)params viewContrloller:(UIViewController *)vc;

//注销证书
- (void)ossRevokeCertWithParams:(NSDictionary *)params withCertID:(NSString *)certId andViewController:(UIViewController *)vc;

//OSS证书延期
- (void)ossDelayIsPersonalCert:(BOOL)isPersonalCert requestWithParams:(NSDictionary *)params WithCert:(CBSCertificate *)cert withViewController:(UIViewController *)vc;


// 获取个人证书详情
- (void)getPersonCertInformationWithCertID:(NSString *)certId success:(SyanCertInfoBlock)successBlock failure:(SyanFailureBlock)failureBlock;

// 获取企业证书详情
- (void)getCompanyCertInformationWithCertID:(NSString *)certId success:(SyanCertInfoBlock)successBlock failure:(SyanFailureBlock)failureBlock;

//延期证书
-(void)CertDelay:(UIViewController *)vc withCert:(CBSCertificate *)cert success:(SyanSuccessBlock)successBlock;

//获取证书列表
-(NSMutableArray *)getAllCertificateist;

//获取签名证书
-(NSMutableArray<CBSCertificate *> *)getAllSignCertList;

//获取加密证书
-(NSMutableArray<CBSCertificate *> *)getallEncCertList;

//获取根证书(先安)
-(NSMutableArray<CBSCertificate *> *)getallRootCertList;

//获取其他证书(先安)
-(NSMutableArray<CBSCertificate *> *)getallOtherCertList:(NSArray *)list;

//验证签名
-(BOOL)verify:(NSString *)certificateStr data:(NSString *)data sign:(NSString *)sign signType:(NSInteger)signType;

// 根据数据类型进行验签
-(BOOL)verify:(NSString *)certificateStr data:(NSString *)data sign:(NSString *)sign signType:(NSInteger)signType andDataType:(NSInteger)dataType;
    
//删除证书
-(CBSResponse *)deleteCertificate:(NSString *)certificateId;
-(CBSResponse *)deleteBlankCertificate;

- (CBSResponse *)deleteContain;

-(CBSResponse *)deleteCertificateDelay:(NSString *)certificateId;


//修改pin码
- (CBSResponse *)updatePin:(NSString *)certificateId oldPin:(NSString *)oldPin newPin:(NSString *)newPin;

- (CBSResponse *)importCertificate:(NSString *)certificateStr;

//导入证书列表
- (CBSResponse *)importCertificates:(NSArray *)certificateList;

//导入证书列表，包含备份的私钥
- (CBSResponse *)importCertificatesWithPrivateKeys:(NSArray *)certificateList;

+ (CBSResponse *)importPin:(NSString *)pin withPrivateKey:(NSString *)key andCertificates:(NSString *)cert andEncryptionCert:(NSString *)encryptCer;

//导出证书私钥
- (NSString *)exportPrivateKeys;

//根据ID导出私钥
- (NSString *)exportPrivateKey:(NSString *)keyId;


#pragma mark 对外暴露的签名方法
/**
 *
 *  签名算法
 */
-(void)sign:(UIViewController *)viewController andText:(NSString *)text andSignType:(NSInteger)signType block:(SyanAlertBlock)syanAlertBlock;

/**
 *
 *  添加摘要算法
 */
//by20180612 zhanghe 添加摘要算法
-(void)sign:(UIViewController *)viewController andText:(NSString *)text andSignType:(NSInteger)signType andDataType:(NSInteger)dataType block:(SyanAlertBlock)syanAlertBlock;

-(void)sign:(UIViewController *)viewController andText:(NSString *)text andSignType:(NSInteger)signType andCertID:(NSString *)certId andDataType:(NSInteger)algType block:(SyanAlertBlock)syanAlertBlock;

-(void)signSelectedCertID:(NSString *)certID WithPin:(NSString *)pin andText:(NSString *)text andSignType:(NSInteger)signType andDataType:(NSInteger)dataType block:(SyanAlertBlock)syanAlertBlock;
//by20180727 zhanghe 不弹出PIN码
/**
 *
 * 签名 PIN码及证书传参形式
 */
- (CBSResponse *)sign:(NSString *)certificateId plainText:(NSString *)plainText pin:(NSString *)pin andSignType:(NSInteger)signType;

- (void)sign:(UIViewController *)vc certificateId:(NSString *)certificateId plainText:(NSString *)plainText andSignType:(NSInteger)signType block:(SyanAlertBlock)syanAlertBlock;


#pragma mark 对外暴露的加密方法
-(void)encypt:(UIViewController *)viewController andText:(NSString *)text block:(SyanAlertBlock)syanAlertBlock;

// by20180613 根据数据类型加密
-(void)encypt:(UIViewController *)viewController andText:(NSString *)text andDataType:(NSInteger)dataType block:(SyanAlertBlock)syanAlertBlock;

/**
 *
 * 加密 PIN码及证书传参形式
 */
-(CBSResponse *)encrypt:(NSString *)certificateId plainText:(NSString *)plainText;

#pragma mark 对外暴露的数字信封方法
-(void)envelop:(UIViewController *)viewController andText:(NSString *)text block:(SyanAlertBlock)syanAlertBlock;

// 根据数据类型制作数字信封方法
-(void)envelop:(UIViewController *)viewController andText:(NSString *)text andDataType:(NSInteger)dataType block:(SyanAlertBlock)syanAlertBlock;

/**
 *
 * 制作数字信封 PIN码 证书通过传参形式
 */
-(CBSResponse *)envelope:(NSString *)certificateId plainText:(NSString *)plainText;

#pragma mark 对外暴露的解密方法
-(void)decrypt:(UIViewController *)viewController andText:(NSString *)text block:(SyanAlertBlock)syanAlertBlock;
// 根据数据类型解密
-(void)decrypt:(UIViewController *)viewController andText:(NSString *)text andDataType:(NSInteger)dataType block:(SyanAlertBlock)syanAlertBlock;

/**
 *
 * 解密 通过传参的方式
 */
-(CBSResponse *)decrypt:(NSString *)certificateId plainText:(NSString *)plainText pin:(NSString *)pin;


#pragma mark 对外暴露的数字信封解封方法
-(void)unenvelop:(UIViewController *)viewController andText:(NSString *)text block:(SyanAlertBlock)syanAlertBlock;

-(void)unenvelop:(UIViewController *)viewController andText:(NSString *)text andDataType:(NSInteger)dataType block:(SyanAlertBlock)syanAlertBlock;

/**
 *
 * 解封 传参形式
 */
-(CBSResponse *)undoEnvelope:(NSString *)certificateId plainText:(NSString *)plainText pin:(NSString *)pin;

#pragma mark 对外暴露的修改pin码方法
-(void)changePin:(UIViewController *)viewController certID:(NSString *)certID block:(SyanAlertBlock)syanAlertBlock;

- (void)makeSurePinInViewController:(UIViewController *)viewC;

#pragma mark 对外暴露的扫码接口
- (void)scanPKI:(UIViewController *)viewController block:(SyanScanSuccessBlock)syanAlertBlock;
/////

#pragma mark 生成pkcs10字符串
-(void)createPKCS10String:(UIViewController *)viewController andParamDic:(NSDictionary *)params block:(SyanAlertBlock)syanAlertBlock;

- (NSString *)SM3DigestWithData:(NSData *)data;

// 签名不带获取PIN码尝试次数
- (void)signWithOutTimes:(UIViewController *)vc certificateId:(NSString *)certificateId plainText:(NSString *)plainText andSignType:(NSInteger)signType block:(SyanAlertBlock)syanAlertBlock;

- (CBSResponse *)getPINTimesWithCertificateId:(NSString *)certificateId;
@end
