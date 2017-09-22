//
//  Huffman.h
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/21.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#ifndef Huffman_h
#define Huffman_h

#include <stdio.h>
#include <stdlib.h>

typedef struct HuffmanTree* HuffmanTree;
typedef struct HuffmanItem* HuffmanItem;

HuffmanTree huffman_code(char string[], int size);
HuffmanTree huffman_create(HuffmanItem array[], int size);
int huffman_length(HuffmanTree tree);

#endif /* Huffman_h */
