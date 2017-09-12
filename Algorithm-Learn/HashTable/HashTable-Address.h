//
//  HashTable-Address.h
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/10.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#ifndef HashTable_Address_h
#define HashTable_Address_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct AddressHashTable* AddressHashTable;
typedef char KeyType;
typedef unsigned int Index;

AddressHashTable ahashtable_create(int maxCapacity);
void ahashtable_makeEmpty(AddressHashTable table);
Index lhashtable_find(KeyType key, AddressHashTable table);
void lhashtable_insert(KeyType key, AddressHashTable table);
KeyType lhashtable_retrieve(Index i, AddressHashTable table);
AddressHashTable lhashtable_rehash(AddressHashTable table);


#endif /* HashTable_Address_h */
