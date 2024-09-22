#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int tp_dll;

typedef struct node Node;

struct node {
    tp_dll data;
    struct node *prev, *next;
};

typedef struct {
    int size;
    Node *head, *tail;
} D_linked_list;

D_linked_list *init_dl_list() {
    D_linked_list *dll = (D_linked_list *) malloc(sizeof(D_linked_list));
    dll -> size = 0;
    dll -> head = dll -> tail = NULL;

    return dll;
}

int get_size(D_linked_list *dll) {
    return dll -> size;
}

int is_empty(D_linked_list *dll) {
    return dll -> head == NULL;
}

Node *search(D_linked_list *dll, tp_dll value) {
    if (is_empty(dll)) return NULL;

    Node *aux = dll -> head;

    while (aux != NULL && aux -> data != value) aux = aux -> next;

    return aux;
}

int show(D_linked_list *dll) {
    Node *aux = dll -> head;

    while (aux != NULL) {
        printf("%i ", aux -> data);
        aux = aux -> next;
    }
    printf("\n");

    return 0;
}

int insert_first(D_linked_list *dll, tp_dll value) {
    Node *node = (Node *) malloc(sizeof(Node));
    node -> data = value;
    node -> next = NULL;

    dll -> head = dll -> tail = node;

    dll -> size++;

    return 0;
}

int insert_before(D_linked_list *dll, tp_dll value) {
    if (is_empty(dll)) insert_first(dll, value);
    else {
        Node *node = (Node *) malloc(sizeof(Node));
        node -> data = value;
        node -> prev = NULL;
        node -> next = dll -> head;

        dll -> head -> prev = node;
        dll -> head = node;

        dll -> size++;
    }

    return 0;
}

int insert_after(D_linked_list *dll, tp_dll value) {
    if (is_empty(dll)) insert_first(dll, value);
    else {
        Node *node = (Node *) malloc(sizeof(Node));
        node -> data = value;
        node -> next = NULL;
        node -> prev = dll -> tail;

        dll -> tail -> next = node;
        dll -> tail = node;

        dll -> size++;
    }

    return 0;
}

int insert_ordered(D_linked_list *dll, tp_dll value) {
    if (is_empty(dll)) insert_first(dll, value);
    else {
        if (dll -> head -> data >= value) insert_before(dll, value);
        else if (dll -> tail -> data < value) insert_after(dll, value);
        else {
            Node *aux1, *aux2;
            aux1 = dll -> head;
            aux2 = aux1 -> next;

            while(aux2 -> data <= value && aux2 -> next != NULL) {
                aux1 = aux2;
                aux2 = aux2 -> next;
            }

            Node *node = (Node *) malloc(sizeof(Node));
            node -> data = value;
            node -> prev = aux1;
            node -> next = aux2;
            aux1 -> next = aux2 -> prev = node;

            dll -> size++;
        }
    }
}

#endif