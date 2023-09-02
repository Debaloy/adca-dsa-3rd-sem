#include <stdio.h>
#define SIZE 10

int LinearSearch(int arr[SIZE], int n, int key) {
    int flag = -1, i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            flag = i;
            break;
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

    if (LinearSearch(arr, n, key) > -1) {
        printf("\n Element exists in the list");
    } else {
        printf("\n Element does not exist in the list");
    }

    return 0;
}