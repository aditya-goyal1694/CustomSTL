# Custom STL in C++

## Introduction
This project is a custom implementation of the Standard Template Library (STL) in C++. It features various data structures, including vectors, stacks, queues, linked lists, trees, and maps, with additional custom methods for enhanced functionality.

## Overview
The CustomSTL header serves as a comprehensive collection of various custom data structures and algorithms. This header file includes implementations of essential data structures like trees, graphs, stacks, queues, heaps, maps, and custom container classes. It is designed to provide flexibility and modularity, allowing users to use these custom implementations in their projects.

---

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

### Custom Unordered Map (unorderedMap.h)
A hash table-based key-value data structure providing average O(1) time complexity for insert, find, and erase operations.

### Custom Ordered Map (orderedMap.h)
A self-balancing binary search tree-based key-value data structure providing ordered key traversal with logarithmic insert, find, and erase operations.

### Custom Unordered Set (unorderedSet.h)
A hash table-based set implementation offering average O(1) time complexity for insert, find, and erase operations.

### Custom Ordered Set (orderedSet.h)
A self-balancing binary search tree-based set implementation that maintains elements in sorted order with logarithmic time complexity for insert, find, and erase operations.

---

## Structure
The CustomSTL header is modular, meaning each data structure is defined in its own file. Below is the list of files included in CustomSTL.h:

- `binaryTree.h`
- `bst.h`
- `circularLinkedList.h`
- `customDeque.h`
- `customQueue.h`
- `customStack.h`
- `customVector.h`
- `directedGraph.h`
- `doublyLinkedList.h`
- `graph.h`
- `linkedList.h`
- `maxheap.h`
- `minheap.h`
- `monotonicStack.h`
- `unorderedMap.h`
- `orderedMap.h`
- `unorderedSet.h`
- `orderedSet.h`

---

## Getting Started

### Prerequisites
- C++ compiler (e.g., GCC or Clang)
- Basic understanding of data structures and algorithms

### Installation
1. Download the `CustomSTL-1.0-win32.zip` or `CustomSTL-1.0-win32.tar.gz`.
2. Extract the contents of the archive.
3. Include the `include/` folder in your C++ project and use the `customSTL.h` header for access to the library.

### Usage
To use the data structures in this header, include CustomSTL.h in your project:

```cpp
#include "CustomSTL.h"
```

Example:
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
    
    // Using ordered map
    orderedMap<int, std::string> omap;
    omap[1] = "Apple";
    omap[2] = "Banana";
    std::cout << "Value at key 1: " << omap[1] << std::endl;
    
    return 0;
}
```

### Compiling
Compile your C++ program with any C++ compiler:
```bash
g++ main.cpp -o main
./main
```

---

## Custom Methods
- Sorting (`sort()` for vector, stack, linked list)
- BFS & DFS (Graph traversal)
- Max Element & Min Element
- Array Rotation
- Hashing-based lookups for unorderedMap and unorderedSet
- Logarithmic access for orderedMap and orderedSet

---

## Future Improvements
- Extend the functionality to support more complex algorithms.
- Add parallel processing for certain operations.
- Optimize the current methods for better performance.
- Implement topoSort for DAGs.
- Implement sorting for Circular Linked Lists.

---

## References
- cplusplus.com: For STL documentation.
- geeksforgeeks.com: For some methods understanding and implementation.
- chat.openai.com: For debugging purposes.
- google.com: For random queries.

---

## Contributing
Feel free to fork the repository, create a branch, and submit pull requests. All contributions are welcome!