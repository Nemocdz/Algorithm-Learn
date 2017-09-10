//
//  HashTable-Link.h
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/10.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#ifndef HashTable_Link_h
#define HashTable_Link_h

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "ListNode.h"

typedef struct LinkHashTable *LinkHashTable;
typedef char KeyType;

LinkHashTable lhashtable_create(int maxCapacity);
void lhashtable_makeEmpty(LinkHashTable table);
ListNode *lhashtable_find(KeyType key, LinkHashTable table);
void lhashtable_insert(KeyType key, LinkHashTable table);
KeyType lhashtable_retrieve(ListNode *p);

#endif /* HashTable_Link_h */
