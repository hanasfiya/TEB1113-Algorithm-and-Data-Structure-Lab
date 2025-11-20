#include <iostream>
using namespace std;

//problems on binary search tree

struct Node {
    int key;
    Node *left, *right;
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

class BST {
public:
    Node* root = NULL;

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else
            node->right = insert(node->right, key);

        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
};

int main() {
    BST tree;
    tree.root = tree.insert(tree.root, 8);
    tree.insert(tree.root, 3);
    tree.insert(tree.root, 10);
    tree.insert(tree.root, 1);
    tree.insert(tree.root, 6);

    cout << "Inorder traversal: ";
    tree.inorder(tree.root);
}
