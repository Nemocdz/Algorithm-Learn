//
//  Treap.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/22.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "Treap.h"

struct TreeNode{
    ValueType value;
    Treap left;
    Treap right;
    int priority;
};

static Treap NullTreap = NULL;
static const int TreapPriorityMax = 100000000;
static const int TreapPriorityMin = 1;

static Treap treap_init(){
    if (NullTreap == NULL) {
        NullTreap = malloc(sizeof(Treap));
        NullTreap->left = NullTreap->right = NullTreap;
        NullTreap->priority = TreapPriorityMax;
    }
    return NullTreap;
}

static TreeNode* left_rotate(TreeNode *p){
    TreeNode *left = p->left;
    p->left = left->right;
    left->right = p;
    return left;
}

static TreeNode* right_rotate(TreeNode *p){
    TreeNode *right = p->right;
    p->right = right->left;
    right->left = p;
    return right;
}


Treap treap_insert(ValueType x, Treap tree){
    if (tree == NullTreap) {
        tree = malloc(sizeof(Treap));
        tree->value = x;
        tree->priority = rand() % (TreapPriorityMax - TreapPriorityMin + 1) + TreapPriorityMin;
        tree->left = tree->right = NullTreap;
    }
    else if (x < tree->value){
        //先插入左子树中
        tree->left = treap_insert(x, tree->left);
        //如果左子树优先级小于树的优先级则调整
        if (tree->left->priority < tree->priority) {
            tree = left_rotate(tree);
        }
    }
    else if (x > tree->value){
        //先插入右子树中
        tree->right = treap_insert(x, tree->right);
        //如果右子树优先级小于树的优先级则调整
        if (tree->right->priority < tree->priority) {
            tree = right_rotate(tree);
        }
    }
    return tree;
}

Treap treap_makeEmpty(Treap tree){
    return searchtree_makeEmpty(tree);
}

TreeNode *treap_find(ValueType x,Treap tree){
    return searchtree_find(x, tree);
}

TreeNode *treap_findMin(Treap tree){
    return searchtree_findMin(tree);
}

TreeNode *treap_findMax(Treap tree){
    return searchtree_findMax(tree);
}

Treap treap_delete(ValueType x,Treap tree){
    if (tree != NullTreap) {
        if (x < tree->value) {
            tree->left = treap_delete(x, tree->left);
        }
        else if (x > tree->value){
            tree->right = treap_delete(x, tree->right);
        }
        else{
            //删除后由子树中优先级大的代替，根据左右子树比较进行选择
            if (tree->left->priority < tree->right->priority) {
                tree = left_rotate(tree);
            }
            else{
                tree = right_rotate(tree);
            }
            
            if (tree != NullTreap) {
                tree = treap_delete(x, tree);
            }
            else{
                free(tree->left);
                tree->left = NullTreap;
            }
        }
    }
    return tree;
}

ValueType treap_retrieve(TreeNode *p){
    return p->value;
}

