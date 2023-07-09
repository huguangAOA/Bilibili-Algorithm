/*************************************************************************
	> File Name: 7.P1433.cpp
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
#include <cmath>
#include <vector>
using namespace std;

#define MAX_N 15
int n;
double ans = 1e9;
double x[MAX_N + 5], y[MAX_N + 5];
double dis[MAX_N + 5][MAX_N + 5];
double dp[70000][20] = {0};
int ind[70000];

#define S(a) ((a) * (a))
double __dis(int i, int j) {
    return sqrt(S(x[i] - x[j]) + S(y[i] - y[j]));
}

void dfs(int t, int now, double s) {
    if (t == 0) {
        if (s < ans) ans = s;
        return ;
    }
    for (int k = t; k; k -= (k & -k)) {
        int to = ind[k & -k], next_t = t - (1 << to);
        double l = s + dis[now][to];
        if (dp[next_t][to] != 0 && dp[next_t][to] <= l) {
            continue;
        }
        dp[next_t][to] = l;
        if (ans <= l) continue;
        dfs(next_t, to, l);
    }
    return ;
}

int main() {
    scanf("%d", &n);
    x[0] = y[0] = 0;
    double a, b;
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf", &a, &b);
        x[i] = a, y[i] = b;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dis[i][j] = dis[j][i] = __dis(i, j);
        }
    }
    for (int k = 1, i = 0; i <= MAX_N; i++, k *= 2) ind[k] = i;
    dfs((1 << (n + 1)) - 2, 0, 0);
    printf("%.2lf\n", ans);
    return 0;
}
