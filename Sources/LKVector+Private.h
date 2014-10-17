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
@property (readonly) LKStride stride;
@property (readonly) LKLength length;

- (instancetype)initSubclass;

@end



#define LKUnwrap(LKVector)      (self.head), (self.stride)

#define LK_vDSP(name)           LKPrecision(vDSP_ ## name, vDSP_ ## name ## D)
#define LK_f(name)              LKPrecision(name ## f, name)


