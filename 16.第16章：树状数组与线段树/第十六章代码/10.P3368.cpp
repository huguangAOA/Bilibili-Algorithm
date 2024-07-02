/*************************************************************************
	> File Name: 10.P3368.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 二  7/ 2 18:02:33 2024
 ************************************************************************/

#include <iostream>
using namespace std;

#define lowbit(x) (x & (-x))

int c[500005];

void add(int i, int x, int n) {
    if (i > n) return ;
    c[i] += x;
    add(i + lowbit(i), x, n);
    return ;
}

int query(int i) {
    if (i == 0) return 0;
    return c[i] + query(i - lowbit(i));
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1, pre = 0, x; i <= n; i++) {
        cin >> x;
        add(i, x - pre, n);
        pre = x;
    }
    for (int i = 1, z; i <= m; i++) {
        cin >> z;
        if (z == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            add(x, k, n);
            add(y + 1, -k, n);
        } else {
            int x;
            cin >> x;
            cout << query(x) << endl;
        }
    }
    return 0;
}
