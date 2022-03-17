#include <iostream>

int binSearch(int *arr, int left, int right, int key) {
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (arr[mid] > key) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return right;
}
