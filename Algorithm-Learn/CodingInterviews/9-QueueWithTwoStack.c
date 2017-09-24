//
//  9-QueueWithTwoStack.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/24.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>
#include "Stack-Array.h"

// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。

typedef struct StackQueue* StackQueue;

struct StackQueue{
    ArrayStack stackA;
    ArrayStack stackB;
};

static StackQueue queue_create(int maxCapacity){
    StackQueue queue = malloc(sizeof(StackQueue));
    queue->stackA = astack_create(maxCapacity);
    queue->stackB = astack_create(maxCapacity);
    return queue;
}


static void queue_enqueue(StackQueue queue, ValueType x){
    astack_push(x, queue->stackA);
}

static ValueType queue_dequeue(StackQueue queue){
    if (astack_isEmpty(queue->stackB)) {
        while (!astack_isEmpty(queue->stackA)) {
            ValueType tmp = astack_top(queue->stackA);
            astack_pop(queue->stackA);
            astack_push(tmp, queue->stackB);
        }
    }
    
    if (astack_isEmpty(queue->stackB)) {
        return -1;
    }
    
    ValueType head = astack_top(queue->stackB);
    astack_pop(queue->stackB);
    return head;
}



