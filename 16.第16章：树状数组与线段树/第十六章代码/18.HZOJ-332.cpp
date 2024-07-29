/*************************************************************************
	> File Name: 18.HZOJ-332.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 一  7/29 11:32:34 2024
 ************************************************************************/

#include <iostream>
using namespace std;

#define lowbit(x) (x & (-x))
int c[2000005], a[2000005], b[2000005];
int ans[2000005];
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
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i], &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        add(i, 1, n);
    }
    for (int i = n; i >= 1; i--) {
        int pos = binary_search(a[i] + 1, n);
        ans[pos] = b[i];
        add(pos, -1, n);
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
