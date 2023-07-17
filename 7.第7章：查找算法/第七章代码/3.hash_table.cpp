/*************************************************************************
	> File Name: 3.hash_table.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define swap(a, b) { \
    __typeof(a) __c = a; \
    a = b, b = __c; \
}

typedef struct Node {
    char *s;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node *data;
    int cnt, size;
} HashTable;

void expand(HashTable *h);
void clearHashTable(HashTable *h);

Node *getNewNode(const char *s) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->s = strdup(s);
    p->next = NULL;
    return p;
}

HashTable * getNewHashTable(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->data = (Node *)malloc(sizeof(Node) * n);
    h->size = n;
    h->cnt = 0;
    return h;
}

int hash_func(const char *s) {
    int seed = 131, h = 0;
    for (int i = 0; s[i]; i++) {
        h = h * seed + s[i];
    }
    return h & 0x7fffffff;
}

bool find(HashTable *h, const char *s) {
    int hcode = hash_func(s), ind = hcode % h->size;
    Node *p = h->data[ind].next;
    while (p) {
        if (strcmp(p->s, s) == 0) return true;
        p = p->next;
    }
    return false;
}


bool insert(HashTable *h, const char *s) {
    if (h->cnt >= h->size * 2) {
        expand(h);
    }
    int hcode = hash_func(s), ind = hcode % h->size;
    Node *p = getNewNode(s);
    p->next = h->data[ind].next;
    h->data[ind].next = p;
    h->cnt += 1;
    return true;
}

void swapHashTable(HashTable *h1, HashTable *h2) {
    swap(h1->data, h2->data);
    swap(h1->cnt,  h2->cnt);
    swap(h1->size, h2->size);
    return ;
}

void expand(HashTable *h) {
    printf("expand Hash Table %d -> %d\n", h->size, h->size * 2);
    HashTable *new_h = getNewHashTable(h->size * 2);
    for (int i = 0; i < h->size; i++) {
        Node *p = h->data[i].next;
        while (p) {
            insert(new_h, p->s);
            p = p->next;
        }
    }
    swapHashTable(h, new_h);
    clearHashTable(new_h);
    return ;
}

void clearNode(Node *p) {
    if (p == NULL) return ;
    if (p->s) free(p->s);
    free(p);
    return ;
}

void clearHashTable(HashTable *h) {
    if (h == NULL) return ;
    for (int i = 0; i < h->size; i++) {
        Node *p = h->data[i].next, *q;
        while (p) {
            q = p->next;
            clearNode(p);
            p = q;
        }
    }
    free(h->data);
    free(h);
    return ;
}

void output(HashTable *h) {
    printf("\n\nHash Table(%d / %d) : \n", h->cnt, h->size);
    for (int i = 0; i < h->size; i++) {
        printf("%d : ", i);
        Node *p = h->data[i].next;
        while (p) {
            printf("%s -> ", p->s);
            p = p->next;
        }
        printf("\n");
    }
    return ;
}

int main() {
    srand(time(0));
    char s[100];
    #define MAX_N 2
    HashTable *h = getNewHashTable(MAX_N);
    while (~scanf("%s", s)) {
        if (strcmp(s, "end") == 0) break;
        insert(h, s);
    }
    output(h);
    while (~scanf("%s", s)) {
        printf("find(%s) = %d\n", s, find(h, s));
    }
    #undef MAX_N
    return 0;
}
