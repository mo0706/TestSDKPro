//
//  X509CertificateEntity.h
//  OpenSSLEx
//
//  Created by jobs on 2/25/15.
//  Copyright (c) 2015 jobs. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface X509CertificateEntity : NSObject


@property (nonatomic,retain)NSString *id;
@property (nonatomic,retain)NSString *alias;
@property (nonatomic,retain)NSString *value;
@property (nonatomic,assign)NSInteger status;



- (instancetype)init:(NSString*)id withValue:(NSString*)value;

- (instancetype)init:(NSString*)id withAlias:(NSString*)alias withValue:(NSString*)value;

- (instancetype)init:(NSString*)id withAlias:(NSString*)alias withValue:(NSString*)value withStatus:(NSInteger)status;

//- (NSInteger)getStatus;
//
//- (NSString*)getAlias;
//
//- (NSString*)getId;
//
//- (NSString*)getValue;
@end
