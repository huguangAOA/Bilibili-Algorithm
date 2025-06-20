/*************************************************************************
	> File Name: 28.P4281.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 三  5/14 22:05:45 2025
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

int n, m;
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

int DIS(int x, int y) {
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, a, b; i < n; i++) {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs1(0, 1);
    dfs2(1, 1);
    for (int i = 1, x, y, z; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        int p1 = lca(x, y);
        int p2 = lca(x, z);
        int p3 = lca(y, z);
        int p = p1;
        if (dep[p2] > dep[p]) p = p2;
        if (dep[p3] > dep[p]) p = p3;
        cout << p << " " << DIS(x, p) + DIS(y, p) + DIS(z, p) << endl;
    }
    return 0;
}
