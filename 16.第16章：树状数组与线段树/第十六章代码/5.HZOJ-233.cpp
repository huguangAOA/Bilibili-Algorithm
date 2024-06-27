/*************************************************************************
	> File Name: 5.HZOJ-233.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 四  6/27 23:10:36 2024
 ************************************************************************/

#include <iostream>
#include <set>
using namespace std;

int x[10005];
set<pair<int, int>> s;

int main() {
    int n, p, h, m;
    cin >> n >> p >> h >> m;
    x[1] = h;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (s.find({a, b}) != s.end()) continue;
        x[a + 1] -= 1;
        x[b] += 1;
        s.insert({a, b});
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += x[i];
        cout << sum << endl;
    }
    return 0;
}
