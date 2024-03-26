/*************************************************************************
	> File Name: 11.ac.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 二  3/26 21:10:59 2024
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

#define BASE 26

typedef struct Node {
    int flag;
    struct Node *next[26];
    struct Node *fail;
    const char *s;
} Node;

vector<Node *> node_vec;

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    p->fail = NULL;
    p->s = NULL;
    for (int i = 0; i < BASE; i++) p->next[i] = NULL;
    node_vec.push_back(p);
    return p;
}

void insert(Node *root, const char *s) {
    Node *p = root;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        if (p->next[ind] == NULL) p->next[ind] = getNewNode();
        p = p->next[ind];
    }
    p->s = strdup(s);
    p->flag = 1;
    return ;
}

void build_ac(Node *root) {
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *cur = q.front(), *p;
        q.pop();
        for (int i = 0; i < BASE; i++) {
            if (cur->next[i] == NULL) {
                if (cur == root) cur->next[i] = root;
                else cur->next[i] = cur->fail->next[i];
                continue;
            }
            p = cur->fail;
            if (p == NULL) p = root;
            else p = p->next[i];
            cur->next[i]->fail = p;
            q.push(cur->next[i]);
        }
    }
    return ;
}

void find_ac(Node *root, const char *s) {
    Node *p = root, *q;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        p = p->next[ind];
        q = p;
        while (q) {
            if (q->flag) {
                int len = strlen(q->s);
                printf("find [%d, %d] = %s\n", i - len + 1, i, q->s);
            }
            q = q->fail;
        }
    }
    return ;
}

void clear() {
    for (int i = 0; i < node_vec.size(); i++) {
        free(node_vec[i]);
    }
    return ;
}

int main() {
    int n;
    char s[100];
    Node *root = getNewNode();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        insert(root, s);
    }
    build_ac(root);
    scanf("%s", s);
    find_ac(root, s);
    clear();
    return 0;
}
