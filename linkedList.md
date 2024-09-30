# LinkedList Class Documentation

## Overview
The `LinkedList` class template provides a singly linked list implementation with several methods to manipulate, access, and traverse the list. It includes helper functions for sorting, rotating, and other custom operations. This class can be used with any data type (T).

### Key Features:
- Insertion at the end or specific position.
- Deletion of elements from the list.
- Reversal, rotation, and sorting of the list.
- Finding elements by value.

---

## Constructors

### Default Constructor
```cpp
LinkedList();
```
- Creates an empty linked list.

### Constructor with Initial Value
```cpp
LinkedList(T val);
```
- Creates a linked list with a single node initialized to the given value.

---

## Destructor

### Destructor
```cpp
~LinkedList();
```
- Destroys the list and frees all the allocated memory.

---

## Element Access

### `getNodeAt` Method
```cpp
Node* getNodeAt(int pos) const;
```
- Retrieves the node at a specific position in the list.
- Throws `out_of_range` if the position is negative or out of bounds.

### `printList` Method
```cpp
void printList() const;
```
- Prints the contents of the list in the format: `value -> value -> ... -> NULL`.

---

## List Manipulation

### `insert` Method (at the end)
```cpp
void insert(T ele);
```
- Inserts a new node with the given value at the end of the list.

### `insert` Method (at specific position)
```cpp
void insert(T ele, int pos);
```
- Inserts a new node with the given value at a specific position in the list.
- Throws `out_of_range` if the position is out of bounds.

### `deleteNode` Method (from the end)
```cpp
void deleteNode();
```
- Deletes the last node in the list.
- Throws `runtime_error` if the list is empty.

### `deleteNode` Method (specific element)
```cpp
void deleteNode(T ele);
```
- Deletes the first occurrence of a node with the specified value.
- Throws `runtime_error` if the list is empty or the element is not found.

---

## Sorting and Reversing

### `sort` Method
```cpp
void sort();
```
- Sorts the linked list using merge sort.

### `reverse` Method
```cpp
void reverse();
```
- Reverses the entire linked list.

---

## Rotation

### `rotateLeft` Method
```cpp
void rotateLeft(int k);
```
- Rotates the list to the left by `k` positions.

### `rotateRight` Method
```cpp
void rotateRight(int k);
```
- Rotates the list to the right by `k` positions.

---

## Finding Elements

### `find` Method
```cpp
int find(T ele) const;
```
- Finds the first occurrence of the specified element in the list and returns its position.
- Throws `runtime_error` if the element is not found.

---

## Private Helper Methods

### `merge` Method
```cpp
Node* merge(Node* left, Node* right);
```
- Helper method to merge two sorted linked lists.

### `split` Method
```cpp
void split(Node* source, Node** front, Node** back);
```
- Helper method to split the list into two halves for merge sort.

### `mergeSort` Method
```cpp
Node* mergeSort(Node* head);
```
- Recursively sorts the linked list using merge sort.

### `rotate` Method
```cpp
Node* rotate(Node* head, int k);
```
- Helper function to rotate the list by `k` positions.

---

## Node Structure

### Node
The linked list uses a nested `Node` structure to store values.
```cpp
struct Node
{
    T val;
    Node* next;
    Node(T data) : val(data), next(nullptr) {}
};
```

- `val`: Stores the data of type `T`.
- `next`: Pointer to the next node in the list.
