//
//  Queue-Array.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/7.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "Queue-Array.h"

struct ArrayQueue {
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ValueType *Array;
};


ArrayQueue aqueue_create(int MaxCapacity){
    ArrayQueue queue = malloc(sizeof(ArrayQueue));
    if (queue != NULL) {
        queue->Array = malloc(sizeof(ValueType) * MaxCapacity);
        queue->Capacity = MaxCapacity;
        aqueue_makeEmpty(queue);
    }
    return queue;
}

int aqueue_isFull(ArrayQueue queue){
    return queue->Size == queue->Capacity;
}

int aqueue_isEmpty(ArrayQueue queue){
    return queue->Size == 0;
}

void aqueue_makeEmpty(ArrayQueue queue){
    queue->Size = 0;
    queue->Front = 1;
    queue->Rear = 0;
}

void aqueue_enqueue(ValueType X, ArrayQueue queue){
    if (!aqueue_isFull(queue)) {
        if (++queue->Rear == queue->Capacity) {
            queue->Rear = 0;
        }
        queue->Array[queue->Rear] = X;
        queue->Size++;
    }
}

ValueType aqueue_dequeue(ArrayQueue queue){
    ValueType result = -1;
    if (!aqueue_isEmpty(queue)) {
        result = queue->Array[queue->Front];
        if (++queue->Front == queue->Capacity) {
            queue->Front = 0;
        }
        queue->Size--;
    }
    return result;
}

ValueType aqueue_front(ArrayQueue queue){
    return queue->Array[queue->Front];
}
