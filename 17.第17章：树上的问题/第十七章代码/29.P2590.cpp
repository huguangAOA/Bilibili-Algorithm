/*************************************************************************
	> File Name: 29.P2590.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 三  5/14 22:38:13 2025
 ************************************************************************/

#include <iostream>
using namespace std;

const int maxn = 30000;
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
int val[maxn + 5];
int fa[maxn + 5], sz[maxn + 5], hson[maxn + 5], dep[maxn + 5];
int id[maxn + 5], idx = 0, top[maxn + 5], w[maxn + 5];

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

struct Node {
    Node() {
        sum = 0;
        mx = -3000000;
    }
    int l, r, lson, rson, sum, mx;
    void operator+=(const Node &obj) {
        sum += obj.sum;
        mx = max(mx, obj.mx);
        return ;
    }
} tree[maxn * 2 + 5];
int root = 1, node_cnt = 1;
#define L(n) (tree[n].l)
#define R(n) (tree[n].r)
#define LS(n) (tree[n].lson)
#define RS(n) (tree[n].rson)
#define S(n) (tree[n].sum)
#define M(n) (tree[n].mx)
#define getNewNode(x) (++x)

void UP(int ind) {
    S(ind) = S(LS(ind)) + S(RS(ind));
    M(ind) = max(M(LS(ind)), M(RS(ind)));
    return ;
}

void build_tree(int ind, int l, int r) {
    L(ind) = l;
    R(ind) = r;
    if (l == r) {
        S(ind) = M(ind) = w[l];
        return ;
    }
    LS(ind) = getNewNode(node_cnt);
    RS(ind) = getNewNode(node_cnt);
    int mid = (l + r) / 2;
    build_tree(LS(ind), l, mid);
    build_tree(RS(ind), mid + 1, r);
    UP(ind);
    return ;
}

void modify(int ind, int x, int y) {
    if (L(ind) == R(ind)) {
        S(ind) = M(ind) = y;
        return ;
    }
    int mid = (L(ind) + R(ind)) / 2;
    if (x <= mid) modify(LS(ind), x, y);
    else modify(RS(ind), x, y);
    UP(ind);
    return ;
}

Node query(int ind, int x, int y) {
    if (x <= L(ind) && R(ind) <= y) {
        return tree[ind];
    }
    Node ans;
    int mid = (L(ind) + R(ind)) / 2;
    if (x <= mid) ans += query(LS(ind), x, y);
    if (mid < y) ans += query(RS(ind), x, y);
    return ans;
}

Node query_path(int x, int y) {
    Node ans;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        ans += query(root, id[top[x]], id[x]);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    ans += query(root, id[y], id[x]);
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    for (int i = 1; i <= n; i++) cin >> val[i];
    dfs1(0, 1);
    dfs2(1, 1);
    build_tree(root, 1, n);
    cin >> Q;
    string op;
    for (int i = 1, x, y; i <= Q; i++) {
        cin >> op >> x >> y;
        if (op == "CHANGE") {
            modify(root, id[x], y);
        }
        if (op == "QMAX") {
            Node ans = query_path(x, y);
            cout << ans.mx << endl;
        }
        if (op == "QSUM") {
            Node ans = query_path(x, y);
            cout << ans.sum << endl;
        }
    }
    return 0;
}
