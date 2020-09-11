//
//  TikTokAppEventQueue.m
//  TikTokBusinessSDK
//
//  Created by Christopher Yang on 9/4/20.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "TikTokAppEvent.h"
#import "TikTokAppEventQueue.h"
#import "TikTokAppEventStore.h"
#import "TikTokAppEventUtility.h"

#define EVENT_NUMBER_THRESHOLD 100
#define FLUSH_PERIOD_IN_SECONDS 15

@implementation TikTokAppEventQueue

- (id)init {
    if (self == nil) return nil;
    self.eventQueue = [NSMutableArray array];
    
    __weak TikTokAppEventQueue *weakSelf = self;
    self.flushTimer = [TikTokAppEventUtility startTimerWithInterval:FLUSH_PERIOD_IN_SECONDS
                                                        block:^{
        [weakSelf flush:@"Timer"];
    }];
    
    return self;
}

- (void)addEvent:(TikTokAppEvent *)event {
    [self.eventQueue addObject:event];
    if(self.eventQueue.count > EVENT_NUMBER_THRESHOLD) {
        [self flush:@"Threshold"];
    }
}

- (void)flush:(NSString *)flushReason {
    NSLog(@"Start flush, with flush reason: %@", flushReason);
    NSArray *eventsFromDisk = [TikTokAppEventStore retrievePersistedAppEvents];
    NSMutableArray *eventsToBeFlushed = [NSMutableArray arrayWithArray:self.eventQueue];
    [eventsToBeFlushed addObjectsFromArray:eventsFromDisk];
    
    [self.eventQueue removeAllObjects];
}


@end
