/*************************************************************************
	> File Name: 31.P2245.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 六  6/21 01:01:32 2025
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100000, maxm = 300000, maxk = 20;

struct Data {
    int a, b, c;
};
Data es[maxm + 5];
bool cmp(Data a, Data b) {
    return a.c < b.c;
}

int n, m, Q;

struct UnionSet {
    int fa[maxn + 5];
    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
        return ;
    }
    int get(int x) {
        if (x == fa[x]) return x;
        return (fa[x] = get(fa[x]));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
        return ;
    }
} u;

struct Edge {
    int to, nxt, c;
} e[maxn * 2 + 5];
int head[maxn + 5], cnt = 0;
void add(int a, int b, int c) {
    e[++cnt] = {b, head[a], c};
    head[a] = cnt;
    return ;
}

int fa[maxn + 5], sz[maxn + 5], hson[maxn + 5], dep[maxn + 5], val[maxn + 5];
int id[maxn + 5], idx = 0, top[maxn + 5], w[maxn + 5];
void dfs1(int pre, int x, int c) {
    fa[x] = pre;
    sz[x] = 1;
    dep[x] = dep[pre] + 1;
    val[x] = c;
    for (int p = head[x]; p; p = e[p].nxt) {
        int to = e[p].to, c = e[p].c;
        if (to == pre) continue;
        dfs1(x, to, c);
        sz[x] += sz[to];
        if (sz[to] > sz[hson[x]]) hson[x] = to;
    }
    return ;
}

void dfs2(int pre, int x) {
    id[x] = ++idx;
    w[idx] = val[x];
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

int st[maxn + 5][maxk + 5], lg[maxn + 5];
void init_st(int n) {
    lg[1] = 0;
    for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= n; i++) st[i][0] = w[i];
    for (int k = 1; k <= lg[n]; k++) {
        for (int i = 1, I = n - (1 << k) + 1; i <= I; i++) {
            st[i][k] = max(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
        }
    }
    return ;
}

int query(int l, int r) {
    if (l > r) return 0;
    int cnt = r - l + 1;
    int k = lg[cnt];
    int p1 = l, p2 = r - (1 << k) + 1;
    return max(st[p1][k], st[p2][k]);
}

int query_path(int x, int y) {
    int ans = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        ans = max(ans, query(id[top[x]], id[x]));
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    ans = max(ans, query(id[y] + 1, id[x]));
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        es[i] = {a, b, c};
    }
    sort(es + 1, es + 1 + m, cmp);
    u.init(n);
    for (int i = 1; i <= m; i++) {
        int a = es[i].a, b = es[i].b, c = es[i].c;
        if (u.get(a) == u.get(b)) continue;
        u.merge(a, b);
        add(a, b, c);
        add(b, a, c);
    }
    for (int i = 1; i <= n; i++) {
        if (i != u.get(i)) continue;
        dfs1(0, i, 0);
        dfs2(i, i);
    }
    init_st(n);
    cin >> Q;
    for (int i = 1, a, b; i <= Q; i++) {
        cin >> a >> b;
        if (u.get(a) != u.get(b)) cout << "impossible" << endl;
        else cout << query_path(a, b) << endl;
    }
    return 0;
}
