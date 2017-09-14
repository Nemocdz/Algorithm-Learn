//
//  SortUtil.c
//  Algorithm-Learn
//
//  Created by Nemocdz on 2017/9/14.
//  Copyright © 2017年 Nemocdz. All rights reserved.
//

#include "SortUtil.h"

void swapValues(ValueType *a, ValueType *b){
    ValueType tmp = *a;
    *a = *b;
    *b = tmp;
}
