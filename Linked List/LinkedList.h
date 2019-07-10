#ifndef __LINKEDLIST__
#define __LINKEDLIST__

/*
    There's a few concepts of OOP.
    I also rename the global functions with the filename first.
    I'll use this module in another data structure then
    I need to do both things to avoid name conflict.

    By: Raphael Fellipe
*/


struct Node_LinkedList {
/*
    A simple linked list node.
*/
    int data;
    struct Node_LinkedList* next;

};


/* A root manager with pointer functions to deal with all list operations */
struct Root_LinkedList {

/* Name functions:
    push,
    retrieveNode,
    pop,
    insert,
    removeNode,
    displayAll,
*/

    int length;    /* There's also a length variable */
    struct Node_LinkedList* next;

    // Functions
    void (*push)(struct Root_LinkedList** root, int data);
    void (*pop)(struct Root_LinkedList** root);
    struct Node_LinkedList* (*retrieveNode)(struct Root_LinkedList** root, int index);
    void (*insert)(struct Root_LinkedList** root, int index, int data);
    void (*removeNode)(struct Root_LinkedList** root, int index);
    void (*displayAll)(struct Root_LinkedList** root);
};

 /* Important*/ struct Root_LinkedList* newRoot_LinkedList();   /* Initialize*/


/* Node initialize, there's no need to be explicitly used */
struct Node_LinkedList* _LinkedList_initNode(int data);


/* All functions mentioned in Root_LinkedList  */
void _LinkedList_push(struct Root_LinkedList** root, int data);
struct Node_LinkedList* _LinkedList_retrieveNode(struct Root_LinkedList** root, int index);
void _LinkedList_pop(struct Root_LinkedList** root);
void _LinkedList_insert(struct Root_LinkedList** root, int index, int data);
void _LinkedList_removeNode(struct Root_LinkedList** root, int index);
void _LinkedList_displayAll(struct Root_LinkedList** root);

#endif
