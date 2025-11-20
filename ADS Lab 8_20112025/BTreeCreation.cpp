#include <iostream>
using namespace std;

//B-Tree Creation

class BTreeNode {
public:
    int *keys;
    int t, n;
    bool leaf;
    BTreeNode **C;

    BTreeNode(int t, bool leaf);
    void traverse();
};

class BTree {
public:
    BTreeNode *root;
    int t;

    BTree(int t) {
        this->t = t;
        root = NULL;
    }
    
    void traverse() {
        if (root) root->traverse();
    }
};

BTreeNode::BTreeNode(int t, bool leaf) {
    this->t = t;
    this->leaf = leaf;
    keys = new int[2*t - 1];
    C = new BTreeNode*[2*t];
    n = 0;
}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (!leaf) C[i]->traverse();
        cout << keys[i] << " ";
    }
    if (!leaf) C[i]->traverse();
}

int main() {
    cout << "B-Tree created (t = 2)\n";
    BTree t(2);
    t.traverse();
}
