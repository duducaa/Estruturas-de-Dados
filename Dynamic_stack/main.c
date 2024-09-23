#include <stdio.h>
#include <stdlib.h>
#include "dynamic_stack.h"

int main() {

    Dynamic_stack *ds = init_stack();

    push(ds, 1);
    push(ds, 5);
    push(ds, 4);

    clear_stack(ds);

    show(ds);

    return 0;

}