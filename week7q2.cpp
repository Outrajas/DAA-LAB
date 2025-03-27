#include <iostream>
#include <vector>
using namespace std;

void comparisonCountingSort(vector<int>& arr) {
    int n = arr.size();
    vector<int> count(n, 0);
    vector<int> sortedArr(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[j] < arr[i] || (arr[j] == arr[i] && j < i))
                count[i]++;

    for (int i = 0; i < n; i++)
        sortedArr[count[i]] = arr[i];

    arr = sortedArr;
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    comparisonCountingSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}

