//
//  BubbleSort.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/13.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>
#include "SortUtil.h"

void bubbleSort(ValueType array[],int size){
    for (int i = 0; i < size - 1; i++) {
        //每次循环后i个是最大的，所以不用循环到size-1
        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j+1]) {
                swapValues(&array[j], &array[j + 1]);
            }
        }
    }
}
