package com.company;


public class Heap {

    private int data;
    private Heap next;
    private Heap previous;

    public Heap(int data, Heap next, Heap previous) {
        this.data = data;
        this.next = next;
        this.previous = previous;
    }


    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }

    public Heap getNext() {
        return next;
    }

    public void setNext(Heap next) {
        this.next = next;
    }

    public Heap getPrevious() {
        return previous;
    }

    public void setPrevious(Heap previous) {
        this.previous = previous;
    }
}
