#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define tp_queue int

struct node {
    tp_queue data;
    struct node *next;
};

typedef struct node Node;

typedef struct {
    int size;
    Node *first, *last;
} Dynamic_queue;

Dynamic_queue *init_queue() {
    Dynamic_queue *dq = (Dynamic_queue *) malloc(sizeof(Dynamic_queue));
    dq -> size;
    dq -> first = dq -> last = NULL;

    return dq;
}

int is_empty(Dynamic_queue *dq) {
    return dq -> first == NULL;
}

int get_size(Dynamic_queue *dq) {
    return dq -> size;
}

int show (Dynamic_queue *dq) {
    Node *aux = dq -> first;

    while (aux != NULL) {
        printf("%i ", aux -> data);
        aux = aux -> next;
    }
    printf("\n");

    return 0;
}

int insert_queue(Dynamic_queue *dq, tp_queue value) {
    Node *node = (Node *) malloc(sizeof(Node));
    node -> data = value;
    node -> next = NULL;

    if (is_empty(dq)) dq -> first = node;
    else dq -> last -> next = node;
    dq -> last = node;

    dq -> size++;
    return 0;
}

tp_queue remove_queue(Dynamic_queue *dq) {
    if (is_empty(dq)) return -1;

    Node *trash = dq -> first;
    tp_queue value = trash -> data;
    dq -> first = trash -> next;
    if (trash -> next == NULL) 
        dq -> last = NULL;
    free(trash);

    dq -> size--;
    return value;
}

int clear_queue(Dynamic_queue *dq) {
    while (!is_empty(dq)) remove_queue(dq);

    return 0;
}

int delete_queue(Dynamic_queue *dq) {
    clear_queue(dq);
    free(dq);

    return 0;
}

#endif