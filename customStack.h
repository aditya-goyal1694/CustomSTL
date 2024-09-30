#include <iostream>
#include <stdexcept>
#include <limits>
using namespace std;

#ifndef CUSTOMSTACK_H
#define CUSTOMSTACK_H

template <typename T>
class customStack
{
private:
    T *st;
    size_t c; // Capacity
    size_t s; // Size

    T maxElement;
    T minElement;

    int topIndex;

    void new_allocation()
    {
        c += 20;
        T *temp = new T[c];

        for (size_t i = 0; i < s; i++)
        {
            temp[i] = st[i];
        }

        delete[] st; // Free the old memory
        st = temp;
    }

public:
    // Constructor
    customStack() : st(new T[20]), s(0), c(20), topIndex(-1),
                    maxElement(std::numeric_limits<T>::lowest()),
                    minElement(std::numeric_limits<T>::max()) {}

    // Destructor
    ~customStack()
    {
        delete[] st;
    }

    // Methods

    void push(const T &ele)
    {

        if (s == c)
        {
            new_allocation();
        }

        if (isEmpty())
        {
            maxElement = ele;
            minElement = ele;
        }
        else
        {
            maxElement = (maxElement >= ele) ? maxElement : ele;
            minElement = (minElement <= ele) ? minElement : ele;
        }

        topIndex++;
        st[topIndex] = ele;
        s++;
    }

    void pop()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack underflow");
        }

        if (maxElement == st[topIndex])
            maxElement = std::numeric_limits<T>::lowest();
        if (minElement == st[topIndex])
            minElement = std::numeric_limits<T>::max();

        topIndex--;
        s--;
    }

    T top()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack is empty");
        }
        return st[topIndex];
    }

    bool isEmpty()
    {
        return s == 0;
    }

    T maxele()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack is empty");
        }

        if (maxElement == std::numeric_limits<T>::lowest())
        {
            maxElement = st[0];
            for (int i = 0; i < topIndex; i++)
                maxElement = (st[i] >= maxElement) ? st[i] : maxElement;
        }

        return maxElement;
    }

    T minele()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack is empty");
        }

        if (minElement == std::numeric_limits<T>::max())
        {
            minElement = st[0];
            for (int i = 0; i < topIndex; i++)
                minElement = (st[i] >= minElement) ? st[i] : minElement;
        }

        return minElement;
    }

    void clear()
    {
        s = 0;
        topIndex = -1;
        maxElement = std::numeric_limits<T>::lowest();
        minElement = std::numeric_limits<T>::max();
    }
};

#endif