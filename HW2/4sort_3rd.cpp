#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>
#include <random>

class StudentSorter {
private:
    std::vector<int> numbers;

    static void insertionSort(std::vector<int>& arr) {
        int i, j, k;
        for (i = 1; i < arr.size(); i++) {
            k = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > k) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = k;
        }
    }

    static void quickSort(std::vector<int>& arr, int l, int h) {
        if (l < h) {
            int p = arr[h];
            int i = (l - 1);
            for (int j = l; j < h; j++) {
                if (arr[j] < p) {
                    i++;
                    std::swap(arr[i], arr[j]);
                }
            }
            std::swap(arr[i + 1], arr[h]);
            int pi = i + 1;
            quickSort(arr, l, pi - 1);
            quickSort(arr, pi + 1, h);
        }
    }

    static void mergeSort(std::vector<int>& arr, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2; 
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            std::vector<int> L(arr.begin() + l, arr.begin() + m + 1);
            std::vector<int> R(arr.begin() + m + 1, arr.begin() + r + 1);
            int i = 0, j = 0, k = l;
            while (i < L.size() && j < R.size()) {
                if (L[i] <= R[j]) {
                    arr[k++] = L[i++];
                } else {
                    arr[k++] = R[j++];
                }
            }
            while (i < L.size()) arr[k++] = L[i++];
            while (j < R.size()) arr[k++] = R[j++];
        }
    }


    static void heapSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            int p = i;
            while (p >= 0) {
                int lg = p;
                int l = 2 * p + 1;
                int r = 2 * p + 2;

                if (l < n && arr[l] > arr[lg])
                    lg = l;
                if (r < n && arr[r] > arr[lg])
                    lg = r;

                if (lg == p)
                    break;
                std::swap(arr[p], arr[lg]);
                p = lg;
            }
        }
        for (int i = n - 1; i > 0; i--) {
            std::swap(arr[0], arr[i]);
            int p = 0;
            while (p < i / 2) {
                int lg = p;
                int l = 2 * p + 1;
                int r = 2 * p + 2;

                if (l < i && arr[l] > arr[lg])
                    lg = l;
                if (r < i && arr[r] > arr[lg])
                    lg = r;

                if (lg == p)
                    break;
                std::swap(arr[p], arr[lg]);
                p = lg;
            }
        }
    }

public:
    void sortRandomNumbers(int count, int sortingMethod) {
        std::vector<int> arr(count);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(1, 50000);
        
        for (int i = 0; i < count; ++i) {
            arr[i] = dis(gen);
        }
        auto start = std::chrono::high_resolution_clock::now();
        switch(sortingMethod) {
            case 1:
                insertionSort(arr);
                break;
            case 2:
                quickSort(arr, 0, arr.size() - 1);
                break;
            case 3:
                mergeSort(arr, 0, arr.size() - 1);
                break;
            case 4:
                heapSort(arr);
                break;
            default:
                std::cout << "Invalid sorting method.\n";
                return;
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        
        std::cout<< duration.count() << "\n";
    }
};

int main() {
    StudentSorter sorter;
    int c;

    std::cout << "1. Insertion Sort\n";
    std::cout << "2. Quick Sort\n";
    std::cout << "3. Merge Sort\n";
    std::cout << "4. Heap Sort\n";
    std::cout << "Choose a sorting method:";
    std::cin >> c;
    
    sorter.sortRandomNumbers(10, c);
    sorter.sortRandomNumbers(50, c);
    sorter.sortRandomNumbers(100, c);
    sorter.sortRandomNumbers(200, c);
    sorter.sortRandomNumbers(500, c);
    sorter.sortRandomNumbers(800, c);
    sorter.sortRandomNumbers(1000, c);
    sorter.sortRandomNumbers(1500, c);
    sorter.sortRandomNumbers(3000, c);
    sorter.sortRandomNumbers(4500, c);
    sorter.sortRandomNumbers(6000, c);
    sorter.sortRandomNumbers(8000, c);
    sorter.sortRandomNumbers(10000, c);
    sorter.sortRandomNumbers(12500, c);
    sorter.sortRandomNumbers(25000, c);
    sorter.sortRandomNumbers(37500, c);
    sorter.sortRandomNumbers(50000, c);
    sorter.sortRandomNumbers(62500, c);
    sorter.sortRandomNumbers(75000, c);
    sorter.sortRandomNumbers(87500, c);
    sorter.sortRandomNumbers(100000, c);

    return 0;
}
