/*************************************************************************
	> File Name: 1.selection_sort.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "0.sort_test.h"

void selection_sort(int *arr, int l, int r) {
    for (int i = l, I = r - 1; i < I; i++) {
        int ind = i;
        for (int j = i + 1; j < r; j++) {
            if (arr[j] < arr[ind]) ind = j;
        }
        swap(arr[i], arr[ind]);
    }
    return ;
}

int main() {
    int *arr = getRandData(SMALL_DATA_N);
    TEST(selection_sort, arr, SMALL_DATA_N);
    free(arr);
    return 0;
}
