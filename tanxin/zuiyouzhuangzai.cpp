#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the Optimal Loading Problem
int optimalLoading(vector<int>& weights, int capacity) {
    // Sort the weights in non-decreasing order
    sort(weights.begin(), weights.end());

    int totalWeight = 0;
    int itemCount = 0;

    // Load items until the capacity is reached
    for (int weight : weights) {
        if (totalWeight + weight <= capacity) {
            totalWeight += weight;
            itemCount++;
        } else {
            break;
        }
    }

    return itemCount;
}

int main() {
    vector<int> weights = {10, 20, 30, 40, 50};
    int capacity = 100;

    int result = optimalLoading(weights, capacity);
    cout << "Maximum number of items that can be loaded: " << result << endl;

    return 0;
}