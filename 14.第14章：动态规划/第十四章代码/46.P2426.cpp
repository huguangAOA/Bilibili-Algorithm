/*************************************************************************
	> File Name: 46.P2426.cpp
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

#define MAX_N 100
int dp[MAX_N + 5];
int x[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + x[i];
        for (int j = 0; j < i - 1; j++) {
            dp[i] = max(dp[i], dp[j] + abs(x[j + 1] - x[i]) * (i - j));
        }
    }
    cout << dp[n] << endl;
    return 0;
}
