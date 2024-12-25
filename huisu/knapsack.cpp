#include <iostream>
#include <vector>

using namespace std;

int maxWeight = 0; // 用于存储最大重量
int maxProfit = 0; // 用于存储最大价值

void backtrack(vector<int>& weights, vector<int>& values, int capacity, int currentWeight, int currentProfit, int index) {
    if (index == weights.size() || currentWeight == capacity) {
        // 更新最大价值和对应的最大重量
        if (currentProfit > maxProfit) {
            maxProfit = currentProfit;
            maxWeight = currentWeight;
        }
        return;
    }

    // 不选择当前物品
    backtrack(weights, values, capacity, currentWeight, currentProfit, index + 1);

    // 选择当前物品（前提是背包容量足够）
    if (currentWeight + weights[index] <= capacity) {
        backtrack(weights, values, capacity, currentWeight + weights[index], currentProfit + values[index], index + 1);
    }
}

int main() {
    vector<int> weights = {2, 1, 3, 2}; // 物品的重量
    vector<int> values = {12, 10, 20, 15}; // 物品的价值
    int capacity = 5; // 背包容量

    backtrack(weights, values, capacity, 0, 0, 0);

    cout << "Maximum profit that can be obtained: " << maxProfit << endl;
    cout << "Maximum weight that can be loaded: " << maxWeight << endl;

    return 0;
}
