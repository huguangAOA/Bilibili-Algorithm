/*************************************************************************
	> File Name: 19.P1967.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 四  4/10 00:36:00 2025
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct Data {
    int a, b, c;
};
int n, m, q;
Data arr[50005];

struct UnionSet {
    int fa[10005];
    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
        return ;
    }
    int get(int x) {
        if (x == fa[x]) return x;
        return (fa[x] = get(fa[x]));
    }
    int merge(int a, int b) {
        if (get(a) == get(b)) return 0;
        fa[get(a)] = get(b);
        return 1;
    }
} u;

struct Edge {
    int to, nxt, c;
} e[20005];
int head[10005], cnt = 0;
void add(int a, int b, int c) {
    e[++cnt] = {b, head[a], c};
    head[a] = cnt;
    return ;
}

#define MAX_K 15
int dep[10005], st[10005][MAX_K + 1], st1[10005][MAX_K + 1];

void dfs(int pre, int x, int d) {
    dep[x] = d;
    for (int p = head[x]; p; p = e[p].nxt) {
        int to = e[p].to, c = e[p].c;
        if (to == pre) continue;
        st[to][0] = x;
        st1[to][0] = c;
        for (int k = 1; k <= MAX_K; k++) {
            st[to][k] = st[st[to][k - 1]][k - 1];
            st1[to][k] = min(st1[to][k - 1], st1[st[to][k - 1]][k - 1]);
        }
        dfs(x, to, d + 1);
    }
    return ;
}

int lca(int x, int y) {
    if (u.get(x) != u.get(y)) return -1;
    int ret = 100000;
    if (dep[x] < dep[y]) swap(x, y);
    for (int k = MAX_K; k >= 0; k--) {
        if (dep[st[x][k]] < dep[y]) continue;
        ret = min(ret, st1[x][k]);
        x = st[x][k];
    }
    if (x == y) return ret;
    for (int k = MAX_K; k >= 0; k--) {
        if (st[x][k] == st[y][k]) continue;
        ret = min(ret, st1[x][k]);
        ret = min(ret, st1[y][k]);
        x = st[x][k];
        y = st[y][k];
    }
    ret = min(ret, st1[x][0]);
    ret = min(ret, st1[y][0]);
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
    }
    sort(arr + 1, arr + 1 + m, [](Data a, Data b) {
        return a.c > b.c;
    });
    u.init(n);
    for (int i = 1; i <= m; i++) {
        if (u.merge(arr[i].a, arr[i].b)) {
            add(arr[i].a, arr[i].b, arr[i].c);
            add(arr[i].b, arr[i].a, arr[i].c);
        }
    }
    dep[0] = -1;
    for (int i = 1; i <= n; i++) {
        if (u.get(i) != i) continue;
        dfs(0, i, 0);
    }
    cin >> q;
    for (int i = 1, a, b; i <= q; i++) {
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    return 0;
}
