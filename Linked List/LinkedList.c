// C program for linked list implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


struct Node* initNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    if (node == NULL) {
        puts("Insufficient memory!");
        exit(1);
    }
    node->data = data;
    node->next = NULL;

    return node;
}


struct Root* newRoot() {
    struct Root* root = (struct Root*) malloc(sizeof(struct Root));
    root->length = 0;

    root->next = NULL;
    root->last = NULL;

    return root;
}


void push(struct Root** root, int data) {
    struct Node* newNode = initNode(data);
    if ((*root)->next == NULL) {
        (*root)->next = newNode;
        (*root)->last = newNode;

    } else {
        (*root)->last->next = newNode;
        (*root)->last = newNode;
    }

    (*root)->length++;
}


struct Node* retrieveNode(struct Root** root, int index) {
    if ((*root)->next == NULL) {
        puts("Error: Linked list is empty!");
        exit(1);
    }

    if (index > 0 && index <= (*root)->length) {
        struct Node* temp = (*root)->next;
        for (int i = 1; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }

    puts("Erro: Index out of range!");
    exit(1);
}


void pop(struct Root** root) {
    if ((*root)->length == 0) {
        puts("Erro: Linked list is empty!");

    } else {
        struct Node* newLastNode = retrieveNode(root, (*root)->length -1);
        struct Node* oldLastNode = newLastNode->next;
        newLastNode->next = NULL;
        free(oldLastNode);
        (*root)->last = newLastNode;
        (*root)->length--;
    }
}


void insert(struct Root** root, int index, int data) {
    if (index == 0) {
        puts("Error: Linked List You can't insert into root!");
        exit(1);
    }
    if (index == 1) {
        if ((*root)->next == NULL) {
            push(root, data);

        } else {
            struct Node* newNode = initNode(data);
            struct Node* posterior = (*root)->next;
            newNode->next = posterior;
            (*root)->next = newNode;
        }
    } else {

        struct Node* previous =  retrieveNode(root, index -1);
        if (previous->next == NULL) {
            push(root, data);

        } else {
            struct Node* newNode = initNode(data);
            newNode->next = previous->next;
            previous->next = newNode;
        }
    }

    (*root)->length++;
}


void removeNode(struct Root** root, int index) {

    if (index == 1) {
        struct Node* temp = (*root)->next;
        (*root)->next = ((*root)->next)->next;
        free(temp);
    } else {
        struct Node* previous = retrieveNode(root, index -1);
        if (previous->next == NULL) {
            puts("Error: Index out of range");
            exit(1);
        }

        struct Node* node = previous->next;
        if (node->next == NULL) {
            pop(root);

        } else {
            struct Node* posterior = node->next;
            previous->next = posterior;
            free(node);
        }
    }

    (*root)->length--;
}


void displayAll(struct Root** root) {
    int index = 1;
    puts("");

    struct Node* temp = (*root)->next;
    while (temp->next != NULL) {
        printf("Index %d: data = %d\n         address = %p\n", index, temp->data, temp->next);
        temp = temp->next;
        index++;
    }
    printf("Index %d: data = %d\n         address = %p\n\n", index, temp->data, temp->next);
}


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
