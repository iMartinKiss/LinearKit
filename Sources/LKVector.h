//
//  LKVector.h
//  LinearKit
//
//  Created by Martin Kiss on 15.10.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "LKTypes.h"





@interface LKVector : NSObject

@end





@interface LKVector (Creating) <NSCopying>

+ (LKVector *)vectorWithLength:(LKLength)length;
- (LKVector *)copy;

#define LKVectorMake(LKFloat...)    _LKVectorMake(LKFloat)
- (LKVector *)initWithMutableData:(NSMutableData *)data;

+ (LKVector *)new NS_UNAVAILABLE;
- (LKVector *)init NS_UNAVAILABLE;

@end





@interface LKVector (Accessing)

@property (readonly) LKLength length;
- (LKFloat)valueAtIndex:(LKIndex)index;
- (void)setValue:(LKFloat)value atIndex:(LKIndex)index;

- (LKFloat*(^)(LKIndex index))at;
- (void)enumerateConcurrently:(BOOL)concurrently block:(void(^)(LKIndex index, LKFloat* reference))block;

@end





@interface LKVector (Equality)

- (NSUInteger)hash;
- (BOOL)isEqual:(LKVector *)other;
- (BOOL)isEqual:(LKVector *)other epsilon:(LKFloat)epsilon;

@end





@interface LKVector (Filling)

- (void)clear;
- (void)fill:(LKFloat)value;
- (void)generateFrom:(LKFloat)start by:(LKFloat)step;
- (void)generateFrom:(LKFloat)start to:(LKFloat)end;

- (void)setValues:(LKVector *)vector;

@end





@interface LKVector (Subvector)

- (LKVector *)from:(LKOffset)start;
- (LKVector *)to:(LKOffset)end;
- (LKVector *)by:(LKStride)stride;

- (LKVector *)from:(LKOffset)start to:(LKOffset)end;
- (LKVector *)from:(LKOffset)start length:(LKLength)length;
- (LKVector *)from:(LKOffset)start by:(LKStride)stride;

- (LKVector *)reversed; //TODO: Negative stride.

@end










#define _LKVectorMake(...) \
(LKVector *)({ \
    LKFloat values[] = { __VA_ARGS__ }; \
    NSMutableData *data = [NSMutableData dataWithBytes:values length:sizeof(values)]; \
    [[LKVector alloc] initWithMutableData:data]; \
})


