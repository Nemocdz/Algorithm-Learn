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
int dlist_sEmpty(DoubleListNode *List);
int dlist_isLast(DoubleListNode *P,DoubleListNode *List);
DoubleListNode *dlist_find(ValueType X, DoubleListNode *List);
void dlist_delete (ValueType X, DoubleListNode *List);
void dlist_insertPre(ValueType X, DoubleListNode *List, DoubleListNode *P);
void dlist_insertNext(ValueType X, DoubleListNode *List, DoubleListNode *P);
void dlist_makeEmpty(DoubleListNode *List);


#endif /* DoubleDoubleListNode_h */
