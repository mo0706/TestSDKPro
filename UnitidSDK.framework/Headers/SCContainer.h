//
//  SCContainer.h
//  MultiKey
//
//  Created by 张鹤 on 2018/12/6.
//  Copyright © 2018 张鹤. All rights reserved.
//

#import "SCElement.h"
#import "IContainer.h"
#import "ISignKey.h"

NS_ASSUME_NONNULL_BEGIN

@interface SCContainer : SCElement<IContainer,ISignKey>
-(instancetype)initWithHandle:(NSInteger)handle parent:(id<IElement>)parent name:(NSString *)Name;


@end

NS_ASSUME_NONNULL_END
