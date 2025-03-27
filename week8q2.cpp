#include <iostream>
using namespace std;

class ClosedHashing {
    int size;
    int *table;
public:
    ClosedHashing(int n) {
        size = n;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1;
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunction(key);
        while (table[index] != -1)
            index = (index + 1) % size;
        table[index] = key;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << ": " << table[i] << endl;
    }
};

int main() {
    ClosedHashing ch(7);
    ch.insert(10);
    ch.insert(20);
    ch.insert(15);
    ch.insert(7);

    ch.display();

    return 0;
}

