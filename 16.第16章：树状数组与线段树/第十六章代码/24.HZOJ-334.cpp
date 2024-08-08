/*************************************************************************
	> File Name: 24.HZOJ-334.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 四  8/ 8 18:45:36 2024
 ************************************************************************/

#include <iostream>
using namespace std;

#define int long long
#define MAX_N 1000000
#define left (ind << 1)
#define right (ind << 1 | 1)
#define define_mid int mid = (l + r) / 2

int n, m;
int a[MAX_N + 5];
int val[MAX_N * 4 + 5], c[MAX_N * 4 + 5], ans;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

void UP(int ind) {
    val[ind] = val[left] + val[right];
    c[ind] = gcd(c[left], c[right]);
    return ;
}

void build(int ind, int l, int r) {
    if (l == r) {
        val[ind] = a[l] - a[l - 1];
        c[ind] = a[l] - a[l - 1];
        return ;
    }
    define_mid;
    build(left, l, mid);
    build(right, mid + 1, r);
    UP(ind);
    return ;
}

void modify(int ind, int l, int r, int x, int y) {
    if (l == r) {
        val[ind] += y;
        c[ind] += y;
        return ;
    }
    define_mid;
    if (x <= mid) modify(left, l, mid, x, y);
    else modify(right, mid + 1, r, x, y);
    UP(ind);
    return ;
}

int query(int ind, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        return val[ind];
    }
    define_mid;
    int ans = 0;
    if (x <= mid) ans += query(left, l, mid, x, y);
    if (mid < y) ans += query(right, mid + 1, r, x, y);
    return ans;
}

void GCD(int ind, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        ans = gcd(ans, c[ind]);
        return ;
    }
    define_mid;
    if (x <= mid) GCD(left, l, mid, x, y);
    if (mid < y) GCD(right, mid + 1, r, x, y);
    return ;
}

int32_t main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        char op[10];
        int l, r, d;
        scanf("%s%lld%lld", op, &l, &r);
        if (op[0] == 'C') {
            scanf("%lld", &d);
            modify(1, 1, n, l, d);
            if (r + 1 <= n) modify(1, 1, n, r + 1, -d);
        } else {
            ans = query(1, 1, n, 1, l);
            if (l + 1 <= r) GCD(1, 1, n, l + 1, r);
            printf("%lld\n", abs(ans));
        }
    }
    return 0;
}
