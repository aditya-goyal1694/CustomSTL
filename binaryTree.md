# BinaryTree Class Documentation

## Overview
The BinaryTree class template implements a binary tree data structure. It supports various 
### `traversal` methods, insertion, deletion, and modification of nodes, while maintaining the structure and properties of a binary tree.

## Key Features:
Dynamic management of the binary tree structure with support for generic data types.

### `Provides` methods for inserting, deleting, and modifying elements.
Supports various tree 
### `traversal` methods: preorder, inorder, postorder, level order, depth-first search (DFS), and breadth-first search (BFS).

---

## Constructors

### Default Constructor
```cpp
BinaryTree();
```
- Initializes an empty binary tree with a root pointer set to nullptr and size s set to 0.

---

## Destructor

### Destructor
```cpp
~BinaryTree();
```
- Destroys the binary tree by clearing all nodes using the clearTree function.

---

## Tree Operations

### `insert` Method
```cpp
void insert(T element);
```
- Inserts a new element into the tree using level order insertion.
- Increments the size of the tree.

### `modify` Method
```cpp
void modify(T oldVal, T newVal);
```
- Modifies the value of a specified node in the tree.
- Throws runtime_error if the value to modify is not found.

### `deleteElement` Method
```cpp
void deleteElement(T element);
```
- Deletes a specified element from the tree.
- Throws runtime_error if the tree is empty or the element is not found.
- Decrements the size of the tree.

### `getSize` Method
```cpp
int getSize();
```
- Returns the current size of the tree.

### `getHeight` Method
```cpp
int getHeight();
```
- Returns the height of the tree.

### `isEmpty` Method
```cpp
bool isEmpty();
```
- Checks if the tree is empty.
- Returns true if the tree is empty; otherwise, returns false.

### `find` Method
```cpp
bool find(T element);
```
- Searches for a specified element in the tree.
- Returns true if the element is found; otherwise, returns false.

### `getParent` Method
```cpp
T getParent(T element);
```
- Returns the parent of the specified element.
- Throws runtime_error if the element is the root or the parent is not found.

---

## Traversal Methods

### `preorder` Method
```cpp
void preorder();
```
- Performs a preorder traversal of the tree and outputs the node values.
- Displays a message if the tree is empty.

### `inorder` Method
```cpp
void inorder();
```
- Performs an inorder traversal of the tree and outputs the node values.
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
- Performs a depth-first search traversal (similar to preorder) of the tree and outputs the node values.
- Displays a message if the tree is empty.

---
 
## Private Methods

### `clearTree` Method
```cpp
void clearTree(Node *node);
```
- Recursively clears the tree starting from the given node.

### `getHeight` Method
```cpp
int getHeight(Node *node);
```
- Returns the height of the tree starting from the given node.

### `insertLevelOrder` Method
```cpp
Node *insertLevelOrder(Node *node, T element);
```
- Helper function to perform level order insertion of a new node.

### `findElement` Method
```cpp
Node *findElement(Node *node, T element);
```
- Searches for a specified element and returns the corresponding node.

### `findAndDelete` Method
```cpp
Node *findAndDelete(Node *node, T element);
```
- Searches for and deletes a specified element in the tree.

### `findParent` Method
```cpp
Node *findParent(Node *node, Node *child);
```
- Searches for the parent of a specified child node.

### Traversal Helper Methods
Recursively implements various traversal strategies:
- `preorderTraversal(Node *node)`
- `inorderTraversal(Node *node)`
- `postorderTraversal(Node *node)`
- `levelOrderTraversal(Node *node)`
- `dfsHelper(Node *node)`
- `printLevel(Node *node, int level)`

---

## Node Structure

### Node
The binary tree implementation use a nested Node structure to store values.

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

- `Node *root`: Pointer to the root of the binary tree.
- `int s`: Tracks the current size of the tree.