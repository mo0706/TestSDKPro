//
//  UnitidNetWorkService.h
//  SyanCMSDK
//
//  Created by 张鹤 on 2019/5/21.
//  Copyright © 2019 XianAn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef void(^UnitidSuccessBlock)(id datasoure);
typedef void(^UnitidErrorBlock)(NSError *error);

@interface UnitidNetWorkService : NSObject

@property (nonatomic, strong)NSURLSessionConfiguration *configuration;
@property (nonatomic, strong)NSURLSession *session;
/**
 *功能: 创建单例的对象方法
 */
+(instancetype)sharedTheSingletion;


-(void)GET:(NSString *)URL parameters:(NSDictionary *)dic success:(UnitidSuccessBlock)success failure:(UnitidErrorBlock)failure;

-(void)POST:(NSString *)URL headParameters:(NSDictionary *)headParam bodyParameters:(NSDictionary *)dic success:(UnitidSuccessBlock)success failure:(UnitidErrorBlock)failure;

@end

NS_ASSUME_NONNULL_END
