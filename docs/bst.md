# BinarySearchTree Class Documentation

## Overview
The BinarySearchTree class template implements a binary search tree (BST) data structure. It allows for efficient searching, insertion, and deletion of nodes while maintaining the properties of a binary search tree.

## Key Features:
- Dynamic management of the binary search tree with support for generic data types.
- Provides methods for inserting, searching, removing, and traversing elements.
- Supports various traversal methods: inorder, preorder, postorder, level order (BFS), and depth-first search (DFS).

---

## Constructors

### Default Constructor
```cpp
BinarySearchTree();
```
- Initializes an empty binary search tree with a root pointer set to nullptr and size s set to 0.

---

## Destructor

### Destructor
```cpp
~BinarySearchTree();
```
- Destroys the binary search tree by clearing all nodes using the clear function.

---

## Tree Operations

### `insert` Method
```cpp
void insert(T element);
```
- Inserts a new element into the tree, maintaining the binary search tree properties.
- Increments the size of the tree.

### `search` Method
```cpp
bool search(T element);
```
- Searches for a specified element in the tree.
- Returns true if the element is found; otherwise, returns false.

### `remove` Method
```cpp
void remove(T element);
```
- Removes a specified element from the tree.
- Throws runtime_error if the element is not found.
- Decrements the size of the tree.

### `isEmpty` Method
```cpp
bool isEmpty();
```
- Checks if the tree is empty.
- Returns true if the tree is empty; otherwise, returns false.

### `getHeight` Method
```cpp
int getHeight();
```
- Returns the height of the tree.

---

## Traversal Methods

### `inorder` Method
```cpp
void inorder();
```
- Performs an inorder traversal of the tree and outputs the node values in ascending order.
- Displays a message if the tree is empty.

### `preorder` Method
```cpp
void preorder();
```
- Performs a preorder traversal of the tree and outputs the node values.
- Displays a message if the tree is empty.

### `postorder` Method
```cpp
void postorder();
```
- Performs a postorder traversal of the tree and outputs the node values.
- Displays a message if the tree is empty.

### `levelOrder` Method
```cpp
void levelOrder();
```
- Performs a level order traversal (BFS) of the tree and outputs the node values.
- Displays a message if the tree is empty.

### `bfs` Method
```cpp
void bfs();
```
- Alias for levelOrder() to indicate breadth-first search traversal.

### `dfs` Method
```cpp
void dfs();
```
- Performs a depth-first search traversal of the tree (similar to preorder) and outputs the node values.
- Displays a message if the tree is empty.

---

## Private Methods

### `clear` Method
```cpp
void clear(Node *node);
```
- Recursively clears the tree starting from the given node.

### Recursive Helper Functions
- `insert(Node *node, T element)`: Recursively inserts a new node into the correct position.
- `search(Node *node, T element)`: Recursively searches for a specified element.
- `deleteElement(Node *node, T element)`: Recursively searches for and deletes a specified element from the tree.
- `findMin(Node *node)`: Finds the node with the minimum value in a subtree.
- `getHeight(Node *node)`: Returns the height of the tree starting from the given node.

### Recursive Traversal Methods
Recursively implement various traversal strategies:
- `inorderTraversal(Node *node)`
- `preorderTraversal(Node *node)`
- `postorderTraversal(Node *node)`
- `levelOrderTraversal()`
- `dfsTraversal(Node *node)`

---

## Node Structure

### Node
The binary search tree implementations use a nested Node structure to store values.

```cpp
struct Node
{
    T data;   // Stores the data of type T.
    Node* left;   // Pointer to the left child node.
    Node* right;  // Pointer to the right child node.

    Node(T val) : data(val), left(nullptr), right(nullptr) {}
};
```

- `data`: Stores the data of type T.
- `left`: Pointer to the left child node.
- `right`: Pointer to the right child node.

---

## Member Variables

- `Node *root`: Pointer to the root of the binary search tree.
- `int s`: Tracks the current size of the tree.
