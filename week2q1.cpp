#include <iostream>
#include <vector>
using namespace std;

// Brute-force recursive function to solve 0/1 Knapsack problem
int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    if (n == 0 || W == 0)
        return 0;

    if (weights[n - 1] > W)
        return knapsack(W, weights, values, n - 1);

    return max(
        values[n - 1] + knapsack(W - weights[n - 1], weights, values, n - 1),
        knapsack(W, weights, values, n - 1)
    );
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50;
    int n = values.size();

    cout << "Maximum value in Knapsack: " << knapsack(W, weights, values, n) << endl;
    return 0;
}

