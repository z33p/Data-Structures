package com.company;



public class Main {

    private static void swap(final int[] arr, final int pos1, final int pos2){
        final int temp = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = temp;
    }

    private static void displayAll(final int[] array) {

        int i;
        for (i = 0; i < array.length -1; i++) {
            System.out.print(array[i] + ", ");
        }
        System.out.print(array[i] + "\n");
    }

    private static void bubbleSort(int[] array) {

        boolean sorted = false;
        while (!sorted) {
            sorted = true;
            for (int i = 0; i < array.length - 1; i++) {
                if (array[i] > array[i+1]) {
                    swap(array, i, i+1);
                    sorted = false;
                }
            }
        }
    }

    public static void main(String[] args) {

        int[] array = {27, 14, 16, 22, 8, 6, 4, 1, 7, 6, 3, 8, 14, -1, -6, 18, 24};
        bubbleSort(array);

        displayAll(array);

    }
}
