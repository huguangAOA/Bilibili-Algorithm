/*************************************************************************
	> File Name: 2.HZOJ-186.cpp
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

int f(int i, vector<int> &arr, int n) {
    if (i >= n) return 0;
    return f(i + arr[i], arr, n) + 1;
}

int main() {
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    cout << f(0, arr, n) << endl;
    return 0;
}
