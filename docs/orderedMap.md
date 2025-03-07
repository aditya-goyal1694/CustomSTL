# OrderedMap Class Documentation

## Overview
The `OrderedMap` class template provides an ordered map implementation using a Binary Search Tree (BST). It supports efficient insertion, deletion, and retrieval of key-value pairs while maintaining a sorted order.

## Key Features:
- Implements an ordered map using a Binary Search Tree (BST).
- Supports dynamic insertion, deletion, and lookup.
- Overloaded `operator[]` for easy key-value access and assignment.
- Maintains keys in sorted order.

---

## Constructor

### Default Constructor
```cpp
OrderedMap();
```
- Initializes an empty ordered map with a `nullptr` root and size `0`.

---

## Destructor

### Destructor
```cpp
~OrderedMap();
```
- Recursively deallocates memory and destroys all nodes in the BST.

---

## Map Operations

### `insert` Method
```cpp
void insert(K key, V value);
```
- Inserts a key-value pair into the map.
- If the key already exists, the value is not updated.

### `operator[]` Overloaded Method
```cpp
V& operator[](const K& key);
```
- Provides access to the value associated with the given key.
- If the key does not exist, it inserts the key with a default value and returns a reference to it.

### `erase` Method
```cpp
void erase(const K& key);
```
- Removes the key-value pair from the map.
- Adjusts the BST structure to maintain order.

### `find` Method
```cpp
Node* find(K key);
```
- Searches for a key in the map.
- Returns a pointer to the node containing the key or `nullptr` if the key is not found.

### `count` Method
```cpp
int count(const K& key);
```
- Checks whether a key exists in the map.
- Returns `1` if the key is found; otherwise, returns `0`.

### `size` Method
```cpp
int size();
```
- Returns the number of elements currently stored in the map.

---

## Private Methods

### `insert` Helper Method
```cpp
Node* insert(Node* node, K key, V value, bool& exists);
```
- Recursively inserts a key-value pair into the BST.
- If the key already exists, the flag `exists` is set to `true`.

### `erase` Helper Method
```cpp
Node* erase(Node* node, K key);
```
- Recursively removes a key from the BST while maintaining its structure.

### `find` Helper Method
```cpp
Node* find(Node* node, K key);
```
- Recursively searches for a key in the BST.

### `findMin` Method
```cpp
Node* findMin(Node* node);
```
- Finds the node with the smallest key in the BST.

### `destroyTree` Method
```cpp
void destroyTree(Node* node);
```
- Recursively deallocates memory for all nodes in the BST.

---

## Member Variables
- `Node* root`: Pointer to the root of the BST.
- `int size`: Current number of elements in the ordered map.
