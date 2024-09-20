#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define tp_stack int

typedef struct {
    tp_stack data[TAM];
    int top;
} Static_stack;

int init_stack(Static_stack *ss) {
    ss -> top = -1;

    return 0;
}

int is_full(Static_stack *ss) {
    return ss -> top == TAM - 1;
}

int is_empty(Static_stack *ss) {
    return ss -> top == -1;
}

int get_size(Static_stack *ss) {
    return ss -> top + 1;
}

int show(Static_stack *ss) {
    for (int i = ss -> top; i > -1; i--) {
        printf("%i\n", ss -> data[i]);
    }
    printf("\n");

    return 0;
}

int push(Static_stack *ss, tp_stack value) {
    if (is_full(ss)) return -1;

    ss -> data[++ss -> top] = value;

    return 0;
}

int pop(Static_stack *ss) {
    if (is_full(ss)) return -1;

    tp_stack value;

    value = ss -> data[--ss -> top];

    return value;
}