#include <stdio.h>
#include <stdlib.h>

struct Branch {
    int data;
    struct Branch *left;
    struct Branch *right;

};

struct Branch* newBranch(int data) {
    struct Branch *root = (struct Branch*) malloc(sizeof(struct Branch));

    root->data = data;
    root->left = NULL;
    root->right = NULL;

    return root;
}


void insert(struct Branch** root, int data) {

    if (data < (*root)->data) {
        if ((*root)->left == NULL) {
            (*root)->left = newBranch(data);

        } else {
            insert(&((*root)->left), data);
        }

    } else if (data > (*root)->data) {
        if ((*root)->right == NULL) {
            (*root)->right = newBranch(data);

        } else {
            insert(&((*root)->right), data);
        }
    }
}


void search(struct Branch** root, int data) {
    /* printf("Searching data: %d\nAtual data: %d\n\n", data, (*root)->data); */

    if (data == (*root)->data) {
        printf("Found %d!\n", data);
        return;

    } else if (data < (*root)->data) {
        if ((*root)->left == NULL) {
            return;

        } else {
            return search(&((*root)->left), data);
        }

    } else if ((*root)->right == NULL) {
        return;

    } else {
        return search(&((*root)->right), data);
    }
}

void sorting(struct Branch** root) {
    if ((*root)->left != NULL)
        sorting(&((*root)->left));

    printf("%d ", (*root)->data);

    if ((*root)->right != NULL)
        sorting(&((*root)->right));
}


int main(int argc, char const *argv[]) {

    struct Branch* root = newBranch(15);

    for (int i = 0; i < 20; i++) {
        insert(&root, rand() % 50);
    }

    insert(&root, 17);
    search(&root, 17);
    sorting(&root);

    return 0;
}
