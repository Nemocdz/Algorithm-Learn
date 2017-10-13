//
//  SelectionSort.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/13.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>
#include "SortUtil.h"

static void selectionSort(ValueType array[],int size){
    for (int i = 0; i < size; i++) {
        int min = i;
        //找到之后最小的一个
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min]) {
                min  = j;
            }
        }
        //将该位置放入最小的一个
        if (min != i) {
            swapValues(&array[i], &array[min]);
        }
    }
}
