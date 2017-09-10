//
//  AVLTree.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/9.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "AVLTree.h"
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

struct TreeNode {
    ValueType value;
    AVLTree left;
    AVLTree right;
    int height;
};

static int height(TreeNode *p){
    if (p == NULL) {
        return -1;
    }
    else{
        return p->height;
    }
}

AVLTree avltree_makeEmpty(AVLTree tree){
   return searchtree_makeEmpty(tree);
}


TreeNode *avltree_find(ValueType x,AVLTree tree){
    return searchtree_find(x, tree);
}

TreeNode *avltree_findMin(AVLTree tree){
    return searchtree_findMin(tree);
}

TreeNode *avltree_findMax(AVLTree tree){
    return searchtree_findMax(tree);
}

static TreeNode* left_rotate(TreeNode *p){
    TreeNode *left = p->left;
    p->left = left->right;
    left->right = p;
    
    p->height = MAX(height(p->left),height(p->right)) + 1;//插入操作增加了高度
    left->height = MAX(height(left->left), height(left->right)) + 1;
    return left;
}

static TreeNode* right_rotate(TreeNode *p){
    TreeNode *right = p->right;
    p->right = right->left;
    right->left = p;
    
    p->height = MAX(height(p->left), height(p->right)) + 1;
    right->height = MAX(height(right->left), height(right->right)) + 1;
    return right;
}

static TreeNode* left_right_rotate(TreeNode *p){
    p->right = left_rotate(p->right);
    return right_rotate(p);
}

static TreeNode* right_left_rotate(TreeNode *p){
    p->left = right_rotate(p->left);
    return left_rotate(p);
}

static TreeNode* fix_balance(TreeNode *p){
    if (height(p->left) > height(p->right)) {
        //p左儿子的左儿子的高度大于p的左儿子的右儿子的高度, 执行左单旋转, 否则执行左-右双旋转
        if (height(p->left->left) > height(p->left->right)) {
            p = left_rotate(p);
        }
        else if(height(p->left->left) < height(p->left->right)) {
            p = left_right_rotate(p);
        }
    }
    else if(height(p->left) < height(p->right)){
        //p右儿子的右儿子的高度大于p的右儿子的左儿子的高度, 执行右单旋转, 否则执行右-左双旋转
        if(height(p->right->right) > height(p->right->left)){
            p = right_rotate(p);
        }
        else if(height(p->right->right) < height(p->right->left)) {
            p = right_left_rotate(p);
        }
    }
    return p;
}


AVLTree avltree_insert(ValueType x,AVLTree tree){
    if (tree == NULL) {
        tree = malloc(sizeof(AVLTree));
        if (tree != NULL) {
            tree->value = x;
            tree->height = 0;
            tree->left = tree->right = NULL;
        }
    }
    else if (x < tree->value) {
        tree->left = avltree_insert(x, tree->left);
        if (height(tree->left) - height(tree->right) == 2) {
            fix_balance(tree);
        }
    }
    else if (x > tree->value) {
        tree->right = avltree_insert(x, tree->right);
        if (height(tree->right) - height(tree->left) == 2) {
            fix_balance(tree);
        }
    }
    tree->height = MAX(height(tree->left), height(tree->right)) + 1;
    return tree;
}

AVLTree avltree_delete(ValueType x,AVLTree tree){
    if(tree == NULL){
        return NULL;
    }
    else {
        TreeNode *node = avltree_find(x, tree);
        if (node == NULL) {
            return tree;
        }
        //找到
        else {
            //左右子树都有用右子树最小节点来替换
            if (tree->left && tree->right) {
                TreeNode *tmp = avltree_findMin(tree->right);
                node->value = tmp->value;
                tree->right = avltree_delete(tree->value, tree->right);
            }
            else {
                //只有其中一个子树，删除后直接用剩下的替换
                if (tree->left == NULL) {
                    tree = tree->right;
                }
                else if (tree->right == NULL){
                    tree = tree->left;
                }
                free(node);
            }
        }
        //删除完节点之后要更新高度
        tree->height = MAX(height(tree->left), height(tree->right)) + 1;
        //不平衡就需要修复
        if ((height(tree->left) - height(tree->right) >= 2) || (height(tree->right) - height(tree->left) >= 2)){
            tree = fix_balance(tree);
            //修复完成后更新节点高度
            tree->height = MAX(height(tree->left), height(tree->right)) + 1;
        }
    }
    return tree;
}

ValueType avltree_retrieve(TreeNode *p){
    return searchtree_retrieve(p);
}




