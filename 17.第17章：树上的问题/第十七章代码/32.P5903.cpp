/*************************************************************************
	> File Name: 33.P5903.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 六  6/21 02:06:37 2025
 ************************************************************************/

#include <iostream>
using namespace std;

#define ui unsigned int
ui s;

inline ui get(ui x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return s = x;
}

#define int long long

const int maxn = 500000;

struct Edge {
    int to, nxt;
} e[maxn + 5];
int head[maxn + 5], cnt = 0;
void add(int a, int b) {
    e[++cnt] = {b, head[a]};
    head[a] = cnt;
    return ;
}

int n, q, root;
int fa[maxn + 5], sz[maxn + 5], hson[maxn + 5], dep[maxn + 5];
int id[maxn + 5], idx = 0, top[maxn + 5], w[maxn + 5];
void dfs1(int pre, int x) {
    sz[x] = 1;
    dep[x] = dep[pre] + 1;
    for (int p = head[x]; p; p = e[p].nxt) {
        int to = e[p].to;
        dfs1(x, to);
        sz[x] += sz[to];
        if (sz[to] > sz[hson[x]]) hson[x] = to;
    }
    return ;
}

void dfs2(int pre, int x) {
    id[x] = ++idx;
    w[idx] = x;
    top[x] = pre;
    if (!hson[x]) return ;
    dfs2(pre, hson[x]);
    for (int p = head[x]; p; p = e[p].nxt) {
        int to = e[p].to;
        if (to == hson[x]) continue;
        dfs2(to, to);
    }
    return ;
}

int query(int x, int k) {
    int d = dep[x] - k;
    while (dep[top[x]] > d) x = fa[top[x]];
    return w[id[top[x]] + (d - dep[top[x]])];
}

int32_t main() {
    cin >> n >> q >> s;
    for (int i = 1; i <= n; i++) {
        cin >> fa[i];
        if (fa[i] == 0) root = i;
        add(fa[i], i);
    }
    dfs1(0, root);
    dfs2(root, root);
    int ret = 0, ans = 0;
    for (int i = 1; i <= q; i++) {
        int x = (get(s) ^ ans) % n + 1, k = (get(s) ^ ans) % dep[x];
        ans = query(x, k);
        ret ^= i * ans;
    }
    cout << ret << endl;
    return 0;
}
