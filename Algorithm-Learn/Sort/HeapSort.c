//
//  HeapSort.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/13.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>

typedef int ValueType;

static int leftChild(int index){
    return 2 * index + 1;
}

static void rebuidHeap(ValueType array[],int size, int index){
    int child;
    ValueType tmp;
    for (tmp = array[index]; leftChild(index) < size ; index = child) {
        child = leftChild(index);
        if (child != size - 1 && array[child + 1] > array[child]) {
            child++;
        }
        if (tmp < array[child]) {
            array[index] = array[child];
        }
        else{
            break;
        }
    }
    array[index] = tmp;
}

void heapSort(ValueType array[],int size){
    for (int i = size / 2; i >= 0; i--) {
        //一开始建立一个最大堆
        rebuidHeap(array, size, i);
    }
    for (int j = size - 1; j > 0; j--) {
        //将最大堆最最大值取出，放置最后
        ValueType tmp = array[0];
        array[0] = array[j];
        array[j] = tmp;
        //取出后需要执行空穴下置
        rebuidHeap(array, j, 0);
    }
}
