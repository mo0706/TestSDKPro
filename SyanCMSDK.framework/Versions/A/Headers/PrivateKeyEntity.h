//
//  PrivateKeyEntity.h
//  OpenSSLEx
//
//  Created by jobs on 2/25/15.
//  Copyright (c) 2015 jobs. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PrivateKeyEntity : NSObject



@property (nonatomic,retain)NSString *id;
@property (nonatomic,retain)NSString *value;
@property (nonatomic,assign)NSInteger status;
@property (nonatomic,retain)NSString *lastUpdateTime;

- (instancetype)init:(NSString*)id withValue:(NSString*)value;

- (instancetype)init:(NSString*)id withValue:(NSString*)value withStatus:(NSInteger)status;



//- (NSString*)getId;
//
//- (NSString*)getValue;
//
//- (NSInteger)getStatus;
@end
