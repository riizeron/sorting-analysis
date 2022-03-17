#include <iostream>

class QuickSort {
private:
    static int partitionHoar(int *arr, int first, int last) {
        int pivot = arr[first + (last - first) / 2];

        int i = first;
        int j = last;

        while (!false) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i > j) {
                return j;
            } else if (i == j) {
                return -j;
            }
            std::swap(arr[i++], arr[j--]);
        }
    }

    static int partitionLomuto(int *arr, int first, int last) {
        int pivot = arr[last];
        int index = first - 1;

        for (int i = first; i < last; ++i) {
            if (arr[i] <= pivot) {
                index++;
                std::swap(arr[index], arr[i]);
            }
        }
        if (arr[last] < arr[index + 1]) {
            std::swap(arr[index + 1], arr[last]);
        }
        return index + 1;
    }

    static void sortHoar_(int *arr, int first, int last) {
        if (first < last) {
            int pivot = partitionHoar(arr, first, last);
            if (pivot >= 0) {
                sortHoar_(arr, first, pivot);
                sortHoar_(arr, pivot + 1, last);
            } else {
                sortHoar_(arr, first, -pivot - 1);
                sortHoar_(arr, -pivot + 1, last);
            }
        }
    }

    static void sortLomuto_(int *arr, int first, int last) {
        if (first < last) {
            int pivot = partitionLomuto(arr, first, last);
            sortLomuto_(arr, first, pivot - 1);
            sortLomuto_(arr, pivot + 1, last);
        }
    }

public:
    static void sortLomuto(int *arr, int n) {
        sortLomuto_(arr, 0, n - 1);
    }
    static void sortHoar(int *arr, int n) {
        sortHoar_(arr, 0, n - 1);
    }
};
