#include <stdlib.h>
#include <stdio.h>
#include "dynamic_queue.h"

int main() {

    Dynamic_queue *dq = init_queue();
    insert_queue(dq, 4);
    insert_queue(dq, 6);
    insert_queue(dq, 1);

    remove_queue(dq);
    remove_queue(dq);
    remove_queue(dq);
    remove_queue(dq);

    clear_queue(dq);

    insert_queue(dq, 8);

    show(dq);

    return 0;

}