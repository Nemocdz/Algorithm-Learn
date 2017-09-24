//
//  5-ReplaceBlanks.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/24.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>
#include <string.h>

// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

static void replaceBlank(char string[], int size){
    if (string == NULL && size <= 0){
        return;
    }
    
    int originalSize = 0;
    int numberOfBlank = 0;
    
    //统计空格数量
    for (int i = 0; string[i] != '\0'; i++) {\
        originalSize++;
        if (string[i] == ' '){
            numberOfBlank++;
        }
    }
    
    //计算替换后长度
    int newSize = originalSize + numberOfBlank * (3 - 1);
    //size不够旧替换不了
    if (newSize > size){
        return;
    }
    
    int indexOfOriginal = originalSize;
    int indexOfNew = newSize;
    
    //从后往前搜索，先从newSize的地方开始
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal){
        //空格就替换后并往前走
        if(string[indexOfOriginal] == ' '){
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
        }
        //否则一一复制
        else{
            string[indexOfNew--] = string[indexOfOriginal];
        }
        indexOfOriginal--;
    }
}
