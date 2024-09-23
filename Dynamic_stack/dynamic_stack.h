#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include <stdio.h>
#include <stdlib.h>

#define tp_stack int

struct node {
    tp_stack data;
    struct node *under;
};

typedef struct node Node;

typedef struct {
    Node *top;
    int size;
} Dynamic_stack;

Dynamic_stack *init_stack() {
    Dynamic_stack *ds = (Dynamic_stack *) malloc(sizeof(Dynamic_stack));
    ds -> top = NULL;
    ds -> size = 0;

    return ds;
}

int is_empty(Dynamic_stack *ds) {
    return ds -> top == NULL;
}

int get_size(Dynamic_stack *ds) {
    return ds -> size;
}

int show(Dynamic_stack *ds) {
    Node *aux = ds -> top;
    while (aux != NULL) {
        printf("%i\n", aux -> data);
        aux = aux -> under;
    }
    printf("\n");

    return 0;
}

int push(Dynamic_stack *ds, tp_stack value) {
    Node *node = (Node *) malloc(sizeof(Node));
    node -> data = value;
    node -> under = ds -> top;
    ds -> top = node;

    ds -> size++;
    return 0;
}

int pop(Dynamic_stack *ds) {
    if (is_empty(ds)) return -1;
    Node *aux = ds -> top;
    ds -> top = aux -> under;
    int value = aux -> data;
    free(aux);
    return value;
}

int clear_stack(Dynamic_stack *ds) {
    while (!is_empty(ds)) pop(ds);

    return 0;
}

#endif