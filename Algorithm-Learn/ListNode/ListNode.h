//
//  ListNode.h
//  ListNode
//
//  Created by Nemocdz on 2017/9/7.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#ifndef ListNode_h
#define ListNode_h

#include <stdio.h>
#include <stdlib.h>

struct ListNode;
typedef struct ListNode ListNode;
typedef int ValueType;

ListNode *list_create(void);
int list_isEmpty(ListNode *list);
int list_isLast(ListNode *P,ListNode *list);
ListNode *list_find(ValueType x, ListNode *list);
ListNode *list_findPrevious(ValueType x, ListNode *list);
void list_delete (ValueType x, ListNode *list);
void list_insert(ValueType x, ListNode *list, ListNode *p);
void list_makeEmpty(ListNode *list);
ListNode *list_first(ListNode *list);
ListNode *list_next(ListNode *p);
ValueType list_value(ListNode *p);

#endif /* ListNode_h */

