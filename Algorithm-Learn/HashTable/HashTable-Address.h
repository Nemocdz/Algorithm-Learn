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
typedef int ValueType;

AddressHashTable ahashtable_create(int maxCapacity);
void ahashtable_makeEmpty(AddressHashTable table);
Index ahashtable_find(KeyType key, AddressHashTable table);
void ahashtable_insert(KeyType key, ValueType value, AddressHashTable table);
ValueType ahashtable_retrieve(Index i, AddressHashTable table);
AddressHashTable ahashtable_rehash(AddressHashTable table);


#endif /* HashTable_Address_h */
