/*************************************************************************
	> File Name: 24.P2420.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 一  4/21 00:28:45 2025
 ************************************************************************/

#include <iostream>
using namespace std;

const int maxn = 100000;
struct Edge {
    int to, nxt, c;
} e[maxn * 2 + 5];
int head[maxn + 5], cnt = 0;
void add(int a, int b, int c) {
    e[++cnt] = {b, head[a], c};
    head[a] = cnt;
    return ;
}
int n, m;
int dis[maxn + 5];

void dfs(int pre, int x, int sum) {
    dis[x] = sum;
    for (int p = head[x]; p; p = e[p].nxt) {
        int to = e[p].to, c = e[p].c;
        if (to == pre) continue;
        dfs(x, to, sum ^ c);
    }
    return ;
}

int main() {
    cin >> n;
    for (int i = 1, a, b, c; i < n; i++) {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dfs(0, 1, 0);
    cin >> m;
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        cout << (dis[a] ^ dis[b]) << endl;
    }
    return 0;
}
