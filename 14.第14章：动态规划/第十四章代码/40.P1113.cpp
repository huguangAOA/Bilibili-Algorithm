/*************************************************************************
	> File Name: 40.P1113.cpp
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

#define MAX_N 10000
int dp[MAX_N + 5];

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1, t, j; i <= n; i++) {
        cin >> t >> t;
        dp[i] = t;
        while (cin >> j) {
            if (j == 0) break;
            dp[i] = max(dp[i], dp[j] + t);
        }
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
    return 0;
}
