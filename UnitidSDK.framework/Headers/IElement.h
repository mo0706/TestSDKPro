//
//  IElement.h
//  MultiKey
//
//  Created by 张鹤 on 2018/12/6.
//  Copyright © 2018 张鹤. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IClose.h"


@protocol IElement <IClose>
/**
 * 获取名称
 *
 * @return 名称
 */
-(NSString*)getName;
/**
 * 获取句柄
 *
 * @return 句柄
 */
-(NSInteger)getHandle;

/**
 * 获取父元素
 *
 * @return 父元素
 */
-(id<IElement>)getParent;
/**
 * 复制自身
 *
 * @return 复制的对象
 */
-(id<IElement>)copy;
/**
 *
 */
/**
 判断对象是否打开
 
 @return 布尔型
 */
-(BOOL)isOpened;



@end

