#include "StackArray.c"


int main(int argc, char const *argv[]) {
    int maxSize = 10;
    int** stack = newStack(10, maxSize);

    push(stack, maxSize, 2);
    push(stack, maxSize, 2);
    push(stack, maxSize, 2);

    pop(stack, maxSize);
    displayAll(stack, maxSize);

    return 0;
}
