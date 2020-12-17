//
//  SecureCoreDevice.h
//  MultiKey
//
//  Created by 张鹤 on 2018/12/6.
//  Copyright © 2018 张鹤. All rights reserved.
//

#import "SCElement.h"
#import "IDevice.h"

NS_ASSUME_NONNULL_BEGIN

@interface SecureCoreDevice : SCElement<IDevice>
+(instancetype)sharedCoreDevice;

@end

NS_ASSUME_NONNULL_END
