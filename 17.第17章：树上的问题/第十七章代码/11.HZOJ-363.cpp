/*************************************************************************
	> File Name: 11.HZOJ-363.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 三  1/15 19:04:21 2025
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

struct Edge {
    int to, nxt;
} e[3005];
int head[1505], cnt = 0;
void add(int a, int b) {
    e[++cnt] = {b, head[a]};
    head[a] = cnt;
    return ;
}

int n;
int dp[1505][3];

void init_data() {
    cnt = 0;
    memset(head, 0, sizeof(head));
    memset(dp, 0, sizeof(dp));
    return ;
}

void getDP(int fa, int x) {
    int f1 = 1;
    dp[x][0] = 1;
    dp[x][1] = 0;
    dp[x][2] = 0;
    for (int p = head[x]; p; p = e[p].nxt) {
        int to = e[p].to;
        if (to == fa) continue;
        getDP(x, to);
        dp[x][0] += dp[to][2];
        dp[x][1] += dp[to][1];
        if (dp[to][1] == dp[to][0]) f1 = 0;
        dp[x][2] += dp[to][1];
    }
    dp[x][1] += f1;
    dp[x][1] = min(dp[x][1], dp[x][0]);
    dp[x][2] = min(dp[x][2], dp[x][1]);
    return ;
}

bool solve() {
    init_data();
    if (scanf("%d", &n) == EOF) return false;
    for (int i = 1, a, b, c; i <= n; i++) {
        scanf("%d:(%d)", &a, &c);
        for (int j = 1; j <= c; j++) {
            scanf("%d", &b);
            add(a, b);
            add(b, a);
        }
    }
    getDP(-1, 0);
    printf("%d\n", dp[0][1]);
    return true;
}

int main() {
    while (solve()) ;
    return 0;
}
