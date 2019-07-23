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

    private static int partition(int[] array, int left, int right, int pivot) {
        while (left <= right) {

            while (array[left] < pivot) {
                left++;
            }

            while (array[right] > pivot) {
                right--;
            }

            if (left <= right)
                swap(array, left++, right--);
        }

        return left;

    }

    private static void quickSort(int[] array, int left, int right) {
        if (left >= right)
            return;

        int pivot = array[(left + right) / 2];
        int index = partition(array, left, right, pivot);

        quickSort(array, left, index -1);
        quickSort(array, index, right);

    }

    public static void main(String[] args) {

        int[] array = {27, 14, 16, 22, 8, 6, 4, 1, 7, 6, 3, 8, 14, -1, -6, 18, 24};

        quickSort(array, 0, array.length - 1);
        displayAll(array);

    }
}
