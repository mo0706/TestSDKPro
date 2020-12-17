//
//  SCElement.h
//  MultiKey
//
//  Created by 张鹤 on 2018/12/6.
//  Copyright © 2018 张鹤. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IElement.h"


@interface SCElement : NSObject <IElement>
-(instancetype)initWithParam:(id<IElement>)parent handle:(NSInteger)handle name:(NSString *)name ;


@end

