#include <iostream>
#include <list>
using namespace std;

class HashTable {
    int capacity;
    list<int>* table;

public:
    HashTable(int size) {
        capacity = size;
        table = new list<int>[capacity];
    }

    int hashFunction(int key) {
        return key % capacity;
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int val : table[index])
            if (val == key) return true;
        return false;
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << i << ": ";
            for (int val : table[i])
                cout << val << " ";
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(7);
    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);

    ht.display();

    cout << "Search 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    return 0;
}

