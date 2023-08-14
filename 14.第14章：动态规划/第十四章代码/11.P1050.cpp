/*************************************************************************
	> File Name: 11.P1050.cpp
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
    int n, k, base = 1, x, y;
    cin >> n >> k;
    for (int i = 0; i < k; i++, base *= 10) ;
    x = n % base;
    y = x;
    int cnt = 1;
    while (x * y % base != x) {
        cout << "y = " << y << "(" << cnt << "), ";
        y = y * x % base;
        cnt += 1;
        if ((cnt - 1) % 4 == 0) cout << endl;
    }
    cout << cnt << endl;
    return 0;
}
