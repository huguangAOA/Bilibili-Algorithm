/*************************************************************************
	> File Name: 9.P1032.cpp
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

int main() {
    string a = "abcdefgcde", b = "cde", c = "xxx";
    cout << a << " " << b << endl;
    int pos = -1;
    while (1) {
        pos = a.find(b, pos + 1);
        cout << pos << endl;
        if (pos == -1) break;
        a.erase(pos, b.size());
        a.insert(pos, c);
    }
    cout << a << endl;
    return 0;
}
