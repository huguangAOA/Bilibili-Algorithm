/*************************************************************************
	> File Name: 15.HZOJ-328.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 一  7/29 09:07:32 2024
 ************************************************************************/

#include <iostream>
using namespace std;

#define lowbit(x) (x & (-x))
int y[200005], l[200005], r[200005];
int c[200005];
int n;

void add(int i, int v, int n) {
    while (i <= n) c[i] += v, i += lowbit(i);
    return ;
}

int query(int i) {
    int sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

void init(int n) {
    for (int i = 1; i <= n; i++) {
        c[i] = 0;
    }
    return ;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> y[i];
    init(n);
    for (int i = 1; i <= n; i++) {
        l[i] = query(y[i]);
        add(y[i], 1, n);
    }
    init(n);
    for (int i = n; i >= 1; i--) {
        r[i] = query(y[i]);
        add(y[i], 1, n);
    }
    long long ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) {
        long long a = l[i], b = r[i];
        long long c = (i - 1 - a), d = (n - i - b);
        ans1 += a * b;
        ans2 += c * d;
    }
    cout << ans2 << " " << ans1 << endl;
    return 0;
}
