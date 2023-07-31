/*************************************************************************
	> File Name: 4.HZOJ-258.cpp
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
#include <cinttypes>
using namespace std;

#define MAX_N 100
int arr[MAX_N + 5][MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            arr[i][j] += arr[i - 1][j];
        }
    }
    int ans = INT32_MIN;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int S = 0;
            for (int k = 1; k <= n; k++) {
                int a = arr[j][k] - arr[i - 1][k];
                if (S >= 0) S += a;
                else S = a;
                if (S > ans) ans = S;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
