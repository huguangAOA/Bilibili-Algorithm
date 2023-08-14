/*************************************************************************
	> File Name: 1.HZOJ-38.cpp
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

#define MAX_N 100
long long arr[MAX_N + 5] = {0};
long long f(int n) {
    if (n <= 2) return n;
    if (arr[n]) return arr[n];
    arr[n] = f(n - 1) + f(n - 2);
    return arr[n];
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
