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

        // 从最后一个非叶子节点开始向上构造大顶堆
        for (int i = n / 2 - 1; i >= 0; i--) {
            int parent = i;
            while (parent < n / 2) {
                int largest = parent;
                int left = 2 * parent + 1; // 左子节点索引
                int right = 2 * parent + 2; // 右子节点索引

                if (left < n && arr[left] > arr[largest])
                    largest = left;
                if (right < n && arr[right] > arr[largest])
                    largest = right;

                if (largest == parent)
                    break;

                // 如果父节点不是最大值，则交换父节点与最大值节点的位置
                std::swap(arr[parent], arr[largest]);
                parent = largest; // 继续调整交换后的子树
            }
        }

        // 堆排序
        for (int i = n - 1; i > 0; i--) {
            // 将堆顶元素与最后一个元素交换，确保最大的元素到达数组的末尾
            std::swap(arr[0], arr[i]);

            // 对剩余元素重新构造大顶堆
            int parent = 0;
            while (parent < i / 2) {
                int largest = parent;
                int left = 2 * parent + 1; // 左子节点索引
                int right = 2 * parent + 2; // 右子节点索引

                if (left < i && arr[left] > arr[largest])
                    largest = left;
                if (right < i && arr[right] > arr[largest])
                    largest = right;

                if (largest == parent)
                    break;

                // 如果父节点不是最大值，则交换父节点与最大值节点的位置
                std::swap(arr[parent], arr[largest]);
                parent = largest; // 继续调整交换后的子树
            }
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
