#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int>& heap, int val) {
    heap.push_back(val);
    int i = heap.size() - 1;
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void display(vector<int>& heap) {
    for (int val : heap)
        cout << val << " ";
    cout << endl;
}

int main() {
    vector<int> heap;
    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 15);
    insert(heap, 30);
    insert(heap, 25);

    cout << "Heap: ";
    display(heap);

    return 0;
}

