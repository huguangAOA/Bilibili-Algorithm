/*************************************************************************
	> File Name: 6.B4016.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 一  1/13 16:44:37 2025
 ************************************************************************/

#include <iostream>
using namespace std;

struct Edge {
    int to, nxt;
} e[200005];
int head[100005], cnt;
void add(int a, int b) {
    e[++cnt] = {b, head[a]};
    head[a] = cnt;
    return ;
}

int n, ans = 0;
int dp[100005];

void getDP(int fa, int ind) {
    dp[ind] = 0;
    int x1 = -1, x2 = -1;
    for (int p = head[ind]; p; p = e[p].nxt) {
        int to = e[p].to;
        if (to == fa) continue;
        getDP(ind, to);
        dp[ind] = max(dp[ind], dp[to] + 1);
        if (dp[to] > x1) x2 = x1, x1 = dp[to];
        else if (dp[to] > x2) x2 = dp[to];
    }
    ans = max(ans, x1 + x2 + 2);
    return ;
}

int main() {
    cin >> n;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    getDP(0, 1);
    cout << ans << endl;
    return 0;
}
