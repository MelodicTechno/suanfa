#include <iostream>
using namespace std;

template<typename T>
void merge(T a[], int l, int m, int r) {
    int n1 = m - l + 1; // 左子数组的大小
    int n2 = r - m;     // 右子数组的大小

    T L[n1]; // 左子数组
    T R[n2]; // 右子数组

    // 拷贝数据到临时数组L和R
    for (int i = 0; i < n1; i++) {
        L[i] = a[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[m + 1 + j];
    }

    int i = 0; // 左子数组的初始索引
    int j = 0; // 右子数组的初始索引
    int k = l; // 合并后数组的初始索引

    // 合并临时数组回到原数组a
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // 拷贝L[]的剩余元素
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    // 拷贝R[]的剩余元素
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

template<typename T>
void mergeSort(T a[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // 分别对左右两半进行排序
        mergeSort(a, left, middle);
        mergeSort(a, middle + 1, right);

        // 合并两半
        merge(a, left, middle, right);
    }
}

int main() {
    int n;
    int a[50];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergeSort(a, 0, n - 1); // 注意右边界应该是n - 1
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
