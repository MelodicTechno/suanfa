#include <iostream>
#include <vector>

using namespace std;

int maxWeight = 0;

void backtrack(vector<int>& weights, int capacity, int currentWeight, int index) {
    if (index == weights.size()) {
        if (currentWeight > maxWeight) {
            maxWeight = currentWeight;
        }
        std::cout << "currentWeight: " << currentWeight << " index: " << index << std::endl;
        return;
    }

    // Do not include the current item
    backtrack(weights, capacity, currentWeight, index + 1);

    // Include the current item if it doesn't exceed the capacity
    if (currentWeight + weights[index] <= capacity) {
        backtrack(weights, capacity, currentWeight + weights[index], index + 1);
    }
}

int main() {
    vector<int> weights = {3, 3, 4, 1}; // Example weights
    int capacity = 9; // Example capacity

    backtrack(weights, capacity, 0, 0);

    cout << "Maximum weight that can be loaded: " << maxWeight << endl;

    return 0;
}
