#include <iostream>
#include <utility>

class SelectionSort {
public:
    static void sort(int *arr, int n) {
        int min = 0;
        for (int i = 0; i < n - 1; ++i) {
            min = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            if (min != i) {
                std::swap(arr[i], arr[min]);
            }
        }
    }
};
