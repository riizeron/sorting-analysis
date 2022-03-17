#include <iostream>

int min = INT32_MAX;
int max = INT32_MIN;

std::pair<int, int> getMinAndMax(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return std::pair<int, int>(min, max);
}