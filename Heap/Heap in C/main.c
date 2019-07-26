#include <stdio.h>
#include <stdlib.h>


struct Node {
  int data;
  struct Node* next;
  struct Node* previous;
};

struct rootHeap {
  int length;
  struct Node* next;
  struct Node* last;
};

struct Node* newNode(int data) {
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  node->previous = NULL;
  return node;
}

struct rootHeap* newRootHeap() {
  struct rootHeap* root = (struct rootHeap*) malloc(sizeof(struct rootHeap));
  root->length = 0;
  root->next = NULL;
  root->last = NULL;
  return root;
};

void insert(struct rootHeap** root, int data) {
  if ((*root)->next == NULL) {
    (*root)->next = newNode(data);
    (*root)->last = (*root)->next;
  } else {
    struct Node* last = (*root)->last;
    last->next = newNode(data);
    (*root)->last = last->next;
  }
}

void displayAll(struct rootHeap** root) {
  int index = 0;
  struct Node* temp = (*root)->next;
  struct Node* previous = NULL;
  while(temp != NULL) {
    printf("%d. data: %d\n    previous: %s\n    last: %d\n\n",
              index++,
              temp->data,
              previous == NULL ? "Null" : previous == temp->previous ? "True" : "False",
              (*root)->last->data
          );

    previous = temp;
    temp = temp->next;
  }
}

int main() {
  struct rootHeap* root = newRootHeap();
  insert(&root, 15);
  displayAll(&root);

  return 0;
}
