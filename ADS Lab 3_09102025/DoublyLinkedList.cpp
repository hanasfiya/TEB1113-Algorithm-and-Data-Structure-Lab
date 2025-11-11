//doubly linked list

#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;
};

int main() {

    Node node1, node2, node3, node4;

    node1.data = "test1";
    node2.data = "test2";
    node3.data = "test3";
    node4.data = "test4";

    node1.next = &node2;
    node1.prev = nullptr;

    node2.next = &node3;
    node2.prev = &node1;

    node3.next = &node4;
    node3.prev = &node2;

    node4.next = nullptr;
    node4.prev = &node3;

    cout << "Forward Traversal:" << endl;
    Node* current = &node1;
    while (current != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }

    cout << endl;

    cout << "Backward Traversal:" << endl;
    current = &node4;
    while (current != nullptr) {
        cout << current->data << endl;
        current = current->prev;
    }

    return 0;
}