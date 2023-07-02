/*************************************************************************
	> File Name: 1.P1219.cpp
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

#define MASK(n) ((1 << (n + 1)) - 2)

unordered_map<int, int> ind;
int total_ans = 3;
int arr[20];

void print_one_result(int n) {
    for (int i = 1; i <= n; i++) {
        if (i > 1) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    total_ans -= 1;
    return ;
}

int dfs(int i, int t1, int t2, int t3, int n) {
    if (i > n) {
        if (total_ans) print_one_result(n);
        return 1;
    }
    int ans = 0;
    for (int t = t1; t; t -= (-t & t)) {
        int j = ind[-t & t];
        if ((t2 & (1 << (i + j - 1))) && (t3 & (1 << (i - j + n)))) {
            arr[i] = j;
            ans += dfs(i + 1, t1 ^ (1 << j), 
                t2 ^ (1 << (i + j - 1)),
                t3 ^ (1 << (i - j + n)),
                n
            );
        }
    }
    return ans;
}

int main() {
    int n, MASK;
    scanf("%d", &n);
    total_ans = 3;
    for (int i = 0; i < 2 * n; i++) ind[1 << i] = i;
    int ans = dfs(1, MASK(n), MASK(2 * n - 1), MASK(2 * n - 1), n);
    printf("%d\n", ans);
    return 0;
}
