//
//  10-Fibonacci.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/24.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>

// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。


static long long fibonacci_reverse(unsigned int n){
    if (n <= 0){
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else {
        return fibonacci_reverse(n - 1) + fibonacci_reverse(n - 2);
    }
}

static long long fibonacci_cycle(unsigned int n){
    int result[2] = {0, 1};
    if (n < 2){
        return result[n];
    }
    long long fibNMinusOne = 1;
    long long fibNMinusTwo = 0;
    long long fibN = 0;
    for (unsigned int i = 2; i <= n; ++ i){
        fibN = fibNMinusOne + fibNMinusTwo;
        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }
    return fibN;
}
