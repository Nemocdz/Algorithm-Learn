//
//  SearchTree.h
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/9.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#ifndef SearchTree_h
#define SearchTree_h

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode TreeNode;
typedef TreeNode* SearchTree;
typedef int ValueType;

SearchTree searchtree_makeEmpty(SearchTree tree);
TreeNode *searchtree_find(ValueType x,SearchTree tree);
TreeNode *searchtree_findMin(SearchTree tree);
TreeNode *searchtree_findMax(SearchTree tree);
SearchTree searchtree_insert(ValueType x,SearchTree tree);
SearchTree searchtree_delete(ValueType x,SearchTree tree);
ValueType searchtree_retrieve(TreeNode *p);

#endif /* SearchTree_h */
