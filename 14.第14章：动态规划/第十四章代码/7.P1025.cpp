/*************************************************************************
	> File Name: 7.P1025.cpp
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

#define MAX_N 200
#define MAX_K 6

int f[MAX_N + 5][MAX_K + 5] = {0};

int main() {
    int n, k;
    cin >> n >> k;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i][1] = 1;
        for (int j = 2, J = min(i, k); j <= J; j++) {
            f[i][j] = f[i - 1][j - 1] + f[i - j][j];
        }
    }
    cout << f[n][k] << endl;
    return 0;
}
