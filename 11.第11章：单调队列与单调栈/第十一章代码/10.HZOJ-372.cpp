/*************************************************************************
	> File Name: 10.HZOJ-372.cpp
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
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    deque<int> ap, bp;
    int p;
    for (p = 0; p < n; p++) {
        while (!ap.empty() && a[p] <= ap.back()) ap.pop_back();
        while (!bp.empty() && b[p] <= bp.back()) bp.pop_back();
        ap.push_back(a[p]);
        bp.push_back(b[p]);
        if (ap.size() != bp.size()) break;
    }
    printf("%d\n", p);
    return 0;
}
