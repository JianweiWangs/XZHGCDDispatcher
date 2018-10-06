//
//  YYDispatchQueueManager.h
//  YYKit <https://github.com/ibireme/YYKit>
//
//  Created by ibireme on 15/7/18.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <Foundation/Foundation.h>

#ifndef YYDispatchQueueContext_H
#define YYDispatchQueueContext_H

NS_ASSUME_NONNULL_BEGIN

/**
 A dispatch queue pool holds multiple serial queues.
 Use this class to control queue's thread count (instead of concurrent queue).
 */
@interface YYDispatchQueueContext : NSObject

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

/**
 Creates and returns a dispatch queue context.
 @param name       The name of the context.
 @param queueCount Maxmium queue count, should in range (1, 32).
 @param qos        Queue quality of service (QOS).
 @return A new pool, or nil if an error occurs.
 */
- (instancetype)initWithName:(nullable NSString *)name
                  queueCount:(NSUInteger)queueCount
                         qos:(NSQualityOfService)qos;

/// Pool's name.
@property (nullable, nonatomic, readonly) NSString *name;

/// Get a serial queue from context.
- (dispatch_queue_t)queue;

@end

NS_ASSUME_NONNULL_END

#endif /** YYDispatchQueueContext_H */
