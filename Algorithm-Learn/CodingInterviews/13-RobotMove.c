//
//  13-RobotMove.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/28.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

static int getDigitSum(int number){
    int sum = 0;
    while(number > 0){
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

static bool check(int k, int rows, int cols, int row, int col, bool* visited){
    if (row >= 0 && row < rows &&
        col >= 0 && col < cols &&
        getDigitSum(row) + getDigitSum(col) <= k &&
        //没有被访问过，数组中记录过
        !visited[row * cols + col]){
        return true;
    }
    return false;
}

static int movingCount_internal(int k, int rows, int cols, int row, int col, bool* visited){
    int count = 0;
    //如果合法，那么继续访问
    if (check(k, rows, cols, row, col, visited)){
        //访问过的用数组存起来
        visited[row * cols + col] = true;
        //次数+1，此次访问有效，并访问上下左右
        count = 1
        + movingCount_internal(k, rows, cols, row - 1, col, visited)
        + movingCount_internal(k, rows, cols, row, col - 1, visited)
        + movingCount_internal(k, rows, cols, row + 1, col, visited)
        + movingCount_internal(k, rows, cols, row, col + 1, visited);
    }
    return count;
}

static int movingCount(int k, int rows, int cols){
    if (k < 0 || rows <= 0 || cols <= 0){
        return 0;
    }
    bool visited[rows * cols];
    for(int i = 0; i < rows * cols; ++i){
        visited[i] = false;
    }
    int count = movingCount_internal(k, rows, cols, 0, 0, visited);
    free(visited);
    return count;
}




