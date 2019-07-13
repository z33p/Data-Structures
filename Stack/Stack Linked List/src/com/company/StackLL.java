package com.company;


public class StackLL {

    private Node next;

    public StackLL(Node next) {
        this.next = next;
    }

    public void push(int data) {

        Node newNode = new Node(data, null);

        if (this.next == null) {
            this.next = newNode;

        } else {
            Node temp = this.next;
            this.next = newNode;
            newNode.setNext(temp);

        }

    }

    public void pop() {
        if (this.next == null) {
            System.out.println("The linked list is empty!");
            System.exit(1);

        }

        if (this.next.getNext() == null) {
            this.next = null;

        } else {
            this.next = this.next.getNext();
        }
    }

    public int peek() {
        if (this.next == null) {
            System.out.println("Linked list is empty!");
            System.exit(1);
        }

        return this.next.getData();
    }

    public void displayAll() {
        int index = 0;
        Node temp = this.next;

        while (temp != null) {
            System.out.printf("%d. data: %d\n", ++index, temp.getData());
            temp = temp.getNext();
        }
    }
}
