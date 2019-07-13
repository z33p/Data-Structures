#include "queueLinkedList.c"

int main(int argc, char const *argv[]) {
    struct Root_Queue* root = newRoot_Queue();

    push_Queue(&root, 2);
    push_Queue(&root, 7);
    pop_Queue(&root);
    displayAll(&root);


    return 0;
}
