/*************************************************************************
	> File Name: 27.P3833.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 三  4/23 00:17:41 2025
 ************************************************************************/

#include <iostream>
using namespace std;

#define int long long

const int maxn = 100000;
struct Node {
    int l, r, sum, c, ltag, lchild, rchild;
} tree[maxn * 2 + 5];
int root = 1, node_cnt = 1;
#define L(ind) (tree[ind].l)
#define R(ind) (tree[ind].r)
#define LC(ind) (tree[ind].lchild)
#define RC(ind) (tree[ind].rchild)
#define S(ind) (tree[ind].sum)
#define T(ind) (tree[ind].ltag)
#define C(ind) (tree[ind].c)
#define getNewNode(x) (++x)

void UP(int ind) {
    S(ind) = S(LC(ind)) + S(RC(ind));
    return ; 
}

void DOWN(int ind) {
    if (T(ind) == 0) return ;
    S(LC(ind)) += C(LC(ind)) * T(ind);
    S(RC(ind)) += C(RC(ind)) * T(ind);
    T(LC(ind)) += T(ind);
    T(RC(ind)) += T(ind);
    T(ind) = 0;
    return ;
}

void build_tree(int ind, int l, int r) {
    T(ind) = 0;
    C(ind) = (r - l + 1);
    L(ind) = l;
    R(ind) = r;
    if (l == r) {
        S(ind) = 0;
        return ;
    }
    LC(ind) = getNewNode(node_cnt);
    RC(ind) = getNewNode(node_cnt);
    int mid = (l + r) / 2;
    build_tree(LC(ind), l, mid);
    build_tree(RC(ind), mid + 1, r);
    UP(ind);
    return ;
}

void modify(int ind, int x, int y, int val) {
    if (x <= L(ind) && R(ind) <= y) {
        T(ind) += val;
        S(ind) += C(ind) * val;
        return ;
    }
    DOWN(ind);
    int mid = (L(ind) + R(ind)) / 2;
    if (x <= mid) modify(LC(ind), x, y, val);
    if (y > mid) modify(RC(ind), x, y, val);
    UP(ind);
    return ;
}

int query(int ind, int x, int y) {
    if (x <= L(ind) && R(ind) <= y) {
        return S(ind);
    }
    DOWN(ind);
    int ans = 0, mid = (L(ind) + R(ind)) / 2;
    if (x <= mid) ans += query(LC(ind), x, y);
    if (y > mid) ans += query(RC(ind), x, y);
    UP(ind);
    return ans;
}

struct Edge {
    int to, nxt;
} e[maxn * 2 + 5];
int head[maxn + 5], cnt = 0;
void add(int a, int b) {
    e[++cnt] = {b, head[a]};
    head[a] = cnt;
    return ;
}

int n, Q;
int fa[maxn + 5], sz[maxn + 5], dep[maxn + 5], hson[maxn + 5];
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

void update_path(int x, int y, int k) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        modify(root, id[top[x]], id[x], k);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    modify(root, id[y], id[x], k);
    return ;
}

int query_tree(int x) {
    return query(root, id[x], id[x] + sz[x] - 1);
}

int32_t main() {
    cin >> n;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        add(a + 1, b + 1);
        add(b + 1, a + 1);
    }
    build_tree(root, 1, n);
    dfs1(0, 1);
    dfs2(1, 1);
    cin >> Q;
    string op;
    for (int i = 1, a, b, c; i <= Q; i++) {
        cin >> op >> a;
        if (op == "A") {
            cin >> b >> c;
            update_path(a + 1, b + 1, c);
        } else {
            cout << query_tree(a + 1) << endl;
        }
    }
    return 0;
}
