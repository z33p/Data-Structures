/* Hash table implementation in C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define maxSize 101

struct Name {
    char* name;
    struct Name* next;
};


struct Name* newName(char* firstName) {
    struct Name* name = (struct Name*) malloc(sizeof(struct Name));
    assert(name);

    name->name = firstName;
    name->next = NULL;

    return name;
}


int hash(char* firstName) {
    int sum = 0;
    char letter = firstName[0];
    for (int i = 0; letter != '\0'; i++) {
        sum += letter;
        letter = firstName[i];

    }

    return sum % maxSize;
}


struct Name** newHashTable() {

    struct Name** dict = (struct Name**) malloc(sizeof(struct Name*) * maxSize);

    for (int i = 0; i < maxSize; i++) {
        dict[i] = NULL;
    }

    return dict;
}


int insert(struct Name** dict, char* firstName) {

    int index = hash(firstName);
    if (index > maxSize || index < 0)
        printf("Error: idnex = %d ::: maxSize = %d\n", index, maxSize);

    struct Name* name = newName(firstName);

    if (dict[index] == NULL)
        dict[index] = name;

    else {
        printf("Colissions index %d: %s, %s\n", index, dict[index]->name, firstName);
        struct Name* filled = dict[index];
        while (filled->next != NULL) {
            filled = filled->next;
        }

        filled->next = name;
    }

    /* printf("%d. %s\n", index, dict[index]); */

    return index;
}

void displayAll(struct Name** dict) {

    struct Name* filled = NULL;
    for (int i = 0; i < maxSize; i++) {
        if (dict[i] != NULL) {
            printf("%d. %s", i, dict[i]->name);
            filled = dict[i]->next;

            while(filled != NULL) {
                printf(" ::: %s", filled->name);
                filled = filled->next;
            }

            puts("");
        }
    }
}

int main(int argc, char const *argv[]) {

    struct Name** dict = newHashTable();

    insert(dict, "Raphael");
    insert(dict, "Luana");
    insert(dict, "Iago");
    insert(dict, "João");
    insert(dict, "John");
    insert(dict, "Diego");
    insert(dict, "Junior");
    insert(dict, "Jessilane");
    insert(dict, "Nine");
    insert(dict, "Sebastião");
    insert(dict, "Paula");
    insert(dict, "Ricey");
    insert(dict, "Victor");
    insert(dict, "Pessoa");
    insert(dict, "Gato");
    insert(dict, "Monstro");


    displayAll(dict);


    return 0;
}
