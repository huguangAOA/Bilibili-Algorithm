/*************************************************************************
	> File Name: 9.HZOJ-259.cpp
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

#define MAX_N 100000

struct Data {
    int x, y;
};
Data task[MAX_N + 5], ma[MAX_N + 5];
int cnt[105] = {0};

bool cmp(const Data &a, const Data &b) {
    if (a.x - b.x) return a.x > b.x;
    return a.y > b.y;
}

int main() {
    int n, m;
    long long ans = 0, task_cnt = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &ma[i].x, &ma[i].y);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &task[i].x, &task[i].y);
    }
    sort(ma, ma + n, cmp);
    sort(task, task + m, cmp);
    for (int i = 0, j = 0; i < m; i++) {
        while (j < n && ma[j].x >= task[i].x) {
            cnt[ma[j].y] += 1;
            j += 1;
        }
        for (int y = task[i].y; y <= 100; y++) {
            if (cnt[y] == 0) continue;
            cnt[y] -= 1;
            ans += 500 * task[i].x + 2 * task[i].y;
            task_cnt += 1;
            break;
        }
    }
    cout << task_cnt << " " << ans << endl;
    return 0;
}
