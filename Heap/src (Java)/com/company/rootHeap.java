package com.company;

public class rootHeap {

    private int length;
    private Heap next;
    private Heap last;


    public rootHeap(Heap next, Heap last) {
        this.length = 0;
        this.next = next;
        this.last = last;
    }


    public void push(int data) {
        if (this.next == null) {
            this.next = new Heap(data, null, null);
            this.last = this.next;
            this.length++;


        } else {
            Heap temp = this.last;
            this.last = new Heap(data, null, temp);
            temp.setNext(this.last);
            int index = ++this.length;

            swapParent(this.last, index);
        }
    }

    public void displayAll() {
        Heap temp = this.next;
        int index = 1;

        while(temp != null) {
            System.out.printf("%d. data: %d\n   previous: ", index, temp.getData());
            System.out.print(System.identityHashCode(temp.getPrevious()));
            System.out.print("\n   next: ");
            System.out.print(System.identityHashCode(temp.getNext()));
            System.out.printf("\n   myHash: ");
            System.out.print(System.identityHashCode(temp));
            System.out.println("\n");

            temp = temp.getNext();
            index++;
        }
    }

    public Heap retrieveNode(int index) {
        if (index > this.length || index < 1) {
            System.out.println("Retrieve node function error: index out of range!");
            System.exit(1);

        }

        Heap temp = this.next;
        int count = 1;
        while (count < index) {
            temp = temp.getNext();
            count++;
        }

        return temp;

    }

    public void swap(Heap parent, Heap child) {

        if (parent.getPrevious() != null) {
            parent.getPrevious().setNext(child);
        }

        if (child.getNext() != null) {
            child.getNext().setPrevious(parent);
        }

        Heap childPrevious = child.getPrevious();
        childPrevious.setNext(parent);

        Heap parentNext = parent.getNext();

        Heap parentPrevious = null;
        if (parent.getPrevious() != null) {
            parentPrevious = parent.getPrevious();
        }
        parentNext.setPrevious(child);

        parent.setNext(child.getNext());
        parent.setPrevious(child.getPrevious());

        child.setNext(parentNext);
        child.setPrevious(parentPrevious);
    }


    public void swapParent(Heap child, int indexChild) {
        int indexParent = indexChild / 2;
        Heap parent = retrieveNode(indexParent);

        if (child.getData() > parent.getData()) {
            swap(parent, child);

            if (indexParent == 1) {
                this.next = child;
                this.last = retrieveNode(this.length);


            } else {
                swapParent(child, indexParent);
            }
        }
    }

    public void swapChildren(Heap parent, int indexParent) {

        int indexLeftChild = indexParent * 2;
        if (indexLeftChild < this.length) {
            Heap leftChild = retrieveNode(indexLeftChild);
            Heap rigthChild = null;
            Heap child = null;
            int indexChild;
            if (leftChild.getNext() == null) {
                child = leftChild;
                indexChild = indexLeftChild;
            } else {
                rigthChild = leftChild.getNext();

                if (leftChild.getData() > rigthChild.getData()) {
                    child = leftChild;
                    indexChild = indexLeftChild;

                } else {
                    child = rigthChild;
                    indexChild = indexLeftChild + 1;
                }
            }

            if (child.getData() > parent.getData()) {
                swap(parent, child);
                if (indexParent == 1) {
                    this.next = child;
                    this.last = retrieveNode(this.length);

                }

                swapChildren(child, indexChild);
            }
        }
    }

    public void extractMax() {
        // System.out.printf("Extracted: %d\n", this.next.getData());
        if (this.next == null) {
            System.out.println("The heap is empty!");
            System.exit(1);

        } else if(this.next != this.last) {
            Heap parent = this.next;
            Heap child = this.last;

            swap(parent, child);
            this.last = parent.getPrevious();
            parent.getPrevious().setNext(null);
            this.next = child;
            this.length--;

            swapChildren(this.next, 1);

        }
    }

    public void heapSort() {
        int count = this.length;
        for (int i = 0; i < count; i++) {
            System.out.println(this.next.getData());
            extractMax();
        }
    }

    public Heap getNext() {
        return next;
    }

    public void setNext(Heap next) {
        this.next = next;
    }

    public Heap getLast() {
        return last;
    }

    public void setLast(Heap last) {
        this.last = last;
    }
}
