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


static int hash(const char *key, int tableSize){
    unsigned int hashVal = 0;
    while (*key != '\0') {
        hashVal = (hashVal << 5) + *key++;
    }
    return hashVal % tableSize;
}

static int nextPrime (int n) {
    if (n % 2 == 0) {
        n++;
    }
    for (; ; n+= 2){
        bool isPrime = false;
        for (int i = 3; i*i <= n; i += 2) {
            if (n % i == 0) {
                isPrime = true;
                break;
            }
        }
        if (isPrime) {
            return n;
        }
    }
}

AddressHashTable ahashtable_create(int maxCapacity){
    AddressHashTable table = malloc(sizeof(AddressHashTable));
    table->capacity = nextPrime(maxCapacity);
    table->items = malloc(sizeof(HashItem) * table->capacity);
    for (int i = 0; i < table->capacity; i++) {
        table->items[i].info = infoEmpty;
    }
    return table;
}

void ahashtable_makeEmpty(AddressHashTable table){
    for (int i = 0; i < table->capacity ; i++) {
        table->items[i].info = infoEmpty;
    }
}

Index ahashtable_find(KeyType key, AddressHashTable table){
    Index current = hash(&key, table->capacity);
    int collistion = 0;//冲突单元距离
    while (table->items[current].info != infoEmpty && !strcmp(&table->items[current].key,&key)) {
        //每次扩大两倍探测，1，2，4...
        current += 2 * ++collistion - 1;
        if (current >= table->capacity) {
            current -= table->capacity;
        }
    }
    return current;
}

void ahashtable_insert(KeyType key, AddressHashTable table){
    Index index = lhashtable_find(key, table);
    if (table->items[index].info != infoUse) {
        table->items[index].info = infoUse;
        strcpy(&table->items[index].key, &key);
    }
}

KeyType ahashtable_retrieve(Index i, AddressHashTable table){
    return table->items[i].key;
}

AddressHashTable ahashtable_rehash(AddressHashTable table){
    HashItem *oldItems = table->items;
    int oldCapacity = table->capacity;
    table = ahashtable_create(2 * oldCapacity);
    // 拷贝旧表的数据到新表
    for (int i = 0; i < oldCapacity; i++ ){
        if (oldItems[i].info == infoUse){
            lhashtable_insert(oldItems[i].key, table);
        }
    }
    free(oldItems);
    return table;
}




