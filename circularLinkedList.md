# CircularLinkedList Class Documentation
## Overview
The `CircularLinkedList` class template provides an implementation of a circular linked list, which allows elements to be inserted, deleted, accessed, and rotated. This class can handle any data type (T) and supports additional functionalities like list rotation and reversal.

### Key Features:
- Insertion at the end or at a specific position.
- Deletion of elements from the end or by value.
- Circular traversal of the list.
- Reversal and rotation of the list.
- Finding elements by value.

---

## Constructors

### Default Constructor
```cpp
CircularLinkedList();
```
- Creates an empty circular linked list.

### Constructor with Initial Value
```cpp
CircularLinkedList(T val);
```
- Creates a circular linked list with a single node initialized to the given value and points the node to itself.

---

## Destructor

### Destructor
```cpp
~CircularLinkedList();
```
- Destroys the list and frees all allocated memory, ensuring proper deletion of circular references.

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
- Prints the contents of the list in a circular fashion, with arrows pointing from one element to the next, and indicating the circular return to the head.

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

### `deleteNode` Method (from the end)
```cpp
void deleteNode();
```
- Deletes the last node in the list.
- Throws runtime_error if the list is empty.

### `deleteNode` Method (specific element)
```cpp
void deleteNode(T ele);
```
- Deletes the first occurrence of a node with the specified value.
- Throws runtime_error if the list is empty or the element is not found.

---

## Reversing

### `reverse` Method
```cpp
void reverse();
```
- Reverses the entire circular linked list.

---

### Rotation

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
int find(T ele) const;
```
- Finds the first occurrence of the specified element in the list and returns its position.
- Throws runtime_error if the element is not found.

---

## Private Helper Methods

### `rotate` Method
```cpp
Node* rotate(Node* head, int k);
```
- Helper function to rotate the list by k positions.

---

## Node Structure

### Node
The circular linked list uses a nested Node structure to store values.

```cpp
struct Node
{
    T val;
    Node* next;
    Node(T data) : val(data), next(nullptr) {}
};
```

- val: Stores the data of type T.
- next: Pointer to the next node in the list.