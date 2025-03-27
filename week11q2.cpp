#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int> &set, int index, int sum, vector<int> &subset) {
    if (sum == 0) {
        cout << "Subset: ";
        for (size_t i = 0; i < subset.size(); i++)  // Traditional loop for compatibility
            cout << subset[i] << " ";
        cout << endl;
        return true;
    }
    if (index == set.size() || sum < 0) return false;
    
    // Include current element
    subset.push_back(set[index]);
    bool include = subsetSum(set, index + 1, sum - set[index], subset);
    
    // Exclude current element
    subset.pop_back();
    bool exclude = subsetSum(set, index + 1, sum, subset);

    return include || exclude;
}

int main() {
    vector<int> set;
    set.push_back(1);
    set.push_back(2);
    set.push_back(5);
    set.push_back(6);
    set.push_back(8);

    int target = 9;
    vector<int> subset;
    
    if (!subsetSum(set, 0, target, subset))
        cout << "No Subset Found";
    return 0;
}

