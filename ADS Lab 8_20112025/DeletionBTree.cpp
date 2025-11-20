#include <iostream>
using namespace std;

//BTree Node
class BTreeNode {
public:
    int *keys, t, n;
    bool leaf;
    BTreeNode **C;

    BTreeNode(int t, bool leaf);
    int findKey(int k);
    void remove(int k);
    void traverse();
};

//BTree Wrapper
class BTree {
public:
    BTreeNode *root;
    int t;
    BTree(int t) : t(t), root(NULL) {}
    void remove(int k);
    void traverse() { if (root) root->traverse(); }
};

//BTree Deletion

BTreeNode::BTreeNode(int t, bool leaf) {
    this->t = t; this->leaf = leaf;
    keys = new int[2*t - 1];
    C = new BTreeNode*[2*t];
    n = 0;
}

int BTreeNode::findKey(int k) {
    int idx = 0;
    while (idx < n && keys[idx] < k) idx++;
    return idx;
}

void BTreeNode::remove(int k) {
    int idx = findKey(k);

    if (idx < n && keys[idx] == k) {
        if (leaf) {
            for (int i = idx+1; i < n; i++)
                keys[i-1] = keys[i];
            n--;
        }
        // (Advanced deletion for internal nodes omitted for lab simplicity)
    }
}

void BTree::remove(int k) {
    if (!root) return;
    root->remove(k);
}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (!leaf) C[i]->traverse();
        cout << keys[i] << " ";
    }
    if (!leaf) C[i]->traverse();
}

//main function

int main() {
    BTree bt(2);

    bt.root = new BTreeNode(2, true);
    bt.root->keys[0] = 5;
    bt.root->keys[1] = 10;
    bt.root->n = 2;

    cout << "Before deletion: ";
    bt.traverse();

    bt.remove(10);

    cout << "\nAfter deletion: ";
    bt.traverse();
}

