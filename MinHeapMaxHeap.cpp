#include <iostream>
#include <vector>
using namespace std;

//max heap

class MaxHeap {
public:
    vector<int> heap;

    void insert(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;

        while (i > 0 && heap[(i - 1)/2] < heap[i]) {
            swap(heap[i], heap[(i - 1)/2]);
            i = (i - 1)/2;
        }
    }

    void removeMax() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
    }

    void heapify(int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    void display() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

//min heap

class MinHeap {
public:
    vector<int> heap;

    void insert(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;

        while (i > 0 && heap[(i - 1)/2] > heap[i]) {
            swap(heap[i], heap[(i - 1)/2]);
            i = (i - 1)/2;
        }
    }

    void removeMin() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
    }

    void heapify(int i) {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;

        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    void display() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

//main function

int main() {
    cout << "=== Max Heap ===\n";
    MaxHeap maxH;
    maxH.insert(10);
    maxH.insert(40);
    maxH.insert(30);
    maxH.insert(5);
    maxH.display();
    maxH.removeMax();
    maxH.display();

    cout << "\n=== Min Heap ===\n";
    MinHeap minH;
    minH.insert(10);
    minH.insert(40);
    minH.insert(3);
    minH.insert(5);
    minH.display();
    minH.removeMin();
    minH.display();

    return 0;
}
