//
//  AVLTree.h
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/9.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h

#include <stdio.h>
#include "SearchTree.h"

typedef struct TreeNode TreeNode;
typedef TreeNode* AVLTree;
typedef int ValueType;

AVLTree avltree_makeEmpty(AVLTree tree);
TreeNode *avltree_find(ValueType x,AVLTree tree);
TreeNode *avltree_findMin(AVLTree tree);
TreeNode *avltree_findMax(AVLTree tree);
AVLTree avltree_insert(ValueType x,AVLTree tree);
AVLTree avltree_delete(ValueType x,AVLTree tree);
ValueType avltree_retrieve(TreeNode *p);

#endif /* AVLTree_h */
