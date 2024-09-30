# CustomSTL Documentation

## Overview
The CustomSTL header serves as a comprehensive collection of various custom data structures and algorithms. This header file includes implementations of essential data structures like trees, graphs, stacks, queues, heaps, and custom container classes. It is designed to provide flexibility and modularity, allowing users to use these custom implementations in their projects.

## Included Data Structures
The following data structures and classes are included in the CustomSTL header:

### Custom Vector (customVector.h)
A dynamically resizable array that grows as more elements are added. Provides operations like insertion, deletion, and random access.

### Linked List (linkedList.h)
A singly linked list with nodes pointing to the next node. Supports common list operations like insertion, deletion, and traversal.

### Circular Linked List (circularLinkedList.h)
A linked list where the last node points back to the head, forming a circular structure. Useful for circular buffers or round-robin scheduling.

### Doubly Linked List (doublyLinkedList.h)
A linked list where each node points to both its previous and next nodes, allowing traversal in both directions.

### Custom Stack (customStack.h)
A custom implementation of a stack, a last-in, first-out (LIFO) data structure. Supports push, pop, and top operations.

### Monotonic Stack (monotonicStack.h)
A stack that maintains elements in either strictly increasing or decreasing order. Useful in certain optimization problems, such as those involving ranges.

### Custom Queue (customQueue.h)
A custom implementation of a first-in, first-out (FIFO) queue with basic operations like enqueue, dequeue, and access to the front and rear of the queue.

### Custom Deque (customDeque.h)
A double-ended queue (deque) allowing insertion and removal of elements from both ends efficiently.

### Binary Tree (binaryTree.h)
Provides an implementation of a binary tree structure with nodes containing left and right child pointers. Common operations like insertion, traversal, and searching are supported.

### Binary Search Tree (bst.h)
An extension of the binary tree that follows the binary search tree property: the left child of a node contains values less than the node's value, and the right child contains values greater than the node's value.

### Min Heap (minheap.h)
A binary heap where the parent node is always less than or equal to its children. Useful for efficiently finding the smallest element.

### Max Heap (maxheap.h)
A binary heap where the parent node is always greater than or equal to its children. Commonly used in priority queues.

### Graph (graph.h)
Represents an undirected graph. Includes various graph algorithms such as DFS, BFS, and shortest path finding.

### Directed Graph (directedGraph.h)
Represents a graph with directed edges. Contains methods for traversal (DFS, BFS), topological sorting, and shortest path algorithms.

---

## Usage
To use the data structures in this header, include CustomSTL.h in your project:
```cpp
#include "CustomSTL.h"
```
You can then use any of the included data structures by including the corresponding header file. Each data structure has its own comprehensive set of methods and operations to suit your needs.

Example
Here is a simple example demonstrating how to use some of the custom data structures:

```cpp
#include "CustomSTL.h"
#include <iostream>

int main() {
    // Using custom vector
    customVector<int> vec = {1, 2, 3, 4};
    vec.push_back(5);
    vec.sort();
    
    // Using custom stack
    customStack<int> stack;
    stack.push(10);
    stack.push(20);
    std::cout << "Top element: " << stack.top() << std::endl;
    
    // Using binary search tree
    BST<int> bst;
    bst.insert(15);
    bst.insert(10);
    bst.insert(20);
    
    // Traversing the BST
    bst.inorderTraversal();  // Output: 10 15 20
    
    return 0;
}
```

---

## Structure
The CustomSTL header is modular, meaning each data structure is defined in its own file. Below is the list of files included in CustomSTL.h:

- `binaryTree.h`: Contains the BinaryTree class implementation.
- `bst.h`: Contains the BST (Binary Search Tree) class implementation.
- `circularLinkedList.h`: Contains the CircularLinkedList class implementation.
- `customDeque.h`: Contains the CustomDeque class implementation.
- `customQueue.h`: Contains the CustomQueue class implementation.
- `customStack.h`: Contains the CustomStack class implementation.
- `customVector.h`: Contains the CustomVector class implementation.
- `directedGraph.h`: Contains the DirectedGraph class implementation.
- `doublyLinkedList.h`: Contains the DoublyLinkedList class implementation.
- `graph.h`: Contains the Graph class implementation.
- `linkedList.h`: Contains the LinkedList class implementation.
- `maxheap.h`: Contains the MaxHeap class implementation.
- `minheap.h`: Contains the MinHeap class implementation.
- `monotonicStack.h`: Contains the MonotonicStack class implementation.

---

## Conclusion

The CustomSTL header provides a variety of essential data structures, each with a well-designed API, tailored for flexibility and performance. These implementations are suitable for academic purposes, personal projects, or even production code if required.