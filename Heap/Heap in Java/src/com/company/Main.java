package com.company;



public class Main {

    public static void main(String[] args) {
        rootHeap lista = new rootHeap(null, null);
        lista.push(11);
        lista.push(13);
        lista.push(17);
        lista.push(19);
        lista.push(15);
        lista.push(21);
        lista.push(23);

        lista.heapSort();



        // System.out.println(lista.retrieveNode(0).getData());

        // lista.displayAll();
        // System.out.println(System.identityHashCode(lista.getLast()));

    }
}
