#include "stdio.h"
#include "LinkedList.h"

int main(int argc, char const *argv[]) {

    struct Root* root = newRoot();

    push(&root, 1);
    push(&root, 2);
    push(&root, 3);
    push(&root, 5);
    displayAll(&root);

    pop(&root);
    displayAll(&root);

    insert(&root, 1, 5);
    insert(&root, 4, 4);
    displayAll(&root);

    removeNode(&root, 1);
    displayAll(&root);

    return 0;
}
