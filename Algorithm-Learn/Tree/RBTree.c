//
//  RBTree.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/22.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "RBTree.h"

typedef enum ColorType{
    Red,
    Black
}ColorType;

struct TreeNode{
    ValueType value;
    RBTree left;
    RBTree right;
    ColorType color;
};

static RBTree NullRBTree = NULL;
static const int RBTreeValueMax = 1000;
static const int RBTreeValueMin = -1;

static RBTree rbtree_init(){
    if (NullRBTree == NULL) {
        NullRBTree = malloc(sizeof(RBTree));
        NullRBTree->left = NullRBTree->right = NullRBTree;
        NullRBTree->color = Black;
        NullRBTree->value = RBTreeValueMax;
    }
    
    RBTree tree = malloc(sizeof(RBTree));
    tree->value = RBTreeValueMin;
    tree->left = tree->right = NullRBTree;
    tree->color = Black;
    return tree;
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


static RBTree rbtree_rotate(ValueType x,RBTree parrent){
    if (x < parrent->value) {
        return parrent->left = x < parrent->left->value ? left_rotate(parrent->left) : right_rotate(parrent->left);
    }
    else{
        return parrent->right = x < parrent->right->value ? right_rotate(parrent->right) : left_rotate(parrent->left);
    }
}

static RBTree temp, parrent, grandpa, grandgrandpa;

static void handleReorient(ValueType x, RBTree tree){
    temp->color = Red;
    temp->left->color = Black;
    temp->right->color = Black;
    if (parrent->color == Red) {
        grandpa->color = Red;
        if ((x < grandpa->value) != (x < parrent->value)){
            parrent = rbtree_rotate(x, grandpa);
        }
        temp = rbtree_rotate(x, grandgrandpa);
        temp->color = Black;
    }
    tree->right->color = Black;
}

RBTree rbtree_insert(ValueType x,RBTree tree){
    rbtree_init();
    //太复杂了，有空再研究
    temp = parrent = grandgrandpa = tree;
    NullRBTree->value = x;
    while (temp->value != x) {
        grandgrandpa = grandpa;
        grandpa = parrent;
        parrent = temp;
        if (x < temp->value) {
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
        
        if (temp->left->color == Red && temp->right->color == Red) {
            handleReorient(x, tree);
        }
    }
    
    if (temp != NullRBTree) {
        return NullRBTree;
    }
    
    temp = malloc(sizeof(RBTree));
    temp->value = x;
    temp->left = temp->right = NullRBTree;
    
    if (x < parrent->value) {
        parrent->left = temp;
    }
    else{
        parrent->right = temp;
    }
    handleReorient(x, tree);
    return tree;
}

RBTree rbtree_makeEmpty(RBTree tree){
    return searchtree_makeEmpty(tree);
}

TreeNode *rbtree_find(ValueType x,RBTree tree){
    return searchtree_find(x, tree);
}

TreeNode *rbtree_findMin(RBTree tree){
    return searchtree_findMin(tree);
}

TreeNode *rbtree_findMax(RBTree tree){
    return searchtree_findMax(tree);
}

RBTree rbtree_delete(ValueType x,RBTree tree){
    //太复杂了，稍后有空再补充
    return NULL;
}

ValueType rbtree_retrieve(TreeNode *p){
    return p->value;
}



