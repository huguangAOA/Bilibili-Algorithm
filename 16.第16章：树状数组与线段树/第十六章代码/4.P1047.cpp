/*************************************************************************
	> File Name: 4.P1047.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 四  6/27 22:57:38 2024
 ************************************************************************/

#include <iostream>
using namespace std;

int x[10005];
int l, m;

int main() {
    cin >> l >> m;
    x[0] = 1;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        x[u] -= 1;
        x[v + 1] += 1;
    }
    int sum = 0, ans = 0;
    for (int i = 0; i <= l; i++) {
        sum += x[i];
        if (sum == 1) ans += 1;
    }
    cout << ans << endl;
    return 0;
}
