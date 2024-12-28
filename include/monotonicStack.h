#include <iostream>
#include <stdexcept>
using namespace std;

#ifndef MONOTONICSTACK_H
#define MONOTONICSTACK_H

template <typename T>
class monotonicStack
{
private:
    T *st;
    size_t c; // Capacity
    size_t s; // Size

    int topIndex;
    bool descending;

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
    // Constructors
    monotonicStack() : st(new T[20]), s(0), c(20), topIndex(-1), descending(false) {}

    monotonicStack(bool desc) : st(new T[20]), s(0), c(20), topIndex(-1), descending(desc) {}

    // Destructor
    ~monotonicStack()
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

        if (descending)
        {
            while (topIndex >= 0 && ele > st[topIndex])
            {
                pop();
            }
        }
        else
        {
            while (topIndex >= 0 && ele < st[topIndex])
            {
                pop();
            }
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

    bool isEmpty() const
    {
        return s == 0;
    }

    void clear()
    {
        topIndex = -1;
        s = 0;
    }
};

#endif