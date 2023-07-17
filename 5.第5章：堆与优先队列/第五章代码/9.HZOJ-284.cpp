/*************************************************************************
	> File Name: 9.HZOJ-284.cpp
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

struct Data {
    Data(int p, int d) : p(p), d(d) {}
    int p, d;
    bool operator<(const Data &obj) const {
        if (d != obj.d) return d < obj.d;
        return p > obj.p;
    }
};

typedef pair<int, int> PII;

int main() {
    int n;
    cin >> n;
    vector<Data> arr;
    set<PII> s;
    for (int i = 0, p, d; i < n; i++) {
        cin >> p >> d;
        arr.push_back(Data(p, d));
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        if (arr[i].d > s.size()) {
            s.insert(PII(arr[i].p, i));
        } else {
            if (arr[i].p > s.begin()->first) {
                s.erase(s.begin());
                s.insert(PII(arr[i].p, i));
            }
        }
    }
    int ans = 0;
    for (auto x : s) {
        ans += x.first;
    }
    cout << ans << endl;
    return 0;
}
