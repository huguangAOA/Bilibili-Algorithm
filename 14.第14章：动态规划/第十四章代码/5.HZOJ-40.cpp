/*************************************************************************
	> File Name: 5.HZOJ-40.cpp
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

#define MAX_N 500

class BigInt : public vector<int> {
public :
    BigInt() { push_back(0); }
    BigInt(int x) {
        push_back(x);
        proccess_digit();
        return ;
    }

    BigInt &operator+=(const BigInt &a) {
        for (int i = 0; i < a.size(); i++) {
            if (i < size()) at(i) += a[i];
            else push_back(a[i]);
        }
        proccess_digit();
        return *this;
    }
    BigInt operator+(const BigInt &a) {
        BigInt ret(*this);
        ret += a;
        return ret;
    }

    void proccess_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        return ;
    }
};

BigInt f[MAX_N + 5];

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;
}

int main() {
    int n;
    cin >> n;
    f[0] = 1;
    f[1] = 0;
    f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 2] + f[i - 3];
    }
    cout << f[n] << endl;
    return 0;
}
