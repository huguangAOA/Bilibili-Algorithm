/*************************************************************************
	> File Name: 26.P2146.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 二  4/22 23:43:38 2025
 ************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

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
    if (T(ind) == -1) return ;
    S(LC(ind)) = C(LC(ind)) * T(ind);
    S(RC(ind)) = C(RC(ind)) * T(ind);
    T(LC(ind)) = T(ind);
    T(RC(ind)) = T(ind);
    T(ind) = -1;
    return ;
}

void build_tree(int ind, int l, int r) {
    T(ind) = -1;
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
        T(ind) = val;
        S(ind) = C(ind) * val;
        return ;
    }
    DOWN(ind);
    int mid = (L(ind) + R(ind)) / 2;
    if (x <= mid) modify(LC(ind), x, y, val);
    if (y > mid) modify(RC(ind), x, y, val);
    UP(ind);
    return ;
}

struct Edge {
    int to, nxt;
} e[maxn * 2 + 5];
int head[maxn +  5], cnt = 0;
void add(int a, int b) {
    e[++cnt] = {b, head[a]};
    head[a] = cnt;
    return ;
}

int n, Q;
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

void update_tree(int x, int k) {
    modify(root, id[x], id[x] + sz[x] - 1, k);
    return ;
}

int main() {
    cin >> n;
    for (int i = 1, x; i < n; i++) {
        cin >> x;
        add(i + 1, x + 1);
        add(x + 1, i + 1);
    }
    build_tree(root, 1, n);
    dfs1(0, 1);
    dfs2(1, 1);
    cin >> Q;
    string op;
    for (int i = 1, x; i <= Q; i++) {
        cin >> op >> x;
        int cnt1 = S(root);
        if (op == "install") {
            update_path(1, x + 1, 1);
        } else {
            update_tree(x + 1, 0);
        }
        int cnt2 = S(root);
        cout << abs(cnt1 - cnt2) << endl;
    }
    return 0;
}
