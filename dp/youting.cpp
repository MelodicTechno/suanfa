#include <iostream>
#include <vector>
#include <algorithm>

// 假设每个游艇的租赁信息是一个 pair，第一个元素是租赁天数，第二个元素是收益
typedef std::pair<int, int> BoatRental;

// 动态规划解决游艇租赁问题
int maxProfit(const std::vector<BoatRental> &rentals, int maxDays) {
    // dp[i] 表示在 i 天内能够获得的最大收益
    std::vector<int> dp(maxDays + 1, 0);

    // 遍历每个游艇的租赁信息
    for (const auto &rental : rentals) {
        // 从后往前更新 dp 数组，以避免重复计算
        for (int i = maxDays; i >= rental.first; --i) {
            dp[i] = std::max(dp[i], dp[i - rental.first] + rental.second);
        }
    }

    // dp[maxDays] 就是最大收益
    return dp[maxDays];
}

int main() {
    // 示例：游艇租赁信息，第一个元素是租赁天数，第二个元素是收益
    std::vector<BoatRental> rentals = {{1, 50}, {2, 140}, {3, 200}, {4, 250}};
    int maxDays = 4; // 给定天数

    // 计算最大收益
    int profit = maxProfit(rentals, maxDays);
    std::cout << "Maximum profit for " << maxDays << " days is: " << profit << std::endl;

    return 0;
}
