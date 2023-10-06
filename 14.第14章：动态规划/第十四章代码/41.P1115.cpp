/*************************************************************************
	> File Name: 41.P1115.cpp
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

int main() {
    int n, ans = 0x80000000, pre_dp = 0, dp;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (pre_dp > 0) dp = pre_dp + x;
        else dp = x;
        ans = max(dp, ans);
        pre_dp = dp;
    }
    cout << ans << endl;
    return 0;
}
