/*************************************************************************
	> File Name: 14.P1096.cpp
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

#define MAX_N 200

class BigInt : public vector<int> {
public :
    BigInt() { push_back(0); }
    BigInt(int x) {
        push_back(x);
        proccess_digit();
    }
    
    BigInt &operator*=(int x) {
        for (int i = 0; i < size(); i++) {
            at(i) *= x;
        }
        proccess_digit();
        return *this;
    }

    BigInt operator*(int x) {
        BigInt ret(*this);
        ret *= x;
        return ret;
    }
    
    BigInt &operator+=(int x) {
        at(0) += x;
        proccess_digit();
        return *this;
    }

    BigInt operator+(int x) {
        BigInt ret(*this);
        ret += x;
        return ret;
    }

private:
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
    f[1] = 2;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] * 2 + 2;
    }
    cout << f[n] << endl;
    return 0;
}
