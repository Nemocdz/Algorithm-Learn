//
//  14-CuttingRope.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/28.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。

static int maxProductAfterCutting_dp(int length){
    if (length < 2){
        return 0;
    }

    if (length == 2){
        return 1;
    }

    if (length == 3){
        return 2;
    }
    
    int products[length + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;
    
    int max = 0;
    for (int i = 4; i <= length; i++){
        max = 0;
        //分成两段最大是1比1
        for (int j = 1; j <= i / 2; j++){
            //计算两段的乘积，products数组存对应段的最大值
            int product = products[j] * products[i - j];
            if (max < product){
                max = product;
            }
            products[i] = max;
        }
    }
    max = products[length];
    free(products);
    return max;
}

static int maxProductAfterCutting_greedy(int length){
    if (length < 2){
        return 0;
    }
    if (length == 2){
        return 1;
    }
    if (length == 3){
        return 2;
    }
    
    // 尽可能多地减去长度为3的绳子段
    int timesOf3 = length / 3;
    
    // 当绳子最后剩下的长度为4的时候，不能再剪去长度为3的绳子段。
    // 此时更好的方法是把绳子剪成长度为2的两段，因为2*2 > 3*1。
    if(length - timesOf3 * 3 == 1) {
        timesOf3 -= 1;
    }
    
    int timesOf2 = (length - timesOf3 * 3) / 2;
    return (int) (pow(3, timesOf3)) * (int) (pow(2, timesOf2));
}

