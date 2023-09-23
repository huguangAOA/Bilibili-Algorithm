/*************************************************************************
	> File Name: 38.HZOJ-52.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

#define MAX_N 1000000
#define SQ(x) ((x) * (x))
long long c[MAX_N + 5], sum[MAX_N + 5];
long long dp[MAX_N + 5], f[MAX_N + 5];
int q[MAX_N + 5], head, tail;
long long n, M;

double slope(int i, int j) {
    return 1.0 * (f[i] - f[j]) / (sum[i] - sum[j]);
}

void set(int i, int j) {
    dp[i] = dp[j] + SQ(sum[i] - sum[j]) + M;
    f[i] = dp[i] + SQ(sum[i]);
    return ;
}

int main() {
    scanf("%lld%lld", &n, &M);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", c + i);
        sum[i] = sum[i - 1] + c[i];
    }
    head = tail = 0;
    q[tail++] = 0;
    for (int i = 1; i <= n; i++) {
        while (tail - head >= 2 && slope(q[head + 1], q[head]) < 2 * sum[i]) head += 1;
        set(i, q[head]);
        while (tail - head >= 2 && slope(q[tail - 1], q[tail - 2]) > slope(i, q[tail - 1])) {
            tail -= 1;
        }
        q[tail++] = i;
    }
    printf("%lld\n", dp[n]);
    return 0;
}
