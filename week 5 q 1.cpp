#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int value) {
        key = value;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root =NULL;
    }

    void insert(int key) {
        root = insertRec(root, key);
    }

    Node* insertRec(Node* node, int key) {
        if (node == NULL) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insertRec(node->left, key);
        } else {
            node->right = insertRec(node->right, key);
        }
        return node;
    }

    int height() {
        return heightRec(root);
    }

    int heightRec(Node* node) {
        if (node == NULL) {
            return -1; // Height of an empty tree is -1
        }
        int leftHeight = heightRec(node->left);
        int rightHeight = heightRec(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    BST tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "Height of the BST: " << tree.height() << endl;
    return 0;
}
