//
//  SplayTree.h
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/22.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#ifndef SplayTree_h
#define SplayTree_h

#include <stdio.h>
#include "SearchTree.h"

typedef SearchTree SplayTree;

SplayTree splaytree_makeEmpty(SplayTree tree);
TreeNode *splaytree_find(ValueType x,SplayTree tree);
TreeNode *splaytree_findMin(SplayTree tree);
TreeNode *splaytree_findMax(SplayTree tree);
SplayTree splaytree_insert(ValueType x,SplayTree tree);
SplayTree splaytree_delete(ValueType x,SplayTree tree);
ValueType splaytree_retrieve(TreeNode *p);

#endif /* SplayTree_h */
