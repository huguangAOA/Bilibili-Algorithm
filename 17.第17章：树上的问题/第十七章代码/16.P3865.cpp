/*************************************************************************
	> File Name: 16.P3865.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 三  4/ 9 00:05:17 2025
 ************************************************************************/

#include <iostream>
using namespace std;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int n, m;
int a[100005];
int st[100005][20], lg[100005];

void init_st() {
    lg[1] = 0;
    for (int i = 2; i <= 100005; i++) lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= n; i++) st[i][0] = a[i];
    for (int k = 1; k <= lg[n]; k++) {
        for (int i = 1, I = n - (1 << k) + 1; i <= I; i++) {
            st[i][k] = max(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
        }
    }
    return ;
}

int query1(int l, int r) {
    int i = 0, b = r - l + 1, ans = st[l][0];
    while (b) {
        if (b & 1) ans = max(ans, st[l][i]), l += (1 << i);
        b /= 2;
        i += 1;
    }
    return ans;
}

int query2(int l, int r) {
    int cnt = r - l + 1;
    int k = lg[cnt];
    int p1 = l, p2 = r - (1 << k) + 1;
    return max(st[p1][k], st[p2][k]);
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    init_st();
    int l, r;
    for (int i = 1; i <= m; i++) {
        l = read(), r = read();
        printf("%d\n", query2(l, r));
    }
    return 0;
}
