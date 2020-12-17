//
//  LicenseUtil.h
//  SyanCMSDK
//
//  Created by 张鹤 on 2018/10/26.
//  Copyright © 2018 XianAn. All rights reserved.
//

#import <Foundation/Foundation.h>



@interface LicenseUtil : NSObject

typedef NS_ENUM(NSInteger, LicenseResultCode) {
    RESULT_OK =0x00000000, //Licence校验成果
    RESULT_NOT_FOUND_LICENSE=0x0A000001,  //未找到License文件
    RESULT_LICENSE_CHECK_FAILED=0x0A000002,  //校验失败
    RESULT_INVALID_LICENSE=0x0A000003,  //License不合法
    RESULT_BUNDLEIDINVALID_LICENSE=0x0A000004,  //Bundle ID不合法
    RESULT_EXPIRED=0x0A000005, //文件失效
};


+ (LicenseResultCode)checkLicense;

@end
