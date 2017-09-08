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
int list_isEmpty(ListNode *List);
int list_isLast(ListNode *P,ListNode *List);
ListNode *list_find(ValueType X, ListNode *List);
ListNode *list_findPrevious(ValueType X, ListNode *List);
void list_delete (ValueType X, ListNode *List);
void list_insert(ValueType X, ListNode *List, ListNode *P);
void list_makeEmpty(ListNode *List);
ListNode *list_first(ListNode *list);
ListNode *list_next(ListNode *P);
ValueType list_value(ListNode *P);

#endif /* ListNode_h */

