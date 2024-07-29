/*************************************************************************
	> File Name: 14.P3919.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 一  7/29 08:29:44 2024
 ************************************************************************/

#include <iostream>
using namespace std;

struct Node {
    int c, l, r;
} tree[30000005];
int node_cnt = 0, root[1000005];
int n, m;
int a[1000005];

int clone(int ind) {
    ++node_cnt;
    tree[node_cnt] = tree[ind];
    return node_cnt;
}

int build_tree(int l, int r) {
    int ind = ++node_cnt;
    if (l == r) {
        tree[ind].c = a[l];
        return ind;
    }
    int mid = (l + r) / 2;
    tree[ind].l = build_tree(l, mid);
    tree[ind].r = build_tree(mid + 1, r);
    return ind;
}

int modify(int ind, int l, int r, int x, int y) {
    ind = clone(ind);
    if (l == r) {
        tree[ind].c = y;
        return ind;
    }
    int mid = (l + r) / 2;
    if (x <= mid) tree[ind].l = modify(tree[ind].l, l, mid, x, y);
    else tree[ind].r = modify(tree[ind].r, mid + 1, r, x, y);
    return ind;
}

int query(int ind, int l, int r, int x) {
    if (l == r) {
        return tree[ind].c;
    }
    int mid = (l + r) / 2;
    if (x <= mid) return query(tree[ind].l, l, mid, x);
    return query(tree[ind].r, mid + 1, r, x);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    root[0] = build_tree(1, n);
    for (int i = 1, v, a, b, c; i <= m; i++) {
        scanf("%d%d%d", &v, &a, &b);
        if (a == 1) {
            scanf("%d", &c);
            root[i] = modify(root[v], 1, n, b, c);
        } else {
            cout << query(root[v], 1, n, b) << endl;
            root[i] = root[v];
        }
    }
    return 0;
}
