#ifndef __STACKARRAY__
#define __STACKARRAY__

int** newStack(int maxSize);
void push(int** array, int maxSize, int data);
void pop(int** array, int maxSize);
void peek(int** array, int maxSize);
void displayAll(int** array, int maxSize);


#endif
