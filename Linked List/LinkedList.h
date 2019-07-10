#ifndef __LINKEDLIST__
#define __LINKEDLIST__

/*
    You're welcome.

    By: Raphael Fellipe
*/


struct Node {
    /* A simple linked list node. */
    int data;
    struct Node* next;

};


/* A root node */
struct Root {

    int length;    /* There's also a length variable */
    struct Node* next;
    struct Node* last;

};

 /* Important*/ struct Root* newRoot();   /* Initialize*/


/* Node initialize, there's no need to be explicitly used */
struct Node* initNode(int data);

/* Name functions:
    push,
    retrieveNode,
    pop,
    insert,
    removeNode,
    displayAll,
*/

void push(struct Root** root, int data);
struct Node* retrieveNode(struct Root** root, int index);
void pop(struct Root** root);
void insert(struct Root** root, int index, int data);
void removeNode(struct Root** root, int index);
void displayAll(struct Root** root);

#endif
