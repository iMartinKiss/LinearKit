//
//  LKVector+Private.m
//  LinearKit
//
//  Created by Martin Kiss on 15.10.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "LKVector+Private.h"



@implementation LKVector

@end





@implementation LKVector (Private)



- (instancetype)initSubclass {
    return [super init];
}


- (LKFloat *)head {
    return NULL;
}


- (LKInteger)stride {
    return 0;
}


- (LKInteger)length {
    return 0;
}



- (BOOL)isIndexValid:(__unused LKInteger)index {
    return NO;
}


- (void)validateIndex:(LKInteger)index {
    if ( ! [self isIndexValid:index]) {
        @throw LKException(LKIndexException, @"Index %li out of bounds for %@", index, self.debugDescription);
    }
}



@end





NSString * const LKIndexException = @"LKIndexException";


NSException * LKException(NSString *name, NSString *format, ...) {
    va_list vargs;
    va_start(vargs, format);
    NSString *reason = [[NSString alloc] initWithFormat:format arguments:vargs];
    va_end(vargs);
    return [NSException exceptionWithName:name reason:reason userInfo:nil];
}





LKInteger const LKIntegerMax = LONG_MAX;


LKUInteger LKUnsigned(LKInteger integer) {
    if (integer < 0) return 0;
    return (LKUInteger)integer;
}


LKInteger LKSigned(LKUInteger integer) {
    if (integer > LKIntegerMax) return LKIntegerMax;
    return (LKInteger)integer;
}





LKFloat const LKZero = 0;
LKFloat const LKEpsion = LKPrecision(FLT_EPSILON, DBL_EPSILON);
LKFloat const LKOne = 1;
LKFloat const LKInfinity = INFINITY;
LKFloat const LKNAN = NAN;





NSUInteger LKHash(LKFloat value) {
    // Taken from _CFHashDouble() at http://www.opensource.apple.com/source/CF/CF-550/ForFoundationOnly.h
    LKFloat absolute = ABS(value);
    LKFloat integral = LK_f(round)(absolute);
    LKFloat fragment = absolute - integral;
    NSUInteger integralHash = 2654435761U * LK_f(fmod)(integral, NSUIntegerMax);
    NSUInteger fragmentHash = fragment * NSUIntegerMax;
    return integralHash + fragmentHash;
}


