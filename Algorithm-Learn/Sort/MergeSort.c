//
//  MergeSort.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/13.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef int ValueType;

static void merge(ValueType array[], ValueType tmp[], int left, int mid, int right){
    int tmpIndex = left;
    int leftBegin = left;
    int leftEnd = mid - 1;
    int rightBegin = mid;
    int rightEnd = right;
    int size = rightEnd - leftBegin + 1;
    while (leftBegin <= leftEnd && rightBegin <= rightEnd) {
        //比较合并的两组的头
        if (array[leftBegin] <= array[rightBegin]) {
            tmp[tmpIndex++] = array[leftBegin++];
        }
        else{
            tmp[tmpIndex++] = array[rightBegin++];
        }
    }
    
    //若左边这组还有剩，继续放入
    while (leftBegin <= leftEnd) {
        tmp[tmpIndex++] = array[leftBegin++];
    }
    //若右边这组还有剩，继续放入
    while (rightBegin <= rightEnd) {
        tmp[tmpIndex++] = array[rightBegin++];
    }
    
    //放回原数组，tmp可以继续使用，因为size一致
    for (int i = 0; i < size; i++, rightEnd--) {
        array[rightEnd] = tmp[rightEnd];
    }
}

static void mergeSort_internal(ValueType array[], ValueType tmpArray[], int left, int right){
    if (left < right) {
        int mid = (left + right) / 2;
        //先排序小的数组，再合并
        mergeSort_internal(array, tmpArray, left, mid);
        mergeSort_internal(array, tmpArray, mid, right);
        merge(array, tmpArray, left, mid, right);
    }
}


void mergeSort(ValueType array[], int size){
    ValueType *tmpArray = malloc(sizeof(ValueType) * size);
    mergeSort_internal(array, tmpArray, 0, size - 1);
}



