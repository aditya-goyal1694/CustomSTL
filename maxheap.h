#include <iostream>
#include <stdexcept>
#include <limits>
using namespace std;

template<typename T>
class MinHeap {
private:
    T* heap;
    int c;      // capacity
    int s;      // size

    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

    void resizeHeap() {
        c += 20;
        T* newHeap = new T[c];
        for (int i = 0; i < s; ++i) {
            newHeap[i] = heap[i];
        }
        delete[] heap;
        heap = newHeap;
    }

    // For deleting the root
    void heapifyDown(int ind) {
        int mini = ind;
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;

        // Compare with left child
        if (left < s && heap[left] < heap[mini]) {
            mini = left;
        }

        // Compare with right child
        if (right < s && heap[right] < heap[mini]) {
            mini = right;
        }

        // If mini is not root, swap and continue heapifying
        if (mini != ind) {
            swap(heap[ind], heap[mini]);
            heapifyDown(mini);
        }
    }

    // For inserting a new element
    void heapifyUp(int ind) {
        int parent = (ind - 1) / 2;
        if (ind > 0 && heap[ind] < heap[parent]) {
            swap(heap[ind], heap[parent]);
            heapifyUp(parent);
        }
    }

public:
    // Constructor
    MinHeap(int cap) : c(cap), s(0) {
        heap = new T[c];
    }

    // Destructor
    ~MinHeap() {
        delete[] heap;
    }

    void insert(T element) {
        if (s == c) {
            resizeHeap();
        }

        heap[s] = element;
        heapifyUp(s);
        s++;
    }

    T extractMin() {
        if (s <= 0) {
            throw std::runtime_error("Heap is empty.");
        }
        T minElement = heap[0];
        heap[0] = heap[s - 1];
        s--;
        heapifyDown(0);
        return minElement;
    }

    T getMin() {
        if (s <= 0) {
            throw std::runtime_error("Heap is empty.");
        }
        return heap[0];
    }

    int getsize() {
        return s;
    }
};
