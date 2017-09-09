//
//  ListNode.c
//  ListNode
//
//  Created by Nemocdz on 2017/9/7.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "ListNode.h"

struct ListNode {
    ValueType value;
    ListNode *next;
};

ListNode *list_create(){
    ListNode *head = malloc(sizeof(ListNode));
    head->next = NULL;
    return head;
}


int list_isEmpty(ListNode *list){
    return list->next == NULL;
}

int list_isLast(ListNode *p, ListNode *list){
    return p->next == NULL;
}

ListNode *list_find(ValueType x, ListNode *list){
    ListNode *result = list -> next;
    while (result != NULL && result->value != x) {
        result = result->next;
    }
    return result;
}

ListNode *list_findPrevious(ValueType x, ListNode *list) {
    ListNode *result = list;
    while (result != NULL && result->next->value != x) {
        result = result->next;
    }
    return result;
}

void list_delete(ValueType x, ListNode *list){
    ListNode *result = list_findPrevious(x, list);
    if (!list_isLast(result, list)) {
        ListNode *tmp = result->next;
        result->next = tmp->next;
        free(tmp);
    }
}

void list_insert(ValueType x,ListNode *list, ListNode *p){
    ListNode *tmp  = malloc(sizeof(ListNode));
    if (tmp == NULL) {
        return;
    }
    tmp->value = x;
    tmp->next = p->next;
    p->next = tmp;
}

void list_makeEmpty(ListNode *list){
    ListNode *result = list->next;
    list->next = NULL;
    while (result != NULL) {
        ListNode *tmp = result->next;
        free(result);
        result = tmp->next;
    }
}


ListNode *list_first(ListNode *list){
    return list->next;
}

ListNode *list_next(ListNode *p){
    return p->next;
}

ValueType list_value(ListNode *p){
    return p->value;
}




