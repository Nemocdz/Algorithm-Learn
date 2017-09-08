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
    ValueType Value;
    DoubleListNode *Pre;
    DoubleListNode *Next;
};

DoubleListNode *dlist_create(void){
    DoubleListNode *head = malloc(sizeof(DoubleListNode));
    head->Pre = NULL;
    head->Next = NULL;
    return head;
}

int dlist_isEmpty(DoubleListNode *List){
    return List->Next == NULL;
}

int dlist_isLast(DoubleListNode *P, DoubleListNode *List){
    return P->Next == NULL;
}

DoubleListNode *dlist_find(ValueType X, DoubleListNode *List){
    DoubleListNode *result = List -> Next;
    while (result != List && result->Value != X) {
        result = result->Next;
    }
    return result;
}

void dlist_delete(ValueType X, DoubleListNode *List){
    DoubleListNode *result = dlist_find(X, List);
    result = result->Pre;
    if (!dlist_isLast(result, List)) {
        DoubleListNode *tmp = result->Next;
        result->Next = tmp->Next;
        free(tmp);
    }
}

void dlist_insertPre(ValueType X, DoubleListNode *List, DoubleListNode *P){
    DoubleListNode *tmp  = malloc(sizeof(DoubleListNode));
    if (tmp == NULL) {
        return;
    }
    tmp->Value = X;
    tmp->Pre = P->Pre;
    P->Pre = tmp;
}

void dlist_insertNext(ValueType X, DoubleListNode *List, DoubleListNode *P){
    DoubleListNode *tmp  = malloc(sizeof(DoubleListNode));
    if (tmp == NULL) {
        return;
    }
    tmp->Value = X;
    tmp->Next = P->Next;
    P->Next = tmp;
}


void dlist_makeEmpty(DoubleListNode *List){
    DoubleListNode *result = List->Next;
    List->Next = NULL;
    while (result != NULL) {
        DoubleListNode *tmp = result->Next;
        free(result);
        result = tmp->Next;
    }
}


