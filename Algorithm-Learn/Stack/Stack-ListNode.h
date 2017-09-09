//
//  Stack-ListNode.h
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/7.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#ifndef Stack_ListNode_h
#define Stack_ListNode_h

#include <stdio.h>
#include "ListNode.h"

typedef struct ListNode* ListStack;

ListStack lstack_create(void);
int lstack_isEmpty(ListStack stack);
void lstack_makeEmpty(ListStack stack);
void lstack_push(ValueType x, ListStack stack);
void lstack_pop(ListStack stack);
ValueType lstack_top(ListStack stack);

#endif /* Stack_ListNode_h */
