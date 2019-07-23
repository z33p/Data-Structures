package com.company;

import java.util.Random;

public class Main {

    public static void main(String[] args) {
        rootHeap lista = new rootHeap();

        Random rand = new Random();
        lista.push(rand.nextInt(50));

        for (int i = 0; i < 50000; i++) {
            lista.push(rand.nextInt(800));

        }

        lista.heapSort();


        // System.out.println(lista.retrieveNode(0).getData());

        // lista.displayAll();
        // System.out.println(System.identityHashCode(lista.getLast()));

    }
}
