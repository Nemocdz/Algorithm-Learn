//
//  ListNode.c
//  ListNode
//
//  Created by Nemocdz on 2017/9/7.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "ListNode.h"

struct ListNode {
    ValueType Value;
    ListNode *Next;
};

ListNode *list_create(){
    ListNode *head = malloc(sizeof(ListNode));
    head->Next = NULL;
    return head;
}


int list_isEmpty(ListNode *List){
    return List->Next == NULL;
}

int list_isLast(ListNode *P, ListNode *List){
    return P->Next == NULL;
}

ListNode *list_find(ValueType X, ListNode *List){
    ListNode *result = List -> Next;
    while (result != NULL && result->Value != X) {
        result = result->Next;
    }
    return result;
}

ListNode *list_findPrevious(ValueType X, ListNode *List) {
    ListNode *result = List;
    while (result != NULL && result->Next->Value != X) {
        result = result->Next;
    }
    return result;
}

void list_delete(ValueType X, ListNode *List){
    ListNode *result = list_findPrevious(X, List);
    if (!list_isLast(result, List)) {
        ListNode *tmp = result->Next;
        result->Next = tmp->Next;
        free(tmp);
    }
}

void list_insert(ValueType X,ListNode *List, ListNode *P){
    ListNode *tmp  = malloc(sizeof(ListNode));
    if (tmp == NULL) {
        return;
    }
    tmp->Value = X;
    tmp->Next = P->Next;
    P->Next = tmp;
}

void list_makeEmpty(ListNode *List){
    ListNode *result = List->Next;
    List->Next = NULL;
    while (result != NULL) {
        ListNode *tmp = result->Next;
        free(result);
        result = tmp->Next;
    }
}


ListNode *list_first(ListNode *list){
    return list->Next;
}

ListNode *list_next(ListNode *P){
    return P->Next;
}

ValueType list_value(ListNode *P){
    return P->Value;
}




