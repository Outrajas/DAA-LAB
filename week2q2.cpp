#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
vector<vector<int>> costMatrix;
vector<bool> assigned;
int minCost = INT_MAX;

void bruteForceAssignment(int person, int currentCost) {
    if (person == n) {
        minCost = min(minCost, currentCost);
        return;
    }

    for (int job = 0; job < n; job++) {
        if (!assigned[job]) {
            assigned[job] = true;
            bruteForceAssignment(person + 1, currentCost + costMatrix[person][job]);
            assigned[job] = false;
        }
    }
}

int main() {
    costMatrix = {{9, 2, 7, 8},
                  {6, 4, 3, 7},
                  {5, 8, 1, 8},
                  {7, 6, 9, 4}};
    n = costMatrix.size();
    assigned.resize(n, false);

    bruteForceAssignment(0, 0);
    cout << "Minimum cost of assignment: " << minCost << endl;
    return 0;
}

