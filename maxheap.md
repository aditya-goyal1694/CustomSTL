# MaxHeap Class Documentation

## Overview
The MaxHeap class template implements a binary max-heap data structure. It allows for efficient insertion, extraction of the maximum element, and maintains the heap property.

## Key Features:
- Dynamic management of the heap structure with support for generic data types.
- Provides methods to insert elements and extract the maximum element.
- Maintains the heap property through up and down heapification.

---

## Constructor

### Default Constructor
```cpp
MaxHeap();
```
- Initializes an empty max-heap with a root pointer set to nullptr and size s set to 0.

---

## Destructor

### Destructor
```cpp
~MaxHeap();
```
- Destroys the max-heap by continuously extracting the maximum element until the heap is empty.

---

## Heap Operations

### `insert` Method
```cpp
void insert(T element);
```
- Inserts a new element into the heap.
- Creates a new node for the element and performs a level order insertion.
- Calls heapifyUp to maintain the heap property after insertion.

### `extractMax` Method
```cpp
T extractMax();
```
- Removes and returns the maximum element (root) from the heap.
- Finds the last node in the heap and replaces the root with it.
- Calls heapifyDown to restore the heap property.
- Throws runtime_error if the heap is empty.

### `getMax` Method
```cpp
T getMax() const;
```
- Returns the maximum element in the heap without removing it.
- Throws runtime_error if the heap is empty.

### `isEmpty` Method
```cpp
bool isEmpty() const;
```
- Checks if the heap is empty.
- Returns true if the heap is empty; otherwise, returns false.

### `getSize` Method
```cpp
int getSize() const;
```
- Returns the current size of the heap.

---

## Private Methods

### `swap` Method
```cpp
void swap(Node *a, Node *b);
```
- Swaps the data between two nodes.

### `heapifyDown` Method
```cpp
void heapifyDown(Node *node);
```
- Maintains the max-heap property by moving the node down the tree as necessary.

### `heapifyUp` Method
```cpp
void heapifyUp(Node *node);
```
- Maintains the max-heap property by moving the node up the tree as necessary.

### `insertNode` Method
```cpp
Node *insertNode(Node *node, T element);
```
- Helper function that performs level order insertion of a new node.

### `findLast` Method
```cpp
Node *findLast(Node *node);
```
- Finds the last node in the heap using level order traversal.

---

## Node Structure

### Node
The maxheap uses a nested Node structure to store values and maintain pointers to its children and parent.

```cpp
struct Node
{
    T data;            // The value stored in the node.
    Node *left;       // Pointer to the left child node.
    Node *right;      // Pointer to the right child node.
    Node *parent;     // Pointer to the parent node.

    Node(T val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
};
```
- `data`: Stores the value of type T.
- `left`: Pointer to the left child node.
- `right`: Pointer to the right child node.
- `parent`: Pointer to the parent node.

---

## Member Variables

- `struct Node`: A structure that represents a node in the heap, containing data, pointers to left and right children, and a parent pointer.
- `Node *root`: Pointer to the root of the max-heap.
- `int s`: Tracks the current size of the heap.