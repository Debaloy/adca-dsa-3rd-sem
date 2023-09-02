#include <stdio.h>
#define SIZE 10

int BinarySearch(int arr[SIZE], int n, int key) {
    int flag = -1;
    int low = 0, mid = 0, high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (key == arr[mid]) {
            flag = mid;
            break;
        }
        else if (key > arr[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return flag;
}

int main() {
    int n, key, i, arr[SIZE];

    do {
        printf("\n Enter how many elements to insert in array (<%d): ", SIZE);
        scanf("%d", &n);
    } while (n > SIZE || n <= 0);

    printf("\n Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n Enter element you want to search: ");
    scanf("%d", &key);

    if (BinarySearch(arr, n, key) > -1) {
        printf("\n Element exists in the list");
    } else {
        printf("\n Element does not exist in the list");
    }

    return 0;
}