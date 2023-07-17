/*************************************************************************
	> File Name: 11.HZOJ-289.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

#define MAX_N 100000
long long arr[MAX_N + 5] = {0};
int l[MAX_N + 5] = {0}, r[MAX_N + 5] = {0}, st[MAX_N + 5] = {0};

typedef pair<int, int> PII;
set<PII> h;

void del(int x) {
    r[l[x]] = r[x];
    l[r[x]] = l[x];
    st[x] = 1;
    return ;
}

int main() {
    int n, m, k = 1;
    scanf("%d%d", &n, &m);
    scanf("%lld", arr + 1);
    for (int i = 1, a; i < n; i++) {
        scanf("%d", &a);
        if (1LL * arr[k] * a < 0) arr[++k] = a;
        else arr[k] += a;
    }
    long long cnt = 0, S = 0;
    n = k;
    for (int i = 1; i <= n; i++) {
        if (arr[i] > 0) {
            cnt += 1;
            S += arr[i];
        }
        h.insert(PII(abs(arr[i]), i));
        l[i] = i - 1;
        r[i] = i + 1;
    }
    while (cnt > m) {
        while (st[h.begin()->second]) h.erase(h.begin());
        int ind  = h.begin()->second;
        h.erase(h.begin());
        int left = l[ind], right = r[ind];
        if ((left > 0 && right <= n) || arr[ind] > 0) {
            S -= abs(arr[ind]);
            cnt -= 1;
            arr[ind] += arr[left] + arr[right];
            h.insert(PII(abs(arr[ind]), ind));
            del(left);
            del(right);
        }
    }
    printf("%lld\n", S);
    return 0;
}
