//
//  SCHash.h
//  MultiKey
//
//  Created by 张鹤 on 2018/12/6.
//  Copyright © 2018 张鹤. All rights reserved.
//

#import "SCElement.h"
#import "IHash.h"

NS_ASSUME_NONNULL_BEGIN

@interface SCHash : SCElement<IHash>
-(instancetype)initWithHandle:(NSInteger)handle parent:(id<IElement>)parent;

@end

NS_ASSUME_NONNULL_END
