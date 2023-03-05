/*************************************************************************
	> File Name: 4.haffman.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char ch;
    int freq;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int freq, char ch) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = ch;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

void swap_node(Node **node_arr, int i, int j) {
    Node *temp = node_arr[i];
    node_arr[i] = node_arr[j];
    node_arr[j] = temp;
    return ;
}

int find_min_node(Node **node_arr, int n) {
    int ind = 0;
    for (int j = 1; j <= n; j++) {
        if (node_arr[ind]->freq > node_arr[j]->freq) ind = j;
    }
    return ind;
}

Node *buildHaffmanTree(Node **node_arr, int n) {
    for (int i = 1; i < n; i++) {
        // find two node
        int ind1 = find_min_node(node_arr, n - i);
        swap_node(node_arr, ind1, n - i);
        int ind2 = find_min_node(node_arr, n - i - 1);
        swap_node(node_arr, ind2, n - i - 1);
        // merge two node
        int freq = node_arr[n - i]->freq + node_arr[n - i - 1]->freq;
        Node *node = getNewNode(freq, 0);
        node->lchild = node_arr[n - i - 1];
        node->rchild = node_arr[n - i];
        node_arr[n - i - 1] = node;
    }
    return node_arr[0];
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

#define MAX_CHAR_NUM 128
char *char_code[MAX_CHAR_NUM] = {0};

void extractHaffmanCode(Node *root, char buff[], int k) {
    buff[k] = 0;
    if (root->lchild == NULL && root->rchild == NULL) {
        char_code[root->ch] = strdup(buff);
        return ;
    }
    buff[k] = '0';
    extractHaffmanCode(root->lchild, buff, k + 1);
    buff[k] = '1';
    extractHaffmanCode(root->rchild, buff, k + 1);
    return ;
}

int main() {
    char s[10];
    int n, freq;
    scanf("%d", &n);
    Node **node_arr = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; i++) {
        scanf("%s%d", s, &freq);
        node_arr[i] = getNewNode(freq, s[0]);
    }
    Node *root = buildHaffmanTree(node_arr, n);
    char buff[1000];
    extractHaffmanCode(root, buff, 0);
    for (int i = 0; i < MAX_CHAR_NUM; i++) {
        if (char_code[i] == NULL) continue;
        printf("%c : %s\n", i, char_code[i]);
    }
    clear(root);
    return 0;
}
