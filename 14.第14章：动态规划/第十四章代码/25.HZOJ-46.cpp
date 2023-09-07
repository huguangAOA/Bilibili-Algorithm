/*************************************************************************
	> File Name: 25.HZOJ-46.cpp
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
#include <cstring>
using namespace std;

#define MAX_N 1000
char s[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5] = {0};

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int l = 1; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1] == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = l;
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + 1);
                }
            }
        }
    }
    printf("%d\n", dp[1][n]);
    return 0;
}
