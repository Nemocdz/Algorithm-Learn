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
    int Capacity;
    int Top;
    ValueType *Array;
};


ArrayStack astack_create(int MaxCapacity){
    ArrayStack stack = malloc(sizeof(ArrayStack));
    if (stack != NULL) {
        stack->Array = malloc(sizeof(ValueType) * MaxCapacity);
        stack->Capacity = MaxCapacity;
        astack_makeEmpty(stack);
    }
    return stack;
}

int astack_isEmpty(ArrayStack Stack){
    return Stack->Top == ArrayStackEmptyTop;
}

int astack_isFull(ArrayStack Stack){
    return Stack->Top == Stack->Capacity;
}

void astack_makeEmpty(ArrayStack Stack){
    if (Stack != NULL) {
        Stack->Top = ArrayStackEmptyTop;
        free(Stack->Array);
        Stack->Array = malloc(sizeof(ValueType) * Stack->Capacity);
    }
}

void astack_push(ValueType X, ArrayStack Stack){
    if (!astack_isFull(Stack)) {
        Stack->Array[++Stack->Top] = X;
    }
}

void astack_pop(ArrayStack Stack){
    if (!astack_isEmpty(Stack)) {
        Stack->Top--;
    }
}

ValueType astack_top(ArrayStack Stack){
    if (!astack_isEmpty(Stack)) {
        return Stack->Array[Stack->Top];
    }
    return -1;
}
