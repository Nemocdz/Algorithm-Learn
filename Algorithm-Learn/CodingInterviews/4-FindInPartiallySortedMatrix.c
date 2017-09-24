//
//  4-FindInPartiallySortedMatrix.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/24.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。

static bool find(const int* matrix, const int rows, const int columns, const int number){
    bool found = false;
    if (matrix != NULL && rows > 0 && columns > 0){
        int row = 0;
        //列从后往前找
        int column = columns - 1;
        while (row < rows && column >= 0){
            if (matrix[row * columns + column] == number){
                found = true;
                break;
            }
            //比需要找的数字大，肯定在上一列
            else if(matrix[row * columns + column] > number){
                column--;
            }
            //小就在下面的行
            else{
                row++;
            }
        }
    }
    return found;
}


