#include "myVector.h"

// Constructors
template <typename T>
MyVector<T>::MyVector() : arr(nullptr), s(0), c(0) {}

template <typename T>
MyVector<T>::MyVector(int n) : s(0), c(n)
{
    arr = new T[n];
}

template <typename T>
MyVector<T>::MyVector(int n, T val) : c(n), s(n)
{
    arr = new T[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = val;
    }
}

// Destructor
template <typename T>
MyVector<T>::~MyVector()
{
    delete[] arr;
}

// Private helper methods

template <typename T>
void MyVector<T>::new_allocation()
{
    c = c + 10;
    T *temp = new T[c];

    for (size_t i = 0; i < s; ++i)
    {
        temp[i] = arr[i];
    }

    delete[] arr; // Free the old memory
    arr = temp;
}

template <typename T>
void MyVector<T>::merge(T *arr, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    T *leftArr = new T[n1];
    T *rightArr = new T[n2];

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    delete[] leftArr;
    delete[] rightArr;
}

template <typename T>
void MyVector<T>::mergeSort(T *arr, int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

template <typename T>
int MyVector<T>::partition(T *arr, int low, int high)
{
    T pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template <typename T>
void MyVector<T>::quickSort(T *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

template <typename T>
void MyVector<T>::insertionSort(T *arr, int start, int end)
{
    for (int i = start + 1; i <= end; ++i)
    {
        T key = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Capacity methods

template <typename T>
size_t MyVector<T>::size() const
{
    return s;
}

template <typename T>
size_t MyVector<T>::capacity() const
{
    return c;
}

template <typename T>
bool MyVector<T>::empty() const
{
    return s == 0;
}

template <typename T>
void MyVector<T>::resize(size_t newSize)
{
    if (newSize > c)
    {
        T *temp = new T[newSize];
        for (size_t i = 0; i < s; ++i)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        c = newSize;
    }
    s = newSize;
}

template <typename T>
void MyVector<T>::resize(size_t newSize, T val)
{
    if (newSize > c)
    {
        T *temp = new T[newSize];
        for (size_t i = 0; i < newSize; ++i)
        {
            temp[i] = val;
        }
        delete[] arr;
        arr = temp;
        c = newSize;
    }
    else
    {
        for (size_t i = s; i < newSize; ++i)
        {
            arr[i] = val;
        }
    }
    s = newSize;
}

template <typename T>
void MyVector<T>::reserve(size_t num)
{
    if (num > c)
    {
        T *temp = new T[num];
        for (size_t i = 0; i < s; ++i)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        c = num;
    }
}

template <typename T>
void MyVector<T>::shrink_to_fit()
{
    if (s < c)
    {
        T *temp = new T[s];
        for (size_t i = 0; i < s; ++i)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        c = s;
    }
}

// Element Access

template <typename T>
T &MyVector<T>::operator[](int index)
{
    if (index >= static_cast<int>(s))
    {
        throw std::out_of_range("Index out of bound");
    }
    return arr[index];
}

template <typename T>
const T &MyVector<T>::operator[](int index) const
{
    if (index >= static_cast<int>(s) || index < 0)
    {
        throw std::out_of_range("Index out of bound");
    }
    return arr[index];
}

template <typename T>
T &MyVector<T>::front()
{
    if (empty())
    {
        throw std::out_of_range("Vector is empty");
    }
    return arr[0];
}

template <typename T>
const T &MyVector<T>::front() const
{
    if (empty())
    {
        throw std::out_of_range("Vector is empty");
    }
    return arr[0];
}

template <typename T>
T &MyVector<T>::back()
{
    if (empty())
    {
        throw std::out_of_range("Vector is empty");
    }
    return arr[s - 1];
}

template <typename T>
const T &MyVector<T>::back() const
{
    if (empty())
    {
        throw std::out_of_range("Vector is empty");
    }
    return arr[s - 1];
}

// Modifiers

template <typename T>
void MyVector<T>::push_back(T ele)
{
    if (s == c)
    {
        new_allocation();
    }
    arr[s] = ele;
    s++;
}

template <typename T>
void MyVector<T>::pop_back()
{
    if (s == 0)
    {
        throw std::out_of_range("Cannot pop from an empty MyVector");
    }
    s--;
}

template <typename T>
void MyVector<T>::assign(size_t count, const T &value)
{
    if (count > c)
    {
        reserve(count);
    }
    for (size_t i = 0; i < count; ++i)
    {
        arr[i] = value;
    }
    s = count;
}

template <typename T>
void MyVector<T>::insert(size_t pos, const T &value)
{
    if (pos > s)
    {
        throw std::out_of_range("Position out of range");
    }
    if (s == c)
    {
        reserve(c + 10);
    }

    T *temp = new T[s + 1];
    for (size_t i = 0; i < pos; ++i)
    {
        temp[i] = arr[i];
    }
    temp[pos] = value;
    for (size_t i = pos + 1; i <= s; ++i)
    {
        temp[i] = arr[i - 1];
    }

    s++;
    delete[] arr;
    arr = temp;
}

template <typename T>
void MyVector<T>::erase(size_t pos)
{
    if (pos >= s)
    {
        throw std::out_of_range("Position out of range");
    }

    T *temp = new T[s - 1];
    for (size_t i = 0; i < pos; ++i)
    {
        temp[i] = arr[i];
    }
    for (size_t i = pos; i < s - 1; ++i)
    {
        temp[i] = arr[i + 1];
    }

    s--;
    delete[] arr;
    arr = temp;
}

template <typename T>
void MyVector<T>::clear()
{
    for (size_t i = 0; i < s; ++i)
    {
        arr[i].~T();
    }
    s = 0;
}

template <typename T>
void MyVector<T>::swap(MyVector &other)
{
    std::swap(arr, other.arr);
    std::swap(c, other.c);
    std::swap(s, other.s);
}

// Iterators

template <typename T>
T *MyVector<T>::begin()
{
    return arr;
}

template <typename T>
T *MyVector<T>::end()
{
    return arr + s;
}

template <typename T>
const T *MyVector<T>::cbegin() const
{
    return arr;
}

template <typename T>
const T *MyVector<T>::cend() const
{
    return arr + s;
}

template <typename T>
std::reverse_iterator<T *> MyVector<T>::rbegin()
{
    return std::reverse_iterator<T *>(MyVector<T>::end());
}

template <typename T>
std::reverse_iterator<T *> MyVector<T>::rend()
{
    return std::reverse_iterator<T *>(MyVector<T>::begin());
}

template <typename T>
std::reverse_iterator<const T *> MyVector<T>::crbegin() const
{
    return std::reverse_iterator<const T *>(MyVector<T>::cend());
}

template <typename T>
std::reverse_iterator<const T *> MyVector<T>::crend() const
{
    return std::reverse_iterator<const T *>(MyVector<T>::cbegin());
}

// Custom Methods

template <typename T>
void MyVector<T>::sort(int start, int end)
{
    if (start < 0 || end >= s || start > end)
    {
        throw out_of_range("Invalid start or end index.");
    }

    int size = end - start + 1;
    if (size < 20)
    {
        insertionSort(arr, start, end);
    }
    else if (size < 10000)
    {
        quickSort(arr, start, end);
    }
    else
    {
        mergeSort(arr, start, end);
    }
}

template <typename T>
void MyVector<T>::sort()
{ // Overloading method with default parameters
    sort(0, s - 1);
}

template <typename T>
int MyVector<T>::find(T ele)
{
    for (int i = 0; i < s; ++i)
    {
        if (arr[i] == ele)
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
int MyVector<T>::findLast(T ele)
{
    for (int i = s - 1; i >= 0; --i)
    {
        if (arr[i] == ele)
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
void MyVector<T>::reverse(int left, int right)
{
    while (left < right)
    {
        std::swap(arr[left], arr[right]);
        ++left;
        --right;
    }
}

template <typename T>
void MyVector<T>::reverse()
{ // Overloading method with default parameters
    MyVector<T>::reverse(0, s - 1);
}

template <typename T>
void MyVector<T>::rotateLeft(int k)
{
    if (s == 0)
        return;

    k = k % s;
    if (k == 0)
        return;

    MyVector<T>::reverse(0, k - 1);
    MyVector<T>::reverse(k, s - 1);
    MyVector<T>::reverse();
}

template <typename T>
void MyVector<T>::rotateRight(int k)
{
    if (s == 0)
        return;

    k = k % s;
    if (k == 0)
        return;

    MyVector<T>::reverse(s - k, s - 1);
    MyVector<T>::reverse(0, s - k - 1);
    MyVector<T>::reverse();
}
