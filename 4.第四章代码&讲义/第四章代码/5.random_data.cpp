/*************************************************************************
	> File Name: 5.random_data.cpp
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
    srand(time(0));
    printf("26\n");
    for (int i = 0; i < 26; i++) {
        printf("%c %d\n", 'a' + i, rand() % 100000);
    }
    return 0;
}
