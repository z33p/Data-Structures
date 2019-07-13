#include <stdio.h>
#include <stdlib.h>

/* Queue implamanting with Linked List */

struct Node_Queue {

    int data;
    struct Node_Queue* next;
};


struct Root_Queue {

    int length;
    struct Node_Queue* next;

    /* Functions */
};


struct Node_Queue* newNode_Queue(int data) {

    struct Node_Queue* newNode = (struct Node_Queue*) malloc(sizeof(struct Node_Queue));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}


void push_Queue(struct Root_Queue** root, int data) {

    struct Node_Queue* newNode = newNode_Queue(data);

    if ((*root)->length == 0) {
        (*root)->next = newNode;

    } else {
        struct Node_Queue* temp = (*root)->next;
        struct Node_Queue* previous = temp;
        while (temp->next != NULL) {

            previous = temp;
            temp = temp->next;
        }

        previous->next = newNode;

    }

    (*root)->length++;

    printf("%d added to the Queue\n", data);
}


void pop_Queue (struct Root_Queue** root) {

    struct Node_Queue* temp = (*root)->next;
    (*root)->next = (*root)->next->next;

    printf("%d popped from the Queue\n", temp->data);
    free(temp);

}


struct Root_Queue* newRoot_Queue() {
    struct Root_Queue* newRoot = (struct Root_Queue*) malloc(sizeof(struct Root_Queue));

    newRoot->length = 0;

    return newRoot;
}

void displayAll(struct Root_Queue** root) {
    int index = 1;
    puts("");

    struct Node_Queue* temp = (*root)->next;
    while (temp -> next != NULL) {
        printf("Index %d: data = %d\n         address = %p\n", index, temp -> data, temp -> next);
        temp = temp->next;
        index++;
    }
    printf("Index %d: data = %d\n         address = %p\n\n", index, temp -> data, temp -> next);
}
