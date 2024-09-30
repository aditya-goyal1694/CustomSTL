#include <iostream>
#include <stdexcept>
#include <limits>
using namespace std;

#ifndef CUSTOMDEQUE_H
#define CUSTOMDEQUE_H

template <typename T>
class customDeque
{
private:
    T *q;
    size_t c; // Capacity
    size_t s; // size

    T maxElement;
    T minElement;
    int base;

    int frontInd;
    int backInd;

    void new_allocation(int flag)
    {
        c += 20;
        T *temp = new T[c];

        if (flag)
        { // Inserting storage in front of the queue
            for (size_t i = frontInd; i <= backInd; i++)
            {
                temp[i + 20] = q[i];
            }

            frontInd += 20;
            backInd += 20;
        }
        else
        { // Appending storage back of the queue
            for (size_t i = frontInd; i <= backInd; i++)
            {
                temp[i] = q[i];
            }
        }

        delete[] q; // Free the old memory
        q = temp;
    }

public:
    // Constructor

    customDeque() : q(new T[20]), c(20), s(0), frontInd(10), backInd(12), base(11),
                    maxElement(std::numeric_limits<T>::lowest()), minElement(std::numeric_limits<T>::max()) {}

    // Destructor

    ~customDeque()
    {
        delete[] q;
    }

    // Methods

    void push_back(const T &ele)
    {
        if (isEmpty())
        {
            maxElement = ele;
            minElement = ele;
        }
        else
        {
            if (ele > maxElement)
                maxElement = ele;
            if (ele < minElement)
                minElement = ele;
        }

        if (backInd == c - 1)
        {
            new_allocation(1);
        }

        backInd++;
        q[backInd] = ele;
        s++;
    }

    void push_front(const T &ele)
    {
        if (isEmpty())
        {
            maxElement = ele;
            minElement = ele;
        }
        else
        {
            if (ele > maxElement)
                maxElement = ele;
            if (ele < minElement)
                minElement = ele;
        }

        if (frontInd == 0)
        {
            new_allocation(0);
        }

        frontInd--;
        q[frontInd] = ele;
        s++;
    }

    void pop_back()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Cannot pop. Queue is empty.");
        }

        if (maxElement == q[backInd])
            maxElement = std::numeric_limits<T>::lowest();
        ;
        if (minElement == q[backInd])
            minElement = std::numeric_limits<T>::max();

        s--;
        backInd--;
        if (backInd == base)
            backInd--;

        if (frontInd == backInd)
        {
            backInd = base + 1;
            frontInd = base - 1;
        }
    }

    void pop_front()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Cannot pop. Queue is empty.");
        }

        if (maxElement == q[frontInd])
            maxElement = std::numeric_limits<T>::lowest();
        ;
        if (minElement == q[frontInd])
            minElement = std::numeric_limits<T>::max();

        s--;
        frontInd++;

        if (frontInd == base)
            frontInd++;

        if (frontInd == backInd)
        {
            backInd = base + 1;
            frontInd = base - 1;
        }
    }

    T front()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Queue is empty");
        }
        return q[frontInd];
    }

    T back()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Queue is empty");
        }
        return q[backInd];
    }

    bool isEmpty()
    {
        return (s == 0);
    }

    T maxele()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Queue is empty");
        }

        if (maxElement == std::numeric_limits<T>::lowest())
        {
            maxElement = q[frontInd];
            for (int i = frontInd; i <= backInd; i++)
            {
                maxElement = (q[i] >= maxElement) ? q[i] : maxElement;
            }
        }

        return maxElement;
    }

    T minele()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Queue is empty");
        }

        if (minElement == std::numeric_limits<T>::max())
        {
            minElement = q[frontInd];
            for (int i = frontInd; i <= backInd; i++)
            {
                minElement = (q[i] <= minElement) ? q[i] : minElement;
            }
        }

        return minElement;
    }

    void clear()
    {
        maxElement = std::numeric_limits<T>::lowest();
        ;
        minElement = std::numeric_limits<T>::max();

        frontInd = base - 1;
        backInd = base + 1;
    }
};

#endif