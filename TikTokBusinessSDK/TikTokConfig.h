//
//  TikTokConfig.h
//  TikTokBusinessSDK
//
//  Created by Aditya Khandelwal on 9/8/20.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TikTokLogger.h"

NS_ASSUME_NONNULL_BEGIN

@interface TikTokConfig : NSObject<NSCopying>

@property (nonatomic, copy, nullable) NSString* sdkPrefix;
@property (nonatomic, copy, nullable) NSString* defaultTracker;
@property (nonatomic, copy, nullable) NSString *externalDeviceId;


@property (nonatomic, copy, readonly, nonnull) NSString *appToken;
@property (nonatomic, copy, readonly, nullable) NSString *secretId;
@property (nonatomic, copy, readonly, nonnull) NSString *environment;
@property (nonatomic, copy, readonly, nullable) NSString *appSecret;

@property (nonatomic, assign) TikTokLogLevel logLevel;
@property (nonatomic, assign) BOOL eventBufferingEnabled;
//@property (nonatomic, weak, nullable) NSObject<AdjustDelegate> *delegate;
@property (nonatomic, assign) BOOL sendInBackground;
@property (nonatomic, assign) BOOL allowiAdInfoReading;
@property (nonatomic, assign) BOOL allowIdfaReading;
@property (nonatomic, assign) double delayStart;
@property (nonatomic, copy, nullable) NSString *userAgent;
@property (nonatomic, assign) BOOL isDeviceKnown;

- (void)setAppSecret:(NSUInteger)secretId
info1:(NSUInteger)info1
info2:(NSUInteger)info2
info3:(NSUInteger)info3
info4:(NSUInteger)info4;


@property (nonatomic, assign, readonly) BOOL isSKAdNetworkHandlingActive;
- (void)deactivateSKAdNetworkHandling;

+ (nullable TikTokConfig *)configWithAppToken:(nonnull NSString *)appToken
                               environment:(nonnull NSString *)environment;

- (nullable id)initWithAppToken:(nonnull NSString *)appToken
                    environment:(nonnull NSString *)environment;

+ (nullable TikTokConfig *)configWithAppToken:(nonnull NSString *)appToken
                               environment:(nonnull NSString *)environment
                     allowSuppressLogLevel:(BOOL)allowSuppressLogLevel;

- (nullable id)initWithAppToken:(nonnull NSString *)appToken
                    environment:(nonnull NSString *)environment
          allowSuppressLogLevel:(BOOL)allowSuppressLogLevel;

- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END
