//
//  QuickSort.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/14.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>
#include "SortUtil.h"

static ValueType median(ValueType array[], int left, int right){
    int mid = (left + right) / 2;
    //将首尾和中间值按小到大排序
    if (array[left] > array[mid]) {
        swapValues(&array[left], &array[mid]);
    }
    
    if (array[left] > array[right]) {
        swapValues(&array[left], &array[right]);
    }
    
    if (array[mid] > array[right]) {
        swapValues(&array[mid], &array[right]);
    }
    
    //将中间值作为标准，并放置倒数第二位
    swapValues(&array[mid], &array[right - 1]);
    return array[right - 1];
}

static void quickSort_internal(ValueType array[], int left, int right){
    //超过3个才可以用3个的中间值
    if (left + 3 <= right) {
        ValueType flag = median(array, left, right);
        int i = left;
        //flag放在了right-1的位置
        int j = right - 1;
        for (;;) {
            //先++和--是因为left一定比flag小，right-1就是flag
            while (array[++i] < flag) {}
            while (array[--j] > flag) {}
            if (i < j) {
                swapValues(&array[i], &array[j]);
            }
            //i碰见j则退出
            else{
                break;
            }
        }
        //将flag放到正确的的位置
        swapValues(&array[i], &array[right - 1]);
        //对flag两边分别应用快排
        quickSort_internal(array, left, i - 1);
        quickSort_internal(array, i + 1, right);
    }
    else{
        //两个以下直接判断
        if (array[left] > array[right]) {
            swapValues(&array[left], &array[right]);
        }
    }
}

static void quickSort(ValueType array[], int size){
    quickSort_internal(array, 0, size - 1);
}
