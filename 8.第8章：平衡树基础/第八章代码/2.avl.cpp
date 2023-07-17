/*************************************************************************
	> File Name: 2.avl.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int key, h;
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)
#define K(n) (n->key)
#define H(n) (n->h)
#define L(n) (n->lchild)
#define R(n) (n->rchild)
__attribute__((constructor))
void init_NIL() {
    NIL->key = -1;
    NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->h = 1;
    p->lchild = p->rchild = NIL;
    return p;
}

void update_height(Node *root) {
    H(root) = (H(L(root)) > H(R(root)) ? H(L(root)) : H(R(root))) + 1;
    return ;
}

Node *left_rotate(Node *root) {
    printf("left rotate : %d\n", root->key);
    Node *new_node = root->rchild;
    root->rchild = new_node->lchild;
    new_node->lchild = root;
    update_height(root);
    update_height(new_node);
    return new_node;
}

Node *right_rotate(Node *root) {
    printf("right rotate : %d\n", root->key);
    Node *new_node = root->lchild;
    root->lchild = new_node->rchild;
    new_node->rchild = root;
    update_height(root);
    update_height(new_node);
    return new_node;
}

const char *type_str[5] = {
    "",
    "maintain type : LL",
    "maintain type : LR",
    "maintain type : RR",
    "maintain type : RL"
};

Node *maintain(Node *root) {
    if (abs(H(L(root)) - H(R(root))) <= 1) return root;
    int type = 0;
    if (H(L(root)) > H(R(root))) {
        if (H(R(L(root))) > H(L(L(root)))) {
            root->lchild = left_rotate(root->lchild);
            type += 1;
        }
        root = right_rotate(root);
        type += 1;
    } else {
        type = 2;
        if (H(L(R(root))) > H(R(R(root)))) {
            root->rchild = right_rotate(root->rchild);
            type += 1;
        }
        root = left_rotate(root);
        type += 1;
    }
    printf("%s\n", type_str[type]);
    return root;
}

Node *insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (key < root->key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    update_height(root);
    return maintain(root);
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NIL) return root;
    if (key < root->key) root->lchild = erase(root->lchild, key);
    else if (key > root->key) root->rchild = erase(root->rchild, key);
    else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild != NIL ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    update_height(root);
    return maintain(root);
}

Node *find(Node *root, int key) {
    if (root == NIL) return NIL;
    if (root->key == key) return root;
    if (key < root->key) return find(root->lchild, key);
    return find(root->rchild, key);
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    printf("(%d[%d] | %d, %d)\n", 
        K(root), H(root), 
        K(L(root)), K(R(root))
    );
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    srand(time(0));
    Node *root = NIL;
    int x;
    // insert
    while (~scanf("%d", &x)) {
        if (x == -1) break;
        printf("insert %d to avl tree\n", x);
        root = insert(root, x);
        output(root);
    }
    // erase
    while (~scanf("%d", &x)) {
        if (x == -1) break;
        printf("erase %d from avl tree\n", x);
        root = erase(root, x);
        output(root);
    }
    // find
    while (~scanf("%d", &x)) {
        if (x == -1) break;
        printf("find %d in avl : %d\n", x, find(root, x) != NIL);
    }
    return 0;
}
