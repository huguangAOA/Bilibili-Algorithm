/*************************************************************************
	> File Name: 1.HZOJ-43-1.cpp
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

#define MAX_N 1000
int val[MAX_N + 5][MAX_N + 5];
int f[MAX_N + 5][MAX_N + 5];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &val[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) f[n][i] = val[n][i];
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + val[i][j];
        }
    }
    //for (int i = 1; i <= n; i++) {
    //    for (int j = 1; j <= i; j++) {
    //        printf("%3d", f[i][j]);
    //    }
    //    printf("\n");
    //}
    printf("%d\n", f[1][1]);
    return 0;
}
