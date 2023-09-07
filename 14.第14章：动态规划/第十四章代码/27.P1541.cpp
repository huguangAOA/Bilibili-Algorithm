/*************************************************************************
	> File Name: 27.P1541.cpp
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

#define MAX_N 40
int dp[MAX_N + 5][MAX_N + 5][MAX_N + 5];
int val[400];
int cnt[4];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", val + i);
    }
    for (int i = 0, a; i < m; i++) {
        scanf("%d", &a);
        cnt[a - 1] += 1;
    }
    for (int a = 0; a <= cnt[0]; a++) {
        for (int b = 0; b <= cnt[1]; b++) {
            for (int c = 0; c <= cnt[2]; c++) {
                for (int d = 0; d <= cnt[3]; d++) {
                    int s = a + 2 * b + 3 * c + 4 * d;
                    int ans = dp[b][c][d];
                    if (b) ans = max(ans, dp[b - 1][c][d]);
                    if (c) ans = max(ans, dp[b][c - 1][d]);
                    if (d) ans = max(ans, dp[b][c][d - 1]);
                    dp[b][c][d] = ans + val[s];
                }
            }
        }
    }
    printf("%d\n", dp[cnt[1]][cnt[2]][cnt[3]]);
    return 0;
}
