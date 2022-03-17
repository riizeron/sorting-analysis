#include <iostream>

#include "../utils/Search.cpp"

class CountingSort {

private:
    static void sort_(int *arr, int n, int min, int max) {
        int64_t k = max - min + 1;
        int *c = new int[k];
        int *b = new int[n];
        for (int i = 0; i < k; ++i) {
            c[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            c[arr[i] - min]++;
        }
        for (int j = 1; j < k; ++j) {
            c[j] = c[j] + c[j - 1];
        }
        for (int i = n - 1; i >= 0; --i) {
            c[arr[i] - min]--;
            b[c[arr[i] - min]] = arr[i];
        }
        for (int i = 0; i < n; ++i) {
            arr[i] = b[i];
        }
        delete[] c;
        delete[] b;
    }

public:
    static void sort(int *arr, int n) {
        std::pair<int, int> min_and_max = getMinAndMax(arr, n);
        sort_(arr, n, min_and_max.first, min_and_max.second);
    }
};
