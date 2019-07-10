#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* Queue implementing with arrays */


struct Queue {

    int** array;
    int length;
    int maxSize;

    /* Functions */
    void (*push)(struct Queue** queue, int data);
    void (*pop)(struct Queue** queue);
    int  (*peek)(struct Queue** queue);
};


void push_Queue(struct Queue** queue, int data) {

    if ((*queue)->length < (*queue)->maxSize) {
        (*queue)->array[(*queue)->length] = malloc(sizeof(int*));
        *((*queue)->array[(*queue)->length]) = data;
        (*queue)->length++;

        printf("%d added\n", data);

    } else {
        puts("Queue error: Queue is fully!");
        exit(1);
    }
}

void pop_Queue(struct Queue** queue) {

    if ((*queue)->length > 0) {
        printf("%d popped\n", *((*queue)->array[0]));

        for (int i = 0; i < (*queue)->length -1; i++) {
            *((*queue)->array[i]) = *((*queue)->array[i+1]);
        }

        free(((*queue)->array)[(*queue)->length -1]);
        (*queue)->length--;


    } else {
        puts("Queue error: Queue is empty!");
        exit(1);
    }
}

int peek_Queue(struct Queue** queue) {
    if ((*queue)->length > 0)
        return *(((*queue)->array)[0]);

    else {
        puts("Queue error: Queue is empty!");
        exit(1);
    }
}


struct Queue* newQueue(int arraySize) {

    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->array = (int**) malloc(sizeof(int*) * arraySize);
    queue->length = 0;
    queue->maxSize = arraySize;

    queue->push = push_Queue;
    queue->pop = pop_Queue;
    queue->peek = peek_Queue;

    return queue;
}


/*
int main(int argc, char const *argv[]) {

    int max = 3;
    srand(time(0));
    struct Queue* fifo = newQueue(max);

    for (int i = 0; i < max; i++) {
        fifo->push(&fifo, rand() % 15);
    }

    for (int i = 0; i < max; i++) {
        fifo->pop(&fifo);
    }

    return 0;
}
*/
