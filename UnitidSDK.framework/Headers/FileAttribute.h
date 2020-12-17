//
//  FileAttribute.h
//  MultiKey
//
//  Created by 张鹤 on 2018/12/6.
//  Copyright © 2018 张鹤. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FileAttribute : NSObject

@property(nonatomic,copy)NSString *FileName;

@property(nonatomic,assign)long FileSize;

@property(nonatomic,assign)long ReadRights;

@property(nonatomic,assign)long WriteRights;

@end

NS_ASSUME_NONNULL_END
