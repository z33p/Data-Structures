package com.company;

public class rootHeap {

    private int length;
    private Heap next;
    private Heap last;

    public rootHeap() {
        this.length = 0;
        this.next = null;
        this.last = null;
    }


    public Heap retrieveNode(int index) {
        Heap temp = this.next;

        if (index == 0 || index > this.length -1) {
            System.out.println("Index out of the range");
            System.exit(1);
        }

        for (int i = 1; i < index; i++) {
            temp = temp.getNext();
        }

        return temp;
    }

    private void swap(Heap parent, Heap child) {
        if (parent.getNext() == child) {
//            System.out.println("Parent: " + parent.getData() + " ::: Child: " + child.getData());
            Heap nextChild = child.getNext();
            child.setPrevious(null);
            parent.setNext(nextChild);
            child.setNext(parent);
            parent.setPrevious(child);
            this.next = child;

            if (nextChild != null)
                nextChild.setPrevious(parent);

        } else if (this.next.getNext().getNext() == child) {
//            System.out.println("Parent: " + parent.getData() + " ::: Child: " + child.getData());

            Heap middle = this.next.getNext();
            Heap nextChild = child.getNext();
            middle.setPrevious(child);
            middle.setNext(parent);
            parent.setNext(nextChild);
            child.setPrevious(null);
            child.setNext(middle);
//            System.out.println("Middle: " + middle.getData() + " ::: child: " + child.getData());
            parent.setPrevious(middle);
            this.next = child;

            if (parent.getNext() != null)
                parent.getNext().setPrevious(parent);

        } else {
//            System.out.println("Parent: " + parent.getData() + " ::: Child: " + child.getData());
            Heap nextParent = parent.getNext();
            Heap previousParent = parent.getPrevious();
            Heap nextChild = child.getNext();     // It could be null
            Heap previousChild = child.getPrevious();

            if (previousParent != null)
                previousParent.setNext(child);
            previousChild.setNext(parent);

            nextParent.setPrevious(child);
            if (nextChild != null)
                nextChild.setPrevious(parent);

            parent.setPrevious(previousChild);
            parent.setNext(nextChild);   // System.out.println(parent.getData() + " " + nextChild);

            child.setNext(nextParent);
            child.setPrevious(previousParent);

        }

        Heap temp = this.next;
        Heap previous = temp;
        while(temp != null) {
            previous = temp;
            temp = temp.getNext();
        }

        this.last = previous;
    }

    private void swapParent(Heap child, int indexChild) {
        int indexParent = indexChild / 2;
        if (indexParent < 1)
            return;

//        System.out.println("index parent: " + indexParent + " ::: length: " + this.length);
        Heap parent = retrieveNode(indexParent);

        if (child.getData() > parent.getData()) {
            swap(parent, child);
            swapParent(child, indexParent);
        }

    }


    public int push(int data) {

        if (this.next == null) {
            this.next = new Heap(data, null, null);
            this.last = this.next;
            this.length++;
            return data;
        }

        this.last.setNext(new Heap(data, null, null));
        this.last.getNext().setPrevious(this.last);
        this.last = this.last.getNext();
        this.length++;
        swapParent(this.last, this.length);
        return data;

    }

    public void swapChildren(Heap parent, int indexParent) {
        int indexChildLeft = indexParent * 2;

        if (indexChildLeft < this.length) {
            Heap childLeft = retrieveNode(indexChildLeft);
//            System.out.println("Child left: " + childLeft.getData() + " ::: Length: " + this.length);
            Heap childRight = childLeft.getNext();
            Heap child;
            int indexChild;
            if (childRight == null) {
                child = childLeft;
                indexChild = indexChildLeft;
            }

            else if (childLeft.getData() > childRight.getData()) {
                child = childLeft;
                indexChild = indexChildLeft;
            }

            else {
                child = childRight;
                indexChild = indexChildLeft + 1;
            }
            if (child.getData() > parent.getData()) {
                swap(parent, child);
                if (this.next == parent)
                    this.next = child;
            }
            swapChildren(parent, indexChild);
        }
    }


    public void extractMax() {
        System.out.printf("Extracted: %d\n", this.next.getData());
        if (this.length > 1) {
//            System.out.println("Next: " + this.next.getData() + " ::: Last: " + this.last.getData());
            Heap parent = this.next;
            Heap child = this.last;
            swap(this.next, this.last);

            this.next = child;
            this.last = parent.getPrevious();
            this.last.setNext(null);

            swapChildren(this.next, 1);
        } else
            this.next = null;

        this.length--;
    }

    public void heapSort() {
        int len = this.length;
        for (int i = 0; i < len; i++) {
            extractMax();
        }
    }

    public void displayAll() {
        Heap temp = this.next;
        Heap previous = null;
        int index = 1;
        while (temp != null) {
            System.out.printf(
                    "%d. data: %d\n    previous: %s\n    last: %d\n\n",
                    index++,
                    temp.getData(),
                    previous == null ? "Null" : previous == temp.getPrevious() ? "True" : "False",
                    this.last.getData()
            );


            previous = temp;
            temp = temp.getNext();
        }
    }
}
