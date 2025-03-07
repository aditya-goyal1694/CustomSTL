# UnorderedMap Class Documentation

## Overview
The `UnorderedMap` class template provides a hash map implementation using open addressing with linear probing for collision resolution. It supports insertion, deletion, and retrieval operations with an average time complexity of O(1). Additionally, it dynamically resizes when the load factor exceeds 0.7.

## Key Features:
- Open addressing with linear probing for efficient collision resolution.
- Dynamic resizing to maintain performance.
- Overloaded `operator[]` for easy element access and assignment.
- Methods for insertion, deletion, search, and element count.

---

## Constructor

### Default Constructor
```cpp
UnorderedMap();
```
- Initializes an empty hash map with a default capacity of 10.
- Allocates memory for keys, values, and tracking arrays.

---

## Destructor

### Destructor
```cpp
~UnorderedMap();
```
- Frees all allocated memory upon object destruction.

---

## Hashing and Resizing

### `hashFunction` Method
```cpp
int hashFunction(const K& key);
```
- Computes the hash value of the given key.
- Uses modulo operation for integer keys and polynomial rolling hash for string keys.

### `rehash` Method
```cpp
void rehash();
```
- Doubles the capacity when the load factor exceeds 0.7.
- Reallocates memory and reinserts existing elements into the new table.

---

## Map Operations

### `operator[]` Overloaded Method
```cpp
V& operator[](const K& key);
```
- Provides access to the value associated with the given key.
- If the key does not exist, it inserts the key with a default value and returns a reference to it.
- Triggers `rehash` if necessary.

### `insert` Method
```cpp
void insert(K key, V value);
```
- Inserts a key-value pair into the hash map.
- Utilizes `operator[]` for insertion.

### `erase` Method
```cpp
void erase(const K& key);
```
- Removes the key-value pair from the map.
- Marks the entry as deleted to handle probing issues.

### `count` Method
```cpp
int count(K key);
```
- Checks whether a key exists in the hash map.
- Returns `1` if the key is found; otherwise, returns `0`.

### `find` Method
```cpp
V* find(K key);
```
- Returns a pointer to the value associated with the key.
- Returns `nullptr` if the key is not found.

### `size` Method
```cpp
int size();
```
- Returns the number of elements currently stored in the hash map.

---

## Member Variables
- `K* keys`: Pointer to the array storing keys.
- `V* values`: Pointer to the array storing values.
- `bool* occupied`: Tracks occupied positions in the hash table.
- `bool* deleted`: Marks deleted elements to aid in linear probing.
- `int capacity`: Total capacity of the hash table.
- `int size`: Current number of stored elements.
