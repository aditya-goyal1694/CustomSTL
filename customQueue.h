#include <iostream>
#include <stdexcept>
#include <algorithm>
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
    bool isEmpty;

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

    customQueue() : q(new T[20]), s(0), c(20), frontInd(0), isEmpty(true), maxElement(std::numeric_limits<T>::min()), minElement(std::numeric_limits<T>::max()) {}

    // Destructor

    ~customQueue()
    {
        delete[] q;
    }

    // Methods

    void push(T& ele) {

        if(isEmpty) maxElement=ele;
        else if(maxElement!=std::numeric_limits<T>::min()){
            maxElement=(ele>=maxElement)?ele:maxElement;
        }
        
        if(isEmpty) minElement=ele;
        else if(minElement!=std::numeric_limits<T>::max()){
            minElement=(ele<=minElement)?ele:minElement;
        }

        if (s == c)
        {
            new_allocation();
        }

        s++;
        q[s]=ele;
        if(isEmpty) isEmpty=false;
    }

    void pop() {
        if(isEmpty) {
            throw std::runtime_error("Cannot pop. Queue is empty.");
        }

        if(maxElement==q[frontInd]) maxElement=std::numeric_limits<T>::min();
        if(minElement==q[frontInd]) minElement=std::numeric_limits<T>::max();

        frontInd++;
        if(frontInd==s){
            isEmpty=true;
            s=0;
            frontInd=0;
        }
    }

    T front(){
        if(isEmpty) {
            throw std::runtime_error("Queue is empty");
        }
        return q[frontInd];
    }

    bool empty(){
        return isEmpty;
    }

    T maxele(){
        if(isEmpty) {
            throw std::runtime_error("Queue is empty");
        }

        if(maxElement==NULL){
            for(int i=frontInd;i<=s;i++) maxElement=(q[i]>=maxElement)?q[i]:maxElement;
        }

        return maxElement;
    }

    T minele(){
        if (isEmpty) {
            throw std::runtime_error("Queue is empty");
        }

        if(minElement==NULL){
            for(int i=frontInd;i<=s;i++) minElement=(q[i]>=minElement)?q[i]:minElement;
        }

        return minElement;
    }

    void clear()
    {
        for (auto i = 0; i < s; i++)
        { // Calling destructor on each element
            q[i].~T();
        }

        s = 0;
        frontInd = 0;
        
        maxElement=std::numeric_limits<T>::min();
        minElement=std::numeric_limits<T>::max();
    }

};