/* Stack implementation in C: Last in Last out */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "StackArray.h"

#define maxSize 10

int** newStack(int maxSize) {

    int** stack = (int**) malloc(sizeof(int*) * maxSize);
    assert(stack);

    for (int i = 0; i < maxSize; i++) {
        stack[i] = NULL;
    }

    return stack;
}


void push(int** array, int maxSize, int data) {

    for (int i = 0; i < maxSize; i++) {
        if (array[i] == NULL) {
            array[i] =  &data;
            return;
        }
    }

    puts("There's no more room into array!");
    exit(1);
}

void pop(int** array, int maxSize) {

    for (int i = 0; i < maxSize; i++) {
        if (array[i] == NULL) {
            if (i != 0)
                array[i-1] = NULL;
            return;
        }
    }
}

int peek(int** array, int maxSize) {

    for (int i = 0; i < maxSize; i++) {
        if (array[i] == NULL) {

            if (i != 0)
                return array[i-1];

            puts("Array is empty");
            exit(1);
        }
    }
}

void displayAll(int** array, int maxSize) {

    for (int i = 0; i < maxSize; i++) {
        if (array[i] != NULL) {
            printf("Index %d: %d\n", i + 1, *(array[i]));
        }
    }
}
