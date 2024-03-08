/*************************************************************************
	> File Name: 7.shift_and.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 五  3/ 8 10:20:04 2024
 ************************************************************************/

#include <iostream>
using namespace std;

#define TEST(func, s, t) { \
    printf("%s(%s, %s) = %d\n", #func, s, t, func(s, t)); \
}

int shift_and(const char *s, const char *t) {
    int code[256] = {0}, n = 0;
    for (n = 0; t[n]; n++) code[t[n]] |= (1 << n);
    int p = 0;
    for (int i = 0; s[i]; i++) {
        p = (p << 1 | 1) & code[s[i]];
        if (p & (1 << (n - 1))) return i - n + 1;
    }
    return -1;
}

int main() {
    char s[100], t[100];
    while (~scanf("%s%s", s, t)) {
        TEST(shift_and, s, t);
    }
    return 0;
}
