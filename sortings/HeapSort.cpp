#include "../utils/BinHeap.cpp"

// I'm glad that I thought of translating this sort into void.
class HeapSort {
    public:
    static void sort(int *arr, int n) {
        BinHeap *heap = new BinHeap(arr, n);
        heap->sort(arr, n);
        delete heap;
    }
};
