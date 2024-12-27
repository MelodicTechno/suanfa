#include <iostream>
#include <vector>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int medianOfThree(std::vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid])
        std::swap(arr[low], arr[mid]);
    if (arr[low] > arr[high])
        std::swap(arr[low], arr[high]);
    if (arr[mid] > arr[high])
        std::swap(arr[mid], arr[high]);
    // 将中位数放在high - 1的位置，以便作为基准
    std::swap(arr[mid], arr[high - 1]);
    return arr[high - 1];
}

int partition(std::vector<int>& arr, int low, int high) {
    // 使用median-of-three选择基准
    int pivot = medianOfThree(arr, low, high);
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high - 1]);
    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // 如果子数组长度为2，直接交换元素（如果需要）
        if (high - low == 1) {
            if (arr[low] > arr[high]) {
                std::swap(arr[low], arr[high]);
            }
            return;
        }

        // 执行划分
        int pi = partition(arr, low, high);

        // 递归排序左侧子数组
        if (low < pi - 1) {
            std::cout << "Sorting left subarray from " << low << " to " << pi - 1 << std::endl;
            quickSort(arr, low, pi - 1);
        }

        // 递归排序右侧子数组
        if (pi + 1 < high) {
            std::cout << "Sorting right subarray from " << pi + 1 << " to " << high << std::endl;
            quickSort(arr, pi + 1, high);
        }
    }
}

void printArray(const std::vector<int>& arr) {
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr;
    int n = 0;
    std::cout << "Enter the number of elements: " << std::endl;
    std::cin >> n;
    if (n <= 0) {
        std::cout << "The number of elements must be positive." << std::endl;
        return 1;
    }
    std::cout << "Enter the elements: " << std::endl;
    for (int i = 0; i < n; ++i) {
        int next;
        std::cin >> next;
        arr.push_back(next);
    }
    quickSort(arr, 0, n - 1);
    std::cout << "Sorted array: ";
    printArray(arr);
    return 0;
}
