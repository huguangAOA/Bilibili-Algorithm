/*************************************************************************
	> File Name: 9.double_array_trie.cpp
	> Author: hug
	> Mail: hug@haizeix.com
	> Created Time: 日  3/10 17:09:08 2024
 ************************************************************************/

#include <iostream>
using namespace std;

#define BASE 26
#define MAX_N 100000

typedef struct DANode {
    int base, check;
} DANode;
DANode trie[MAX_N + 5];
int da_trie_root = 1;

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

int find(DANode *trie, const char *s) {
    int p = da_trie_root;
    for (int i = 0; s[i]; i++) {
        int ind = trie[p].base + s[i] - 'a';
        if (abs(trie[ind].check) != p) return 0;
        p = ind;
    }
    return trie[p].check < 0;
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

int get_base(Node *root, int ind, DANode *trie) {
    int base = 2;
    do {
        int flag = 1;
        for (int i = 0; i < BASE; i++) {
            if (root->next[i] == NULL) continue;
            if (trie[base + i].check == 0) continue;
            flag = 0;
            break;
        }
        if (flag == 1) break;
        base += 1;
    } while (1);
    return base;
}

void convert_to_double_array_trie(Node *root, int ind, DANode *trie) {
    trie[ind].base = get_base(root, ind, trie);
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        trie[trie[ind].base + i].check = (root->next[i]->flag ? -ind : ind);
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        convert_to_double_array_trie(
            root->next[i], 
            trie[ind].base + i,
            trie
        );
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
    convert_to_double_array_trie(root, da_trie_root, trie);
    while (scanf("%s", s) != EOF) {
        printf("find %s from double array trie : %d\n", s, find(trie, s));
    }
    clear(root);
    return 0;
}
