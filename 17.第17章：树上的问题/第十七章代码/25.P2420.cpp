/*************************************************************************
	> File Name: 25.P2420.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 一  4/21 00:57:53 2025
 ************************************************************************/

#include <iostream>
using namespace std;

const int maxn = 100000;
struct Edge {
    int to, nxt, c;
} e[maxn * 2 + 5];
int head[maxn + 5], cnt = 0;
void add(int a, int b, int c) {
    e[++cnt] = {b, head[a], c};
    head[a] = cnt;
    return ;
}
int n, m;
int fa[maxn + 5], sz[maxn + 5], hson[maxn + 5], dep[maxn + 5], val[maxn + 5];
int id[maxn + 5], idx = 0, top[maxn + 5], w[maxn + 5];

void dfs1(int pre, int x, int c) {
    val[x] = c;
    fa[x] = pre;
    dep[x] = dep[pre] + 1;
    sz[x] = 1;
    for (int p = head[x]; p; p = e[p].nxt) {
        int to = e[p].to, c = e[p].c;
        if (to == pre) continue;
        dfs1(x, to, c);
        sz[x] += sz[to];
        if (sz[hson[x]] < sz[to]) hson[x] = to;
    }
    return ;
}

void dfs2(int pre, int x) {
    top[x] = pre;
    id[x] = ++idx;
    w[idx] = val[x];
    if (!hson[x]) return ;
    dfs2(pre, hson[x]);
    for (int p = head[x]; p; p = e[p].nxt) {
        int to = e[p].to;
        if (to == fa[x] || to == hson[x]) continue;
        dfs2(to, to);
    }
    return ;
}

int query(int x, int y) {
    int ans = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        ans ^= w[id[x]] ^ w[id[top[x]] - 1];
        x = fa[top[x]];
    }
    return ans ^ w[id[x]] ^ w[id[y]];
}

int main() {
    cin >> n;
    for (int i = 1, a, b, c; i < n; i++) {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dfs1(0, 1, 0);
    dfs2(1, 1);
    for (int i = 2; i <= n; i++) w[i] ^= w[i - 1];
    cin >> m;
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        cout << query(a, b) << endl;
    }
    return 0;
}
