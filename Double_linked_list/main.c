#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

int main() {

    D_linked_list *dll = init_dl_list();

    insert_end(dll, 5);
    insert_end(dll, 7);
    insert_start(dll, 10);
    insert_ordered(dll, 8);

    show(dll);
    printf("Start: %i\n", remove_start(dll));
    printf("End: %i\n", remove_end(dll));
    printf("Between: %i\n", remove_between(dll, 5));
    printf("Size: %i\n", get_size(dll));
    remove_end(dll);
    show(dll);

    return 0;

}