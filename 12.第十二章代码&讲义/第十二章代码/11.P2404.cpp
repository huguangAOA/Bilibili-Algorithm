/*************************************************************************
	> File Name: 11.P2404.cpp
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
using namespace std;

int ans[20] = {0};

void print_one_result(int n) {
    if (n < 2) return ;
    for (int i = 0; i < n; i++) {
        if (i) cout << "+";
        cout << ans[i];
    }
    cout << endl;
    return ;
}

void dfs(int k, int s_num, int n) {
    if (n == 0) {
        print_one_result(k);
        return ;
    }
    if (s_num > n) return ;
    for (int i = s_num; i <= n; i++) {
        ans[k] = i;
        dfs(k + 1, i, n - i);
    }
    return ;
}

int main() {
    int n;
    cin >> n;
    dfs(0, 1, n);
    return 0;
}
