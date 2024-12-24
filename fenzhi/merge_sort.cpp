#include <iostream>
using namespace std;

template<typename T>
void merge(T a[], int l, int m, int r) {
    int n1 = r - m + 1;
    int n2 = m - l;

    T R[n1];
    T L[n2];
    for (int i = 0; i < n1; i++) {
        R[i] = a[l + i];
    }
    for (int i = 0; i < n2; i++) {
        L[i] = a[m + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

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
        mergeSort(a, left, middle);
        mergeSort(a, middle + 1, right);
        merge<T>(a, left, middle, right);
    }
}


int main() {
    int n;
    int a[50];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergeSort<int>(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}