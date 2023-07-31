/*************************************************************************
	> File Name: 8.HZOJ-253.cpp
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

#define MAX_N 2500

struct Data {
    int a, b;
};

Data cow[MAX_N + 5], item[MAX_N + 5];

bool cmp(const Data &a, const Data &b) {
    if (a.b != b.b) return a.b < b.b;
    return a.a < b.a;
}

int main() {
    int C, L;
    cin >> C >> L;
    for (int i = 0; i < C; i++) {
        cin >> cow[i].a >> cow[i].b;
    }
    for (int i = 0; i < L; i++) {
        cin >> item[i].b >> item[i].a;
    }
    sort(item, item + L, cmp);
    sort(cow, cow + C, cmp);
    int ans = 0;
    for (int i = 0; i < C; i++) {
        int flag = 0;
        for (int j = 0; j < L; j++) {
            if (item[j].a == 0) continue;
            if (item[j].b <= cow[i].b && item[j].b >= cow[i].a) {
                flag = 1;
                item[j].a -= 1;
                break;
            }
        }
        ans += flag;
    }
    cout << ans << endl;
    return 0;
}
