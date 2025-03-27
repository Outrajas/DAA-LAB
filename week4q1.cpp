#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};

    auto start = high_resolution_clock::now();
    insertionSort(arr);
    auto stop = high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}

