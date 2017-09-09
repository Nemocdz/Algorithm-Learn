//
//  SearchTree.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/9.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "SearchTree.h"

struct TreeNode{
    ValueType value;
    SearchTree left;
    SearchTree right;
};

SearchTree searchtree_makeEmpty(SearchTree tree){
    if (tree != NULL) {
        searchtree_makeEmpty(tree->left);
        searchtree_makeEmpty(tree->right);
        free(tree);
    }
    return NULL;
}

TreeNode *searchtree_find(ValueType x,SearchTree tree){
    if (tree == NULL) {
        return NULL;
    }
    if (x < tree->value){
        return searchtree_find(x, tree->left);
    }
    else if (x > tree->value){
        return searchtree_find(x, tree->right);
    }
    else{
        return tree;
    }
}

TreeNode *searchtree_findMin(SearchTree tree){
    if (tree != NULL) {
        if (tree->left != NULL) {
            return searchtree_findMin(tree->left);
        }
        else{
            return tree;
        }
    }
    return NULL;
}

TreeNode *searchtree_findMax(SearchTree tree){
    if (tree != NULL) {
        while (tree->right != NULL) {
            tree = tree->right;
        }
        return tree;
    }
    return NULL;
}

SearchTree searchtree_insert(ValueType x,SearchTree tree){
    if (tree == NULL) {
        tree = malloc(sizeof(SearchTree));
        if (tree != NULL) {
            tree->value = x;
            tree->left=tree->right=NULL;
        }
    }
    else if (x < tree->value){
        tree->left = searchtree_insert(x, tree->left);
    }
    else if (x > tree->value){
        tree->right = searchtree_insert(x, tree->right);
    }
    return tree;
}

SearchTree searchtree_delete(ValueType x,SearchTree tree){
    
}

ValueType searchtree_retrieve(TreeNode *p){
    
}
