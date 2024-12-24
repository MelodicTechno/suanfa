/**
 * 将输入的数字序列用递归方式倒序
 * 输入：
 * 4
 * 1 2 3 4
 * 输出：4 3 2 1
 */

#include <iostream>

using namespace std;

void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void daoxu(int a[], int i, int n) {
    if (i >= n - 1) {
        return;
    }

    swap(a, i, n - 1);

    daoxu(a, i + 1, n - 1);
}

int main() {
    static int n;

    cout << "the length of the numbers: (it should below 10)" << endl;
    cin >> n;
    int a[10];

    cout << "the numbers: (seperate with blanks)" << endl;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    daoxu(a, 0, n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}