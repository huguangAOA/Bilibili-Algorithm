/*************************************************************************
	> File Name: 1.HZOJ-184.cpp
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

int f(int n) {
    if (n == 1) return 1;
    return (f(n - 1) + 1) * 2;
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
