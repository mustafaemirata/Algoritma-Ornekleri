#include <stdio.h>

int binarySearch(int array[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return mid;
        }
        if (array[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }

    return -1; 
}

int main() {
    int array[] = {2, 3, 4, 10, 23, 40, 55};
    int size = sizeof(array) / sizeof(array[0]);
    int target = 4;

    int result = binarySearch(array, size, target);

    if (result != -1) {
        printf("Eleman %d indeks %d 'de bulundu.\n", target, result);
    } else {
        printf("Eleman %d dizide yok.\n", target);
    }

    return 0;
}
