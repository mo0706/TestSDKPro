//
//  CustomView.h
//  SyanCMSDK
//
//  Created by 卢义思 on 2018/4/8.
//  Copyright © 2018年 XianAn. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CBSCertificate.h"
#import "SyanCertService.h"

typedef void(^GetCert)(CBSCertificate *cert,NSInteger idx);

@interface CustomView : UIView

@property(nonatomic,copy)GetCert getCert;
-(void)requestCert:(CertUsage)usage;
@end
