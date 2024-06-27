/*************************************************************************
	> File Name: 6.P1083.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 四  6/27 23:27:02 2024
 ************************************************************************/

#include <iostream>
using namespace std;

struct Data {
    long long d, s, t;
};
int n, m;
long long a[1000005];
long long x[1000005];
Data ods[1000005];

int check(int k) {
    x[1] = a[1];
    for (int i = 2; i <= n; i++) {
        x[i] = a[i] - a[i - 1];
    }
    for (int i = 1; i <= k; i++) {
        long long d = ods[i].d, s = ods[i].s, t = ods[i].t;
        x[s] -= d;
        x[t + 1] += d;
    }
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += x[i];
        if (sum < 0) return 1;
    }
    return 0;
}

int binary_search() {
    int l = 1, r = m + 1, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (check(mid) == 0) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%lld%lld%lld", &ods[i].d, &ods[i].s, &ods[i].t);
    }
    int ind = binary_search();
    if (ind == m + 1) {
        printf("0\n");
    } else {
        printf("-1\n");
        printf("%d\n", ind);
    }
    return 0;
}
