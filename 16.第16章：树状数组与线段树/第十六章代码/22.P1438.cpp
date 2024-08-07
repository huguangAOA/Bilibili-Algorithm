/*************************************************************************
	> File Name: 22.P1438.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 三  8/ 7 17:38:04 2024
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 100000
#define L(n) (tree[n].l)
#define R(n) (tree[n].r)
#define S(n) (tree[n].sum)
#define X(n) (tree[n].x)
#define C(n) (tree[n].cnt)
#define define_mid int mid = (l + r) >> 1

struct Node {
    int l, r;
    long long sum, x, cnt;
} tree[MAX_N * 2 + 5];
int root = 1, cnt = 1;

int n, m;
int num[MAX_N + 5];

void UP(int ind) {
    S(ind) = S(L(ind)) + S(R(ind));
    return ;
}

void DOWN(int ind) {
    if (X(ind) == 0) return ;
    X(L(ind)) += X(ind);
    X(R(ind)) += X(ind);
    S(L(ind)) += C(L(ind)) * X(ind);
    S(R(ind)) += C(R(ind)) * X(ind);
    X(ind) = 0;
    return ;
}

int build(int ind, int l, int r) {
    X(ind) = 0, C(ind) = (r - l + 1);
    if (l == r) {
        S(ind) = num[l] - num[l - 1];
        return ind;
    }
    define_mid;
    L(ind) = build(++cnt, l, mid);
    R(ind) = build(++cnt, mid + 1, r);
    UP(ind);
    return ind;
}

long long query(int ind, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return S(ind);
    }
    DOWN(ind);
    define_mid;
    long long ans = 0;
    if (x <= mid) ans += query(L(ind), l, mid, x, y);
    if (mid < y) ans += query(R(ind), mid + 1, r, x, y);
    return ans;
}

void modify(int ind, int l, int r, int x, int y, long long k) {
    if (x > y || y < l || r < x) return ;
    if (x <= l && r <= y) {
        X(ind) += k;
        S(ind) += C(ind) * k;
        return ;
    }
    DOWN(ind);
    define_mid;
    if (x <= mid) modify(L(ind), l, mid, x, y, k);
    if (mid < y) modify(R(ind), mid + 1, r, x, y, k);
    UP(ind);
    return ;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> num[i];
    build(root, 1, n);
    for (int i = 1, op; i <= m; i++) {
        cin >> op;
        if (op == 1) {
            long long l, r, k, d;
            cin >> l >> r >> k >> d;
            modify(root, 1, n, l, l, k);
            modify(root, 1, n, l + 1, r, d);
            modify(root, 1, n, r + 1, r + 1, -(k + (r - l) * d));
        } else {
            int p;
            cin >> p;
            cout << query(root, 1, n, 1, p) << endl;
        }
    }
    return 0;
}
