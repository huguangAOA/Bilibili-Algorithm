/*************************************************************************
	> File Name: 18.P3379.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 三  4/ 9 23:59:36 2025
 ************************************************************************/

#include <iostream>
using namespace std;

struct Edge {
    int to, nxt;
} e[1000005];
int head[500005], cnt = 0;
void add(int a, int b) {
    e[++cnt] = {b, head[a]};
    head[a] = cnt;
    return ;
}

#define MAX_K 20

int n, m, s;
int dep[500005], st[500005][MAX_K + 1];

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
        x = st[x][k], y = st[y][k];
    }
    return st[x][0];
}

int main() {
    cin >> n >> m >> s;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dep[0] = -1;
    dfs(0, s, 0);
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }
    return 0;
}
