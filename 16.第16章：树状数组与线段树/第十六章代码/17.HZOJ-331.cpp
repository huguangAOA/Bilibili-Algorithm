/*************************************************************************
	> File Name: 17.HZOJ-331.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 一  7/29 10:56:54 2024
 ************************************************************************/

#include <iostream>
using namespace std;

#define lowbit(x) (x & (-x))
int c[80005], a[80005];
void add(int i, int v, int n) {
    while (i <= n) c[i] += v, i += lowbit(i);
    return ;
}
int query(int i) {
    if (i == 0) return 0;
    return c[i] + query(i - lowbit(i));
}

int binary_search(int x, int n) {
    int l = 1, r = n, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (query(mid) < x) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main() {
    int n;
    cin >> n;
    a[1] = 0;
    for (int i = 2; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        add(i, 1, n);
    }
    for (int i = n; i >= 1; i--) {
        a[i] = binary_search(a[i] + 1, n);
        add(a[i], -1, n);
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
