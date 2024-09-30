# MonotonicStack Class Documentation

## Overview
The monotonicStack class template implements a monotonic stack, which maintains its elements in a specified order (either strictly increasing or strictly decreasing). It supports standard stack operations along with the property of maintaining monotonicity.

## Key Features:

- Dynamic resizing of the stack when capacity is reached.
- Customizable order (increasing or decreasing) based on the constructor parameter.
- Efficient push operation that maintains the monotonic property.

---

## Constructors

### Default Constructor
```cpp
monotonicStack();
```
- Initializes an empty monotonic stack with an initial capacity of 20 and defaults to increasing order.

### Parameterized Constructor
```cpp
monotonicStack(bool desc);
```
- Initializes an empty monotonic stack with an initial capacity of 20.
- `desc`: Set to true for a decreasing stack; otherwise, it defaults to an increasing stack.

---

## Destructor

### Destructor
```cpp
~monotonicStack();
```
- Destroys the stack and frees all allocated memory.

---

## Stack Operations

### `push` Method
```cpp
void push(const T &ele);
```
- Pushes a new element onto the top of the stack while maintaining the monotonic property.
- If the stack is in decreasing order, all elements greater than ele are popped.
- If the stack is in increasing order, all elements less than ele are popped.

### `pop` Method
```cpp
void pop();
```
- Removes the top element from the stack.
- Throws underflow_error if the stack is empty.

### `top` Method
```cpp
T top();
```
- Returns the top element of the stack without removing it.
- Throws underflow_error if the stack is empty.

### `isEmpty` Method
```cpp
bool isEmpty() const;
```
- Checks if the stack is empty.
- Returns true if the stack is empty; otherwise, returns false.

---

## Additional Methods

### `clear` Method
```cpp
void clear();
```
- Clears the stack, resetting size and top index.

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
- `int topIndex`: Index of the top element in the stack.
- `bool descending`: Indicates if the stack is in decreasing order.