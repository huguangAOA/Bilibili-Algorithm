/*************************************************************************
	> File Name: 9.P3374.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 二  7/ 2 17:50:36 2024
 ************************************************************************/

#include <iostream>
using namespace std;

#define lowbit(x) (x & (-x))

int c[500005];

void add(int i, int x, int n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
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

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1, x; i <= n; i++) {
        cin >> x; // a[i] = x
        add(i, x, n);
    }
    for (int i = 0, x, y, z; i < m; i++) {
        cin >> z >> x >> y;
        if (z == 1) {
            add(x, y, n);
        } else {
            cout << query(y) - query(x - 1) << endl;
        }
    }
    return 0;
}
