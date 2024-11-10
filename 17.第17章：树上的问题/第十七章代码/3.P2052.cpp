/*************************************************************************
	> File Name: 3.P2052.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 一 11/11 01:43:43 2024
 ************************************************************************/

#include <iostream>
using namespace std;

#define int long long

struct Edge {
    int to, c, nxt;
} e[2000005];
int head[1000005], cnt = 0;
void add(int a, int b, int c) {
    e[++cnt] = {b, c, head[a]};
    head[a] = cnt;
    return ;
} 

int f[1000005];
int n, ans = 0;

void dfs(int fa, int ind) {
    f[ind] = 1;
    for (int p = head[ind]; p; p = e[p].nxt) {
        int to = e[p].to, c = e[p].c;
        if (to == fa) continue;
        dfs(ind, to);
        f[ind] += f[to];
        int cnt1 = f[to];
        int cnt2 = n - cnt1;
        ans += c * abs(cnt1 - cnt2);
    }
    return ;
}

int32_t main() {
    cin >> n;
    for (int i = 1, a, b, c; i < n; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    dfs(0, 1);
    cout << ans << endl;
    return 0;
}
