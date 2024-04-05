/*************************************************************************
	> File Name: 24.P2292.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 五  4/ 5 21:51:40 2024
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <unordered_set>
using namespace std;

#define MAX_CNT 400
#define MAX_N 2000000
int node[MAX_CNT + 5][26];
int val[MAX_CNT + 5], dep[MAX_CNT + 5];
int fail[MAX_CNT + 5];
unordered_set<int> str_len[MAX_CNT + 5];
int cnt = 1, root = 1;
char s[MAX_N + 5];
int _dp[MAX_N + 5], slen;

void insert(const char *s) {
    int p = root;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        if (node[p][ind] == 0) {
            node[p][ind] = ++cnt;
            dep[cnt] = dep[p] + 1;
        }
        p = node[p][ind];
    }
    val[p] += 1;
    str_len[p].insert(dep[p]);
    return ;
}

void build_ac() {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            if (node[now][i] == 0) {
                node[now][i] = (now == root ? root : node[fail[now]][i]);
                continue;
            }
            int p1 = node[now][i], p2 = node[fail[now]][i];
            if (p2 == 0) p2 = root;
            fail[p1] = p2;
            for (auto x : str_len[p2]) {
                str_len[p1].insert(x);
            }
            q.push(p1);
        }
    }
    return ;
}

int query(const char *s) {
    int ans = -1, p = root, *dp = _dp + 1;
    dp[-1] = 1;
    for (int i = 0; i < slen; i++) dp[i] = 0;
    for (slen = 0; s[slen]; slen++) {
        if (slen - ans > 20) break;
        p = node[p][s[slen] - 'a'];
        for (auto x : str_len[p]) {
            if (dp[slen - x] == 0) continue;
            dp[slen] = 1;
            ans = slen;
            break;
        }
    }
    return ans + 1;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        insert(s);
    }
    build_ac();
    for (int i = 0; i < m; i++) {
        scanf("%s", s);
        printf("%d\n", query(s));
    }
    return 0;
}
