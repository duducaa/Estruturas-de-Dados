#include <stdio.h>
#include <stdlib.h>
#include "static_stack.h"

int main() {

    Static_stack ss;
    init_stack(&ss);

    for (int i = 0; i < 5; i++) push(&ss, i + 1);
    for (int i = 0; i < 7; i++) pop(&ss);

    clear_stack(&ss);

    show(&ss);

    return 0;

}