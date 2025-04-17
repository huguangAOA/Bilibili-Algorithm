/*************************************************************************
	> File Name: 21.P8855.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 日  4/13 15:26:01 2025
 ************************************************************************/

#include <iostream>
using namespace std;

const int maxn = 30000, maxk = 19;
struct Edge {
    int to, nxt;
} e[maxn * 2 + 5];
int head[maxn + 5], cnt = 0;
void add(int a, int b) {
    e[++cnt] = {b, head[a]};
    head[a] = cnt;
    return ;
}

int n, m;
int dis[maxn + 5], st[maxn + 5][maxk + 1];

void dfs(int pre, int x) {
    dis[x] = dis[pre] + 1;
    st[x][0] = pre;
    for (int k = 1; k <= maxk; k++) {
        st[x][k] = st[st[x][k - 1]][k - 1];
    }
    for (int p = head[x]; p; p = e[p].nxt) {
        int to = e[p].to;
        if (to == pre) continue;
        dfs(x, to);
    }
    return ;
}

int lca(int x, int y) {
    if (dis[x] < dis[y]) swap(x, y);
    for (int k = maxk; k >= 0; k--) {
        if (dis[st[x][k]] < dis[y]) continue;
        x = st[x][k];
    }
    if (x == y) return x;
    for (int k = maxk; k >= 0; k--) {
        if (st[x][k] == st[y][k]) continue;
        x = st[x][k], y = st[y][k];
    }
    return st[x][0];
}

int DIS(int x, int y) {
    return dis[x] + dis[y] - 2 * dis[lca(x, y)];
}

int main() {
    cin >> n;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(0, 1);
    cin >> m;
    int ans = 0;
    for (int i = 1, x = 1, y; i <= m; i++, x = y) {
        cin >> y;
        ans += DIS(x, y);
    }
    cout << ans << endl;
    return 0;
}
