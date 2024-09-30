
# customVector Documentation

## Overview

The `customVector` class is a custom implementation of a dynamic array similar to the `std::vector` in C++. It dynamically resizes as elements are added or removed. This class provides a variety of methods for element access, modification, sorting, and iteration.

### Table of Contents

- [Class Overview](#class-overview)
- [Capacity Methods](#capacity-methods)
- [Element Access](#element-access)
- [Modifiers](#modifiers)
- [Iterators](#iterators)
- [Custom Methods](#custom-methods)

## Class Overview

The `customVector` class template can store any data type. It dynamically manages its own memory and grows in capacity when necessary.

```cpp
template <typename T>
class customVector {
    // Private members
    T *arr;
    size_t c;  // Capacity
    size_t s;  // Size
};
```

### Constructors

- **Default constructor:** `customVector()` creates an empty vector.
- **Constructor with initial capacity:** `customVector(int n)` creates a vector with a specified capacity.
- **Constructor with initial values:** `customVector(int n, T val)` creates a vector with a specified size and initializes all elements to a given value.
- **Initializer list constructor:** Allows creating a vector using an initializer list.
- **Range constructor:** Initializes a vector from a range of iterators.

### Destructor

- **Destructor:** Automatically deallocates memory when the vector is destroyed.

```cpp
~customVector();
```

## Capacity Methods

### `size()`
- **Returns:** The number of elements currently in the vector.
  
### `capacity()`
- **Returns:** The current capacity of the vector (i.e., how many elements can be stored without resizing).

### `empty()`
- **Returns:** `true` if the vector is empty, `false` otherwise.

### `resize(size_t newSize)`
- **Description:** Resizes the vector to `newSize`. If `newSize` is larger than the current capacity, the vector will expand.

### `resize(size_t newSize, T val)`
- **Description:** Resizes the vector to `newSize` and fills new elements with `val`.

### `reserve(int num)`
- **Description:** Reserves memory for at least `num` elements to avoid multiple reallocations.

### `shrink_to_fit()`
- **Description:** Reduces the capacity to match the current size.

## Element Access

### `operator[](int index)`
- **Description:** Provides access to the element at the given index. Throws an `out_of_range` exception if the index is invalid.

### `front()`
- **Description:** Returns a reference to the first element in the vector.

### `back()`
- **Description:** Returns a reference to the last element in the vector.

## Modifiers

### `push_back(const T &ele)`
- **Description:** Adds a new element `ele` to the end of the vector, resizing if necessary.

### `pop_back()`
- **Description:** Removes the last element from the vector.

### `assign(size_t count, const T &value)`
- **Description:** Assigns `count` copies of `value` to the vector, resizing if necessary.

### `insert(size_t pos, const T &val)`
- **Description:** Inserts `val` at the given position `pos`. Shifts elements to the right.

### `erase(size_t pos)`
- **Description:** Erases the element at the specified position `pos`.

### `clear()`
- **Description:** Removes all elements from the vector, resetting the size to 0.

## Iterators

### `begin()` and `end()`
- **Description:** Returns pointers (or const pointers) to the beginning and end of the vector, respectively.

### `rbegin()` and `rend()`
- **Description:** Returns reverse iterators to the beginning and end of the vector, respectively.

### Example:
```cpp
for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
    cout << *it << endl;
}
```

## Custom Methods

### `sort(int start, int end)`
- **Description:** Sorts the elements in the range `[start, end]`. Automatically uses insertion sort, quick sort, or merge sort based on the size of the range.

### `find(T ele)`
- **Description:** Returns the index of the first occurrence of `ele`. Returns `-1` if not found.

### `findLast(T ele)`
- **Description:** Returns the index of the last occurrence of `ele`. Returns `-1` if not found.

### `reverse(int left, int right)`
- **Description:** Reverses the elements between indices `left` and `right`.

### `rotateLeft(int k)`
- **Description:** Rotates the vector to the left by `k` positions.

### `rotateRight(int k)`
- **Description:** Rotates the vector to the right by `k` positions.

## Sorting Algorithms

The class includes helper methods for sorting:

- **Insertion Sort:** Used for small ranges.
- **Quick Sort:** Used for medium-sized ranges.
- **Merge Sort:** Used for large ranges.

## Example Usage

```cpp
customVector<int> vec = {10, 20, 30, 40, 50};
vec.push_back(60);
vec.pop_back();
vec.sort();
```