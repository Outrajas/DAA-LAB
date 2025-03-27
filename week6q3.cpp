#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& heap, int i, int size) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest]) largest = left;
    if (right < size && heap[right] > heap[largest]) largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, largest, size);
    }
}

void deleteElement(vector<int>& heap, int val) {
    int size = heap.size();
    int i;
    for (i = 0; i < size; i++) {
        if (heap[i] == val) break;
    }

    if (i == size) {
        cout << "Element not found!\n";
        return;
    }

    swap(heap[i], heap[size - 1]);
    heap.pop_back();

    heapify(heap, i, heap.size());
}

void printHeap(const vector<int>& heap) {
    for (int num : heap) cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> heap = {40, 30, 20, 15, 10, 5};
    
    cout << "Heap before deletion: ";
    printHeap(heap);
    
    deleteElement(heap, 20);
    
    cout << "Heap after deletion: ";
    printHeap(heap);

    return 0;
}

