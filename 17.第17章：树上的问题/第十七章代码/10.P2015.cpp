/*************************************************************************
	> File Name: 10.P2015.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 三  1/15 18:21:45 2025
 ************************************************************************/

#include <iostream>
using namespace std;

struct Edge {
    int to, nxt, c;
} e[205];
int head[105], cnt = 0;
void add(int a, int b, int c) {
    e[++cnt] = {b, head[a], c};
    head[a] = cnt;
    return ;
}

int n, m;
int dp[105][105], edge_cnt[105];

void getDP(int fa, int x) {
    dp[x][0] = 0;
    edge_cnt[x] = 0;
    for (int p = head[x]; p; p = e[p].nxt) {
        int to = e[p].to, c = e[p].c;
        if (to == fa) continue;
        getDP(x, to);
        edge_cnt[x] += edge_cnt[to] + 1;
        for (int j = min(edge_cnt[x], m); j >= 1; j--) {
            for (int k = 0; k <= edge_cnt[to]; k++) {
                if (k + 1 > j) break;
                dp[x][j] = max(dp[x][j], dp[x][j - k - 1] + dp[to][k] + c);
            }
        }
    }
    return ;
}

int main() {
    cin >> n >> m;
    for (int i = 1, a, b, c; i < n; i++) {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    getDP(0, 1);
    cout << dp[1][m] << endl;
    return 0;
}
