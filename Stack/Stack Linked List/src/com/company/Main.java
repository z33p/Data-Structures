package com.company;



public class Main {

    public static void main(String[] args) {
        StackLL root = new StackLL(null);
        root.push(15);
        root.push(10);
        root.push(5);

        root.pop();
        root.pop();

        System.out.println(root.peek());

        root.displayAll();
    }
}
