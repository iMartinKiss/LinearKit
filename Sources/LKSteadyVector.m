//
//  LKSteadyVector.m
//  LinearKit
//
//  Created by Martin Kiss on 15.10.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "LKVector+Private.h"



@interface LKSteadyVector ()

@property (readonly) NSMutableData *data;

@property (readonly) LKFloat* head;
@property (readonly) LKInteger length;

@end





@implementation LKSteadyVector



@synthesize head = _head;
@synthesize length = _length;



- (LKVector *)initWithMutableData:(NSMutableData *)data {
    self = [super initSubclass];
    if (self) {
        self->_data = (data.length? data : nil);
        self->_head = self->_data.mutableBytes;
        self->_length = LKSigned(data.length / sizeof(LKFloat));
    }
    return self;
}


- (LKInteger)stride {
    return 1;
}


- (BOOL)isIndexValid:(LKInteger)index {
    return (0 <= index && index < self->_length);
}



@end


