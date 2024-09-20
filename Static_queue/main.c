#include <stdlib.h>
#include <stdio.h>
#include "static_queue.h"

int main() {

    Static_queue sq;
    init_queue(&sq);
    for (int i = 0; i < TAM; i++) {
        insert_queue(&sq, i + 1);
        printf("start: %i, end: %i\n", sq.start, sq.end);
    }
    printf("\n");
    for (int i = 0; i < 4; i++) {
        remove_queue(&sq);
        printf("start: %i, end: %i\n", sq.start, sq.end);
    }
    printf("\n");
    for (int i = 0; i < 3; i++) {
        insert_queue(&sq, i + 1);
        printf("start: %i, end: %i\n", sq.start, sq.end);
    }
    show(&sq);


    return 0;

}