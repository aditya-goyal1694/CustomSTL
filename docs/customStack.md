# CustomStack Class Documentation

## Overview
The customStack class template provides a dynamic stack implementation with added functionalities to track the maximum and minimum elements. It supports standard stack operations, including push, pop, and top, along with additional methods to retrieve the maximum and minimum elements in constant time.

## Key Features:
- Dynamic resizing of the stack when capacity is reached.
- Retrieval of maximum and minimum elements in O(1) time.
- Clear method to reset the stack.

---

## Constructor

### Default Constructor
```cpp
customStack();
```
- Initializes an empty stack with an initial capacity of 20.

---

## Destructor

### Destructor
```cpp
~customStack();
```
- Destroys the stack and frees all allocated memory.

---

## Stack Operations

### `push` Method
```cpp
void push(const T &ele);
```
- Pushes a new element onto the top of the stack.
- Updates the maximum and minimum elements accordingly.

### `pop` Method
```cpp
void pop();
```
- Removes the top element from the stack.
- Updates the maximum and minimum elements if the popped element was either of them.
- Throws underflow_error if the stack is empty.

### `top` Method
```cpp
T top();
```
- Returns the top element of the stack without removing it.
- Throws underflow_error if the stack is empty.

### `isEmpty` Method
```cpp
bool isEmpty();
```
- Checks if the stack is empty.
- Returns true if the stack is empty; otherwise, returns false.
- Maximum and Minimum Element Retrieval

### `maxele` Method
```cpp
T maxele();
```
- Returns the maximum element in the stack.
- Throws underflow_error if the stack is empty.
- If the maximum element is not correctly tracked, it recalculates it by iterating through the stack.

### `minele` Method
```cpp
T minele();
```
- Returns the minimum element in the stack.
- Throws underflow_error if the stack is empty.
- If the minimum element is not correctly tracked, it recalculates it by iterating through the stack.

---

## Additional Methods

### clear Method
```cpp
void clear();
```
- Clears the stack, resetting size and top index, and updates the maximum and minimum elements to their initial states.

---

## Private Methods

### `new_allocation` Method
```cpp
void new_allocation();
```
- Increases the stack's capacity by 20 when the current capacity is reached.
- Allocates new memory and copies the existing elements to the new array.

---

## Member Variables

- `T *st`: Pointer to the array that holds the stack elements.
- `size_t c`: Current capacity of the stack.
- `size_t s`: Current size of the stack.
- `T maxElement`: Tracks the maximum element in the stack.
- `T minElement`: Tracks the minimum element in the stack.
- `int topIndex`: Index of the top element in the stack.