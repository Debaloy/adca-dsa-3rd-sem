#include <stdio.h>
#define SIZE 10

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

void BubbleSort(int arr[SIZE], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[SIZE], n;

    do {
        printf("\n Enter how many elements to insert in array (<%d): ", SIZE);
        scanf("%d", &n);
    } while (n > SIZE || n <= 0);

    InputArray(arr, n);

    BubbleSort(arr, n);

    printf("\n Sorted array: ");
    PrintArray(arr, n);

    return 0;
}