#include <stdio.h>
#define SIZE 10

int sorted[SIZE];

void InputArray(int arr[SIZE], int n) {
    int i;
    printf("\n Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void PrintArray(int arr[SIZE], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d", arr[i]);
        } else {
            printf("%d, ", arr[i]);
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int arr[SIZE], int low, int high) {
    int pivot = arr[low];
    int start = low, end = high;

    while (start < end) {
        while (arr[start] <= pivot)
            start++;
        while (arr[end] > pivot)
            end--;

        if (start < end)
            swap(&arr[start], &arr[end]);
    }

    swap(&arr[low], &arr[end]);
    return end;
}

void QuickSort(int arr[SIZE], int low, int high) {
    if (low < high) {
        int pivotPosition = Partition(arr, low, high);
        QuickSort(arr, low, pivotPosition - 1);
        QuickSort(arr, pivotPosition + 1, high);
    }
}

int main() {
    int arr[SIZE], n;

    do {
        printf("\n Enter how many elements to insert in array (<%d): ", SIZE);
        scanf("%d", &n);
    } while (n > SIZE || n <= 0);

    InputArray(arr, n);

    QuickSort(arr, 0, n - 1);

    printf("\n Sorted array: ");
    PrintArray(arr, n);

    return 0;
}