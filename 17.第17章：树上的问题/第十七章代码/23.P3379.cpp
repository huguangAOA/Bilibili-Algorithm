/*************************************************************************
	> File Name: 23.P3379.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 一  4/21 00:09:37 2025
 ************************************************************************/

#include <iostream>
using namespace std;

const int maxn = 500000;
struct Edge {
    int to, nxt;
} e[maxn * 2 + 5];
int head[maxn + 5], cnt = 0;
void add(int a, int b) {
    e[++cnt] = {b, head[a]};
    head[a] = cnt;
    return ;
}

int n, m, s;
int fa[maxn + 5], sz[maxn + 5], hson[maxn + 5], dep[maxn + 5];
int top[maxn + 5];

void dfs1(int pre, int x) {
    fa[x] = pre;
    dep[x] = dep[pre] + 1;
    sz[x] = 1;
    for (int p = head[x]; p; p = e[p].nxt) {
        int to = e[p].to;
        if (to == pre) continue;
        dfs1(x, to);
        sz[x] += sz[to];
        if (sz[hson[x]] < sz[to]) hson[x] = to;
    }
    return ;
}

void dfs2(int pre, int x) {
    top[x] = pre;
    if (!hson[x]) return ;
    dfs2(pre, hson[x]);
    for (int p = head[x]; p; p = e[p].nxt) {
        int to = e[p].to;
        if (to == fa[x] || to == hson[x]) continue;
        dfs2(to, to);
    }
    return ;
}

int lca(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    return y;
}

int main() {
    cin >> n >> m >> s; 
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs1(0, s);
    dfs2(s, s);
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    return 0;
}
