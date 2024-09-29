#include <iostream>
#include <stdexcept>
#include <limits>
using namespace std;

template <typename T>
class customQueue {
private:
    T *q;
    size_t c; // Capacity
    size_t s; // Size

    T maxElement;
    T minElement;

    int frontInd;

    void new_allocation()
    {
        c += 20;
        T *temp = new T[c];

        for (size_t i = 0; i < s; i++)
        {
            temp[i] = q[i];
        }

        delete[] q; // Free the old memory
        q = temp;
    }

public:
    // Constructor
    customQueue() : q(new T[20]), s(0), c(20), frontInd(0), 
    maxElement(std::numeric_limits<T>::lowest()), minElement(std::numeric_limits<T>::max()) {}

    // Destructor
    ~customQueue()
    {
        delete[] q;
    }

    // Methods
    void push(T& ele) {
        if (isEmpty()) {
            maxElement = ele;
            minElement = ele;
        } else {
            if (ele > maxElement) {
                maxElement = ele;
            }
            if (ele < minElement) {
                minElement = ele;
            }
        }

        if (s == c)
        {
            new_allocation();
        }

        q[s]=ele;
        s++;
    }

    void pop() {
        if(isEmpty()) {
            throw std::runtime_error("Cannot pop. Queue is empty.");
        }

        if(maxElement==q[frontInd]) maxElement=std::numeric_limits<T>::lowest();
        if(minElement==q[frontInd]) minElement=std::numeric_limits<T>::max();

        frontInd++;
        if(frontInd==s){
            s=0;
            frontInd=0;
        }
    }

    T front() const {
        if(isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        return q[frontInd];
    }

    bool isEmpty() const {
        return s==0;
    }

    T maxele(){
        if(isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }

        if(maxElement==std::numeric_limits<T>::lowest()){
            maxElement = q[frontInd];
            for (int i = frontInd; i < s; i++) {
                if (q[i] > maxElement) {
                    maxElement = q[i];
                }
            }
        }

        return maxElement;
    }

    T minele(){
        if (isEmpty) {
            throw std::runtime_error("Queue is empty");
        }

        if(minElement==std::numeric_limits<T>::max()){
            minElement = q[frontInd];
            for (int i = frontInd; i < s; i++) {
                if (q[i] < minElement) {
                    minElement = q[i];
                }
            }
        }

        return minElement;
    }

    void clear()
    {
        s = 0;
        frontInd = 0;
        
        maxElement=std::numeric_limits<T>::lowest();
        minElement=std::numeric_limits<T>::max();
    }

};