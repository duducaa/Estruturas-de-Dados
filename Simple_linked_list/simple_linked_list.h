#ifndef SIMPLE_LINKED_LIST_H
#define SIMPLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int tp_sll;

typedef struct node Node;

struct node {
    tp_sll data;
    struct node *next;
};

typedef struct {
    int size;
    Node *head, *tail;
} S_linked_list;

S_linked_list *init_sl_list() {
    S_linked_list *sll = (S_linked_list *) malloc(sizeof(S_linked_list));
    sll -> size = 0;
    sll -> head = sll -> tail = NULL;

    return sll;
}

int get_size(S_linked_list *sll) {
    return sll -> size;
}

int is_empty(S_linked_list *sll) {
    return sll -> head == NULL;
}

Node *search(S_linked_list *sll, tp_sll value) {
    if (is_empty(sll)) return NULL;

    Node *aux = sll -> head;

    while (aux != NULL && aux -> data != value) aux = aux -> next;

    return aux;
}

int show(S_linked_list *sll) {
    Node *aux = sll -> head;

    while (aux != NULL) {
        printf("%i ", aux -> data);
        aux = aux -> next;
    }
    printf("\n");

    return 0;
}

int insert_first(S_linked_list *sll, tp_sll value) {
    Node *node = (Node *) malloc(sizeof(Node));
    node -> data = value;
    node -> next = NULL;

    sll -> head = sll -> tail = node;

    return 0;
}

int insert_start(S_linked_list *sll, tp_sll value) {
    if (is_empty(sll)) insert_first(sll, value);
    else {
        Node *node = (Node *) malloc(sizeof(Node));
        node -> data = value;
        node -> next = sll -> head;

        sll -> head = node;

        sll -> size++;
    }
}

int insert_end(S_linked_list *sll, tp_sll value) {
    if (is_empty(sll)) insert_first(sll, value);
    else {
        Node *node = (Node *) malloc(sizeof(Node));
        node -> data = value;

        sll -> tail -> next = node;
        sll -> tail = node;

        sll -> size++;
    }

    return 0;
}

int insert_ordered(S_linked_list *sll, tp_sll value) {
    if (is_empty(sll)) insert_first(sll, value);
    else {
        if (sll -> head -> data >= value) insert_start(sll, value);
        else if (sll -> tail -> data < value) insert_end(sll, value);
        else {
            Node *aux1, *aux2;
            aux1 = sll -> head;
            aux2 = aux1 -> next;

            while (aux2 -> data <= value && aux2 -> next != NULL) {
                aux1 = aux2;
                aux2 = aux2 -> next;
            }
            
            Node *node = (Node *) malloc(sizeof(Node));
            node -> data = value;
            node -> next = aux2;
            aux1 -> next = node;

            sll -> size++;
        }
    }

    return 0;
}

int remove_last(S_linked_list *sll) {
    Node *trash = sll -> head;
    int value = trash -> data;
    sll -> head = sll -> tail = NULL;
    free(trash);

    return value;
}

int remove_start(S_linked_list *sll) {
    if (is_empty(sll)) return -1;
    else if (sll -> size == 1) return remove_last(sll);
    else {
        Node *trash = sll -> head;
        int value = trash -> data;
        sll -> head = sll -> head -> next;
        free(trash);

        sll -> size--;
        return value;
    }
}

int remove_end(S_linked_list *sll) {
    if (is_empty(sll)) return -1;
    else if (sll -> size == 1) return remove_last(sll);
    else {
        Node *aux1, *aux2;
        aux1 = NULL;
        aux2 = sll -> head;

        while (aux2 -> next != NULL) {
            aux1 = aux2;
            aux2 = aux2 -> next;
        }

        if (aux1 != NULL) aux1 -> next = aux2 -> next;
        else sll -> head = sll -> tail = NULL;
        int trash = aux2 -> data;
        free(aux2);

        sll -> size--;

        return trash;
    }
}

tp_sll remove_between(S_linked_list *sll, tp_sll value) {
    if (is_empty(sll)) return -1;
    else if (sll -> size == 1) return remove_last(sll);
    else {
        Node *aux1, *aux2;
        aux1 = NULL;
        aux2 = sll -> head;

        while (aux2 != NULL && aux2 -> data != value) {
            aux1 = aux2;
            aux2 = aux2 -> next;
        }

        if (aux2 != NULL) {
            aux1 -> next = aux2 -> next;
            free(aux2);
        }

        sll -> size--;

        return (aux2 == NULL) ? -1 : value;
    }
}

int clear(S_linked_list *sll) {
    Node *aux = sll -> head;

    while (!is_empty(sll)) {
        sll -> head = sll -> head -> next;
        free(aux);
        aux = sll -> head;
    }

    return 0;
}

int delete_sll(S_linked_list *sll) {
    clear(sll);
    free(sll);

    return 0;
}

#endif