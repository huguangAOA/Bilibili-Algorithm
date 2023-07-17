/*************************************************************************
	> File Name: 11.HZOJ-242.cpp
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

#define MAX_N 100000
long long a[MAX_N + 5], b[MAX_N + 5];

int check(long long *a, int n, int M, int A) {
    for (int i = 1; i <= n; i++) b[i] = a[i] - A;
    b[0] = 0;
    for (int i = 1; i <= n; i++) b[i] += b[i - 1];
    long long pre = 0;
    for (int i = M; i <= n; i++) {
        pre = min(pre, b[i - M]);
        if (b[i] - pre >= 0) return 1;
    }
    return 0;
}

int solve(long long *a, int n, int M, int max_num) {
    int head = 0, tail = max_num, mid;
    while (head < tail) {
        mid = (head + tail + 1) / 2;
        if (check(a, n, M, mid)) head = mid;
        else tail = mid - 1;
    }
    return head;
}

int main() {
    int n, m, max_num = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        x *= 1000;
        a[i] = x;
        max_num = max(x, max_num);
    }
    printf("%d\n", solve(a, n, m, max_num));
    return 0;
}
