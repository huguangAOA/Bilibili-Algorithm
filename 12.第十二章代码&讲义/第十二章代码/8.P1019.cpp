/*************************************************************************
	> File Name: 8.P1019.cpp
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
string s[MAX_N + 5], start;
int n, ans = 0;
int vis[MAX_N + 5] = {0};
int d[MAX_N + 5][MAX_N + 5] = {0};

int f(string &s1, string &s2) {
    for (int i = s1.size() - 1; i >= 1; i--) {
        int flag = 1;
        for (int j = 0; j < s1.size() - i; j++) {
            if (s1[i + j] == s2[j]) continue;
            flag = 0;
            break;
        }
        if (flag == 1) return s1.size() - i;
    }
    return 0;
}

void dfs(int x, int L) {
    vis[x] += 1;
    if (L > ans) ans = L;
    for (int y = 0; y < n; y++) {
        if (d[x][y] == 0) continue;
        if (vis[y] == 2) continue;
        dfs(y, L + s[y].size() - d[x][y]);
    }
    vis[x] -= 1;
    return ;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    cin >> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = f(s[i], s[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i][0] != start[0]) continue;
        dfs(i, s[i].size());
    }
    cout << ans << endl;
    return 0;
}
