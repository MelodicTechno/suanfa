#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int level; // 当前考虑的货物索引
    int profit; // 当前装载的总重量
    float bound; // 当前节点的上界

    Node(int l, int p, float b) : level(l), profit(p), bound(b) {}
};

bool cmp(int a, int b) {
    return a > b;
}

float calculateBound(int level, int profit, int capacity, vector<int>& weights) {
    if (profit > capacity) return 0;
    float bound = profit;
    int totalWeight = 0;
    for (int i = level + 1; i < weights.size(); i++) {
        totalWeight += weights[i];
    }
    bound += (capacity - profit) * ((float)weights[level + 1] / totalWeight);
    return bound;
}

int knapsack(int capacity, vector<int>& weights) {
    sort(weights.begin(), weights.end(), cmp); // 按重量降序排序
    vector<Node> queue;
    Node u(0, 0, 0), v(0, 0, 0);
    u.bound = calculateBound(-1, 0, capacity, weights);
    queue.push_back(u);

    int maxProfit = 0;
    while (!queue.empty()) {
        u = queue.front();
        queue.erase(queue.begin());

        if (u.level == weights.size() - 1) continue;

        v.level = u.level + 1;

        // 不选择当前货物
        v.profit = u.profit;
        v.bound = calculateBound(v.level, v.profit, capacity, weights);
        if (v.bound > maxProfit) {
            queue.push_back(v);
        }

        // 选择当前货物
        v.profit = u.profit + weights[v.level];
        if (v.profit <= capacity && v.profit > maxProfit) {
            maxProfit = v.profit;
        }
        v.bound = calculateBound(v.level, v.profit, capacity, weights);
        if (v.bound > maxProfit) {
            queue.push_back(v);
        }
    }

    return maxProfit;
}

int main() {
    vector<int> weights = {2, 3, 4, 5}; // 货物重量
    int capacity = 5; // 船的载重限制

    int maxWeight = knapsack(capacity, weights);
    cout << "Maximum weight that can be loaded: " << maxWeight << endl;

    return 0;
}
