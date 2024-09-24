#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main() {

    Binary_tree *bt = init_tree();
    insert(bt, 5);
    insert(bt, 4);
    insert(bt, 6);
    insert(bt, 1);
    post_order(bt);

    return 0;

}