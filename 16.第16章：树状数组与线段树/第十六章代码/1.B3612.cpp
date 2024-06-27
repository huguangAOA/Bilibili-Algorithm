/*************************************************************************
	> File Name: 1.B3612.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 四  6/27 21:56:52 2024
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 100000
int a[MAX_N + 5];
int n, m;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    cin >> m;
    for (int i = 1, l, r; i <= m; i++) {
        cin >> l >> r;
        cout << a[r] - a[l - 1] << endl;
    }
    return 0;
}
