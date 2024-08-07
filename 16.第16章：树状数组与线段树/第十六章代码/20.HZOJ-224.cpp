/*************************************************************************
	> File Name: 20.HZOJ-224.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 三  8/ 7 14:07:12 2024
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 100000
#define L(n) (tree[n].l)
#define R(n) (tree[n].r)
#define S(n) (tree[n].sum)
#define C(n) (tree[n].cnt)
#define X(n) (tree[n].x)
#define Y(n) (tree[n].y)
#define MOD(expr) ((expr) %= p)

struct Node {
    int l, r;
    long long sum, cnt;
    long long x, y;
} tree[MAX_N * 2+ 5];
int root = 1, cnt = 1;
int n, m;
long long p;
int num[MAX_N + 5];

void DOWN_MUL(int ind) {
    if (X(ind) == 1) return ;
    MOD(X(L(ind)) *= X(ind));
    MOD(X(R(ind)) *= X(ind));
    MOD(Y(L(ind)) *= X(ind));
    MOD(Y(R(ind)) *= X(ind));
    MOD(S(L(ind)) *= X(ind));
    MOD(S(R(ind)) *= X(ind));
    X(ind) = 1;
    return ;
}

void DOWN_ADD(int ind) {
    if (Y(ind) == 0) return ;
    MOD(Y(L(ind)) += Y(ind));
    MOD(Y(R(ind)) += Y(ind));
    MOD(S(L(ind)) += C(L(ind)) * Y(ind));
    MOD(S(R(ind)) += C(R(ind)) * Y(ind));
    Y(ind) = 0;
    return ;
}

void DOWN(int ind) {
    DOWN_MUL(ind);
    DOWN_ADD(ind);
    return ;
}

void UP(int ind) {
    MOD(S(ind) = S(L(ind)) + S(R(ind)));
    return ;
}

int build_tree(int ind, int l, int r) {
    tree[ind].x = 1, tree[ind].y = 0;
    tree[ind].cnt = (r - l + 1);
    if (l == r) {
        MOD(tree[ind].sum = num[l]);
        return ind;
    }
    int mid = (l + r) / 2;
    tree[ind].l = build_tree(++cnt, l, mid);
    tree[ind].r = build_tree(++cnt, mid + 1, r);
    UP(ind);
    return ind;
}

long long query(int ind, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return tree[ind].sum;
    }
    DOWN(ind);
    int mid = (l + r) / 2;
    long long ans = 0;
    if (x <= mid) MOD(ans += query(L(ind), l, mid, x, y));
    if (mid + 1 <= y) MOD(ans += query(R(ind), mid + 1, r, x, y));
    return ans;
}

void modify(int ind, int l, int r, int x, int y, long long k, int type) {
    if (x <= l && r <= y) {
        if (type == 1) {
            MOD(X(ind) *= k);
            MOD(Y(ind) *= k);
            MOD(S(ind) *= k);
            return ;
        } else {
            MOD(Y(ind) += k);
            MOD(S(ind) += C(ind) * k);
            return ;
        }
    }
    DOWN(ind);
    int mid = (l + r) / 2;
    if (x <= mid) modify(L(ind), l, mid, x, y, k, type);
    if (mid + 1 <= y) modify(R(ind), mid + 1, r, x, y, k, type);
    UP(ind);
    return ;
}

int main() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) cin >> num[i];
    build_tree(root, 1, n);
    for (int i = 1, a, x, y, k; i <= m; i++) {
        cin >> a >> x >> y;
        if (a == 1 || a == 2) {
            cin >> k;
            modify(root, 1, n, x, y, k, a);
        } else {
            cout << query(root, 1, n, x, y) << endl;
        }
    }
    return 0;
}
