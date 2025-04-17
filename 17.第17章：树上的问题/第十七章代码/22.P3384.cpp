/*************************************************************************
	> File Name: 22.P3384.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 五  4/18 00:06:10 2025
 ************************************************************************/

#include <iostream>
using namespace std;

const int maxn = 100000;
int MOD = (1 << 30) - 1 + (1 << 30);
struct Node {
    int l, r, lchild, rchild, ltag, sum, cnt;
} tree[maxn * 2 + 5];
int sgt_root = 1, node_cnt = 1;
#define L(ind) (tree[ind].l)
#define R(ind) (tree[ind].r)
#define LC(ind) (tree[ind].lchild)
#define RC(ind) (tree[ind].rchild)
#define T(ind) (tree[ind].ltag)
#define S(ind) (tree[ind].sum)
#define C(ind) (tree[ind].cnt)
#define getNewNode(x) (++x)

void UP(int ind) {
    S(ind) = (S(LC(ind)) + S(RC(ind))) % MOD;
    return ;
}
void DOWN(int ind) {
    if (T(ind)) {
        T(LC(ind)) = (T(LC(ind)) + T(ind)) % MOD;
        T(RC(ind)) = (T(RC(ind)) + T(ind)) % MOD;
        S(LC(ind)) = (S(LC(ind)) + C(LC(ind)) * T(ind)) % MOD;
        S(RC(ind)) = (S(RC(ind)) + C(RC(ind)) * T(ind)) % MOD;
        T(ind) = 0;
    }
    return ;
}

void build_tree(int ind, int l, int r, int *arr) {
    L(ind) = l;
    R(ind) = r;
    C(ind) = (r - l + 1);
    if (l == r) {
        T(ind) = 0;
        S(ind) = arr[l] % MOD;
        return ;
    }
    LC(ind) = getNewNode(node_cnt);
    RC(ind) = getNewNode(node_cnt);
    int mid = (l + r) / 2;
    build_tree(LC(ind), l, mid, arr);
    build_tree(RC(ind), mid + 1, r, arr);
    UP(ind);
    return ;
}

void modify(int ind, int x, int y, int z) {
    if (x <= L(ind) && R(ind) <= y) {
        T(ind) = (T(ind) + z) % MOD;
        S(ind) = (S(ind) + C(ind) * z) % MOD;
        return ;
    }
    int mid = (L(ind) + R(ind)) / 2;
    DOWN(ind);
    if (x <= mid) modify(LC(ind), x, y, z);
    if (y > mid) modify(RC(ind), x, y, z);
    UP(ind);
    return ;
}

int query(int ind, int x, int y) {
    if (x <= L(ind) && R(ind) <= y) {
        return S(ind);
    }
    int mid = (L(ind) + R(ind)) / 2, ans = 0;
    DOWN(ind);
    if (x <= mid) ans = (ans + query(LC(ind), x, y)) % MOD;
    if (y > mid) ans = (ans + query(RC(ind), x, y)) % MOD;
    return ans;
}

struct Edge {
    int to, nxt;
} e[maxn * 2+ 5];
int head[maxn + 5], cnt = 0;
void add(int a, int b) {
    e[++cnt] = {b, head[a]};
    head[a] = cnt;
    return ;
}

int n, m, r;
int arr[maxn + 5];
int fa[maxn + 5], sz[maxn + 5], hson[maxn + 5], dep[maxn + 5];
int id[maxn + 5], idx = 0, top[maxn + 5], w[maxn + 5];

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
    id[x] = ++idx;
    w[idx] = arr[x];
    if (!hson[x]) return ;
    dfs2(pre, hson[x]);
    for (int p = head[x]; p; p = e[p].nxt) {
        int to = e[p].to;
        if (to == fa[x] || to == hson[x]) continue;
        dfs2(to, to);
    }
    return ;
}

void update_add_tree(int x, int z) {
    modify(sgt_root, id[x], id[x] + sz[x] - 1, z);
    return ;
}

int update_query_tree(int x) {
    return query(sgt_root, id[x], id[x] + sz[x] - 1);
}

void update_add_path(int x, int y, int z) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        modify(sgt_root, id[top[x]], id[x], z);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    modify(sgt_root, id[y], id[x], z);
    return ;
}

int update_query_path(int x, int y) {
    int ans = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        ans = (ans + query(sgt_root, id[top[x]], id[x])) % MOD;
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    ans = (ans + query(sgt_root, id[y], id[x])) % MOD;
    return ans;
}

int main() {
    cin >> n >> m >> r >> MOD;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs1(0, r);
    dfs2(r, r);
    build_tree(sgt_root, 1, n, w);
    for (int i = 1, op, x, y, z; i <= m; i++) {
        cin >> op >> x;
        switch (op) {
            case 1: {
                cin >> y >> z;
                update_add_path(x, y, z);
            } break;
            case 2: {
                cin >> y;
                cout << update_query_path(x, y) << endl;
            } break;
            case 3: {
                cin >> z;
                update_add_tree(x, z);
            } break;
            case 4: {
                cout << update_query_tree(x) << endl;
            } break;
        }
    }
    return 0;
}
