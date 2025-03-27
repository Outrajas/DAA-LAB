#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int height(Node* root, int& diameter) {
    if (!root) return 0;

    int leftHeight = height(root->left, diameter);
    int rightHeight = height(root->right, diameter);

    diameter = max(diameter, leftHeight + rightHeight);
    
    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(Node* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Diameter of the tree: " << diameterOfBinaryTree(root) << endl;
    
    return 0;
}

