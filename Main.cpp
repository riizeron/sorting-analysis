// 1) ПиАА 2022, Давыдов Вячеслав Олегович, БПИ208
// 2) Давыдов Вячеслав Олегович, БПИ208
// 3) Visual Studio Code. Graphics were made in jupyter notebook.
// 4) Сделано все. 
//      * Таблицы, графики есть
//      * Соответственно и результаты работы тоже получены
//      * Все алгоритмы сортировки работают правильно, тк все она прошли суровую школу контестов (да, все зашли)
//      * Массив не меняется, везде подается копия
//      * Измерения тоже все правильные, делал по инструкции
//      * csv файл тоже разумеется есть, иначе откуда взяться графикам
//      * Утечек и ничего подобного нет, память разумеется чищу (компилировал контестной командой - все ок)
//      * Рандомная генерация вообще какая то сверхумная со стаковерфлоу
//      * Все массивы генерируются правильно
//      * Графики все красивые, с осями, с тайтлами, с легендами
//      * Все комментраии к коду написаны.
//      * Задействован массив указателей на функции
//      * Все гррафики присутствуют
//      * Функция проверяющая массив на отсортированность реализована и применяется в коде. 
//
// 5) Функция записи массива в файлы присутствует ('utils/Arrays.cpp' - printToFile), но не используется, 
//      по причине ненахождения автором данного кода достойного ей применения.
//    
//    
//    

// P.S.1 Считаю важным сообщить, что вместо наименований 'случайный 0-5' 'случайный 0-4000' и тп, 
//      я предпочел использовать 'small_vals', 'big_vals', 'almost_sort' и 'reversed' соответственно.
//
// P.S.2 Так же сообщу, что при использоании сортировки подсчетом, 
//      я включил во время работы алгоритма поиск минимального и максимального значения,
//      так как я считаю, что они являются неотъемлемой частью нормально работы алгоритмаи 
//      не учитывать время затраченное на поиск минимума и максимума я посчитал неправильным.
//
// P.S.3 Наименования 'InserionSortB', 'BubbleSortA1', 'BubbleSortA1&2', осзначают сортировку
//      бинарными вставким, пузырьком с условием Айверсона 1, пузырьком с условие Айверсона 1 и 2
//      соответственно. А так же QuickSortH и QuickSortL означают ни что иное как
//      быстрые сортировки с разбиением Хоара и Ломуто соответственно.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <utility>
#include <ctime>
#include <chrono>
#include <cstring>

#include "sortings/BubbleSort.cpp"
#include "sortings/SelectionSort.cpp"
#include "sortings/InsertionSort.cpp"
#include "sortings/CountingSort.cpp"
#include "sortings/LSD.cpp"
#include "sortings/HeapSort.cpp"
#include "sortings/MergeSort.cpp"

#include "utils/Arrays.cpp"

int main() {

    // Array of pointer on variable sorting methods.
    void (*func_arr[12])(int *arr, int n){
        SelectionSort::sort, BubbleSort::sort,       BubbleSort::sortA1,    BubbleSort::sortA2,
        InsertionSort::sort, InsertionSort::sortBin, CountingSort::sort,    LSD::sort,
        MergeSort::sort,     QuickSort::sortHoar,    QuickSort::sortLomuto, HeapSort::sort};

    // Names of sorting methods
    // It is needed due to I didn't know how to use reflections such as java in c plus plus.
    std::string func_names[]{"SelectionSort", "BubbleSort",    "BubbleSortA1", "BubbleSortA1&2",
                             "InsertionSort", "InserionSortB", "CountingSort", "LSD",
                             "MergeSort",     "QuickSortH",    "QuickSortL",   "HeapSort"};

    // Names of those four arrays
    std::string type_names[4]{"small_vals", "big_vals", "almost_sorted", "reversed"};
    // Those four arrays
    int *arrays[4];
    Arrays::fillArrays(arrays);

    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    int64_t duration;
    
    // First and last value of array length.
    int gap[4]{50, 100, 301, 4101};
    // Step between length.
    int step[2]{10, 100};

    int *arr;

    std::string file_path[2]{"data/SMALL_.csv", "data/BIG_.csv"};
    // Open stream
    std::ofstream file;

    // A loop that determines whether the array will be big or small.
    for (int i = 0; i < 2; ++i) {
        file.open(file_path[i], std::ios_base::ate);

        // In next 7 strings we fill headers of csv file.
        file << "array size" << ',';
        for (int func = 0; func < 12; ++func) {
            for (int type = 0; type < 4; ++type) {
                file << func_names[func] << "_" << type_names[type] << ',';
            }
        }
        file << std::endl;

        // A loop of value of array lenght.
        for (int size = gap[i]; size < gap[i + 2]; size += step[i]) {
            file << size << ',';

            // A loop of sortings methods.
            for (int index = 0; index < 12; ++index) {

                // A loop of types of array.
                for (int type = 0; type < 4; ++type) {
                    arr = Arrays::getCopy(arrays[type], size);
                    start = std::chrono::high_resolution_clock::now();

                    func_arr[index](arr, size);

                    auto elapsed = std::chrono::high_resolution_clock::now() - start;
                    duration =
                        std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

                    if (!Arrays::isSorted(arr, size)) {
                        std::cout << "нехорошо" << std::endl;
                    }

                    file << duration << ',';
                    delete[] arr;
                }
            }
            file << std::endl;
        }
        file.close();
    }
    return 0;
}