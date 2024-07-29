/*************************************************************************
	> File Name: 13.HZOJ-222.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 日  7/28 11:15:39 2024
 ************************************************************************/

#include <iostream>
using namespace std;

#define L(ind) (tree[ind].lchild)
#define R(ind) (tree[ind].rchild)
#define C(ind) (tree[ind].c)

struct Node {
    int c, lchild, rchild;
} tree[20005];
int root = 1, node_cnt = 1;
inline int getNewNode() { return ++node_cnt; }
int n, m;
int a[10005];

void UP(int ind) {
    C(ind) = max(C(L(ind)), C(R(ind)));
    return ;
}

void build_tree(int ind, int l, int r) {
    if (l == r) {
        tree[ind].c = a[l];
        return ;
    }
    int mid = (l + r) / 2;
    L(ind) = getNewNode();
    R(ind) = getNewNode();
    build_tree(L(ind), l, mid);
    build_tree(R(ind), mid + 1, r);
    UP(ind);
    return ;
}

void modify(int ind, int l, int r, int x, int y) {
    if (l == r) {
        C(ind) = y;
        return ;
    }
    int mid = (l + r) / 2;
    if (x <= mid) modify(L(ind), l, mid, x, y);
    else modify(R(ind), mid + 1, r, x, y);
    UP(ind);
    return ;
}

int query(int ind, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return C(ind);
    }
    int mid = (l + r) / 2;
    int ans = -2147483648;
    if (x <= mid) ans = max(ans, query(L(ind), l, mid, x, y));
    if (y > mid) ans = max(ans, query(R(ind), mid + 1, r, x, y));
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build_tree(root, 1, n);
    for (int i = 1, a, b, c; i <= m; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            if (b <= c) modify(root, 1, n, b, c);
        } else {
            if (b <= c) cout << query(root, 1, n, b, c) << endl;
            else cout << "-2147483648" << endl;
        }
    }
    return 0;
}
