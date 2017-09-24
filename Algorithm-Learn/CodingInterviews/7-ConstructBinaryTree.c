//
//  7-ConstructBinaryTree.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/24.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出

typedef int ValueType;
typedef struct TreeNode TreeNode;
struct TreeNode{
    ValueType value;
    TreeNode *left;
    TreeNode *right;
};

static TreeNode* construct_internal(int* startPreorder, int* endPreorder,int* startInorder, int* endInorder){
    // 前序遍历序列的第一个数字是根结点的值
    int rootValue = startPreorder[0];
    TreeNode* root = malloc(sizeof(TreeNode *));
    root->value = rootValue;
    root->left = root->right = NULL;
    
    //只有一个点
    if (startPreorder == endPreorder){
        //判断前中续是否符合
        if (startInorder == endInorder && *startPreorder == *startInorder){
            return root;
        }
        //不符合就是输入错误
        else{
            return NULL;
        }
    }
    
    
    // 在中序遍历中找到根结点的值
    int* rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue){
        rootInorder++;
    }
    
    //如果找到最后还不相等，就说明跟节点不在中序中
    if (rootInorder == endInorder && *rootInorder != rootValue){
        return NULL;
    }
    
    //跟节点离最前的长度，前面是left，后面是right
    int leftSize = (int)(rootInorder - startInorder);
    
    //左子树的最后一个值
    int* leftPreorderEnd = startPreorder + leftSize;
    
    if (leftSize > 0){
        // 构建左子树
        root->left = construct_internal(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
    }
    
    if (leftSize < endPreorder - startPreorder){
        // 构建右子树
        root->right = construct_internal(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
    }
    return root;
}

static TreeNode* construct(int* preorder, int* inorder, int size){
    if (preorder == NULL || inorder == NULL || size <= 0){
        return NULL;
    }
    return construct_internal(preorder, preorder + size  - 1, inorder, inorder + size - 1);
}

