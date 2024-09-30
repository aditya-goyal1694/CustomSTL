# CustomQueue Class Documentation

## Overview
The customQueue class template implements a dynamic queue data structure that allows for efficient insertion and deletion of elements. It also keeps track of the maximum and minimum elements in the queue.

## Key Features:
- Dynamic resizing of the queue when capacity is reached.
- Ability to retrieve the maximum and minimum elements in constant time.
- Supports standard queue operations.

---

## Constructors

### Default Constructor
```cpp
customQueue();
```
- Initializes an empty queue with an initial capacity of 20.

---

## Destructor

### Destructor
```cpp
~customQueue();
```
- Destroys the queue and frees all allocated memory.

---

## Queue Operations

### `push` Method
```cpp
void push(const T &ele);
```
- Adds a new element to the end of the queue.
- Updates the maximum and minimum elements accordingly.
- If the queue is full, it resizes the underlying array.

### `pop` Method
```cpp
void pop();
```
- Removes the front element from the queue.
- Throws runtime_error if the queue is empty.
- Updates the maximum and minimum elements if the front element is being removed.

### `front` Method
```cpp
T front() const;
```
- Returns the front element of the queue without removing it.
- Throws runtime_error if the queue is empty.

### `isEmpty` Method
```cpp
bool isEmpty() const;
```
- Checks if the queue is empty.
- Returns true if the queue is empty; otherwise, returns false.

---

## Additional Methods

### `maxele` Method
```cpp
T maxele();
```
- Returns the maximum element in the queue.
- Throws runtime_error if the queue is empty.

### `minele` Method
```cpp
T minele();
```
- Returns the minimum element in the queue.
- Throws runtime_error if the queue is empty.

### `clear` Method
```cpp
void clear();
```
- Clears the queue, resetting size and front index.

---

## Private Methods

### `new_allocation` Method
```cpp
void new_allocation();
```
- Increases the queue's capacity by 20 when the current capacity is reached.
- Allocates new memory and copies the existing elements to the new array.

---

## Member Variables

- `T *q`: Pointer to the array that holds the queue elements.
- `size_t c`: Current capacity of the queue.
- `size_t s`: Current size of the queue.
- `T maxElement`: Tracks the maximum element in the queue.
- `T minElement`: Tracks the minimum element in the queue.
- `int frontInd`: Index of the front element in the queue.