//
//  16-Power.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/10/13.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。

static double powerWithUnsignedExponent(double base, unsigned int exponent){
    if (exponent == 0){
        return 1;
    }
    
    if (exponent == 1){
        return base;
    }
    
    double result = powerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if ((exponent & 0x1) == 1){
        result *= base;
    }
    return result;
}

//double的精度问题
static bool equal(double num1, double num2){
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001)){
        return true;
    }
    else{
        return false;
    }
}

static double power(double base, int exponent){
    if (equal(base, 0.0) && exponent < 0){
        return 0.0;
    }
    
    
    unsigned int absExponent = (unsigned int) (exponent);
    if (exponent < 0){
        absExponent = (unsigned int) (-exponent);
    }
    
    double result = powerWithUnsignedExponent(base, absExponent);
    if (exponent < 0){
        result = 1.0 / result;
    }
    return result;
}



