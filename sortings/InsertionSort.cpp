#include <iostream>
#include <utility>

#include "../utils/BinarySearch.cpp"

class InsertionSort {
public:
    static void sort(int *arr, int n) {
        int tmp;
        int i;
        for (int j = 1; j < n; ++j) {
            tmp = arr[j];
            i = j;

            while (i > 0 && arr[i - 1] > tmp) {
                arr[i] = arr[i - 1];
                i--;
            }
            arr[i] = tmp;
        }
    }

    static void sortBin(int *arr, int n) {
        int j, tmp;
        for (int i = 1; i < n; ++i) {
            j = i;
            tmp = binSearch(arr, 0, j, arr[i]);
            while (j > tmp) {
                std::swap(arr[j], arr[j - 1]);
                j--;
            }
        }
    }
};
