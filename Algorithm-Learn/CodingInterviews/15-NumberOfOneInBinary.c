//
//  15-NumberOfOneInBinary.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/28.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>

// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

static int numOfOne_1(int n){
    int count = 0;
    unsigned int flag = 1;
    while (flag){
        //每一位相与，1则有1
        if (n & flag){
            count++;
        }
        flag = flag << 1;
    }
    return count;
}

static int numOfOne_2(int n){
    int count = 0;
    while (n){
        count++;
        //把和-1的相与
        n = (n - 1) & n;
    }
    return count;
}

