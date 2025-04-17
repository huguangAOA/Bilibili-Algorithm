/*************************************************************************
	> File Name: 13.double_dfs.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 六  4/ 5 17:29:29 2025
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> g[105];
int dep[105], fa[105];

int dfs(int pre, int x, int d) {
    fa[x] = pre;
    dep[x] = d;
    int ind = x;
    for (auto to : g[x]) {
        if (to == pre) continue;
        int temp = dfs(x, to, d + 1);
        if (dep[temp] > dep[ind]) ind = temp;
    }
    return ind;
}

int main() {
    cin >> n;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int p1 = dfs(0, 1, 0);
    int p2 = dfs(0, p1, 0);
    int p = p2;
    while (p) {
        cout << p << "->";
        p = fa[p];
    }
    cout << endl;
    cout << dep[p2] << endl;
    return 0;
}
