#include <iostream>
using namespace std;

void addMatrix(int** a, int** b, int** c, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subMatrix(int** a, int** b, int** c, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

int** strassen(int** a, int** b) {

}

int main() {

    int a[4][4] = {
        {1, 2, 3, 4},
        {2, 1, 4, 3},
        {3, 1, 4, 2},
        {4, 2, 3, 1}
    };

    int b[4][4] = {
        {1, 2, 2, 1},
        {2, 1, 1, 2},
        {3, 2, 2, 3},
        {2, 3, 3, 2}
    };


}