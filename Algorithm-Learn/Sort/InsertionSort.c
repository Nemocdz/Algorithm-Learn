//
//  InsertionSort.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/13.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>
#include "SortUtil.h"


void insertionSort(ValueType array[],int size){
    ValueType tmp;
    //第一个元素前面没有元素，不需要比较，所以下标从1开始
    for (int i = 1; i < size; i++) {
        tmp = array[i];
        int j;
        //往前找，若比该数字大则应该在之后，往后移动，直到找到没有比该数字大的位置停下
        for (j = i; j > 0 && array[j -1] > tmp; j--) {
            array[j] = array[j-1];
        }
        array[j] = tmp;
    }
}


