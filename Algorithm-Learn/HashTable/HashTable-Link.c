//
//  HashTable-Link.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/10.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "HashTable-Link.h"

struct ListNode {
    KeyType value;
    ListNode *next;
};

struct HashTable {
    int capacity;
    ListNode **list;
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

HashTable hashtable_create(int maxCapacity){
    HashTable table = malloc(sizeof(HashTable));
    table->capacity = nextPrime(maxCapacity);
    table->list = malloc(sizeof(ListNode *) * table->capacity);
    for (int i = 0; i < table->capacity; i++) {
        table->list[i] = malloc(sizeof(ListNode **));
    }
    return table;
}

void hashtable_makeEmpty(HashTable table){
    for (int i = 0; i < table->capacity ; i++) {
        ListNode *list = table->list[i];
        ListNode *result = list->next;
        while (result != NULL) {
            ListNode *tmp = result->next;
            free(result);
            result = tmp->next;
        }
    }
}

ListNode *hashtable_find(KeyType key, HashTable table){
    ListNode *list = table->list[hash(&key, table->capacity)];
    ListNode *node = list->next;
    while (node != NULL && strcmp(&node->value, &key)) {
        node = node->next;
    }
    return node;
}

void hashtable_insert(KeyType key, HashTable table){
    ListNode *node = hashtable_find(key, table);
    if (node == NULL) {
        ListNode *new = malloc(sizeof(ListNode *));
        new->value = key;
        ListNode *list = table->list[hash(&key, table->capacity)];
        new->next = list->next;
        list->next = new;
    }
}

KeyType hashtable_retrieve(ListNode *p){
    return p->value;
}
