/*************************************************************************
	> File Name: 19.HZOJ-691.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 一  7/29 12:05:12 2024
 ************************************************************************/

#include <iostream>
using namespace std;

int n;
int a[100005];

int main() {
    int n, ans;
    cin >> n;
    cin >> a[1];
    ans = a[1];
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        if (a[i] > a[i - 1]) {
            ans += (a[i] - a[i - 1]);
        }
    }
    cout << ans << endl;
    return 0;
}
