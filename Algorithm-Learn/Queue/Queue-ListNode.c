//
//  Queue-ListNode.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/7.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "Queue-ListNode.h"

struct ListNode {
    ListNode *head;
    ListNode *tail;
    ValueType Value;
    ListNode *Next;
};

ListQueue lqueue_create(void){
    ListQueue queueCreate = list_create();
    queueCreate->tail = queueCreate;
    queueCreate->tail = queueCreate;
    return queueCreate;
}

int lqueue_isEmpty(ListQueue queue){
    return queue->head == queue->tail;
}

void lqueue_makeEmpty(ListQueue queue){
    queue->head = queue;
    queue->tail = queue;
    list_makeEmpty(queue);
}

void lqueue_enqueue(ValueType X, ListQueue queue){
    ListNode *node = malloc(sizeof(ListNode));
    node->Value = X;
    node->Next = queue->tail->Next;
    queue->tail->Next = node;
}

ValueType lqueue_dequeue(ListQueue queue){
   ValueType value = -1;
    if (!lqueue_isEmpty(queue)) {
        ListNode *node = list_first(queue);
        queue->head->Next = node->Next;
        value = node->Value;
        free(node);
    }
    return value;
}

ValueType lqueue_front(ListQueue queue){
    return list_first(queue)->Value;
}

