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

void InsertionSort(int arr[SIZE], int n) {
    int i, j, temp;

    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;

        while (temp < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

int main() {
    int arr[SIZE], n;

    do {
        printf("\n Enter how many elements to insert in array (<%d): ", SIZE);
        scanf("%d", &n);
    } while (n > SIZE || n <= 0);

    InputArray(arr, n);

    InsertionSort(arr, n);

    printf("\n Sorted array: ");
    PrintArray(arr, n);

    return 0;
}