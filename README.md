# Custom STL in C++
## Introduction
This project is a custom implementation of the Standard Template Library (STL) in C++. It features various data structures, including vectors, stacks, queues, linked lists, and trees, with additional custom methods for enhanced functionality.

## Features
Data Structures Implemented: 
- Vector
- Stack
- Queue
- Linked List
- Doubly Linked List
- Circular Linked List
- Monotonic Stack
- MinHeap
- MaxHeap
- Dequeue
- Trees
- Graphs

## Algorithms & Methods
- Sorting: Custom sorting methods for different data structures.
- Max Element: Find the maximum element in various containers.
- Min Element: Find the minimum element in various containers.
- Breadth-First Search (BFS): Traverse graphs using BFS.
- Depth-First Search (DFS): Traverse graphs using DFS.
- Array Rotation: Rotate arrays and lists by specified positions.

## Getting Started

### Prerequisites
C++ compiler (e.g., GCC or Clang)
Basic understanding of data structures and algorithms
### Installation
Clone the repository:

bash
Copy code
git clone https://github.com/your-repo/custom-stl.git

### Usage
Include the appropriate headers from the repository into your project files. For example, to use the custom vector:

cpp
Copy code
#include "customVector.h"

int main() {
    CustomVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.sort();
    return 0;
}
### Compiling
Compile your C++ program with any C++ compiler:

bash
Copy code
g++ main.cpp -o main
./main

## Custom Methods
- Sorting
The sort() function is implemented in various data structures such as vector, stack, and linked list. This method sorts the elements in ascending order.

- BFS & DFS (Graphs)
Graph traversal methods are provided to explore nodes using BFS and DFS techniques.

- Max Element & Min Element
You can find the maximum and minimum elements using maxElement() and minElement() methods in applicable data structures.

- Array Rotation
The rotate() method shifts the elements of arrays or lists by a given number of positions.

## Future Improvements
- Extend the functionality to support more complex algorithms.
- Add parallel processing for certain operations.
- Optimize the current methods for better performance.

## Contributing
Feel free to fork the repository, create a branch, and submit pull requests. All contributions are welcome!

