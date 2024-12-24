#include <iostream>
#include <vector>

int countWaysRecursion(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 2;

    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int main() {
    int n = 10; // 例如，计算n=10时的方法数
    std::cout << "n:" << std::endl;
    std::cin >> n;
    std::cout << "Number of ways to transfer beans using recursion: " << countWaysRecursion(n) << std::endl;
    return 0;
}
