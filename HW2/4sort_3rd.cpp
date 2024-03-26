#include <iostream>
#include <vector>
#include <string>

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
            int parent = i;
            while (parent < n / 2) {
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
};

int main() {
    
    return 0;
}
