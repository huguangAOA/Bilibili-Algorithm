/*************************************************************************
	> File Name: 15.HZOJ-287.cpp
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

typedef pair<int, int> PII;

int main() {
    int n;
    set<PII> s;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        s.insert(PII(a, i));
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int a = s.begin()->first;
        s.erase(s.begin());
        int b = s.begin()->first;
        s.erase(s.begin());
        ans += a + b;
        s.insert(PII(a + b, n + i));
    }
    cout << ans << endl;
    return 0;
}
