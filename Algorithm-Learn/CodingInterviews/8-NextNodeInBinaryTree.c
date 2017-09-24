//
//  8-NextNodeInBinaryTree.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/24.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>
// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。

typedef int ValueType;
typedef struct TreeNode TreeNode;
struct TreeNode{
    ValueType value;
    TreeNode *parrent;
    TreeNode *left;
    TreeNode *right;
};

static TreeNode* getNext(TreeNode* node){
    if (node == NULL) {
        return NULL;
    }
    
    TreeNode* result = NULL;
    //如果有右子树，则是右子树的最底层左子树
    if (node->right != NULL){
        result = node->right;
        while(result->left != NULL){
            result = result->left;
        }
    }
    //如果有父子树，无右子树，则找到第一个父子树的是祖父子树的右子树
    else if (node->parrent != NULL){
        TreeNode* current = node;
        TreeNode* parrent = node->parrent;
        while(parrent != NULL && current == parrent->right){
            current = parrent;
            parrent = parrent->parrent;
        }
        result = parrent;
    }
    return result;
}
