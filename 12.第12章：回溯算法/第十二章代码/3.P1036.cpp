/*************************************************************************
	> File Name: 3.P1036.cpp
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

#define MAX_N 20
int val[MAX_N + 5];
long long ans = 0;

int is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void dfs(int k, int ind, int n, int m, int sum) {
    if (k == m) {
        if (is_prime(sum)) ans += 1;
        return ;
    }
    for (int i = ind; i <= n; i++) {
        dfs(k + 1, i + 1, n, m, sum + val[i]);
    }
    return ;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", val + i);
    }
    dfs(0, 1, n, k, 0);
    printf("%lld\n", ans);
    return 0;
}
