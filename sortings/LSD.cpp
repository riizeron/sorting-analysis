#include <iostream>

class LSD {
private:
    static int digit(int x, int dgt) {
        return (x >> (8 * dgt)) & 255;
    }

public:
    static void sort(int* a, int n) {
        int* c = new int[256];
        int* b = new int[n];
        int d;
        for (int dgt = 0; dgt < 4; ++dgt) {
            for (int j = 0; j < 256; ++j) {
                c[j] = 0;
            }
            for (int j = 0; j < n; ++j) {
                d = digit(a[j], dgt);
                c[d]++;
            }
            for (int j = 1; j < 256; ++j) {
                c[j] += c[j - 1];
            }
            for (int j = n - 1; j >= 0; --j) {
                d = digit(a[j], dgt);
                c[d]--;
                b[c[d]] = a[j];
            }
            for (int j = 0; j < n; ++j) {
                a[j] = b[j];
            }
        }
        delete[] c;
        delete[] b;
    }
};
