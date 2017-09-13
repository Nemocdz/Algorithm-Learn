//
//  MergeSort.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/13.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>

typedef int ValueType;

void mergeSort(ValueType array[], int size){
    
}

static void MSort(ValueType array[], ValueType tmpArray[], int left, int right){
    if (left < right) {
        int center = (left + right) / 2;
        MSort(array, tmpArray, left, center);
        MSort(array, tmpArray, center, right);
        
    }
}




