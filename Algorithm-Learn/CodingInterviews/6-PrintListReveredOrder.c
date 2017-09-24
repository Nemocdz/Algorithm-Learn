//
//  6-PrintListReveredOrder.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/24.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>
#include "Stack-ListNode.h"

// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

static void PrintListReversingly_Stack(ListNode* pHead){
    //用栈，先入栈后出
    ListStack stack = lstack_create();
    ListNode* pNode = pHead;
    while(pNode != NULL){
        lstack_push(list_value(pNode), stack);
        pNode = list_next(pNode);
    }
    while(!lstack_isEmpty(stack)){
        printf("%d\t", lstack_top(stack));
        lstack_pop(stack);
    }
}


static void PrintListReversingly(ListNode* pHead){
    //递归实现
    if (pHead != NULL){
        ListNode *node = list_next(pHead);
        if (node != NULL){
            PrintListReversingly(node);
        }
        printf("%d\t", list_value(pHead));
    }
}

