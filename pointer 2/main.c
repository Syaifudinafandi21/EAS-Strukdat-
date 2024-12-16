#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr; // pointer menunjuk ke elemen pertama array
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Elemen-elemen array:\n");
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, *(ptr + i));
    }

    return 0;
}

