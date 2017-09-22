//
//  RBTree.h
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/22.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#ifndef RBTree_h
#define RBTree_h

#include <stdio.h>
#include <stdlib.h>
#include "SearchTree.h"

typedef TreeNode* RBTree;

RBTree rbtree_makeEmpty(RBTree tree);
TreeNode *rbtree_find(ValueType x,RBTree tree);
TreeNode *rbtree_findMin(RBTree tree);
TreeNode *rbtree_findMax(RBTree tree);
RBTree rbtree_insert(ValueType x,RBTree tree);
RBTree rbtree_delete(ValueType x,RBTree tree);
ValueType rbtree_retrieve(TreeNode *p);


#endif /* RBTree_h */
