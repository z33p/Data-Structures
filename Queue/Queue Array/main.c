#include "queueArray.c"


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
