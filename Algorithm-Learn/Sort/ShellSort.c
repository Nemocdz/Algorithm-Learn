//
//  ShellSort.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/13.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include <stdio.h>

typedef int ValueType;

//下界是O(n*log2n)，和增量间隔选择有关
void shellSort(ValueType array[],int size){
    //先选一个增量间隔，一开始是size一半，增量每次变成一半（可改进）
    for (int increment = size/2; increment > 0; increment /= 2) {
        for (int i = increment; i < size; i++) {
            ValueType tmp  = array[i];
            int j;
            //和间隔相同的数分为一组去比较，底线是第一个分组数
            for (j = i; j >= increment; j-=increment) {
                if (tmp < array[j-increment]) {
                    array[j] = array[j-increment];
                }
                else{
                    break;
                }
            }
            array[j] = tmp;
        }
    }
    
}
