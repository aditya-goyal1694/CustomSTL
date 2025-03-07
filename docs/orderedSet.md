# OrderedSet Class Documentation

## Overview
The `OrderedSet` class template provides a binary search tree (BST)-based implementation of a set that maintains elements in sorted order. It allows efficient insertions, deletions, and lookups while preserving the ordering of elements.

## Key Features:
- Implements an ordered set using a binary search tree.
- Ensures elements remain sorted.
- Insert, erase, and find operations in average O(log N) time complexity.

---

## Constructor

### Default Constructor
```cpp
OrderedSet();
```
- Initializes an empty ordered set.

---

## Destructor

### Destructor
```cpp
~OrderedSet();
```
- Destroys the set and deallocates all memory.

---

## Set Operations

### `insert` Method
```cpp
void insert(T key);
```
- Inserts a new element into the set.
- If the element already exists, the insertion is ignored.

### `erase` Method
```cpp
void erase(const T& key);
```
- Removes the specified element from the set if it exists.

### `find` Method
```cpp
bool find(T key);
```
- Returns `true` if the element exists, otherwise returns `false`.

### `count` Method
```cpp
int count(const T& key);
```
- Checks if an element exists in the set.
- Returns `1` if the element exists; otherwise, returns `0`.

### `size` Method
```cpp
int size();
```
- Returns the number of elements currently in the set.

---

## Private Methods

### `insert` Method (Recursive)
```cpp
Node* insert(Node* node, T key, bool& exists);
```
- Recursively inserts a key into the BST.

### `erase` Method (Recursive)
```cpp
Node* erase(Node* node, T key);
```
- Recursively removes a key from the BST.

### `find` Method (Recursive)
```cpp
Node* find(Node* node, T key);
```
- Recursively searches for a key in the BST.

### `findMin` Method
```cpp
Node* findMin(Node* node);
```
- Finds the node with the minimum key in the BST (used for deletion).

### `destroyTree` Method
```cpp
void destroyTree(Node* node);
```
- Recursively deletes all nodes in the BST.

---

## Member Variables

- `struct Node`: Represents a node in the BST.
- `Node* root`: Pointer to the root of the BST.
- `int size`: Number of elements in the set.
