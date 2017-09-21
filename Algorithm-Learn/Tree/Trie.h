//
//  Trie.h
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/21.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#ifndef Trie_h
#define Trie_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Trie* Trie;

Trie trie_create(void);
void trie_insert(Trie trie,char *word);
int trie_search(Trie trie,char *word);
void trie_delete(Trie trie,char *word);
void trie_makeEmpty(Trie trie);

#endif /* Trie_h */
