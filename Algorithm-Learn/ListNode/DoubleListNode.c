//
//  DoubleListNode.c
//  ListNode
//
//  Created by Nemocdz on 2017/9/7.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int ValueType;
typedef struct DoubleListNode DoubleListNode;

struct DoubleListNode {
    ValueType value;
    DoubleListNode *pre;
    DoubleListNode *next;
};

DoubleListNode *dlist_create(void){
    DoubleListNode *head = malloc(sizeof(DoubleListNode));
    head->pre = NULL;
    head->next = NULL;
    return head;
}

int dlist_isEmpty(DoubleListNode *list){
    return list->next == NULL;
}

int dlist_isLast(DoubleListNode *p, DoubleListNode *list){
    return p->next == NULL;
}

DoubleListNode *dlist_find(ValueType x, DoubleListNode *list){
    DoubleListNode *result = list ->next;
    while (result != list && result->value != x) {
        result = result->next;
    }
    return result;
}

void dlist_delete(ValueType x, DoubleListNode *list){
    DoubleListNode *result = dlist_find(x, list);
    result = result->pre;
    if (!dlist_isLast(result, list)) {
        DoubleListNode *tmp = result->next;
        result->next = tmp->next;
        free(tmp);
    }
}

void dlist_insertPre(ValueType x, DoubleListNode *list, DoubleListNode *p){
    DoubleListNode *tmp  = malloc(sizeof(DoubleListNode));
    if (tmp == NULL) {
        return;
    }
    tmp->value = x;
    tmp->pre = p->pre;
    p->pre = tmp;
}

void dlist_insertNext(ValueType x, DoubleListNode *list, DoubleListNode *p){
    DoubleListNode *tmp  = malloc(sizeof(DoubleListNode));
    if (tmp == NULL) {
        return;
    }
    tmp->value = x;
    tmp->next = p->next;
    p->next = tmp;
}


void dlist_makeEmpty(DoubleListNode *list){
    DoubleListNode *result = list->next;
    list->next = NULL;
    while (result != NULL) {
        DoubleListNode *tmp = result->next;
        free(result);
        result = tmp->next;
    }
}


