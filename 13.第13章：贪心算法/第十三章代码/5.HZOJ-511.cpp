/*************************************************************************
	> File Name: 5.HZOJ-511.cpp
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
    long long a, b, k, ans = 0;
    cin >> a >> b >> k;
    if (k == 1) {
        cout << b - a << endl;
        return 0;
    }
    if (k == 0) {
        if (b != 0) cout << b - a << endl;
        else cout << !!(a) << endl;
        return 0;
    }
    while (1) {
        if (a * k <= b) {
            ans += 1 + b % k;
            b /= k;
        } else {
            ans += b - a;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
