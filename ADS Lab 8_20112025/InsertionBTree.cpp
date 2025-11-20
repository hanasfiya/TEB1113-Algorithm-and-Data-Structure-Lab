#include <iostream>
using namespace std;

//btree declaration

class BTreeNode {
public:
    int *keys, n, t;
    bool leaf;
    BTreeNode **C;

    BTreeNode(int t, bool leaf);
    void insertNonFull(int k);
    void splitChild(int i, BTreeNode* y);
    void traverse();
};

class BTree {
public:
    BTreeNode *root;
    int t;

    BTree(int t) : t(t), root(NULL) {}
    void insert(int k);
    void traverse() { if (root) root->traverse(); }
};

//insertion

BTreeNode::BTreeNode(int t, bool leaf) {
    this->t = t;
    this->leaf = leaf;
    keys = new int[2*t - 1];
    C = new BTreeNode*[2*t];
    n = 0;
}

void BTree::insert(int k) {
    if (!root) {
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
        return;
    }

    if (root->n == 2*t - 1) {
        BTreeNode *s = new BTreeNode(t, false);
        s->C[0] = root;
        s->splitChild(0, root);
        int i = (s->keys[0] < k);
        s->C[i]->insertNonFull(k);
        root = s;
    }
    else {
        root->insertNonFull(k);
    }
}

void BTreeNode::insertNonFull(int k) {
    int i = n - 1;

    if (leaf) {
        while (i >= 0 && keys[i] > k) {
            keys[i+1] = keys[i];
            i--;
        }
        keys[i+1] = k;
        n++;
    }
    else {
        while (i >= 0 && keys[i] > k) i--;
        if (C[i+1]->n == 2*t - 1) {
            splitChild(i+1, C[i+1]);
            if (keys[i+1] < k) i++;
        }
        C[i+1]->insertNonFull(k);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t-1;

    for (int j = 0; j < t-1; j++)
        z->keys[j] = y->keys[j+t];

    if (!y->leaf)
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j+t];

    y->n = t-1;

    for (int j = n; j >= i+1; j--)
        C[j+1] = C[j];

    C[i+1] = z;

    for (int j = n-1; j >= i; j--)
        keys[j+1] = keys[j];

    keys[i] = y->keys[t-1];

    n++;
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

    bt.insert(10);
    bt.insert(20);
    bt.insert(5);
    bt.insert(6);
    bt.insert(12);

    cout << "B-Tree elements: ";
    bt.traverse();
}

