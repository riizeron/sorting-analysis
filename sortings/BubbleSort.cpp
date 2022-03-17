#include <iostream>
#include <utility>
class BubbleSort {
public:
    static void sort(int *arr, int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    static void sortA1(int *arr, int n) {
        int i = 0;
        bool t = true;
        while (t) {
            t = false;
            for (int j = 0; j < n - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    t = true;
                }
            }
            i++;
        }
    }

    static void sortA2(int *arr, int n) {
        int i = 0;
        bool t = true;
        while (t) {
            t = false;
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    t = true;
                }
            }
            i++;
        }
    }
};
