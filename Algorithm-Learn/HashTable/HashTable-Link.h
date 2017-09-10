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

typedef struct HashTable* HashTable;
typedef char KeyType;

HashTable hashtable_create(int maxCapacity);
void hashtable_makeEmpty(HashTable table);
ListNode *hashtable_find(KeyType key, HashTable table);
void hashtable_insert(KeyType key, HashTable table);
KeyType hashtable_retrieve(ListNode *p);



#endif /* HashTable_Link_h */
