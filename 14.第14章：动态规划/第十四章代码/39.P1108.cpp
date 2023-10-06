/*************************************************************************
	> File Name: 39.P1108.cpp
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

#define MAX_N 5000
#define INF 0x7fffffff
int dp[MAX_N + 5], val[MAX_N + 5];
int f[MAX_N + 5];

int main() {
    int n, max_len = 0, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", val + i);
    }
    val[0] = INF;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (val[j] <= val[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        for (int j = 0; j < i; j++) {
            if (val[j] < val[i]) continue;
            if (val[j] > val[i] && dp[j] + 1 == dp[i]) {
                f[i] += f[j];
            } else if (val[j] == val[i] && dp[j] == dp[i]) {
                f[j] = 0;
            }
        }
        max_len = max(max_len, dp[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (dp[i] == max_len) ans += f[i];
    }
    cout << max_len << " " << ans << endl;
    return 0;
}
