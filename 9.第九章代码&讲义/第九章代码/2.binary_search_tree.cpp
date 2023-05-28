/*************************************************************************
	> File Name: 1.binary_search_tree.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <time.h>
using namespace std;

#define KEY(n) (n ? n->key : -1)

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (key == root->key) return root;
    if (key < root->key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NULL) return root;
    if (key < root->key) root->lchild = erase(root->lchild, key);
    else if (key > root->key) root->rchild = erase(root->rchild, key);
    else {
        if (root->lchild == NULL && root->rchild == NULL) {
            free(root);
            return NULL;
        } else if (root->lchild == NULL || root->rchild == NULL) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    return root;
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NULL) return ;
    printf("(%d ; %d, %d)\n", 
        KEY(root), 
        KEY(root->lchild),
        KEY(root->rchild)
    );
    output(root->lchild);
    output(root->rchild);
    return ;
}

void in_order(Node *root) {
    if (root == NULL) return ; // code = 0
    in_order(root->lchild);    // code = 1
    printf("%d ", root->key);  // code = 2
    in_order(root->rchild);    // code = 3
    return ;                   // code = 4
}

struct Data {
    Data(Node *root) : root(root), code(0) {}
    Node *root;
    int code; 
};

void non_in_order(Node *root) {
    stack<Data> s;
    Data d(root);
    s.push(d);
    while (!s.empty()) {
        Data &cur = s.top();
        switch (cur.code) {
            case 0: {
                if (cur.root == NULL) {
                    s.pop();
                } else {
                    cur.code = 1;
                }
            } break;
            case 1: {
                Data d(cur.root->lchild);
                cur.code = 2;
                s.push(d);
            } break;
            case 2: {
                printf("%d ", cur.root->key);
                cur.code = 3;
            } break;
            case 3: {
                Data d(cur.root->rchild);
                cur.code = 4;
                s.push(d);
            } break;
            case 4: {
                s.pop();
            } break;
        }
    }
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 10
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int key = rand() % 100;
        printf("insert key %d to BST\n", key);
        root = insert(root, key);
    }
    output(root);
    printf("in order : \n");
    in_order(root);
    printf("\n");
    non_in_order(root);
    printf("\n");
    
    int x;
    while (~scanf("%d", &x)) {
        printf("erase %d from BST\n", x);
        root = erase(root, x);
        in_order(root); printf("\n");
    }
    return 0;
}
