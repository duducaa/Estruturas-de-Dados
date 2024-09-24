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

    return 0;
}
int pre_order(Binary_tree *bt) {
    _pre_order(bt -> root);
    printf("\n");
    return 0;
}

int _in_order(Node *root) {
    if (root != NULL) {
        _in_order(root -> left);
        printf("%i ", root -> data);
        _in_order(root -> right);
    }

    return 0;
}
int in_order(Binary_tree *bt) {
    _in_order(bt -> root);
    printf("\n");
    return 0;
}

int _post_order(Node *root) {
    if (root != NULL) {
        _post_order(root -> left);
        _post_order(root -> right);
        printf("%i ", root -> data);
    }

    return 0;
}
int post_order(Binary_tree *bt) {
    _post_order(bt -> root);
    printf("\n");
    return 0;
}

int insert(Binary_tree *bt, tp_tree value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node -> data = value;
    new_node -> left = new_node -> right = NULL;

    Node *aux1, *aux2;
    aux1 = NULL;
    aux2 = bt -> root;

    while (aux2 != NULL) {
        aux1 = aux2;
        if (value < aux2 -> data) aux2 = aux2 -> left;
        else aux2 = aux2 -> right;
    }

    if (aux1 == NULL) bt -> root = new_node;
    else {
        if (value < aux1 -> data) aux1 -> left = new_node;
        else aux1 -> right = new_node;
    }

    return 0;
}

int remove(Binary_tree *bt, tp_tree value) {
    Node *aux, *trash, *ant, *sub, *sub_sub;
    aux = NULL;
    trash = bt -> root;

    // find the node
    while (trash != NULL && trash -> data != value) {
        aux = trash;
        if (trash -> data < value) trash = trash -> left;
        else trash = trash -> right;
    }

    // find the number of child nodes
    if (trash == NULL) return -1;
    if (trash -> left == NULL) sub = trash -> right;
    else if (trash -> right == NULL) sub = trash -> left;
    else {
        ant = trash;
        sub = trash -> right;
        sub_sub = sub -> left;
        
        /* find the node with the value immediatly after the value
            of the trash node */
        while (sub_sub != NULL) {
            ant = sub;
            sub = sub_sub;
            sub_sub = sub_sub -> left;
        }

        // if the node founded previously have more than one child
        if (ant != trash) {
            ant -> left = sub -> right;
            sub -> right = trash -> right;
        }
        sub -> left = trash -> left;
    }

    if (aux == NULL) bt -> root = sub;
    else if (trash == aux -> right) aux -> right = sub;
    else aux -> left = sub;

    free(trash);

    return 0;
}

#endif