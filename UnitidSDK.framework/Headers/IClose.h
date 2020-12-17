//
//  IClose.h
//  MultiKey
//
//  Created by 张鹤 on 2018/12/6.
//  Copyright © 2018 张鹤. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "resultCode.h"

NS_ASSUME_NONNULL_BEGIN

@protocol IClose <NSObject>

- (ResultCode) SKF_CloseHandle;

@end

NS_ASSUME_NONNULL_END
