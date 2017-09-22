//
//  SplayTree.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/22.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "SplayTree.h"

struct TreeNode{
    ValueType value;
    SplayTree left;
    SplayTree right;
};

static SplayTree SplayNode = NULL;

static SplayTree splay_init(){
    if (SplayNode == NULL) {
        SplayNode = malloc(sizeof(SplayTree));
        SplayNode->left = SplayNode->right = SplayNode;
    }
    return SplayNode;
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

static TreeNode* left_right_rotate(TreeNode *p){
    p->right = left_rotate(p->right);
    return right_rotate(p);
}

static TreeNode* right_left_rotate(TreeNode *p){
    p->left = right_rotate(p->left);
    return left_rotate(p);
}


static TreeNode* splaytree_splay(ValueType x, TreeNode *node){
    splay_init();
    TreeNode head;
    head.left = head.right = SplayNode;
    SplayTree leftTreeMax = &head;
    SplayTree rightTreeMin = &head;
    SplayNode->value = x;
    //查找x
    while (x != node->value) {
        if (x < node->value) {
            //一字型，左子树的左子树
            if (x < node->left->value) {
                //从左节点的旋转
                node = left_rotate(node);
            }
            //找到NULL就停下
            if (node->left == SplayNode) {
                break;
            }
            //此时旋转完后，将最右树的左子树接上旋转后的根节点，也就是原来的中间树
            rightTreeMin->left = node;
            //记录此时的最右树的根
            rightTreeMin = node;
            //继续往左子树找
            node = node->left;
        }
        else{
            //一字型，右子树的右子树
            if (x > node->right->value) {
                //从右节点的旋转
                node = right_rotate(node);
            }
            //找到NULL就停止
            if (node->right == SplayNode) {
                break;
            }
            leftTreeMax->right = node;
            leftTreeMax = node;
            node = node->right;
        }
    }
    //把根的右节点拆下来放到左树的右节点
    leftTreeMax->right = node->left;
    //把根的左节点拆下来放到右树的左节点
    rightTreeMin->left = node->right;
    //左子树接上左子树的右子树
    node->left = head.right;
    //右子树接上右子树的左子树
    node->right = head.left;
    return node;
}


SplayTree splaytree_makeEmpty(SplayTree tree){
    return searchtree_makeEmpty(tree);
}

TreeNode *splaytree_find(ValueType x,SplayTree tree){
    return  searchtree_find(x, tree);
}

TreeNode *splaytree_findMin(SplayTree tree){
    return searchtree_findMin(tree);
}

TreeNode *splaytree_findMax(SplayTree tree){
    return searchtree_findMax(tree);
}

SplayTree splaytree_insert(ValueType x,SplayTree tree){
    TreeNode *newNode = NULL;
    if (newNode  == NULL) {
        newNode = malloc(sizeof(SplayTree));
    }
    newNode->value = x;
    if (tree == SplayNode) {
        newNode->left = newNode->right = NULL;
        tree = newNode;
    }
    else{
        //先伸展
        tree = splaytree_splay(x, tree);
        //若伸展完没找到，则插入
        if (x  < tree->value) {
            //在插入树的左节点放入树的左子树
            newNode->left = tree->left;
            //把树放入插入点的右边
            newNode->right = tree;
            //左边置空
            tree->left = SplayNode;
            tree = newNode;
        }
        else if (tree->value < x){
            //在插入树的右节点放入树的右子树
            newNode->right = tree->right;
            //把树放入如插入点的左边
            newNode->left = tree;
            //右边置空
            tree->right = SplayNode;
            tree = newNode;
        }
        else{
            return tree;
        }
    }
    newNode = NULL;
    return tree;
}

SplayTree splaytree_delete(ValueType x,SplayTree tree){
    SplayTree newTree;
    if (tree != SplayNode) {
        //先伸展
        tree = splaytree_splay(x, tree);
        //找到需要删除的值
        if (x == tree->value) {
            //如果无左树
            if (tree->left == SplayNode) {
                //直接取整个右子树
                newTree = tree->right;
            }
            else{
                //将左子树进行伸展，再接上右子树
                newTree = tree->left;
                newTree = splaytree_splay(x, newTree);
                newTree->right = tree->right;
            }
            free(tree);
            tree = newTree;
        }
    }
    return tree;
}

ValueType splaytree_retrieve(TreeNode *p){
    return p->value;
}
