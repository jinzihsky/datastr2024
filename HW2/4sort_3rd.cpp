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
        int i, j, key;
        for (i = 1; i < arr.size(); i++) {
            key = arr[i];
            j = i - 1;#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>
#include <random>

class StudentSorter {
private:
    std::vector<int> numbers;

    static void insertionSort(std::vector<int>& arr) {
        int i, j, key;
        for (i = 1; i < arr.size(); i++) {
            key = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    static void quickSort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            int pivot = arr[high];
            int i = (low - 1);
            for (int j = low; j < high; j++) {
                if (arr[j] < pivot) {
                    i++;
                    std::swap(arr[i], arr[j]);
                }
            }
            std::swap(arr[i + 1], arr[high]);
            int pi = i + 1;
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    static void mergeSort(std::vector<int>& arr, int l, int r) {
        if (l < r) {
            int m = l + (r - l + 1) / 2;
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
            int parent = i;
            while (parent >= 0) {
                int largest = parent;
                int left = 2 * parent + 1;
                int right = 2 * parent + 2;

                if (left < n && arr[left] > arr[largest])
                    largest = left;
                if (right < n && arr[right] > arr[largest])
                    largest = right;

                if (largest == parent)
                    break;
                std::swap(arr[parent], arr[largest]);
                parent = largest;
            }
        }
        for (int i = n - 1; i > 0; i--) {
            std::swap(arr[0], arr[i]);
            int parent = 0;
            while (parent < i / 2) {
                int largest = parent;
                int left = 2 * parent + 1;
                int right = 2 * parent + 2;

                if (left < i && arr[left] > arr[largest])
                    largest = left;
                if (right < i && arr[right] > arr[largest])
                    largest = right;

                if (largest == parent)
                    break;
                std::swap(arr[parent], arr[largest]);
                parent = largest;
            }
        }
    }

public:
    void sortRandomNumbers(int count, int sortingMethod) {
        std::vector<int> arr(count);
        
        // Generate random numbers
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(1, 50000);
        
        for (int i = 0; i < count; ++i) {
            arr[i] = dis(gen);
        }
        
        auto start = std::chrono::high_resolution_clock::now();
        
        // Choose sorting method
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
        
        std::cout << count << ":" << sortingMethod << ": " << duration.count() << " ns\n";
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

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    static void quickSort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            int pivot = arr[high];
            int i = (low - 1);
            for (int j = low; j < high; j++) {
                if (arr[j] < pivot) {
                    i++;
                    std::swap(arr[i], arr[j]);
                }
            }
            std::swap(arr[i + 1], arr[high]);
            int pi = i + 1;
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    static void mergeSort(std::vector<int>& arr, int l, int r) {
        if (l < r) {
            int m = l + (r - l + 1) / 2;
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
            int parent = i;
            while (parent >= 0) {
                int largest = parent;
                int left = 2 * parent + 1;
                int right = 2 * parent + 2;

                if (left < n && arr[left] > arr[largest])
                    largest = left;
                if (right < n && arr[right] > arr[largest])
                    largest = right;

                if (largest == parent)
                    break;
                std::swap(arr[parent], arr[largest]);
                parent = largest;
            }
        }
        for (int i = n - 1; i > 0; i--) {
            std::swap(arr[0], arr[i]);
            int parent = 0;
            while (parent < i / 2) {
                int largest = parent;
                int left = 2 * parent + 1;
                int right = 2 * parent + 2;

                if (left < i && arr[left] > arr[largest])
                    largest = left;
                if (right < i && arr[right] > arr[largest])
                    largest = right;

                if (largest == parent)
                    break;
                std::swap(arr[parent], arr[largest]);
                parent = largest;
            }
        }
    }

public:
    void chooseSortMethod(int method, std::vector<int>& arr) {
        switch (method) {
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
                std::cout << "Invalid choice!" << std::endl;
        }
    }

    void generateRandomData(std::vector<int>& arr) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> x_dist(10, 100000);
        std::uniform_int_distribution<> y_dist(1, 50000);

        int x = x_dist(gen);
        for (int i = 0; i < x; ++i) {
            arr.push_back(y_dist(gen));
        }
    }

    void measureTime(int method) {
        double total_time = 0;
        for (int i = 0; i < 20; ++i) {
            std::vector<int> arr;
            generateRandomData(arr);

            auto start = std::chrono::high_resolution_clock::now();

            chooseSortMethod(method, arr);

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end - start;
            total_time += diff.count();
        }
        std::cout << "Average time taken: " << (total_time / 20) * 1e9 << " nanoseconds" << std::endl;
    }
};

int main() {
    StudentSorter sorter;
    int choice;

    std::cout << "1. Insertion Sort\n";
    std::cout << "2. Quick Sort\n";
    std::cout << "3. Merge Sort\n";
    std::cout << "4. Heap Sort\n";
    std::cout << "Choose a sorting method:";
    std::cin >> choice;

    sorter.measureTime(choice);

    return 0;
}
