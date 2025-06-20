/*************************************************************************
	> File Name: 29.P2590.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 三  5/14 22:38:13 2025
 ************************************************************************/

#include <iostream>
using namespace std;

const int maxn = 100000;
struct Edge {
    int to, nxt;
} e[maxn * 2 + 5];
int head[maxn + 5], cnt = 0;
void add(int a, int b) {
    e[++cnt] = {b, head[a]};
    head[a] = cnt;
    return ;
}

int fa[maxn + 5], sz[maxn + 5], hson[maxn + 5], dep[maxn + 5];
int id[maxn + 5], idx = 0, top[maxn + 5];

void dfs1(int pre, int x) {
    fa[x] = pre;
    sz[x] = 1;
    dep[x] = dep[pre] + 1;
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
    id[x] = ++idx;
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

struct Node {
    int l, r, lson, rson, ltag, sum;
} tree[maxn * 2 + 5];
int root = 1, node_cnt = 1;
#define L(n) (tree[n].l)
#define R(n) (tree[n].r)
#define LS(n) (tree[n].lson)
#define RS(n) (tree[n].rson)
#define S(n) (tree[n].sum)
#define T(n) (tree[n].ltag)
#define C(n) (tree[n].r - tree[n].l + 1)
#define getNewNode(x) (++x)

void UP(int ind) {
    S(ind) = S(LS(ind)) + S(RS(ind));
    return ;
}

void DOWN(int ind) {
    if (T(ind) == 0) return ;
    T(LS(ind)) += T(ind);
    T(RS(ind)) += T(ind);
    S(LS(ind)) += T(ind) * C(LS(ind));
    S(RS(ind)) += T(ind) * C(RS(ind));
    T(ind) = 0;
    return ;
}

void build_tree(int ind, int l, int r) {
    L(ind) = l;
    R(ind) = r;
    if (l == r) return ;
    LS(ind) = getNewNode(node_cnt);
    RS(ind) = getNewNode(node_cnt);
    int mid = (l + r) / 2;
    build_tree(LS(ind), l, mid);
    build_tree(RS(ind), mid + 1, r);
    return ;
}

void modify(int ind, int x, int y, int k) {
    if (x > y) return ;
    if (x <= L(ind) && R(ind) <= y) {
        T(ind) += k;
        S(ind) += k * C(ind);
        return ;
    }
    DOWN(ind);
    int mid = (L(ind) + R(ind)) / 2;
    if (x <= mid) modify(LS(ind), x, y, k);
    if (mid < y) modify(RS(ind), x, y, k);
    UP(ind);
    return ;
}

int query(int ind, int x) {
    if (L(ind) == R(ind)) {
        return S(ind);
    }
    DOWN(ind);
    int mid = (L(ind) + R(ind)) / 2;
    if (x <= mid) return query(LS(ind), x);
    return query(RS(ind), x);
}

int n, m;

void update_path(int x, int y, int k) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        modify(root, id[top[x]], id[x], k);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    modify(root, id[y] + 1, id[x], k);
    return ;
}

int main() {
    cin >> n >> m;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs1(0, 1);
    dfs2(1, 1);
    build_tree(root, 1, n);
    string op;
    for (int i = 1, x, y; i <= m; i++) {
        cin >> op >> x >> y;
        if (op == "P") {
            update_path(x, y, 1);
        } else {
            if (dep[x] < dep[y]) swap(x, y);
            cout << query(root, id[x]) << endl;
        }
    }
    return 0;
}
