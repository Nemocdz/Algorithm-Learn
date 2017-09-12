//
//  BinaryHeap.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/12.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "BinaryHeap.h"

static const ValueType MinData = -1;

struct BinaryHeap {
    int capacity;
    int size;
    ValueType *items;
};

BinaryHeap binaryheap_create(int maxCapacity){
    BinaryHeap heap = malloc(sizeof(BinaryHeap));
    //多一个空间放很小的数
    heap->items = malloc(sizeof(ValueType) * (maxCapacity + 1));
    heap->capacity = maxCapacity;
    heap->size = 0;
    //第一位是一个比所有数据都小的数，保证循环可以停止
    heap->items[0] = MinData;
    return heap;
}

int binaryheap_isFull(BinaryHeap heap){
    return heap->size >= heap->capacity;
}

int binaryheap_isEmpty(BinaryHeap heap){
    return heap->size == 0;
}

void binaryheap_makeEmpty(BinaryHeap heap){
    
}

void binaryheap_insert(ValueType x,BinaryHeap heap){
    if (!binaryheap_isFull(heap)) {
        int i;
        //先从插入的地方往父节点比较，若x小则将父节点往下移动，最后找到父节点比x小的位置填上x
        for (i = heap->size; heap->items[i/2] > x; i /= 2) {
            heap->items[i] = heap->items[i/2];
        }
        heap->items[i] = x;
        heap->size++;
    }
}

ValueType deleteMin(BinaryHeap heap);

ValueType findMin(BinaryHeap heap){
    if (!binaryheap_isEmpty(heap)) {
        return heap->items[1];
    }
    return MinData;
}
