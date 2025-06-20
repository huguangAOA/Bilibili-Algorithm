/*************************************************************************
	> File Name: 29.P2590.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 三  5/14 22:38:13 2025
 ************************************************************************/

#include <iostream>
using namespace std;

const int maxn = 200000;
struct Edge {
    int to, nxt, c;
} e[maxn * 2 + 5];
int head[maxn + 5], cnt = 0;
void add(int a, int b, int c) {
    e[++cnt] = {b, head[a], c};
    head[a] = cnt;
    return ;
}

int n, Q;
int val[maxn + 5];
int fa[maxn + 5], sz[maxn + 5], hson[maxn + 5], dep[maxn + 5];
int id[maxn + 5], idx = 0, top[maxn + 5], w[maxn + 5];

void dfs1(int pre, int x, int c) {
    fa[x] = pre;
    sz[x] = 1;
    val[x] = c;
    dep[x] = dep[pre] + 1;
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
        psum = 0;
        nsum = 0;
        ltag = 0;
        mx = -3000000;
        mi = 3000000;
    }
    int l, r, lson, rson, ltag, psum, nsum, mx, mi;
    void operator+=(const Node &obj) {
        psum += obj.psum;
        nsum += obj.nsum;
        mx = max(mx, obj.mx);
        mi = min(mi, obj.mi);
        return ;
    }
} tree[maxn * 2 + 5];
int root = 1, node_cnt = 1;
#define L(n) (tree[n].l)
#define R(n) (tree[n].r)
#define LS(n) (tree[n].lson)
#define RS(n) (tree[n].rson)
#define PS(n) (tree[n].psum)
#define NS(n) (tree[n].nsum)
#define MX(n) (tree[n].mx)
#define MI(n) (tree[n].mi)
#define T(n) (tree[n].ltag)
#define getNewNode(x) (++x)

void UP(int ind) {
    PS(ind) = PS(LS(ind)) + PS(RS(ind));
    NS(ind) = NS(LS(ind)) + NS(RS(ind));
    MX(ind) = max(MX(LS(ind)), MX(RS(ind)));
    MI(ind) = min(MI(LS(ind)), MI(RS(ind)));
    return ;
}

void DOWN(int ind) {
    if (T(ind) % 2 == 0) {
        T(ind) = 0;
        return ;
    }
    swap(PS(LS(ind)), NS(LS(ind)));
    swap(MX(LS(ind)), MI(LS(ind)));
    MX(LS(ind)) = -MX(LS(ind));
    MI(LS(ind)) = -MI(LS(ind));
    swap(PS(RS(ind)), NS(RS(ind)));
    swap(MX(RS(ind)), MI(RS(ind)));
    MX(RS(ind)) = -MX(RS(ind));
    MI(RS(ind)) = -MI(RS(ind));
    T(LS(ind)) += 1;
    T(RS(ind)) += 1;
    T(ind) = 0;
    return ;
}

void build_tree(int ind, int l, int r) {
    L(ind) = l;
    R(ind) = r;
    if (l == r) {
        if (w[l] >= 0) PS(ind) = w[l];
        else NS(ind) = -w[l];
        MX(ind) = MI(ind) = w[l];
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

void modify_one(int ind, int x, int y) {
    if (L(ind) == R(ind)) {
        if (y >= 0) PS(ind) = y, NS(ind) = 0;
        else NS(ind) = -y, PS(ind) = 0;
        MX(ind) = MI(ind) = y;
        return ;
    }
    DOWN(ind);
    int mid = (L(ind) + R(ind)) / 2;
    if (x <= mid) modify_one(LS(ind), x, y);
    else modify_one(RS(ind), x, y);
    UP(ind);
    return ;
}

void modify(int ind, int x, int y) {
    if (x > y) return ;
    if (x <= L(ind) && R(ind) <= y) {
        swap(PS(ind), NS(ind));
        swap(MX(ind), MI(ind));
        MX(ind) = -MX(ind);
        MI(ind) = -MI(ind);
        T(ind) += 1;
        return ;
    }
    DOWN(ind);
    int mid = (L(ind) + R(ind)) / 2;
    if (x <= mid) modify(LS(ind), x, y);
    if (mid < y) modify(RS(ind), x, y);
    UP(ind);
    return ;
}

Node query(int ind, int x, int y) {
    if (x > y) return Node();
    if (x <= L(ind) && R(ind) <= y) {
        return tree[ind];
    }
    DOWN(ind);
    Node ans;
    int mid = (L(ind) + R(ind)) / 2;
    if (x <= mid) ans += query(LS(ind), x, y);
    if (mid < y) ans += query(RS(ind), x, y);
    return ans;
}

void modify_path(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
         modify(root, id[top[x]], id[x]);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    modify(root, id[y] + 1, id[x]);
    return ;
}

Node query_path(int x, int y) {
    Node ans;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        ans += query(root, id[top[x]], id[x]);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    ans += query(root, id[y] + 1, id[x]);
    return ans;
}

struct Data {
    int a, b, c;
};
Data es[maxn + 5];

int main() {
    cin >> n;
    for (int i = 1, a, b, c; i < n; i++) {
        cin >> a >> b >> c;
        es[i] = {a + 1, b + 1, c};
        add(a + 1, b + 1, c);
        add(b + 1, a + 1, c);
    }
    dfs1(0, 1, 0);
    dfs2(1, 1);
    build_tree(root, 1, n);
    cin >> Q;
    string op;
    for (int i = 1, x, y; i <= Q; i++) {
        cin >> op >> x >> y;
        if (op == "C") {
            int a = es[x].a, b = es[x].b;
            if (dep[a] > dep[b]) modify_one(root, id[a], y);
            else modify_one(root, id[b], y);
        } else if (op == "N") {
            x += 1, y += 1;
            modify_path(x, y);
        } else {
            x += 1, y += 1;
            Node ans = query_path(x, y);
            if (op == "SUM") cout << ans.psum - ans.nsum << endl;
            if (op == "MAX") cout << ans.mx << endl;
            if (op == "MIN") cout << ans.mi << endl;
        }
    }
    return 0;
}
