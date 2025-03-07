# UnorderedSet Class Documentation

## Overview
The `UnorderedSet` class template provides a hash-based implementation of a set that allows fast insertions, deletions, and lookups. It utilizes linear probing for collision resolution and automatically resizes when the load factor exceeds 0.7.

## Key Features:
- Hash table with linear probing for collision resolution.
- Dynamic resizing (rehashing) to maintain performance.
- Insert, erase, and find operations in average O(1) time complexity.

---

## Constructor

### Default Constructor
```cpp
UnorderedSet();
```
- Initializes an empty unordered set with an initial capacity of 10.

---

## Destructor

### Destructor
```cpp
~UnorderedSet();
```
- Destroys the set and deallocates all memory.

---

## Set Operations

### `insert` Method
```cpp
void insert(const T& key);
```
- Inserts a new element into the set.
- If the element already exists, the insertion is ignored.
- Triggers a rehash if the load factor exceeds 0.7.

### `erase` Method
```cpp
void erase(const T& key);
```
- Removes the specified element from the set if it exists.
- Marks the element as deleted without shifting other elements.

### `count` Method
```cpp
int count(const T& key);
```
- Checks if an element exists in the set.
- Returns `1` if the element exists; otherwise, returns `0`.

### `find` Method
```cpp
T* find(const T& key);
```
- Returns a pointer to the element if found, otherwise returns `nullptr`.

### `size` Method
```cpp
int size();
```
- Returns the number of elements currently in the set.

---

## Private Methods

### `hashFunction` Method
```cpp
int hashFunction(const T& key);
```
- Computes the hash index for a given key.
- Uses modulo hashing for integers and a rolling hash function for strings.

### `rehash` Method
```cpp
void rehash();
```
- Doubles the capacity of the hash table and reinserts existing elements.
- Helps maintain an efficient load factor and avoids excessive collisions.

---

## Member Variables

- `T* keys`: Array to store set elements.
- `bool* occupied`: Marks whether a position in the array is occupied.
- `bool* deleted`: Marks whether an element was deleted (used to handle collisions in linear probing).
- `int capacity`: Maximum capacity of the set.
- `int size`: Current number of elements in the set.