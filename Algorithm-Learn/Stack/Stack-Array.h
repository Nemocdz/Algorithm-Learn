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

ArrayStack astack_create(int MaxCapacity);
int astack_isEmpty(ArrayStack Stack);
int astack_isFull(ArrayStack Stack);
void astack_makeEmpty(ArrayStack Stack);
void astack_push(ValueType X, ArrayStack Stack);
void astack_pop(ArrayStack Stack);
ValueType astack_top(ArrayStack Stack);

#endif /* Stack_Array_h */
