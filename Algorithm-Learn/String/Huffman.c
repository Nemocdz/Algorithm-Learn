//
//  Huffman.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/21.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "Huffman.h"
#include "HashTable-Link.h"

struct HuffmanTree{
    char value;
    int weight; //权值
    HuffmanTree left;
    HuffmanTree right;
};

struct HuffmanItem{
    char s;
    int weight;
};

HuffmanTree huffman_code(char string[], int size){
    LinkHashTable table = lhashtable_create(size);
    for (int i = 0; i < size; i++) {
        char s = string[i];
        ListNode *p = lhashtable_find(s, table);
        if (p == NULL) {
            lhashtable_insert(s, 1, table);
        }
        else{
            ValueType times = lhashtable_retrieve(p);
            times++;
            lhashtable_insert(s, times, table);
        }
    }
    
    //遍历哈希表，将每个值存成一个数组
    return huffman_create(NULL, 0);
}


HuffmanTree huffman_create(HuffmanItem array[], int size){
    HuffmanTree nodes[size];
    HuffmanTree node = malloc(sizeof(HuffmanTree));
    for (int i = 0; i < size; i++){
        nodes[i] = malloc(sizeof(HuffmanTree));
        nodes[i]->weight = array[i]->weight;
        nodes[i]->value = array[i]->s;
        nodes[i]->left = nodes[i]->right = NULL;
    }
    
    for (int i = 1; i < size; i++){
        //k1表示森林中具有最小权值的树根结点的下标，k2为次最小的下标
        int k1 = -1;
        int k2 = -1;
        //先将k1和k2置为前两个不为NULL的树节点的index
        for (int j = 0; j < size; j++){
            if (nodes[j] != NULL && k1 == -1){
                k1 = j;
                continue;
            }
            if (nodes[j] != NULL){
                //如果k2 < k1则交换
                if (nodes[j] < nodes[k1]) {
                    k2 = k1;
                    k1 = j;
                }
                else{
                    k2 = j;
                }
                break;
            }
        }
        
        
        for (int j = k2; j < size; j++){
            if (nodes[j] != NULL){
                //如果小于k1，则将k2等于k1，k1等于新的
                if (nodes[j]->weight < nodes[k1]->weight){
                    k2 = k1;
                    k1 = j;
                }
                //如果小于k2而大于k1则，将k2等于新的
                else if (nodes[j]->weight < nodes[k2]->weight){
                    k2 = j;
                }
            }
        }
        
        //由最小权值树和次最小权值树建立一棵新树，q指向树根结点
        node->weight = nodes[k1]->weight + nodes[k2]->weight;
        node->left = nodes[k1];
        node->right = nodes[k2];
        
        //将指向新树的指针赋给b指针数组中k1位置
        nodes[k1] = node;
        //k2位置为空
        nodes[k2] = NULL;
    }
    free(nodes);
    return node;
}

static int lengthOfTree(HuffmanTree tree, int length){
    if (tree == NULL) {
        return 0;
    }
    else{
        if (tree->left == NULL && tree->right == NULL){
            return tree->weight * length;
        }
        else {
            return lengthOfTree(tree->left, length + 1) + lengthOfTree(tree->right, length + 1);
        }
    }
}

int huffman_length(HuffmanTree tree){
    return lengthOfTree(tree, 0);
}



