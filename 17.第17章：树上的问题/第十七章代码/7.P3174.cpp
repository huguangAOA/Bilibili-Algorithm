/*************************************************************************
	> File Name: 7.P3174.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 一  1/13 17:21:52 2025
 ************************************************************************/

#include <iostream>
using namespace std;

struct Edge {
    int to, nxt;
} e[600005];
int head[300005], cnt;
void add(int a, int b) {
    e[++cnt] = {b, head[a]};
    head[a] = cnt;
    return ;
}

int n, m, ans = 0;
int dp[300005];

void getDP(int fa, int ind) {
    int cnt = 0, mx1 = 0, mx2 = 0;
    for (int p = head[ind]; p; p = e[p].nxt) {
        int to = e[p].to;
        if (to == fa) continue;
        getDP(ind, to);
        cnt += 1;
        if (dp[to] > mx1) mx2 = mx1, mx1 = dp[to];
        else if (dp[to] > mx2) mx2 = dp[to];
    }
    if (cnt) dp[ind] = mx1 + cnt;
    else dp[ind] = 1;
    ans = max(ans, dp[ind]);
    if (cnt >= 2) ans = max(ans, mx1 + mx2 + cnt - 2 + 1 + (fa != 0));
    return ;
}

int main() {
    cin >> n >> m;
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    getDP(0, 1);
    cout << ans << endl;
    return 0;
}
