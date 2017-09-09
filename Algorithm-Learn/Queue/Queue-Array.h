//
//  Queue-Array.h
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/7.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#ifndef Queue_Array_h
#define Queue_Array_h

#include <stdio.h>
#include <stdlib.h>

typedef int ValueType;
typedef struct ArrayQueue* ArrayQueue;

ArrayQueue aqueue_create(int maxCapacity);
int aqueue_isFull(ArrayQueue queue);
int aqueue_isEmpty(ArrayQueue queue);
void aqueue_makeEmpty(ArrayQueue queue);
void aqueue_enqueue(ValueType x, ArrayQueue queue);
ValueType aqueue_dequeue(ArrayQueue queue);
ValueType aqueue_front(ArrayQueue queue);

#endif /* Queue_Array_h */
