/*************************************************************************
	> File Name: 7.lowbit.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 二  7/ 2 17:17:35 2024
 ************************************************************************/

#include <iostream>
using namespace std;

#define lowbit(x) ((x) & (-x))

int main() {
    int x;
    cin >> x;
    cout << x << " = ";
    while (x) {
        cout << lowbit(x);
        x -= lowbit(x);
        if (x) cout << " + ";
    }
    cout << endl;
    return 0;
}
