/*************************************************************************
	> File Name: 1.adjacency_list.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 日 11/10 17:55:40 2024
 ************************************************************************/

#include <iostream>
using namespace std;

struct Edge {
    int to, nxt;
} e[1005];
int head[1005], cnt = 0;
void add(int a, int b) {
    e[++cnt] = {b, head[a]};
    head[a] = cnt;
    return ;
}

void output(int ind) {
    cout << ind << " : ";
    for (int p = head[ind]; p; p = e[p].nxt) {
        int to = e[p].to;
        cout << to << " ";
    }
    cout << endl;
    return ;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        add(a, b);
    }
    for (int i = 1; i <= n; i++) {
        output(i);
    }
    return 0;
}
