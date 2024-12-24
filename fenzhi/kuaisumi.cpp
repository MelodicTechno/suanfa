/**
 * 快速幂递归版
 * 输入：1.2
 *      2
 * 输出：1.44
 */

#include <iostream>
using namespace std;

double kuaisumi(double a, int n) {
    if (a == 0) {
        return 0.0;
    }

    if (n <= 0) return 1;

    double x = kuaisumi(a, n / 2);

    if (n % 2 == 1) {
        return x * x * a;
    }

    else {
        return x * x;
    }
}

int main() {
    double a = 0.0;
    int n = 0;
    cout << "input a:" << endl;
    cin >> a;
    cout << "input n: " << endl;
    cin >> n;
    cout << "output: " << endl;
    cout << kuaisumi(a, n);
}