#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    
    buildMaxHeap(arr);
    
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};

    auto start = high_resolution_clock::now();
    heapSort(arr);
    auto stop = high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}

