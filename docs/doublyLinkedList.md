# DoublyLinkedList Class Documentation

## Overview
The doublyLinkedList class template provides a doubly linked list implementation with several methods to manipulate, access, and traverse the list. It supports sorting, rotating, reversing, and other common operations.

## Key Features:
- Insertion at the end or at a specific position.
- Deletion of elements from the head or by value.
- Reversing, rotating, and sorting the list.
- Finding elements by value.

---

## Constructors

### Default Constructor
```cpp
doublyLinkedList();
```
- Creates an empty doubly linked list.

## Destructor
```cpp
~doublyLinkedList();
```
- Destroys the list and frees all the allocated memory.

---

## Element Access

### `getNodeAt` Method
```cpp
Node* getNodeAt(int pos) const;
```
- Retrieves the node at a specific position in the list.
- Throws out_of_range if the position is negative or out of bounds.

### `printList` Method
```cpp
void printList() const;
```
- Prints the contents of the list.

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
- Throws out_of_range if the position is out of bounds.

### `deleteNode` Method (specific element)
```cpp
void deleteNode(T ele);
```
- Deletes the first occurrence of a node with the specified value.
- Throws runtime_error if the element is not found.

### `deleteHead` Method
```cpp
void deleteHead();
```
- Deletes the head of the list.

---

## Sorting and Reversing

### `sort` Method
```cpp
void sort();
```
- Sorts the linked list using merge sort.

## `reverse` Method
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
- Rotates the list to the left by k positions.

### `rotateRight` Method
```cpp
void rotateRight(int k);
```
- Rotates the list to the right by k positions.

---

## Finding Elements

### `find` Method
```cpp
bool find(T ele) const;
```
- Finds the specified element in the list and returns true if found, otherwise false.

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

---

## Node Structure

### Node
The doubly linked list uses a nested Node structure to store values.

```cpp
struct Node
{
    T val;
    Node* next;
    Node* prev;
    Node(const T& value) : val(value), next(nullptr), prev(nullptr) {}
};
```

- val: Stores the data of type T.
- next: Pointer to the next node in the list.
- prev: Pointer to the previous node in the list.