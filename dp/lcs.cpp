#include <iostream>
#include <vector>
#include <string>

// 动态规划求解最长公共子序列的长度
int lcsLength(const std::string &X, const std::string &Y) {
    int m = X.length();
    int n = Y.length();
    std::vector<std::vector<int>> L(m + 1, std::vector<int>(n + 1, 0));

    // 构建L[m+1][n+1]，L[i][j]包含X[0..i-1]和Y[0..j-1]的LCS长度
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = std::max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

// 打印最长公共子序列
void printLCS(const std::vector<std::vector<int>> &L, const std::string &X, const std::string &Y, int i, int j) {
    if (i == 0 || j == 0)
        return;
    if (X[i - 1] == Y[j - 1]) {
        printLCS(L, X, Y, i - 1, j - 1);
        std::cout << X[i - 1];
    } else if (L[i - 1][j] > L[i][j - 1]) {
        printLCS(L, X, Y, i - 1, j);
    } else {
        printLCS(L, X, Y, i, j - 1);
    }
}

int main() {
    std::string X = "AGGTAB";
    std::string Y = "GXTXAYB";
    int m = X.length();
    int n = Y.length();

    std::vector<std::vector<int>> L(m + 1, std::vector<int>(n + 1, 0));

    std::cout << "Length of LCS is " << lcsLength(X, Y) << std::endl;

    // 构建L[m+1][n+1]用于打印LCS
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = std::max(L[i - 1][j], L[i][j - 1]);
        }
    }

    std::cout << "LCS of " << X << " and " << Y << " is ";
    printLCS(L, X, Y, m, n);
    std::cout << std::endl;

    return 0;
}
