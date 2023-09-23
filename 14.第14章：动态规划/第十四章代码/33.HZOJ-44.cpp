/*************************************************************************
	> File Name: 33.HZOJ-44.cpp
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

#define MAX_N 1000000
int dp[MAX_N + 5], len[MAX_N + 5];

int binary_search(int *len, int n, int x) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (len[mid] < x) head = mid;
        else tail = mid - 1;
    }
    return head;
}

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    len[0] = -1;
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        dp[i] = binary_search(len, ans, a) + 1;
        len[dp[i]] = a;
        if (dp[i] > ans) ans = dp[i];
    }
    return 0;
}
