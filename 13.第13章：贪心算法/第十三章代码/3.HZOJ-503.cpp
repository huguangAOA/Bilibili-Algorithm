/*************************************************************************
	> File Name: 3.HZOJ-503.cpp
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
    int w, n;
    cin >> w >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int i = 0, j = n - 1, cnt = 0;
    while (i < j) {
        if (arr[i] + arr[j] <= w) {
            i++, j--;
        } else {
            j--;
        }
        cnt += 1;
    }
    if (i == j) cnt += 1;
    cout << cnt << endl;
    return 0;
}
