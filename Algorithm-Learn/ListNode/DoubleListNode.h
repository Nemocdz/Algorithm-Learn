//
//  DoubleListNode.h
//  ListNode
//
//  Created by Nemocdz on 2017/9/7.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#ifndef DoubleListNode_h
#define DoubleListNode_h

#include <stdio.h>
#include <stdlib.h>

struct DoubleListNode;
typedef struct DoubleListNode DoubleListNode;
typedef int ValueType;

DoubleListNode *dlist_create(void);
int dlist_isEmpty(DoubleListNode *list);
int dlist_isLast(DoubleListNode *p,DoubleListNode *list);
DoubleListNode *dlist_find(ValueType x, DoubleListNode *list);
void dlist_delete (ValueType x, DoubleListNode *list);
void dlist_insertPre(ValueType x, DoubleListNode *list, DoubleListNode *p);
void dlist_insertNext(ValueType x, DoubleListNode *list, DoubleListNode *p);
void dlist_makeEmpty(DoubleListNode *list);


#endif /* DoubleDoubleListNode_h */
