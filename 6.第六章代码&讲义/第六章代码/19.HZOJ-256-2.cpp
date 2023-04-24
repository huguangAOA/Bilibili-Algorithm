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

#define MAX_N 1000
int a[MAX_N + 5], b[MAX_N + 5], ind[MAX_N + 5];

class BigInt : public vector<int> { // 1234 -> [4, 3, 2, 1]
public :
    BigInt(int x) {
        this->push_back(x);
        proccess_digit();
        return ;
    }
    BigInt operator/(int x) {
        BigInt ret(*this);
        int y = 0;
        for (int i = size() - 1; i >= 0; i--) {
            y = y * 10 + at(i);
            ret[i] = y / x;
            y %= x;
        }
        ret.proccess_digit();
        return ret;
    }
    void operator*=(int x) {
        for (int i = 0; i < size(); i++) at(i) *= x;
        proccess_digit();
        return ;
    }
    bool operator>(const BigInt &a) const {
        if (size() != a.size()) return size() > a.size();
        for (int i = size() - 1; i >= 0; i--) {
            if (at(i) != a[i]) return at(i) > a[i];
        }
        return false;
    }
    void proccess_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) this->push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        while (size() > 1 && at(size() - 1) == 0) this->pop_back();
        return ;
    }
};

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> a[i] >> b[i];
        ind[i] = i;
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
