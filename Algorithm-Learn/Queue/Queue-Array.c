//
//  Queue-Array.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/7.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "Queue-Array.h"

struct ArrayQueue {
    int capacity;
    int front;
    int rear;
    int size;
    ValueType *array;
};


ArrayQueue aqueue_create(int maxCapacity){
    ArrayQueue queue = malloc(sizeof(ArrayQueue));
    if (queue != NULL) {
        queue->array = malloc(sizeof(ValueType) * maxCapacity);
        queue->capacity = maxCapacity;
        aqueue_makeEmpty(queue);
    }
    return queue;
}

int aqueue_isFull(ArrayQueue queue){
    return queue->size == queue->capacity;
}

int aqueue_isEmpty(ArrayQueue queue){
    return queue->size == 0;
}

void aqueue_makeEmpty(ArrayQueue queue){
    queue->size = 0;
    queue->front = 1;
    queue->rear = 0;
}

void aqueue_enqueue(ValueType X, ArrayQueue queue){
    if (!aqueue_isFull(queue)) {
        if (++queue->rear == queue->capacity) {
            queue->rear = 0;
        }
        queue->array[queue->rear] = X;
        queue->size++;
    }
}

ValueType aqueue_dequeue(ArrayQueue queue){
    ValueType result = -1;
    if (!aqueue_isEmpty(queue)) {
        result = queue->array[queue->front];
        if (++queue->front == queue->capacity) {
            queue->front = 0;
        }
        queue->size--;
    }
    return result;
}

ValueType aqueue_front(ArrayQueue queue){
    return queue->array[queue->front];
}
