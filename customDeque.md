# CustomDeque Class Documentation

## Overview
The customDeque class template implements a dynamic double-ended queue (deque) data structure that allows for efficient insertion and deletion of elements from both ends. It also keeps track of the maximum and minimum elements in the deque.

## Key Features:
- Dynamic resizing of the deque when capacity is reached.
- Ability to retrieve the maximum and minimum elements in constant time.
- Supports standard deque operations.

---

## Constructors

### Default Constructor
```cpp
customDeque();
```
- Initializes an empty deque with an initial capacity of 20 and sets front and back indices for element management.

---

## Destructor

### Destructor
```cpp
~customDeque();
```
- Destroys the deque and frees all allocated memory.

---

## Deque Operations

### `push_back` Method
```cpp
void push_back(const T &ele);
```
- Adds a new element to the back of the deque.
- Updates the maximum and minimum elements accordingly.
- If the back index reaches the capacity, it resizes the underlying array.

### `push_front` Method
```cpp
void push_front(const T &ele);
```
- Adds a new element to the front of the deque.
- Updates the maximum and minimum elements accordingly.
- If the front index reaches zero, it resizes the underlying array.

### `pop_back` Method
```cpp
void pop_back();
```
- Removes the back element from the deque.
- Throws runtime_error if the deque is empty.
- Updates the maximum and minimum elements if the back element is being removed.

### `pop_front` Method
```cpp
void pop_front();
```
- Removes the front element from the deque.
- Throws runtime_error if the deque is empty.
- Updates the maximum and minimum elements if the front element is being removed.

### front Method
```cpp
T front();
```
- Returns the front element of the deque without removing it.
- Throws runtime_error if the deque is empty.

### `back` Method
```cpp
T back();
```
- Returns the back element of the deque without removing it.
- Throws runtime_error if the deque is empty.

### `isEmpty` Method
```cpp
bool isEmpty();
```
- Checks if the deque is empty.
- Returns true if the deque is empty; otherwise, returns false.

---

## Additional Methods

### `maxele` Method
```cpp
T maxele();
```
- Returns the maximum element in the deque.
- Throws runtime_error if the deque is empty.

### `minele` Method
```cpp
T minele();
```
- Returns the minimum element in the deque.
- Throws runtime_error if the deque is empty.

### `clear` Method
```cpp
void clear();
```
- Clears the deque, resetting size and indices.

---

## Private Methods

### `new_allocation` Method
```cpp
void new_allocation(int flag);
```
- Increases the deque's capacity by 20 when the current capacity is reached.
- Allocates new memory and copies the existing elements to the new array based on whether elements are added to the front or back.

---

## Member Variables

- `T *q`: Pointer to the array that holds the deque elements.
- `size_t c`: Current capacity of the deque.
- `size_t s`: Current size of the deque.
- `T maxElement`: Tracks the maximum element in the deque.
- `T minElement`: Tracks the minimum element in the deque.
- `int base`: Used to manage indices.
- `int frontInd`: Index of the front element in the deque.
- `int backInd`: Index of the back element in the deque.