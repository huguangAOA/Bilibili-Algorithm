/*************************************************************************
	> File Name: 23.P8306.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 五  4/ 5 21:27:04 2024
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAX_N 3000000
int node[MAX_N + 5][62];
int val[MAX_N + 5];
int cnt = 1, root = 1;
char s[MAX_N + 5];

int code(char c) {
    if (c <= 'z' && c >= 'a') return c - 'a';
    if (c <= 'Z' && c >= 'A') return c - 'A' + 26;
    return c - '0' + 52;
}

void insert(const char *s) {
    int p = root;
    for (int i = 0; s[i]; i++) {
        val[p] += 1;
        int ind = code(s[i]);
        if (node[p][ind] == 0) node[p][ind] = ++cnt;
        p = node[p][ind];
    }
    val[p] += 1;
    return ;
}

int query(const char *s) {
    int p = root;
    for (int i = 0; s[i]; i++) {
        int ind = code(s[i]);
        p = node[p][ind];
        if (p == 0) return 0;
    }
    return val[p];
}

void init() {
    for (int i = 0; i <= cnt; i++) {
        for (int j = 0; j < 62; j++) {
            node[i][j] = 0;
        }
    }
    for (int i = 0; i <= cnt; i++) val[i] = 0;
    cnt = 1, root = 1;
    return ;
}

void solve() {
    init();
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        insert(s);
    }
    for (int i = 0; i < q; i++) {
        scanf("%s", s);
        printf("%d\n", query(s));
    }
    return ;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
