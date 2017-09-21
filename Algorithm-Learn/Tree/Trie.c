//
//  Trie.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/21.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "Trie.h"

static const int TrieCharNum = 26;

struct Trie{
    char value;//字母
    int count; //表示到该节点路径组成的单词出现的次数,大于0则为出现过的单词
    Trie subTrie[TrieCharNum];//每个树都有26个子树，分别代表26个字母
};


Trie trie_create(){
    Trie root = malloc(sizeof(Trie));
    root->count = 0;
    root->value = 0;
    for(int i = 0; i < TrieCharNum ; i++){
        root->subTrie[i] = NULL;
    }
    return root;
}

void trie_insert(Trie trie,char *word){
    Trie node  = trie;
    char *key = word;
    while (*key) {
        //找到在哪一棵子树的位置
        int index = *key - 'a';
        if (node->subTrie[index] == NULL) {
            node->subTrie[index] = trie_create();
        }
        //往下一层搜索
        node = node->subTrie[index];
        //判断下一个字符
        key++;
    }
    node->count += 1;
}


int trie_search(Trie trie,char *word){
    Trie node = trie;
    char *key = word;
    while(*key && node != NULL){
        int id = *key - 'a';
        node = node->subTrie[id];
        key++;
    }
    if (*key){
        //key未遍历完，也就是node已经等于NULL
        return 0;
    }
    else{
        return node->count;
    }
}

void trie_delete(Trie trie,char *word){
    if (trie_search(trie, word) == 0) {
        return;
    }
    Trie node = trie;
    char *key = word;
    while (*key) {
        int id = *key - 'a';
        node = node->subTrie[id];
        node->count -= 1;
        //找到频次为0的，也就是可以删除的子树
        if (node->count == 0) {
            break;
        }
        key++;
    }
    trie_makeEmpty(node);
}

void trie_makeEmpty(Trie trie){
    if (!trie){
        return;
    }
    for (int i = 0; i < TrieCharNum; i++){
        if (trie->subTrie[i]){
            trie_makeEmpty(trie->subTrie[i]);
        }
        free(trie->subTrie[i]);
    }
}




