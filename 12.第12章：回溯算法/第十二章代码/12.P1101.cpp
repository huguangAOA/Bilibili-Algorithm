/*************************************************************************
	> File Name: 12.P1101.cpp
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
int n;
int dir[8][2] = {
    {1, 1}, {-1, -1}, {1, 0}, {0, 1},
    {1, -1}, {-1, 1}, {-1, 0}, {0, -1}
};
char g[MAX_N + 5][MAX_N + 5] = {0};
int vis[MAX_N + 5][MAX_N + 5] = {0};
int ans[MAX_N + 5][MAX_N + 5] = {0};
char match[8] = "yizhong";

void get_ans(int x, int y) {
    for (int k = 0; k < 8; k++) {
        int flag = 1;
        for (int i = 0; match[i]; i++) {
            int dx = x + i * dir[k][0];
            int dy = y + i * dir[k][1];
            if (match[i] == g[dx][dy]) continue;
            flag = 0;
            break;
        }
        if (flag == 1) {
            for (int i = 0; match[i]; i++) {
                int dx = x + i * dir[k][0];
                int dy = y + i * dir[k][1];
                ans[dx][dy] = 1;
            }
        }
    }
    return ;
}

void dfs(int i, int j) {
    if (g[i][j] == '\0') return ;
    if (vis[i][j]) return ;
    if (g[i][j] == 'y') {
        get_ans(i, j);
    }
    vis[i][j] = 1;
    dfs(i, j + 1);
    dfs(i + 1, j);
    return ;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> (g[i] + 1);
    }
    dfs(1, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i][j]) cout << g[i][j];
            else cout << "*";
        }
        cout << endl;
    }
    return 0;
}
