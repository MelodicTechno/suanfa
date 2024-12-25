#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    if (n == 0 || W == 0)
        return 0;

    if (weights[n-1] > W)
        return knapsack(W, weights, values, n-1);

    else
        return max(values[n-1] + knapsack(W - weights[n-1], weights, values, n-1),
                   knapsack(W, weights, values, n-1));
}

int main() {
    int W = 50; // Maximum weight of knapsack
    vector<int> weights = {10, 20, 30}; // Weights of items
    vector<int> values = {60, 100, 120}; // Values of items
    int n = weights.size();

    cout << "Maximum value in Knapsack = " << knapsack(W, weights, values, n) << endl;

    return 0;
}