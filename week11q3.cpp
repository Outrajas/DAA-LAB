#include <iostream>
#include <queue>
using namespace std;

struct Item { int weight, value; };
struct Node { int level, profit, bound, weight; };

int bound(Node u, int n, int W, Item arr[]) {
    if (u.weight >= W) return 0;
    int profit_bound = u.profit, j = u.level + 1, totalWeight = u.weight;
    while (j < n && totalWeight + arr[j].weight <= W) {
        totalWeight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }
    return profit_bound;
}

int knapsack(int W, Item arr[], int n) {
    queue<Node> Q; Node u, v = {0, 0, 0, 0};
    Q.push(v); int maxProfit = 0;

    while (!Q.empty()) {
        u = Q.front(); Q.pop();
        if (u.level == n - 1) continue;
        v.level = u.level + 1;
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;
        if (v.weight <= W && v.profit > maxProfit) maxProfit = v.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit) Q.push(v);
        v.weight = u.weight, v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit) Q.push(v);
    }
    return maxProfit;
}

int main() {
    Item arr[] = {{2, 10}, {3, 20}, {4, 30}, {5, 40}};
    int W = 7, n = 4;
    cout << "Max Profit: " << knapsack(W, arr, n);
    return 0;
}

