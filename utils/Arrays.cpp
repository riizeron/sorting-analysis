#include <algorithm>
#include <fstream>

#include "Random.cpp"
#include "../sortings/QuickSort.cpp"

class Arrays {
public:
    // Method that fill array of those four.
    static void fillArrays(int *arrays[4]) {
        for (int i = 0; i < 4; ++i) {
            arrays[i] = generate(4100, i);
        }
    }
    // Arrays generation.
    static int *generate(int n, int flag) {
        int *res = new int[n];
        // values [0, 5]
        if (flag == 0) {
            for (int i = 0; i < n; ++i) {
                res[i] = Random::get(0, 5);
            }
        // values [0, 4000]
        } else if (flag == 1) {
            for (int i = 0; i < n; ++i) {
                res[i] = Random::get(0, 4000);
            }
        // almost sorted
        } else if (flag == 2) {
            for (int i = 0; i < n; ++i) {
                res[i] = Random::get(0, 4000);
            }
            QuickSort::sortHoar(res, n);
            // In each almost sorted array, there are about ten cases of incorrect arrangement of
            // elements.
            for (int i = 1; i < n; ++i) {
                if (!(i % (n / 10))) {
                    std::swap(res[i], res[i - 1]);
                }
            }
        // reversed
        } else {
            for (int i = 0; i < n; ++i) {
                res[i] = Random::get(1, 4100);
            }
            QuickSort::sortHoar(res, n);
            // Reverse array
            for (int i = 0; i < n / 2; ++i) {
                std::swap(res[i], res[n - i - 1]);
            }
        }
        return res;
    }

    static int *getCopy(int *arr, int n) {
        int *res = new int[n];
        for (int i = 0; i < n; ++i) {
            res[i] = arr[i];
        }
        return res;
    }

    static bool isSorted(int *arr, int n) {
        for (int i = 0; i < n - 1; ++i) {
            if(arr[i] > arr[i + 1]) {
                return false; 
            }
        }
        return true;
    }

    // for input and outpu txt 
    static void printToFile(int *arr, int n, std::string filepath) {
        std::ofstream f;
        f.open(filepath, std::ios_base::ate);
        for (int i = 0; i < n; ++i) {
            f << arr[i] << ' ';
        }
        f << std::endl;

    }
};
