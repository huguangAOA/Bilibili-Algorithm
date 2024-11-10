/*************************************************************************
	> File Name: 5.P2018.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 一 11/11 02:47:35 2024
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int to, nxt;
} e[2005];
int head[1005], cnt = 0;
void add(int a, int b) {
    e[++cnt] = {b, head[a]};
    head[a] = cnt;
    return ;
}


int n;
int dp[1005], ans[1005];

void getDP(int fa, int ind) {
    vector<int> t;
    for (int p = head[ind]; p; p = e[p].nxt) {
        int to = e[p].to;
        if (to == fa) continue;
        getDP(ind, to);
        t.push_back(dp[to]);
    }
    sort(t.begin(), t.end(), greater<int>());
    for (int i = 0; i < t.size(); i++) {
        dp[ind] = max(dp[ind], t[i] + i + 1);
    }
    return ;
}

int main() {
    cin >> n;
    for (int i = 2, a; i <= n; i++) {
        cin >> a;
        add(a, i);
        add(i, a);
    }
    int min_ = n + 1;
    for (int i = 1; i <= n; i++) {
        memset(dp, 0, sizeof(dp));
        getDP(0, i);
        ans[i] = dp[i];
        min_ = min(min_, ans[i]);
    }
    cout << min_ + 1 << endl;
    for (int i = 1, flag = 0; i <= n; i++) {
        if (ans[i] != min_) continue;
        if (flag) cout << " ";
        cout << i;
        flag = 1;
    }
    cout << endl;
    return 0;
}
