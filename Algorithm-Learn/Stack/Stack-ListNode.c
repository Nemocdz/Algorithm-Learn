//
//  Stack-ListNode.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/7.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "Stack-ListNode.h"

//struct ListNode {
//    ValueType Value;
//    ListNode *Next;
//};


ListStack lstack_create(){
    ListStack stack = list_create();
    lstack_makeEmpty(stack);
    return stack;
}


int lstack_isEmpty(ListStack Stack){
    return list_isEmpty(Stack);
}

void lstack_makeEmpty(ListStack Stack){
    if (Stack != NULL) {
        while (!lstack_isEmpty(Stack)) {
            lstack_pop(Stack);
        }
    }
}

void lstack_push(ValueType X, ListStack Stack){
    list_insert(X, Stack, Stack);
}


void lstack_pop(ListStack Stack){
    if (!lstack_isEmpty(Stack)) {
        list_delete(list_value(list_first(Stack)), Stack);
    }
}


ValueType lstack_top(ListStack Stack){
    if (!lstack_isEmpty(Stack)) {
        return list_value(list_first(Stack));
    }
    return -1;
}

