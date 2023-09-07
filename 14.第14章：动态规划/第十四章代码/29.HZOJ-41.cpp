/*************************************************************************
	> File Name: 29.HZOJ-41.cpp
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

class BigInt : public vector<int>{
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

    BigInt &operator*=(const int x) {
        for (int i = 0; i < size(); i++) at(i) *= x;
        proccess_digit();
        return *this;
    }

    BigInt operator*(const int x) {
        BigInt ret(*this);
        ret *= x;
        return ret;
    }

private :
    void proccess_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 100000) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 100000;
            at(i) %= 100000;
        }
        return ;
    }
};

ostream &operator<<(ostream &out, const BigInt &a) {
    out << a[a.size() - 1];
    for (int i = int(a.size()) - 2; i >= 0; i--) {
        int num = a[i];
        for (int j = 10000; j > 0; j /= 10) {
            out << a[i] % (j * 10) / j;
        }
    }
    return out;
}

#define MAX_N 1000
BigInt f[MAX_N + 5];

int main() {
    int n, k;
    cin >> n >> k;
    f[1] = k;
    f[2] = k * (k - 1);
    f[3] = k * (k - 1) * (k - 2);
    for (int i = 4; i <= n; i++) {
        f[i] = f[i - 1] * (k - 2);
        f[i] += f[i - 2] * (k - 1);
    }
    cout << f[n] << endl;
    return 0;
}
