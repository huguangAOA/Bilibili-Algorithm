/*************************************************************************
	> File Name: 8.fenwick_tree.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 二  7/ 2 17:36:11 2024
 ************************************************************************/

#include <iostream>
using namespace std;

#define lowbit(x) (x & (-x))

int a[10000];
int c[10000];

void add(int i, int x, int n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
    return ;
}

int query(int i) {
    int sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(i, a[i], n);
    }
    cout << "a : ";
    for (int i = 1; i <= n; i++) {
        printf("%4d", a[i]);
    }
    cout << endl;
    cout << "c : ";
    for (int i = 1; i <= n; i++) {
        printf("%4d", c[i]);
    }
    cout << endl;
    cout << "s : ";
    for (int i = 1; i <= n; i++) {
        printf("%4d", query(i));
    }
    cout << endl;
    
    return 0;
}
