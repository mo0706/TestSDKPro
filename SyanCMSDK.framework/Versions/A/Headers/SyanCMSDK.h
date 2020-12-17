//
//  SyanCMSDK.h
//  SyanCMSDK
//
//  Created by 卢义思 on 2018/1/22.
//  Copyright © 2018年 XianAn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SyanCertService.h"
#import "CBSResponse.h"
#import "CBSCertificate.h"
#import "CBSAuthAttr.h"
#import "LicenseUtil.h"
#import "TYAlertController+BlurEffects.h"
#import "CustomView.h"
#import "TYAlertController.h"
//#import "UIView+TYAutoLayout.h"
#import "TYAlertView.h"



@interface SyanCMSDK : NSObject

+ (void)setupAppKey:(NSString *)appkey andAppSecert:(NSString *)appSecret andBaseURL:(NSString *)url;

@end
