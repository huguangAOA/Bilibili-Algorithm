/*************************************************************************
	> File Name: 17.lca.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 三  4/ 9 00:48:05 2025
 ************************************************************************/

#include <iostream>
using namespace std;

struct Edge {
    int to, nxt;
} e[205];
int head[105], cnt = 0;
void add(int a, int b) {
    e[++cnt] = {b, head[a]};
    head[a] = cnt;
    return ;
}

#define MAX_K 9
int n, m;
int dep[105], st[105][10];

void dfs(int pre, int x, int d) {
    dep[x] = d;
    for (int p = head[x]; p; p = e[p].nxt) {
        int to = e[p].to;
        if (to == pre) continue;
        st[to][0] = x;
        for (int k = 1; k <= MAX_K; k++) {
            st[to][k] = st[st[to][k - 1]][k - 1];
        }
        dfs(x, to, d + 1);
    }
    return ;
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int k = MAX_K; k >= 0; k--) {
        if (dep[st[x][k]] < dep[y]) continue;
        x = st[x][k];
    }
    if (x == y) return x;
    for (int k = MAX_K; k >= 0; k--) {
        if (st[x][k] == st[y][k]) continue;
        x = st[x][k];
        y = st[y][k];
    }
    return st[x][0];
}

int dis(int x, int y) {
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}

int main() {
    cin >> n >> m;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dep[0] = -1;
    dfs(0, 1, 0);
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        cout << lca(x, y) << " " << dis(x, y) << endl;
    }
    return 0;
}
