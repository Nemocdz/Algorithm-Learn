//
//  Stack-Array.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/7.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "Stack-Array.h"

static const int ArrayStackEmptyTop = -1;

struct ArrayStack{
    int capacity;
    int top;
    ValueType *array;
};


ArrayStack astack_create(int maxCapacity){
    ArrayStack stack = malloc(sizeof(ArrayStack));
    if (stack != NULL) {
        stack->array = malloc(sizeof(ValueType) * maxCapacity);
        stack->capacity = maxCapacity;
        astack_makeEmpty(stack);
    }
    return stack;
}

int astack_isEmpty(ArrayStack stack){
    return stack->top == ArrayStackEmptyTop;
}

int astack_isFull(ArrayStack stack){
    return stack->top == stack->capacity;
}

void astack_makeEmpty(ArrayStack stack){
    if (stack != NULL) {
        stack->top = ArrayStackEmptyTop;
        free(stack->array);
        stack->array = malloc(sizeof(ValueType) * stack->capacity);
    }
}

void astack_push(ValueType x, ArrayStack stack){
    if (!astack_isFull(stack)) {
        stack->array[++stack->top] = x;
    }
}

void astack_pop(ArrayStack stack){
    if (!astack_isEmpty(stack)) {
        stack->top--;
    }
}

ValueType astack_top(ArrayStack Stack){
    if (!astack_isEmpty(Stack)) {
        return Stack->array[Stack->top];
    }
    return -1;
}
