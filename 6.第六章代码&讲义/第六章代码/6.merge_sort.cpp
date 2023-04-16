/*************************************************************************
	> File Name: 6.merge_sort.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "0.sort_test.h"

int *buff;
void merge_sort(int *arr, int l, int r) {
    if (r - l <= 1) return ;
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid, r);
    // merge
    int p1 = l, p2 = mid, k = 0;
    while (p1 < mid || p2 < r) {
        if (p2 == r || (p1 < mid && arr[p1] <= arr[p2])) {
            buff[k++] = arr[p1++];
        } else {
            buff[k++] = arr[p2++];
        }
    }
    for (int i = l; i < r; i++) arr[i] = buff[i - l];
    return ;
}

int main() {
    int *arr_s = getRandData(SMALL_DATA_N);
    int *arr_b = getRandData(BIG_DATA_N);
    buff = (int *)malloc(sizeof(int) * BIG_DATA_N);
    TEST(merge_sort, arr_s, SMALL_DATA_N);
    TEST(merge_sort, arr_b, BIG_DATA_N);
    free(arr_s);
    free(arr_b);
    free(buff);
    return 0;
}
