// C program for linked list implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


struct Node_LinkedList* _LinkedList_initNode(int data) {
    struct Node_LinkedList* node = (struct Node_LinkedList*) malloc(sizeof(struct Node_LinkedList));
    if (node == NULL) {
        puts("Insufficient memory!");
        exit(1);
    }
    node -> data = data;
    node -> next = NULL;

    return node;
}


void _LinkedList_push(struct Root_LinkedList** root, int data) {
    struct Node_LinkedList* new_LinkedList_Node = _LinkedList_initNode(data);
    if ((*root) -> length == 0) {
        /* When the linked list is empty */
        (*root) -> next = new_LinkedList_Node;

    } else {

        struct Node_LinkedList* temp = (*root) -> next;
        while(temp -> next != NULL) {
            temp = temp -> next;
        }

        temp -> next = new_LinkedList_Node;
    }


    (*root) -> length++;
}


struct Node_LinkedList* _LinkedList_retrieveNode(struct Root_LinkedList** root, int index) {
    if ((*root) -> length == 0) {
        puts("Erro: Linked list is empty!");
        exit(1);
    }

    if (index > 0 && index <= (*root) -> length) {

        struct Node_LinkedList* temp = (*root) -> next;
        for (int i = 1; i < index; i++) {
            temp = temp -> next;
        }
        return temp;
    }

    puts("Erro: Index out of range!");
    exit(1);
}


void _LinkedList_pop(struct Root_LinkedList** root) {
    if ((*root) -> length == 0) {
        puts("Erro: Linked list is empty!");

    } else {
        struct Node_LinkedList* newLast_LinkedList_Node = _LinkedList_retrieveNode(root, (*root) -> length -1);
        struct Node_LinkedList* oldLast_LinkedList_Node = newLast_LinkedList_Node -> next;
        newLast_LinkedList_Node -> next = NULL;
        free(oldLast_LinkedList_Node);
        (*root) -> length--;
    }
}


void _LinkedList_insert(struct Root_LinkedList** root, int index, int data) {
    if (index == 0) {
        puts("You can't insert into root!");
        exit(1);
    }
    if (index == 1) {
        if ((*root) -> length == 0) {
            _LinkedList_push(root, data);

        } else {
            struct Node_LinkedList* new_LinkedList_Node = _LinkedList_initNode(data);
            struct Node_LinkedList* posterior = (*root) -> next;
            new_LinkedList_Node -> next = posterior;
            (*root) -> next = new_LinkedList_Node;
        }
    } else {

        struct Node_LinkedList* previous =  _LinkedList_retrieveNode(root, index -1);
        if (previous -> next == NULL) {
            _LinkedList_push(root, data);
            return;

        } else {
            struct Node_LinkedList* new_LinkedList_Node = _LinkedList_initNode(data);
            new_LinkedList_Node -> next = previous -> next;
            previous -> next = new_LinkedList_Node;
        }
    }

    (*root) -> length++;
}


void _LinkedList_removeNode(struct Root_LinkedList** root, int index) {

    if (index == 1) {
        struct Node_LinkedList* temp = (*root) -> next;
        (*root) -> next = ((*root) -> next) -> next;
        free(temp);
    } else {
        struct Node_LinkedList* previous = _LinkedList_retrieveNode(root, index -1);
        if (previous -> next == NULL) {
            puts("Error: Index out of range");
            exit(1);
        }

        struct Node_LinkedList* node = previous -> next;
        if (node -> next == NULL) {
            _LinkedList_pop(root);

        } else {
            struct Node_LinkedList* posterior = node -> next;
            previous -> next = posterior;
            free(node);
        }
    }

    (*root) -> length--;
}


void _LinkedList_displayAll(struct Root_LinkedList** root) {
    int index = 1;
    puts("");

    struct Node_LinkedList* temp = (*root) -> next;
    while (temp -> next != NULL) {
        printf("Index %d: data = %d\n         address = %p\n", index, temp -> data, temp -> next);
        temp = temp -> next;
        index++;
    }
    printf("Index %d: data = %d\n         address = %p\n\n", index, temp -> data, temp -> next);
}


struct Root_LinkedList* newRoot_LinkedList() {
    struct Root_LinkedList* root = (struct Root_LinkedList*) malloc(sizeof(struct Root_LinkedList));
    root -> length = 0;

    // Functions
    root -> push = _LinkedList_push;
    root -> pop = _LinkedList_pop;
    root -> retrieveNode = _LinkedList_retrieveNode;
    root -> insert = _LinkedList_insert;
    root -> removeNode = _LinkedList_removeNode;
    root -> displayAll = _LinkedList_displayAll;

    return root;
}
