#include <stdio.h>
#include <stdlib.h>

struct Array {
    int length;
    int* array;
};

struct Array* newArray(int max) {
    struct Array* myArray = (struct Array*) malloc(sizeof(struct Array));

    myArray->length = 1;
    myArray->array = (int*) malloc(sizeof(int) * max);

    return myArray;
}


void swapChild(struct Array** myArray, int indexParent) {
    int indexLeft = indexParent * 2;
    int indexRight = indexLeft + 1;

    if ((*myArray)->array[indexLeft] != 0) {
        int child;
        if ((*myArray)->array[indexLeft] > (*myArray)->array[indexRight])
            child = indexLeft;
        else
            child = indexRight;

        if ((*myArray)->array[child] > (*myArray)->array[indexParent]) {
            int temp;
            temp = (*myArray)->array[child];
            (*myArray)->array[child] = (*myArray)->array[indexParent];
            (*myArray)->array[indexParent] = temp;

            indexParent = child;
            if (indexParent * 2 < (*myArray)->length)
                swapChild(myArray, indexParent);
        }
    }

}

void swapParent(struct Array** myArray, int indexChild, int indexParent) {
    if ((*myArray)->array[indexChild] > (*myArray)->array[indexParent]) {
        int temp = (*myArray)->array[indexParent];
        (*myArray)->array[indexParent] = (*myArray)->array[indexChild];
        (*myArray)->array[indexChild] = temp;

        indexChild = indexParent;
        indexParent = indexParent / 2;

        if (indexParent != 0) {
            /* puts("Recursion on swapParent");
            swapChild(myArray, indexChild); */
            swapParent(myArray, indexChild, indexParent);
        }
    }
}


void push(struct Array** myArray,int data) {
    // printf("Array size: %d", (*array)->length);
    if ((*myArray)->length == 1) {
        (*myArray)->array[1] = data;
        (*myArray)->length++;
    }

    else {
        int indexChild = (*myArray)->length;
        int indexParent = indexChild / 2;
        (*myArray)->array[indexChild] = data;
        /*
        printf("Index of child: %d\n", indexChild);
        printf("Index of parent: %d\n", indexParent);
        */

        swapParent(myArray, indexChild, indexParent);
        (*myArray)->length++;
    }
}


void displayAll(struct Array** myArray) {
    int i;
    for (i=1; i < (*myArray)->length -1; i++) {
        printf("%d, ", (*myArray)->array[i]);
    }
    printf("%d\n", (*myArray)->array[i]);
}

void extractMax(struct Array** myArray) {
    /* printf("Last: %d\n", (*myArray)->array[(*myArray)->length -1]); */
    if ((*myArray)->array[1] != 0) {
        int temp = (*myArray)->array[(*myArray)->length -1];
        (*myArray)->array[(*myArray)->length -1] = 0;
        (*myArray)->array[1] = temp;

        (*myArray)->length--;
        swapChild(myArray, 1);

    }
}

int main(int argc, char const *argv[]) {
    struct Array* myArray = newArray(10);

    push(&myArray, 15);
    push(&myArray, 17);
    push(&myArray, 19);
    push(&myArray, 23);
    push(&myArray, 30);


    extractMax(&myArray);
    extractMax(&myArray);

    push(&myArray, 12);
    push(&myArray, 20);

    extractMax(&myArray);

    displayAll(&myArray);
    return 0;
}
