//
//  Stack-Array.h
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/7.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#ifndef Stack_Array_h
#define Stack_Array_h

#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayStack* ArrayStack;
typedef int ValueType;

ArrayStack astack_create(int maxCapacity);
int astack_isEmpty(ArrayStack stack);
int astack_isFull(ArrayStack stack);
void astack_makeEmpty(ArrayStack stack);
void astack_push(ValueType x, ArrayStack stack);
void astack_pop(ArrayStack stack);
ValueType astack_top(ArrayStack stack);

#endif /* Stack_Array_h */
