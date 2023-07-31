/*************************************************************************
	> File Name: 7.HZOJ-254.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

#define MAX_N 50000

struct Data {
    int l, r, id;
} arr[MAX_N + 5];
int m_time[MAX_N + 5], ans[MAX_N + 5];
int cnt = 0;

bool cmp(const Data &a, const Data &b) {
    if (a.l != b.l) return a.l < b.l;
    return a.id < b.id;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &arr[i].l, &arr[i].r);
        arr[i].id = i;
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++) {
        int pos = -1;
        for (int j = 0; j < cnt; j++) {
            if (m_time[j] < arr[i].l) {
                pos = j;
                break;
            }
        }
        if (pos == -1) pos = (cnt++);
        m_time[pos] = arr[i].r;
        ans[arr[i].id] = pos + 1;
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
