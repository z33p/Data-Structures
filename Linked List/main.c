#include "stdio.h"
#include "LinkedList.h"

int main(int argc, char const *argv[]) {

    struct Root_LinkedList* root = newRoot_LinkedList();

    root -> push(&root, 1);
    root -> push(&root, 2);
    root -> push(&root, 3);
    root -> push(&root, 5);
    root -> displayAll(&root);

    root -> pop(&root);
    root -> displayAll(&root);

    root -> insert(&root, 1, 5);
    root -> insert(&root, 4, 4);
    root -> displayAll(&root);

    root -> removeNode(&root, 1);
    root -> displayAll(&root);

    return 0;
}
