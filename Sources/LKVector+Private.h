//
//  LKVector+Private.h
//  LinearKit
//
//  Created by Martin Kiss on 15.10.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "LKVector.h"



@interface LKVector (Private)

@property (readonly) LKFloat* head;
@property (readonly) LKInteger stride;
@property (readonly) LKInteger length;

- (instancetype)initSubclass;

- (BOOL)isIndexValid:(LKInteger)index;
- (void)validateIndex:(LKInteger)index;

- (void)copyValuesTo:(LKVector *)vector;

@end





@interface LKSteadyVector : LKVector

- (LKVector *)initWithMutableData:(NSMutableData *)data;

@end



@interface LKSubvector : LKVector

- (instancetype)initWithSource:(LKVector *)vector offset:(LKInteger)offset stride:(LKInteger)stride length:(LKInteger)length;

@end



@interface LKOperationVector : LKVector

@end






extern NSString * const LKIndexException;
extern NSException * LKException(NSString *name, NSString *format, ...) NS_FORMAT_FUNCTION(2, 3);







#define LKUnwrap(LKVector)      (LKVector.head), (LKVector.stride)

#define LK_vDSP(name)           LKPrecision(vDSP_ ## name, vDSP_ ## name ## D)
#define LK_f(name)              LKPrecision(name ## f, name)


