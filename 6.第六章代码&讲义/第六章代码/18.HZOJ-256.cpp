/*************************************************************************
	> File Name: 18.HZOJ-256.cpp
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

#define BASE 10000
#define MAX_N 1000
int a[MAX_N + 5], b[MAX_N + 5], ind[MAX_N + 5];

class BigInt : public vector<int> { // 1234 -> [4, 3, 2, 1]
public :
    BigInt(int x) {
        this->push_back(x);
        proccess_digit();
        return ;
    }
    void output_digit(int x, bool flag, ostream &out) const {
        if (flag) {
            out << x;
            return ;
        }
        int y = BASE / 10;
        while (y) {
            out << x / y;
            x %= y;
            y /= 10;
        }
        return ;
    }
    void output(ostream &out) const {
        for (int i = size() - 1; i >= 0; i--) {
            output_digit(at(i), i == size() - 1, out);
        }
        return ;
    }
    bool operator>(const BigInt &obj) const {
        if (size() != obj.size()) return size() > obj.size();
        for (int i = size() - 1; i >= 0; i--) {
            if (at(i) != obj[i]) return at(i) > obj[i];
        }
        return false;
    }
    void operator*=(int x) {
        for (int i = 0; i < size(); i++) {
            at(i) *= x;
        }
        proccess_digit();
        return ;
    }
    BigInt operator/(int x) const {
        int y = 0;
        BigInt ret(*this);
        for (int i = size() - 1; i >= 0; i--) {
            y = y * BASE + at(i);
            ret[i] = y / x;
            y %= x;
        }
        ret.proccess_digit();
        return ret;
    }
    void proccess_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < BASE) continue;
            if (i + 1 == size()) this->push_back(0);
            at(i + 1) += at(i) / BASE;
            at(i) %= BASE;
        }
        while (size() > 1 && at(size() - 1) == 0) {
            this->pop_back();
        }
        return ;
    }
};

ostream &operator<<(ostream &out, const BigInt &a) {
    a.output(out);
    return out;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        ind[i] = i;
        cin >> a[i] >> b[i];
    }
    sort(ind + 1, ind + n + 1, [&](int i, int j) -> bool {
        return a[i] * b[i] < a[j] * b[j];
    });
    BigInt p = a[0], ans = 0, temp = 0;
    for (int i = 1; i <= n; i++) {
        temp = p / b[ind[i]];
        if (temp > ans) ans = temp;
        p *= a[ind[i]];
    }
    cout << ans << endl;
    return 0;
}
