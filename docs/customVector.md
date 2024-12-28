# customVector Class Documentation

## Overview
The customVector class template provides a dynamic array implementation with automatic resizing. It includes various methods for element access, capacity management, sorting, and custom operations. This class can handle any data type (T).

## Key Features:
- Automatic resizing of the vector when adding elements.
- Methods for accessing elements, modifying capacity, and iterating over the contents.
- Sorting options: `insertion sort`, `quicksort`, and `merge sort` based on the size of the array.
- Custom methods for reversing and rotating elements.

---

## Constructors

### Default Constructor
```cpp
customVector();
```
- Creates an empty vector with no allocated memory.

### `Constructor` with Initial Capacity
```cpp
customVector(int n);
```
- Creates a vector with an initial capacity of n, but size is set to 0.

### `Constructor` with Initial Size and Value
```cpp
customVector(int n, T val);
```
- Creates a vector with an initial size of n and fills it with the value val.

### `Initializer` List Constructor
```cpp
customVector(std::initializer_list<T> list);
```
- Constructs a vector from an initializer list of values.

### `Range` Constructor
```cpp
template <typename InputIt>
customVector(InputIt first, InputIt last);
```
- Constructs a vector from the elements in the range [first, last].

---

## Destructor

### `Destructor`
```cpp
~customVector();
```
- Destroys the vector and frees all the allocated memory.

---

## Capacity Methods

### `size` Method
```cpp
size_t size() const;
```
- Returns the number of elements currently stored in the vector.

### `capacity` Method
```cpp
size_t capacity();
```
- Returns the total allocated capacity of the vector.

### `empty` Method
```cpp
bool empty();
```
- Returns true if the vector is empty, otherwise false.

### `resize` Method
```cpp
void resize(size_t newSize);
```
- Resizes the vector to the specified newSize. If the new size is greater than the current capacity, memory is reallocated.

### `reserve` Method
```cpp
void reserve(int num);
```
- Increases the capacity of the vector to at least num. If the capacity is already greater than or equal to num, no action is taken.

### `shrink_to_fit` Method
```cpp
void shrink_to_fit();
```
- Shrinks the capacity of the vector to match its size, deallocating unused memory.

---

## Element Access

### `operator`[] Method
```cpp
T& operator[](int index);
```
- Provides access to the element at the specified index. Throws out_of_range if the index is invalid.

### `front` Method
```cpp
T& front();
```
- Returns a reference to the first element in the vector. Throws out_of_range if the vector is empty.

### `back` Method
```cpp
T& back();
```
- Returns a reference to the last element in the vector. Throws out_of_range if the vector is empty.
Modifiers

### `push_back` Method
```cpp
void push_back(const T& ele);
```
- Adds the given element ele to the end of the vector, resizing if necessary.

### `pop_back` Method
```cpp
void pop_back();
```
- Removes the last element from the vector. Throws out_of_range if the vector is empty.

### `assign` Method
```cpp
void assign(size_t count, const T& value);
```
- Fills the vector with count copies of value.

### `insert` Method
```cpp
void insert(size_t pos, const T& val);
```
- Inserts val at position pos, shifting all subsequent elements.

### `erase` Method
```cpp
void erase(size_t pos);
```
- Erases the element at position pos, shifting all subsequent elements left.

### `clear` Method
```cpp
void clear();
```
- Clears the vector, destroying all elements.

---

## Iterators

### `begin` Method
```cpp
T* begin();
```
- Returns a pointer to the first element in the vector.

### `end` Method
```cpp
T* end();
```
- Returns a pointer to one past the last element in the vector.

### `Reverse` Iterators
```cpp
std::reverse_iterator<T*> rbegin();
std::reverse_iterator<T*> rend();
```
- Returns reverse iterators to the beginning and end of the vector.

---

## Sorting and Reversing

### `sort` Method
```cpp
void sort();
```
- Sorts the vector using an appropriate algorithm based on the size of the array (insertion sort, quicksort, or merge sort).

### `reverse` Method
```cpp
void reverse();
```
- Reverses the order of the elements in the vector.

---

## Rotation

### `rotateLeft` Method
```cpp
void rotateLeft(int k);
```
- Rotates the vector to the left by k positions.

### `rotateRight` Method
```cpp
void rotateRight(int k);
```
- Rotates the vector to the right by k positions.

---

## Finding Elements

### `find` Method
```cpp
int find(T ele);
```
- Returns the position of the first occurrence of the element ele, or -1 if not found.

### `findLast` Method
```cpp
int findLast(T ele);
```
- Returns the position of the last occurrence of the element ele, or -1 if not found.

---

## Private Helper Methods

### `new_allocation` Method
```cpp
void new_allocation();
```
- Resizes the internal array to double its current capacity.

### Helper methods for sorting the vector using merge sort and quicksort.
```cpp
void merge(T* arr, int l, int mid, int r);
int partition(T* arr, int low, int high);
void quickSort(T* arr, int low, int high);
```

---

## Member Variables

- `T* arr`: Pointer to the dynamically allocated array that stores the elements.
- `size_t c`: The total allocated capacity of the array.
- `size_t s`: The current number of elements in the vector.