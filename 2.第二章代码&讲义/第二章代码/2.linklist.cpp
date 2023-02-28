/*************************************************************************
	> File Name: 2.linklist.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DL 3
#define STR(n) #n
#define DIGIT_LEN_STR(n) "%" STR(n) "d"

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

Node *insert(Node *head, int pos, int val) {
    Node new_head, *p = &new_head, *node = getNewNode(val);
    new_head.next = head;
    for (int i = 0; i < pos; i++) p = p->next;
    node->next = p->next;
    p->next = node;
    return new_head.next;
}

void clear(Node *head) {
    if (head == NULL) return ;
    for (Node *p = head, *q; p; p = q) {
        q = p->next;
        free(p);
    }
    return ;
}

void output_linklist(Node *head, int flag = 0) {
    int n = 0;
    for (Node *p = head; p; p = p->next) n += 1;
    for (int i = 0; i < n; i++) {
        printf(DIGIT_LEN_STR(DL), i);
        printf("  ");
    }
    printf("\n");
    for (Node *p = head; p; p = p->next) {
        printf(DIGIT_LEN_STR(DL), p->data);
        printf("->");
    }
    printf("\n");
    if (flag == 0) printf("\n\n");
    return ;
}

int find(Node *head, int val) {
    Node *p = head;
    int n = 0;
    while (p) {
        if (p->data == val) {
            output_linklist(head, 1);
            int len = n * (DL + 2) + 2;
            for (int i = 0; i < len; i++) printf(" ");
            printf("^\n");
            for (int i = 0; i < len; i++) printf(" ");
            printf("|\n");
            return 1;
        }
        n += 1;
        p = p->next;
    }
    return 0;
}

int main() {
    srand(time(0));
    #define MAX_OP 7
    Node *head = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int pos = rand() % (i + 1), val = rand() % 100;
        printf("insert %d at %d to linklist\n", val, pos);
        head = insert(head, pos, val);
        output_linklist(head);
    }
    int val;
    while (~scanf("%d", &val)) {
        if (!find(head, val)) {
            printf("not found\n");
        }
    }
    clear(head);
    return 0;
}
