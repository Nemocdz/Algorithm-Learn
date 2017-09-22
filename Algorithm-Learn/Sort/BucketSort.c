//
//  BucketSort.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/14.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>
#include "SortUtil.h"

void bucketSort(ValueType array[], int size, int max){
    int hash[max];
    //初始化为0，代表数字出现次数
    for (int i = 0; i < max; i++) {
        hash[i] = 0;
    }
    //遍历，发现数字则次数+1
    for (int i = 0; i < size; i++) {
        int key = array[i];
        hash[key]++;
    }
    int index = 0;
    //遍历hash，发现有数字次数大于0则放入原数组
    for (int i = 0; i < max && index < size; i++) {
        int count = hash[i];
        for (int j = 0; j < count; j++) {
            array[index++] = i;
        }
    }
}

