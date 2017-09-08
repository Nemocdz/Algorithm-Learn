//
//  Queue-ListNode.h
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/7.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#ifndef Queue_ListNode_h
#define Queue_ListNode_h

#include <stdio.h>
#include "ListNode.h"

typedef struct ListNode* ListQueue;

ListQueue lqueue_create(void);
int lqueue_isEmpty(ListQueue queue);
void lqueue_makeEmpty(ListQueue queue);
void lqueue_enqueue(ValueType X, ListQueue queue);
ValueType lqueue_dequeue(ListQueue queue);
ValueType lqueue_front(ListQueue queue);


#endif /* Queue_ListNode_h */
