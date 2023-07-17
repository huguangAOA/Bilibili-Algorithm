/*************************************************************************
	> File Name: 12.HZOJ-266.cpp
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
#include <cmath>
using namespace std;

#define INF 0x3f3f3f3f
#define DEBUG 0

#if DEBUG
void output(string &s, int l, int r) {
    for (int i = l; i < r; i++) {
        cout << s[i];
    }
    cout << endl;
    return ;
}
#endif

bool is_operator(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^': return true;
        default : return false;
    }
    return false;
}

long long calc(string &s, long long l, long long r) {
    #if DEBUG
    cout << s << " " << l << " " << r << " : "; output(s, l, r);
    #endif
    long long pos = -1, pri = INF - 1, cur_pri, temp_pri = 0;
    for (long long i = l; i < r; i++) {
        cur_pri = INF;
        switch (s[i]) {
            case '(' : temp_pri += 100; break;
            case ')' : temp_pri -= 100; break;
            case '+' : 
            case '-' : cur_pri = 1 + temp_pri; break;
            case '*' :
            case '/' : cur_pri = 2 + temp_pri; break;
            case '^' : cur_pri = 3 + temp_pri; break;
        }
        if ((s[i] == '-' || s[i] == '+') && 
            (i - 1 < 0 || is_operator(s[i - 1]))
        ) {
            cur_pri += 1000;
        }
        if (pri >= cur_pri) {
            pri = cur_pri;
            pos = i;
        }
    }
    if (pos == -1) {
        long long num = 0;
        for (long long i = l; i < r; i++) {
            if (s[i] < '0' || s[i] > '9') continue;
            num = num * 10 + (s[i] - '0');
        }
        return num;
    } else {
        long long a = calc(s, l, pos);
        long long b = calc(s, pos + 1, r);
        switch (s[pos]) {
            case '+' : return a + b;
            case '-' : return a - b;
            case '*' : return a * b;
            case '/' : return a / b;
            case '^' : return pow(a, b);
        }
    }
    return 0;
}

int main() {
    string str;
    cin >> str;
    cout << calc(str, 0, str.size()) << endl;
    return 0;
}
