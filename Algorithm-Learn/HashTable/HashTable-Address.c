//
//  HashTable-Address.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/10.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "HashTable-Address.h"

typedef enum InfoType {
    infoEmpty,
    infoUse,
    infoDelete
} InfoType;

typedef struct HashItem {
    KeyType key;
    InfoType info;
} HashItem;

struct AddressHashTable {
    int capacity;
    HashItem *items;
};





