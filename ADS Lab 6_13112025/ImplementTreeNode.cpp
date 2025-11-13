#include <iostream>
using namespace std;

//define the tree node
struct Node {
    string value;   // the data or label of the node (e.g., "A", "B", "C")
    Node* left;     // pointer to the left child node
    Node* right;    // pointer to the right child node

    //constructor to initialize a new node
    Node(string val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

//function to build the tree
Node* buildTree() {
    */

    //create all the nodes
    Node* root = new Node("A");
    root->left = new Node("B");
    root->right = new Node("C");

    root->left->left = new Node("D");
    root->right->left = new Node("E");
    root->right->right = new Node("F");

    return root;
}

//tree traversal function

//in order (left -> root -> right)
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

//preorder traversal (root -> left -> right)
void preorder(Node* root) {
    if (root == nullptr)
        return;
    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}

//postorder traversal (left -> right -> root)
void postorder(Node* root) {
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
}

//main function
int main() {
    //build the tree
    Node* root = buildTree();
    
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
