/*************************************************************************
	> File Name: 13.P2392.cpp
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
#define MAX_NUM 9999999
int s[10] = {0};
int t[10][MAX_N + 5]; // t[i][j] TODO(1)
int ans = 0;

void dfs(int k, int x, int l, int r) {
    if (k == s[x]) {
        ans = min(ans, max(l, r));
        return ;
    }
    // TODO(2)
    l += t[x][k];
    dfs(k + 1, x, l, r);
    l -= t[x][k];
    // TODO(3)
    r += t[x][k];
    dfs(k + 1, x, l, r);
    r -= t[x][k];
    return ;
}

int main() {
    for (int i = 0; i < 4; i++) cin >> s[i]; // TODO(4)
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < s[i]; j++) {
            cin >> t[i][j];
        }
    }
    int total = 0;
    for (int i = 0; i < 4; i++) {
        ans = MAX_NUM;
        dfs(0, i, 0, 0);
        total += ans;
    }
    cout << total << endl;
    return 0;
}
