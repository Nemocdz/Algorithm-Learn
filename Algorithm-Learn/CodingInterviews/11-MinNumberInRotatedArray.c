//
//  11-MinNumberInRotatedArray.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/24.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>

// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

static int minInOrderArray(int* numbers, int start, int end){
    int result = numbers[start];
    for(int i = start + 1; i <= end; ++i){
        if (result > numbers[i]){
            result = numbers[i];
        }
    }
    return result;
}


static int minInRotateArray(int* numbers, int size){
    if (numbers == NULL || size <= 0){
        return -1;
    }
    
    int start = 0;
    int end = size - 1;
    //若end大于start，那么就是递增，旋转0个字符，最小值就是第一个值
    int mid = start;
    
    while (numbers[start] >= numbers[end]){
        //如果只剩两个数，则start指向第一个子数组的最后，end指向第二个子数组的第一个，也就是最小数字
        if (end - start == 1){
            mid = end;
            break;
        }
        
        mid = (start + end) / 2;
        //如果三个数字相等，则只能顺序查找，如353，323
        if(numbers[start] == numbers[end] && numbers[mid] == numbers[start]){
            return minInOrderArray(numbers, start, end);
        }
        
        //缩小查找范围,若mid大于等于start，则mid在第一个递增数组中，第二个数组开头在mid后面
        if (numbers[mid] >= numbers[start]){
            start = mid;
        }
        //或者是小于end，mid在第二个数组中，第二个数组开头在mid前面
        else if(numbers[mid] <= numbers[end]){
            end = mid;
        }
    }
    return numbers[mid];
}


