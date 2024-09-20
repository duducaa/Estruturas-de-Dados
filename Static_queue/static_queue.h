#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <stdlib.h>
#include <stdio.h>

#define TAM 10
#define tp_queue int

typedef struct {
    tp_queue data[TAM];
    int start, end;
    int size;
} Static_queue;

int init_queue(Static_queue *sq) {
    sq -> start = sq -> end = 0;
    sq -> size = 0;

    return 0;
}

int is_empty(Static_queue *sq) {
    return sq -> size == 0;
}

int is_full(Static_queue *sq) {
    return sq -> size == TAM;
}

int get_size(Static_queue *sq) {
    return sq -> size;
}

int show(Static_queue *sq) {
    for (int i = 0, j = sq -> start; i < sq -> size; i++) {
        printf("%i ", sq -> data[j]);
        j = (j + 1) % TAM;
    }
    printf("\n");

    return 0;
}

int insert_queue(Static_queue *sq, tp_queue value) {
    if (is_full(sq)) return -1;

    sq -> data[sq -> end] = value;
    sq -> end = (sq -> end + 1) % TAM;
    sq -> size++;

    return 0;
}

tp_queue remove_queue(Static_queue *sq) {
    if (is_empty(sq)) return -1;

    tp_queue value;

    value = sq -> data[sq -> start];
    sq -> start = (sq -> start + 1) % TAM;
    sq -> size--;

    return value;
}

int clear_queue(Static_queue *sq) {
    while (!is_empty(sq)) remove_queue(sq);

    return 0;
}

#endif