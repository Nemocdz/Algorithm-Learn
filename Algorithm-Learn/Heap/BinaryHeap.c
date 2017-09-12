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
    heap->size = 0;
}

void binaryheap_insert(ValueType x,BinaryHeap heap){
    if (!binaryheap_isFull(heap)) {
        int i;
        //先从插入的地方往父节点比较，若x小则将父节点往下移动，最后找到父节点比x小的位置填上x
        for (i = ++heap->size; heap->items[i/2] > x; i /= 2) {
            heap->items[i] = heap->items[i/2];
        }
        heap->items[i] = x;
    }
}

ValueType deleteMin(BinaryHeap heap){
    if (binaryheap_isEmpty(heap)) {
        return MinData;
    }
    else{
        int i,child;
        ValueType min = heap->items[1];
        //将最后一个值移到正确位置
        ValueType last = heap->items[heap->size--];
        //最顶的值准备置空，每次下移一层比较
        for (i = 1; i * 2 <= heap->size; i = child) {
            //计算子节点位置
            child = i * 2;
            //有两个子节点的情况下，取小的
            if (child != heap->size && heap->items[child+1] < heap->items[child]) {
                child++;
            }
            //若last大则空穴下移，填字节的值
            if (last > heap->items[child]) {
                heap->items[i] = heap->items[child];
            }
            else{
                break;
            }
        }
        //在合适位置填入最后一个值
        heap->items[i] = last;
        return min;
    }
}

ValueType findMin(BinaryHeap heap){
    if (!binaryheap_isEmpty(heap)) {
        return heap->items[1];
    }
    return MinData;
}
