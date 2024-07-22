#include <iostream>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <memory>
#include <limits>
using namespace std;

template <typename T>
class MyVector
{
private:
    T *arr;
    size_t c; // Capacity
    size_t s; // Size

    void new_allocation()
    {
        c = c + 10;
        T *temp = new T[c];

        for (auto i = 0; i < s; i++)
        {
            temp[i] = arr[i];
        }

        delete[] arr; // Free the old memory
        arr = temp;
    }
    // ---------------------------------------------------------------------------------------------------------------------------------------

    // Helper methods

    void merge(T *arr, int l, int mid, int r)
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

    void mergeSort(T *arr, int l, int r)
    {
        if (l < r)
        {
            int mid = l + (r - l) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }

    int partition(T *arr, int low, int high)
    {
        T pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    void quickSort(T *arr, int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    void insertionSort(T *arr, int start, int end)
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

public:
    // Constructors

    MyVector() : arr(nullptr), s(0), c(0) {}

    MyVector(int n) : s(0), c(n)
    {
        arr = new T[n];
    }

    MyVector(int n, T val) : c(n), s(n)
    {
        arr = new T[n];
        for (int i = 0; i < n; ++i)
        {
            arr[i] = val;
        }
    }

    // ---------------------------------------------------------------------------------------------------------------------------------------

    // Destructor

    ~MyVector()
    {
        delete[] arr;
    }

    // ---------------------------------------------------------------------------------------------------------------------------------------

    // Capacity methods

    size_t size()
    {
        return s;
    }

    size_t capacity()
    {
        return c;
    }

    bool empty()
    {
        return s == 0;
    }

    void resize(size_t newSize)
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

    void resize(size_t newSize, T val)
    { // Custom method
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

    void reserve(int num)
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

    void shrink_to_fit()
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

    // ---------------------------------------------------------------------------------------------------------------------------------------

    // Element Access

    T &operator[](int index)
    {
        if (index >= s)
        {
            throw out_of_range("Index out of bound");
        }
        return arr[index];
    }

    const T &operator[](int index) const
    {
        if (index >= static_cast<int>(s) || index < 0)
        {
            throw out_of_range("Index out of bound");
        }
        return arr[index];
    }

    T &front()
    {
        if (empty())
        {
            throw out_of_range("Vector is empty");
        }
        return arr[0];
    }

    const T &front() const
    {
        if (empty())
        {
            throw out_of_range("Vector is empty");
        }
        return arr[0];
    }

    T &back()
    {
        if (empty())
        {
            throw out_of_range("Vector is empty");
        }
        return arr[s - 1];
    }

    const T &back() const
    {
        if (empty())
        {
            throw out_of_range("Vector is empty");
        }
        return arr[s - 1];
    }

    // ---------------------------------------------------------------------------------------------------------------------------------------

    // Modifiers

    void push_back(T ele)
    {
        if (s == c)
        {
            new_allocation();
        }

        arr[s] = ele;
        s++;
    }

    void pop_back()
    {
        if (s == 0)
        {
            throw out_of_range("Cannot pop from an empty MyVector");
            return;
        }
        s--;
    }

    void assign(size_t count, T &value)
    {
        if (count > c)
        {
            reserve(count);
        }

        for (auto i = 0; i < count; ++i)
        {
            arr[i] = value;
        }

        s = count;
    }

    void insert(size_t pos, T &value)
    {
        if (pos > s)
        {
            throw out_of_range("Position out of range");
        }
        if (s == c)
        {
            reserve(c + 10);
        }

        T *temp = new T[s + 1];
        for (auto i = 0; i < pos - 1; i++)
        {
            temp[i] = arr[i];
        }
        arr[pos - 1] = value;
        for (auto i = pos; i < s; i++)
        {
            temp[i] = arr[i - 1];
        }

        s++;
        delete[] arr;
        arr = temp;
    }

    void erase(size_t pos)
    {
        if (pos >= s)
        {
            throw out_of_range("Position out of range");
        }

        T *temp = new T[s - 1];
        for (auto i = 0; i < pos - 1; i++)
        {
            temp[i] = arr[i];
        }
        for (auto i = pos - 1; i < s - 1; i++)
        {
            temp[i] = arr[i + 1];
        }

        s--;
        delete[] arr;
        arr = temp;
    }

    void clear()
    {
        for (auto i = 0; i < s; i++)
        { // Callling destructor on each element
            arr[i].~T();
        }
        s = 0;
    }

    void swap(MyVector &other)
    {
        std::swap(arr, other.arr); // Swaps the arr pointers
        std::swap(c, other.c);
        std::swap(s, other.s);
    }

    // ---------------------------------------------------------------------------------------------------------------------------------------

    // Iterators

    T *begin()
    {
        return arr;
    }

    T *end()
    {
        return arr + s;
    }

    const T *cbegin() const
    {
        return arr;
    }

    const T *cend() const
    {
        return arr + s;
    }

    std::reverse_iterator<T *> rbegin()
    {
        return std::reverse_iterator<T *>(end());
    }

    std::reverse_iterator<T *> rend()
    {
        return std::reverse_iterator<T *>(begin());
    }

    std::reverse_iterator<const T *> crbegin() const
    {
        return std::reverse_iterator<const T *>(cend());
    }

    std::reverse_iterator<const T *> crend() const
    {
        return std::reverse_iterator<const T *>(cbegin());
    }

    // ---------------------------------------------------------------------------------------------------------------------------------------

    // Custom Methods

    void sort(int start, int end)
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

    void sort()
    { // Overloading method with default parameters
        sort(0, s - 1);
    }

    int find(T ele)
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

    int findLast(T ele)
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

    void reverse(int left, int right)
    {
        while (left < right)
        {
            std::swap(arr[left], arr[right]);
            ++left;
            --right;
        }
    }

    void reverse()
    { // Overloading method with default parameters
        reverse(0, s - 1);
    }

    void rotateLeft(int k)
    {
        if (s == 0)
            return;

        k = k % s;
        if (k == 0)
            return;

        reverse(0, k - 1);
        reverse(k, s - 1);
        reverse();
    }

    void rotateRight(int k)
    {
        if (s == 0)
            return;

        k = k % s;
        if (k == 0)
            return;

        reverse(s - k, s - 1);
        reverse(0, s - k - 1);
        reverse();
    }
};