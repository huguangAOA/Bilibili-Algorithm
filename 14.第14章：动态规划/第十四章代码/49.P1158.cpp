/*************************************************************************
	> File Name: 49.P1158.cpp
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
#define P2(a) ((a) * (a))
#define DIS(x1, y1, x2, y2) P2(x1 - x2) + P2(y1 - y2)
int x[MAX_N + 5], y[MAX_N + 5], ind[MAX_N + 5];
int dis[MAX_N + 5];
int n, x1, y1, x2, y2;

bool cmp(int i, int j) {
    return DIS(x[i], y[i], x1, y1) < DIS(x[j], y[j], x1, y1);
}

int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        ind[i] = i;
    }
    sort(ind, ind + n, cmp);
    for (int i = n - 1; i >= 0; i--) {
        dis[i] = DIS(x[ind[i]], y[ind[i]], x2, y2);
        dis[i] = max(dis[i + 1], dis[i]);
    }
    int ans = dis[0];
    for (int i = 0; i < n; i++) {
        ans = min(ans, DIS(x[ind[i]], y[ind[i]], x1, y1) + dis[i + 1]);
    }
    cout << ans << endl;
    return 0;
}
