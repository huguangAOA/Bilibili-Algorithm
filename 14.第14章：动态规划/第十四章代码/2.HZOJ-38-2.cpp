/*************************************************************************
	> File Name: 2.HZOJ-38-2.cpp
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

long long f[105] = {0};

int main() {
    int n;
    cin >> n;
    f[1] = 1; 
    f[2] = 2;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n] << endl;
    return 0;
}
