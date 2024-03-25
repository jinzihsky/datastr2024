#include <iostream>
#include <vector>
#include <string>
using namespace std;

class StudentSorter {
private:
    vector<int> numbers;

    static void insertionSort(vector<int>& arr) {
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

    static int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    static void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    static void merge(vector<int>& arr, int l, int m, int r) {
        vector<int> L(arr.begin() + l, arr.begin() + m + 1);
        vector<int> R(arr.begin() + m + 1, arr.begin() + r + 1);
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

    static void mergeSort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    static void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    static void heapSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

public:
    StudentSorter(const string& studentId) {
        for (char digit : studentId.substr(1)) {
            numbers.push_back(digit - '0');
        }
    }

    vector<int> sortAndAdd(int modResult) {
        vector<int> sorted1(numbers), sorted2(numbers), sorted3(numbers);
        switch (modResult) {
            case 0:
                insertionSort(sorted1);
                quickSort(sorted2, 0, sorted2.size() - 1);
                mergeSort(sorted3, 0, sorted3.size() - 1);
                break;
            case 1:
                quickSort(sorted1, 0, sorted1.size() - 1);
                mergeSort(sorted2, 0, sorted2.size() - 1);
                heapSort(sorted3);
                break;
            case 2:
                mergeSort(sorted1, 0, sorted1.size() - 1);
                heapSort(sorted2);
                insertionSort(sorted3);
                break;
            case 3:
                heapSort(sorted1);
                insertionSort(sorted2);
                quickSort(sorted3, 0, sorted3.size() - 1);
                break;
        }

        vector<int> result(numbers.size(), 0);
        for (size_t i = 0; i < numbers.size(); i++) {
            result[i] = sorted1[i] + sorted2[i] + sorted3[i];
        }
        return result;
    }
};

int main() {
    string studentId;
    cout << "Enter an 8-digit student ID: ";
    cin >> studentId;

    if (studentId.size() != 8 || !isalpha(studentId[0])) {
        cout << "Invalid input format." << endl;
        return 1;
    }

    StudentSorter sorter(studentId);
    int modResult = (studentId.back() - '0') % 4;
    vector<int> result = sorter.sortAndAdd(modResult);

    cout << "Resulting numbers after sorting and adding: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
