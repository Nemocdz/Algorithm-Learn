//
//  Treap.h
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/22.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#ifndef Treap_h
#define Treap_h

#include <stdio.h>
#include "SearchTree.h"

typedef TreeNode* Treap;

Treap treap_makeEmpty(Treap tree);
TreeNode *treap_find(ValueType x,Treap tree);
TreeNode *treap_findMin(Treap tree);
TreeNode *treap_findMax(Treap tree);
Treap treap_insert(ValueType x,Treap tree);
Treap treap_delete(ValueType x,Treap tree);
ValueType treap_retrieve(TreeNode *p);


#endif /* Treap_h */
