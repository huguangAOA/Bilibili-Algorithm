/*************************************************************************
	> File Name: 4.P1131.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 一 11/11 02:13:49 2024
 ************************************************************************/

#include <iostream>
using namespace std;

#define int long long

struct Edge {
    int to, c, nxt;
} e[1000005];
int head[500005], cnt = 0;
void add(int a, int b, int c) {
    e[++cnt] = {b, c, head[a]};
    head[a] = cnt;
    return ;
}

int dp[500005], t[500005];
int n, s;

void getDP(int fa, int ind) {
    t[ind] = 0;
    dp[ind] = 0;
    for (int p = head[ind]; p; p = e[p].nxt) {
        int to = e[p].to, c = e[p].c;
        if (to == fa) continue;
        getDP(ind, to);
        t[ind] = max(t[ind], t[to] + c);
    }
    for (int p = head[ind]; p; p = e[p].nxt) {
        int to = e[p].to, c = e[p].c;
        if (to == fa) continue;
        dp[ind] += t[ind] - t[to] - c + dp[to];
    }
    return ;
}

int32_t main() {
    cin >> n >> s;
    for (int i = 1, a, b, c; i < n; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    getDP(0, s);
    cout << dp[s] << endl;
    return 0;
}
