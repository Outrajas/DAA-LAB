#include <iostream>
#include <vector>
using namespace std;

void distributionCountingSort(vector<int>& arr) {
    int n = arr.size();
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    vector<int> count(range, 0);
    vector<int> output(n);

    for (int i = 0; i < n; i++)
        count[arr[i] - minVal]++;

    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    distributionCountingSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}

