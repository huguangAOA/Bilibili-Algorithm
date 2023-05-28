/*************************************************************************
	> File Name: 5.quick_sort.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include "0.sort_test.h"
using namespace std;

#define swap(a, b) { \
    __typeof(a) __c = a; \
    a = b, b = __c; \
}

void quick_sort(int *arr, int l, int r) {
    // code = 0
    if (r - l <= 2) {
        if (r - l <= 1) return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    // code = 1, partition
    int x = l, y = r - 1, z = arr[l];
    while (x < y) {
        while (x < y && z <= arr[y]) --y;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= z) ++x;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = z;
    // code = 2
    quick_sort(arr, l, x);
    // code = 3
    quick_sort(arr, x + 1, r);
    return ; // code = 4
}

struct Data {
    Data(int *arr, int l, int r)
    : arr(arr), l(l), r(r), code(0) {}
    int *arr, l, r, x;
    int code;
};

void non_quick_sort(int *arr, int l, int r) {
    stack<Data> s;
    Data d(arr, l, r);
    s.push(d);
    while (!s.empty()) {
        Data &cur = s.top();
        switch (cur.code) {
            case 0: {
                if (cur.r - cur.l <= 2) {
                    if (cur.r - cur.l <= 1) s.pop();
                    else {
                        if (cur.arr[cur.l] > cur.arr[cur.l + 1]) { 
                            swap(cur.arr[cur.l], cur.arr[cur.l + 1]);
                        }
                        s.pop();
                    }
                } else {
                    cur.code = 1;
                }
            } break;
            case 1: {
                int x = cur.l, y = cur.r - 1, z = cur.arr[cur.l];
                while (x < y) {
                    while (x < y && z <= cur.arr[y]) --y;
                    if (x < y) cur.arr[x++] = cur.arr[y];
                    while (x < y && cur.arr[x] <= z) ++x;
                    if (x < y) cur.arr[y--] = cur.arr[x];
                }
                cur.arr[x] = z;
                cur.x = x;
                cur.code = 2;
            } break;
            case 2: {
                Data d(cur.arr, cur.l, cur.x);
                cur.code = 3;
                s.push(d);
            } break;
            case 3: {
                Data d(cur.arr, cur.x + 1, cur.r);
                cur.code = 4;
                s.push(d);
            } break;
            case 4: { s.pop(); } break;
        }
    }
    return ;
}


void quick_sort_v1(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l <= 1) return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    // partition
    int x = l, y = r - 1, z = arr[l];
    do {
        while (arr[x] < z) ++x;
        while (arr[y] > z) --y;
        if (x <= y) {
            swap(arr[x], arr[y]);
            ++x, --y;
        }
    } while (x <= y);    
    quick_sort_v1(arr, l, x);
    quick_sort_v1(arr, x, r);
    return ;
}

inline int three_point_select(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    return b;
}

void quick_sort_v2(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l <= 1) return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    // partition
    int x = l, y = r - 1;
    int z = three_point_select(
        arr[l], 
        arr[r - 1], 
        arr[(l + r) / 2]
    );
    do {
        while (arr[x] < z) ++x;
        while (arr[y] > z) --y;
        if (x <= y) {
            swap(arr[x], arr[y]);
            ++x, --y;
        }
    } while (x <= y);    
    quick_sort_v2(arr, l, x);
    quick_sort_v2(arr, x, r);
    return ;
}

void quick_sort_v3(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l <= 1) return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    while (l < r) {
        // partition
        int x = l, y = r - 1;
        int z = three_point_select(
            arr[l], 
            arr[r - 1], 
            arr[(l + r) / 2]
        );
        do {
            while (arr[x] < z) ++x;
            while (arr[y] > z) --y;
            if (x <= y) {
                swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while (x <= y);    
        quick_sort_v3(arr, l, x); // left
        l = x;
    }
    return ;
}

#define threshold 16

void unguarded_insert_sort(int *arr, int l, int r) {
    int ind = l;
    for (int i = l + 1; i < r; i++) {
        if (arr[i] < arr[ind]) ind = i;
    }
    while (ind > l) {
        swap(arr[ind], arr[ind - 1]);
        ind -= 1;
    }
    for (int i = l + 1; i < r; i++) {
        int j = i;
        while (arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j -= 1;
        }
    }
    return ;
}

void __quick_sort_v4(int *arr, int l, int r) {
    while (r - l > threshold) {
        // partition
        int x = l, y = r - 1;
        int z = three_point_select(
            arr[l], 
            arr[r - 1], 
            arr[(l + r) / 2]
        );
        do {
            while (arr[x] < z) ++x;
            while (arr[y] > z) --y;
            if (x <= y) {
                swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while (x <= y);    
        __quick_sort_v4(arr, l, x); // left
        l = x;
    }
    return ;
}

void quick_sort_v4(int *arr, int l, int r) {
    __quick_sort_v4(arr, l, r);
    unguarded_insert_sort(arr, l, r);
    return ;
}

int main() {
    int *arr_s = getRandData(SMALL_DATA_N);
    int *arr_b = getRandData(BIG_DATA_N);
    TEST(quick_sort, arr_s, SMALL_DATA_N);
    TEST(quick_sort, arr_b, BIG_DATA_N);
    TEST(non_quick_sort, arr_b, BIG_DATA_N);
    TEST(quick_sort_v1, arr_b, BIG_DATA_N);
    TEST(quick_sort_v2, arr_b, BIG_DATA_N);
    TEST(quick_sort_v3, arr_b, BIG_DATA_N);
    TEST(quick_sort_v4, arr_b, BIG_DATA_N);
    free(arr_s);
    free(arr_b);
    return 0;
}
