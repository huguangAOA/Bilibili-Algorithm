/*************************************************************************
	> File Name: 10.HZOJ-322.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

class UnionSet {
public :
    UnionSet(int n) : fa(n + 1) {
        for (int i = 0; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
    vector<int> fa;
};

struct Data {
    int i, j, e;
};

void solve() {
    int n, cnt = 0;
    scanf("%d", &n);
    vector<Data> arr(n);
    unordered_map<int, int> h;
    for (int i = 0; i < n; i++) {
        Data &x = arr[i];
        scanf("%d%d%d", &x.i, &x.j, &x.e);
        if (h.find(x.i) == h.end()) h[x.i] = cnt++;
        if (h.find(x.j) == h.end()) h[x.j] = cnt++;
    }
    UnionSet u(2 * n);
    for (int i = 0; i < n; i++) {
        if (arr[i].e == 0) continue;
        u.merge(h[arr[i].i], h[arr[i].j]);
    }
    int flag = 1;
    for (int i = 0; i < n && flag; i++) {
        if (arr[i].e == 1) continue;
        if (u.get(h[arr[i].i]) == u.get(h[arr[i].j])) {
            flag = 0;
        }  
    }
    printf("%s\n", flag ? "YES" : "NO");
    return ;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
