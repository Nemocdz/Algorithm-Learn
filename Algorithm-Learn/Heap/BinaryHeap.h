//
//  BinaryHeap.h
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/12.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#ifndef BinaryHeap_h
#define BinaryHeap_h

#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryHeap* BinaryHeap;
typedef int ValueType;

BinaryHeap binaryheap_create(int maxCapacity);
int binaryheap_isFull(BinaryHeap heap);
int binaryheap_isEmpty(BinaryHeap heap);
void binaryheap_makeEmpty(BinaryHeap heap);
void binaryheap_insert(ValueType x,BinaryHeap heap);
ValueType deleteMin(BinaryHeap heap);
ValueType findMin(BinaryHeap heap);


#endif /* BinaryHeap_h */
