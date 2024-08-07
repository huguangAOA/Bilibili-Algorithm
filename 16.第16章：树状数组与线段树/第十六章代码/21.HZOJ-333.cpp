/*************************************************************************
	> File Name: 21.HZOJ-333.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 三  8/ 7 16:29:12 2024
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 500000
#define L(n) (tree[n].l)
#define R(n) (tree[n].r)
#define S(n) (tree[n].sum)
#define M(n) (tree[n].m)
#define LM(n) (tree[n].lm)
#define RM(n) (tree[n].rm)
#define define_mid int mid = (l + r) >> 1
#define swap(a, b) { \
    __typeof(a) __c = a; \
    a = b; b = __c; \
}

struct Node {
    int l, r;
    int sum, m, lm, rm;
} tree[MAX_N * 2 + 5];
int root = 2, cnt = 2, t1 = 0, t2 = 1, flag;

int n, m;
int num[MAX_N + 5];

void UP(int a, int b, int c) {
    S(a) = S(b) + S(c);
    LM(a) = max(LM(b), S(b) + LM(c));
    RM(a) = max(RM(c), S(c) + RM(b));
    M(a) = max(M(b), M(c));
    M(a) = max(M(a), RM(b) + LM(c));
    return ;
}

int build_tree(int ind, int l, int r) {
    if (l == r) {
        S(ind) = M(ind) = LM(ind) = RM(ind) = num[l];
        return ind;
    }
    define_mid;
    L(ind) = build_tree(++cnt, l, mid);
    R(ind) = build_tree(++cnt, mid + 1, r);
    UP(ind, L(ind), R(ind));
    return ind;
}

void modify(int ind, int l, int r, int x, int y) {
    if (l == r) {
        S(ind) = M(ind) = LM(ind) = RM(ind) = y;
        return ;
    }
    define_mid;
    if (x <= mid) modify(L(ind), l, mid, x, y);
    else modify(R(ind), mid + 1, r, x, y);
    UP(ind, L(ind), R(ind));
    return ;
}

void query(int ind, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        if (flag) {
            tree[t1] = tree[ind];
            flag = 0;
        } else {
            UP(t1, t2, ind);
        }
        swap(t1, t2);
        return ;
    }
    define_mid;
    if (x <= mid) query(L(ind), l, mid, x, y);
    if (mid < y) query(R(ind), mid + 1, r, x, y);
    return ;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", num + i);
    build_tree(root, 1, n);
    for (int i = 1, x, y, k; i <= m; i++) {
        scanf("%d%d%d", &k, &x, &y);
        if (k == 1) {
            if (x > y) swap(x, y);
            flag = 1;
            query(root, 1, n, x, y);
            printf("%d\n", M(t2));
        } else {
            modify(root, 1, n, x, y);
        }
    }
    return 0;
}
