#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    auto start = high_resolution_clock::now();
    int totalNodes = countNodes(root);
    auto stop = high_resolution_clock::now();
    
    cout << "Total nodes in the tree: " << totalNodes << endl;

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}

