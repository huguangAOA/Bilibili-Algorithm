/*************************************************************************
	> File Name: 12.P2279.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 三  1/15 22:41:19 2025
 ************************************************************************/

#include <iostream>
using namespace std;

struct Edge {
    int to, nxt;
} e[2005];
int head[1005], cnt = 0;
void add(int a, int b) {
    e[++cnt] = {b, head[a]};
    head[a] = cnt;
    return ;
}

int n;
int dp[1005][5];

void getDP(int fa, int x) {
    int f1 = 1, f2 = 1;
    dp[x][0] = 1;
    dp[x][1] = 0;
    dp[x][2] = 0;
    dp[x][3] = 0;
    dp[x][4] = 0;
    for (int p = head[x]; p; p = e[p].nxt) {
        int to = e[p].to;
        if (to == fa) continue;
        getDP(x, to);
        dp[x][0] += dp[to][4];
        dp[x][1] += dp[to][3];
        if (dp[to][3] == dp[to][0]) f1 = 0;
        dp[x][2] += dp[to][2];
        if (dp[to][2] == dp[to][1]) f2 = 0;
        dp[x][3] += dp[to][2];
        dp[x][4] += dp[to][3];
    }
    dp[x][1] += f1;
    dp[x][2] += f2;
    dp[x][1] = min(dp[x][1], dp[x][0]);
    dp[x][2] = min(dp[x][2], dp[x][1]);
    dp[x][3] = min(dp[x][3], dp[x][2]);
    dp[x][4] = min(dp[x][4], dp[x][3]);
    return ;
}

int main() {
    cin >> n;
    for (int i = 2, a; i <= n; i++) {
        cin >> a;
        add(a, i);
        add(i, a);
    }
    getDP(0, 1);
    cout << dp[1][2] << endl;
    return 0;
}
