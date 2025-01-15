/*************************************************************************
	> File Name: 8.P1757.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 二  1/14 13:37:13 2025
 ************************************************************************/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Data {
    int a, b;
};

int m, n;
map<int, vector<Data>> arr;
int dp[1005];

int main() {
    cin >> m >> n;
    for (int i = 1, a, b, c; i <= n; i++) {
        cin >> a >> b >> c;
        arr[c].push_back({a, b});
    }
    for (auto z : arr) {
        for (int j = m; j >= 1; j--) {
            for (auto x : z.second) {
                if (j < x.a) continue;
                dp[j] = max(dp[j], dp[j - x.a] + x.b);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}
