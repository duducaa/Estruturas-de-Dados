#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "simple_linked_list.h"

int main() {

    S_linked_list *sll = init_sl_list();

    insert_end(sll, 5);
    insert_end(sll, 7);
    insert_start(sll, 10);
    insert_ordered(sll, 8);

    show(sll);
    printf("Start: %i\n", remove_start(sll));
    printf("End: %i\n", remove_end(sll));
    printf("Between: %i\n", remove_between(sll, 5));
    printf("Size: %i\n", get_size(sll));
    remove_end(sll);
    show(sll);

    return 0;

}