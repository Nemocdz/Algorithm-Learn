//
//  3-FindDuplication.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/24.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

static bool duplicate(int numbers[], const int size, int *duplication){
    //边界判断
    if (numbers == NULL || size <= 0){
        return false;
    }
    
    //边界判断
    for (int i = 0; i < size; i++){
        if (numbers[i] < 0 || numbers[i] > size - 1){
            return false;
        }
    }
    
    for (int i = 0; i < size; i++){
        while(numbers[i] != i){
            if(numbers[i] == numbers[numbers[i]]){
                *duplication = numbers[i];
                return true;
            }
            // 将数字交换到该数字下标的位置，下一次发现数字直接到该下标找
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
    return false;
}

// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。

static int countRange(const int* numbers, const int size, const int start, const int end){
    if (numbers == NULL){
        return 0;
    }
    
    int count = 0;
    for (int i = 0; i < size; i++) {
        //计算在大小在start和end范围之间的数量
        if (numbers[i] >= start && numbers[i] <= end){
            count++;
        }
    }
    return count;
}


static bool duplicateConst(const int numbers[], const int size, int *duplication){
    if(numbers == NULL || size <= 0){
        return false;
    }
    
    int start = 1;
    int end = size - 1;
    while(end >= start){
        int middle = ((end - start) >> 1) + start;
        //计算前半的在范围内的数量
        int count = countRange(numbers, size, start, middle);
        
        //当start等于end，搜索那个数，看是否有重复
        if (end == start){
            if (count > 1){
                *duplication = start;
                return true;
            }
            else{
                break;
            }
        }
        
        //如果数目大于前半的数量，则重复的数在前半部分，将end移到midddle
        if (count > (middle - start + 1)){
            end = middle;
        }
        //小于则在后半部分，将start移到middle
        else{
            start = middle + 1;
        }
    }
    return false;
}






