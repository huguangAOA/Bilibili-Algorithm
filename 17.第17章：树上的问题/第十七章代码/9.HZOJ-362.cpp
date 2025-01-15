/*************************************************************************
	> File Name: 9.HZOJ-362.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 三  1/15 17:37:17 2025
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> g[305];
int val[305], cnt[305];
int dp[305][305];

void getDP(int fa, int x) {
    cnt[x] = 1;
    dp[x][0] = 0;
    dp[x][1] = val[x];
    for (auto to : g[x]) {
        getDP(x, to);
        cnt[x] += cnt[to];
        for (int j = min(m, cnt[x]); j >= 2; j--) {
            for (int k = 0; k <= cnt[to]; k++) {
                if (k + 1 > j) break;
                dp[x][j] = max(dp[x][j], dp[x][j - k] + dp[to][k]);
            }
        }
    }
    return ;
}

int main() {
    cin >> n >> m;
    for (int i = 1, a, b; i <= n; i++) {
        cin >> a >> b;
        g[a].push_back(i);
        val[i] = b;
    }
    m += 1;
    getDP(-1, 0);
    cout << dp[0][m] << endl;
    return 0;
}
