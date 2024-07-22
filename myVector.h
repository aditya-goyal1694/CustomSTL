#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <memory>
#include <limits>

template <typename T>

class MyVector{
private:
    T *arr;
    size_t c; // Capacity
    size_t s; // Size

    // Helper methods
    void new_allocation();
    void merge(T *arr, int l, int mid, int r);
    void mergeSort(T *arr, int l, int r);
    int partition(T *arr, int low, int high);
    void quickSort(T *arr, int low, int high);
    void insertionSort(T *arr, int start, int end);

public:
    // Constructors
    MyVector();
    MyVector(int n);
    MyVector(int n, T val);

    // Destructor
    ~MyVector();

    // Capacity methods
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    void resize(size_t newSize);
    void resize(size_t newSize, T val);
    void reserve(size_t num);
    void shrink_to_fit();

    // Element Access
    T &operator[](int index);
    const T &operator[](int index) const;
    T &front();
    const T &front() const;
    T &back();
    const T &back() const;

    // Modifiers
    void push_back(T ele);
    void pop_back();
    void assign(size_t count, const T &value);
    void insert(size_t pos, const T &value);
    void erase(size_t pos);
    void clear();
    void swap(MyVector &other);

    // Iterators
    T *begin();
    T *end();
    const T *cbegin() const;
    const T *cend() const;
    std::reverse_iterator<T *> rbegin();
    std::reverse_iterator<T *> rend();
    std::reverse_iterator<const T *> crbegin() const;
    std::reverse_iterator<const T *> crend() const;

    // Custom Methods
    void sort(int start, int end);
    void sort(); // Overloaded method
    int find(T ele) const;
    int findLast(T ele) const;
    void reverse(int left, int right);
    void reverse(); // Overloaded method
    void rotateLeft(int k);
    void rotateRight(int k);
};

#include "myVector.tpp" // Include the template implementation

#endif // MYVECTOR_H
