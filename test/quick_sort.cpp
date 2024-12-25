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
        swap(arr[low], arr[mid]);
    if (arr[low] > arr[high])
        swap(arr[low], arr[high]);
    if (arr[mid] > arr[high])
        swap(arr[mid], arr[high]);
    swap(arr[mid], arr[high - 1]);
    return arr[high - 1];
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = medianOfThree(arr, low, high);
    int i = low;
    int j = high - 1;

    while (true) {
        while (arr[++i] < pivot) {}
        while (arr[--j] > pivot) {}
        if (i < j)
            swap(arr[i], arr[j]);
        else
            break;
    }
    swap(arr[i], arr[high - 1]);
    return i;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(const std::vector<int>& arr) {
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    for (int i = 0; i < 1000; ++i) {
        arr.push_back(rand() % 1000); // Random numbers between 0 and 999999
    }
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    std::cout << "Sorted array: ";
    printArray(arr);
    return 0;
}