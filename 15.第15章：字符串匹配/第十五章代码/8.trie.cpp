/*************************************************************************
	> File Name: 8.trie.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 日  3/10 17:09:08 2024
 ************************************************************************/

#include <iostream>
using namespace std;

#define BASE 26

typedef struct Node {
    struct Node *next[BASE];
    int flag;
} Node;

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    for (int i = 0; i < BASE; i++) p->next[i] = NULL;
    p->flag = 0;
    return p;
}

void insert(Node *root, const char *s) {
    Node *p = root;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        if (p->next[ind] == NULL) p->next[ind] = getNewNode();
        p = p->next[ind];
    }
    p->flag = 1;
    return ;
}

int find(Node *root, const char *s) {
    Node *p = root;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        p = p->next[ind];
        if (p == NULL) return 0;
    }
    return p->flag;
}

void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) clear(root->next[i]);
    free(root);
    return ;
}

void output(Node *root, int k, char *buff) {
    buff[k] = 0;
    if (root->flag) {
        printf("find : %s\n", buff);
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        buff[k] = i + 'a';
        output(root->next[i], k + 1, buff);
    }
    return ;
}

int main() {
    int op;
    char s[100];
    Node *root = getNewNode();
    do {
        cin >> op;
        if (op == 3) break;
        cin >> s;
        switch (op) {
            case 1: {
                printf("insert %s to trie\n", s);
                insert(root, s);
            } break;
            case 2: {
                printf("find %s from trie : %d\n",s, find(root, s));
            } break;
        }
    } while (1);
    output(root, 0, s);
    clear(root);
    return 0;
}
