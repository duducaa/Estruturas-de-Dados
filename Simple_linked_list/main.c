#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "simple_linked_list.h"

int main() {

    srand(time(NULL));

    S_linked_list *sll = init_sl_list();
    
    int x;
    for (int i = 0; i < 10; i++) insert_ordered(sll, rand() % 10 + 1);
    show(sll);

    printf("Size: %i\n", get_size(sll));

    Node *s = search(sll, 5);
    if (s == NULL) printf("Not found\n");
    else printf("Found: %i\n", s -> data);

    int trash;
    for (int i = 0; i < 10; i++) remove_after(sll);
    show(sll);

    remove_between(sll, 3);
    show(sll);

    clear(sll);

    printf("%i\n", get_size(sll));

    return 0;

}