//
//  Stack-ListNode.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/7.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "Stack-ListNode.h"


ListStack lstack_create(){
    ListStack stack = list_create();
    lstack_makeEmpty(stack);
    return stack;
}


int lstack_isEmpty(ListStack stack){
    return list_isEmpty(stack);
}

void lstack_makeEmpty(ListStack stack){
    if (stack != NULL) {
        while (!lstack_isEmpty(stack)) {
            lstack_pop(stack);
        }
    }
}

void lstack_push(ValueType X, ListStack stack){
    list_insert(X, stack, stack);
}


void lstack_pop(ListStack stack){
    if (!lstack_isEmpty(stack)) {
        list_delete(list_value(list_first(stack)), stack);
    }
}


ValueType lstack_top(ListStack stack){
    if (!lstack_isEmpty(stack)) {
        return list_value(list_first(stack));
    }
    return -1;
}

