/*************************************************************************
	> File Name: 18.HZOJ-282.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 五  4/ 5 19:39:27 2024
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 3100000
int node[MAX_N + 5][2];
int cnt = 1, root = 1;

void insert(int x) {
    int p = root;
    for (int i = 30; i >= 0; i--) {
        int ind = !!(x & (1 << i));
        if (node[p][ind] == 0) node[p][ind] = ++cnt;
        p = node[p][ind];
    }
    return ;
}

int query(int x) {
    int ans = 0, p = root;
    for (int i = 30; i >= 0; i--) {
        int ind = !!(x & (1 << i));
        if (node[p][1 - ind] != 0) {
            ans |= (1 << i);
            p = node[p][1 - ind];
        } else {
            p = node[p][ind];
        }
    }
    return ans;
}

int main() {
    int n, ans = 0, temp;
    scanf("%d", &n);
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        insert(a);
        temp = query(a);
        ans = max(ans, temp);
    }
    printf("%d\n", ans);
    return 0;
}
