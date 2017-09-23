//
//  KMP.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/22.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "KMP.h"
#include <string.h>

static void getNext(char *string, int *next){
    //后缀首字母
    int i = 1;
    //前缀首字母
    int j = 0;
    //0个字符和1个字符都没有匹配
    next[0] = next[1] = 0;
    //后缀不能超过长度
    while (i < strlen(string)){
        //j = 0时，直接记录next[2] = 1，但也可以统一至下面的代码
        /*
        if (j == 0) {
            next[2] = 1;
        }
         */
        if (j == 0 || string[i] == string[j]){
            i++;
            j++;
            //到j位还是匹配的，所以若不匹配回退至j，将j记录下来
            next[i] = j;
        }
        else
            //若不匹配则回退，回退的数字记录在第j个中，因为j = i - 1，也就是上一个
            j = next[j];
    }
}
static void getNextBetter(char *string, int *next){
    int i = 1;
    int j = 0;
    next[0] = next[1] = 0;
    while (i < strlen(string)) {
        if (j == 0 || string[i] == string[j]) {
            i++;
            j++;
            //若下一位不匹配，则记录回退和原先一样
            if (string[i] != string[j]) {
                next[i] = j;
            }
            //若匹配则自己使用上一个回退的值
            else{
                next[i] = next[j];
            }
        }
        else{
            j = next[j];
        }
    }
}


int kmp_index(char *string, char *target){
    int i = 0;
    int j = 0;
    int next[strlen(target)];
    getNextBetter(target, next);
    while (i < strlen(string) && j < strlen(target)){
        // 两字母相等则继续
        if (string[i] == target[j]){
            i++;
            j++;
        }
        //指针后退重新开始匹配
        else{
            //j退回合适的位置，i值不变
            j = next[j];
        }
    }
    //匹配完全，j走到target最后
    if (j == strlen(target)){
        //i值到了主串的末尾，减到长度就是开头
        return (int)(i - strlen(string));
    }
    else{
        return 0;
    }
}


