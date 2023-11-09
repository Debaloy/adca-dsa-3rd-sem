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

void Merge(int arr[SIZE], int low, int mid, int high) {
    int i = low, k = low;
    int j = mid + 1;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            sorted[k++] = arr[i++];
        } else {
            sorted[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        sorted[k++] = arr[i++];
    }

    while (j <= high) {
        sorted[k++] = arr[j++];
    }

    for (i = low; i <= high; i++) {
        arr[i] = sorted[i];
    }
}

void MergeSort(int arr[SIZE], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

int main() {
    int arr[SIZE], n;

    do {
        printf("\n Enter how many elements to insert in array (<%d): ", SIZE);
        scanf("%d", &n);
    } while (n > SIZE || n <= 0);

    InputArray(arr, n);

    MergeSort(arr, 0, n - 1);

    printf("\n Sorted array: ");
    PrintArray(arr, n);

    return 0;
}