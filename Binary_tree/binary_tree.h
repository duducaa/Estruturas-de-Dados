#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

#define tp_tree int

struct node {
    tp_tree data;
    struct node *left, *right;
};

typedef struct node Node;

typedef struct {
    Node *root;
} Binary_tree;

Binary_tree *init_tree() {
    Binary_tree *bt = (Binary_tree *) malloc(sizeof(Binary_tree));
    bt -> root = NULL;

    return bt;
}

int _pre_order(Node *root) {
    if (root != NULL) {
        printf("%i ", root -> data);
        _pre_order(root -> left);
        _pre_order(root -> right);
    }
    printf("\n");

    return 0;
}
int pre_order(Binary_tree *bt) {
    _pre_order(bt -> root);
    return 0;
}

int _in_order(Node *root) {
    if (root != NULL) {
        _in_order(root -> left);
        printf("%i ", root -> data);
        _in_order(root -> right);
    }
    printf("\n");

    return 0;
}
int in_order(Binary_tree *bt) {
    _in_order(bt -> root);
    return 0;
}

int _post_order(Node *root) {
    if (root != NULL) {
        _post_order(root -> left);
        _post_order(root -> right);
        printf("%i ", root -> data);
    }
    printf("\n");

    return 0;
}
int post_order(Binary_tree *bt) {
    _post_order(bt -> root);
    return 0;
}

int insert(Binary_tree *bt, tp_tree value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node -> data = value;
    new_node -> left = new_node -> right = NULL;

    return 0;
}

#endif