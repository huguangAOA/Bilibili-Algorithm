/*************************************************************************
	> File Name: 15.HZOJ-425.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 日  4/ 6 16:27:50 2025
 ************************************************************************/

#include <iostream>
using namespace std;

struct Edge {
    int from, to, nxt, c;
} e[200005];
int head[100005], cnt = 1;
void add(int a, int b) {
    e[++cnt] = {a, b, head[a], 1};
    head[a] = cnt;
    return ;
}

int n, K;
int dep[100005], fa[100005];
int dfs(int pre, int x, int d) {
    dep[x] = d;
    int ind = x;
    for (int p = head[x]; p; p = e[p].nxt) {
        int to = e[p].to;
        if (to == pre) continue;
        fa[to] = p;
        int temp = dfs(x, to, d + 1);
        if (dep[temp] > dep[ind]) ind = temp;
    }
    return ind;
}

int DP(int pre, int x) {
    dep[x] = 0;
    int ans = 0;
    for (int p = head[x]; p; p = e[p].nxt) {
        int to = e[p].to, c = e[p].c;
        if (to == pre) continue;
        int temp = DP(x, to);
        ans = max(ans, temp);
        ans = max(ans, dep[x] + dep[to] + c);
        dep[x] = max(dep[x], dep[to] + c);
    } 
    return ans;
}

int main() {
    cin >> n >> K;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    int p1 = dfs(0, 1, 0);
    int p2 = dfs(0, p1, 0);
    int len1 = dep[p2], len2 = 0;
    if (K == 2) {
        int p = p2;
        while (p != p1) {
            int k = fa[p];
            e[k].c = -1;
            e[k ^ 1].c = -1;
            p = e[k].from;
        }
        len2 = DP(0, 1);
    }
    cout << 2 * (n - 1) - len1 - len2 + K << endl;
    return 0;
}
