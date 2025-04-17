/*************************************************************************
	> File Name: 20.P8805.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 日  4/13 15:11:17 2025
 ************************************************************************/

#include <iostream>
using namespace std;

const int maxn = 100000;
struct Edge {
    int to, nxt, c;
} e[maxn * 2 + 5];
int head[maxn + 5], cnt = 0;
void add(int a, int b) {
    e[++cnt] = {b, head[a], e[head[a]].c + 1};
    head[a] = cnt;
    return ;
}

const int maxk = 19;
int n, m;
int dep[maxn + 5], dis[maxn + 5], st[maxn + 5][maxk + 1];

void dfs(int pre, int x) {
    dep[x] = dep[pre] + 1;
    dis[x] = dis[pre] + e[head[x]].c;
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
    if (dep[x] < dep[y]) swap(x, y);
    for (int k = maxk; k >= 0; k--) {
        if (dep[st[x][k]] < dep[y]) continue;
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
    return dis[x] + dis[y] - 2 * dis[lca(x, y)] + e[head[lca(x, y)]].c;
}

int main() {
    cin >> n >> m;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(0, 1);
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        cout << DIS(a, b) << endl;
    }
    return 0;
}
