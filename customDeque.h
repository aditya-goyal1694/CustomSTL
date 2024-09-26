#include <iostream>
#include <stdexcept>
#include <limits>
using namespace std;

template <typename T>
class customDeque {
private:
    T *q;
    size_t c; // Capacity

    T maxElement;
    T minElement;
    int base;

    int frontInd;
    int backInd;
    bool isEmpty;

    void new_allocation(int flag)
    {
        c += 20;
        T *temp = new T[c];

        if(flag){                                                                // Inserting storage in front of the queue
            for (size_t i = frontInd; i <= backInd; i++){
                temp[i+20] = q[i];
            }

            frontInd+=20;
            backInd+=20;
        }
        else{                                                                    // Appending storage back of the queue 
            for (size_t i = frontInd; i <= backInd; i++){
                temp[i] = q[i];
            }
        }

        delete[] q; // Free the old memory
        q = temp;
    }

public:
    // Constructor

    customDeque() : q(new T[20]), c(20), frontInd(10), backInd(12), base(11), isEmpty(true), 
    maxElement(std::numeric_limits<T>::min()), minElement(std::numeric_limits<T>::max()) {}

    // Destructor

    ~customDeque()
    {
        delete[] q;
    }

    // Methods

    void push_back(T& ele) {

        if(isEmpty) maxElement=ele;
        else if(maxElement != std::numeric_limits<T>::min()){
            maxElement=(ele>=maxElement)?ele:maxElement;
        }
        
        if(isEmpty) minElement=ele;
        else if(minElement != std::numeric_limits<T>::max()){
            minElement=(ele<=minElement)?ele:minElement;
        }

        if (backInd == c-1)
        {
            new_allocation(1);
        }

        backInd++;
        q[backInd]=ele;
        if(isEmpty) isEmpty=false;
    }

    void push_front(T& ele) {

        if(isEmpty) maxElement=ele;
        else if(maxElement != std::numeric_limits<T>::min()){
            maxElement=(ele>=maxElement)?ele:maxElement;
        }
        
        if(isEmpty) minElement=ele;
        else if(minElement != std::numeric_limits<T>::max()){
            minElement=(ele<=minElement)?ele:minElement;
        }

        if (frontInd == 0)
        {
            new_allocation(0);
        }

        frontInd--;
        q[frontInd]=ele;
        if(isEmpty) isEmpty=false;

    }

    void pop_back() {
        if(isEmpty) {
            throw std::runtime_error("Cannot pop. Queue is empty.");
        }

        if(maxElement==q[backInd]) maxElement=std::numeric_limits<T>::min();
        if(minElement==q[backInd]) minElement=std::numeric_limits<T>::max();

        backInd--;
        if(backInd==base) backInd--;

        if(frontInd==backInd){
            isEmpty=true;
            backInd=base+1;
            frontInd=base-1;
        }
    }

    void pop_front() {
        if(isEmpty) {
            throw std::runtime_error("Cannot pop. Queue is empty.");
        }

        if(maxElement==q[frontInd]) maxElement=std::numeric_limits<T>::min();
        if(minElement==q[frontInd]) minElement=std::numeric_limits<T>::max();

        frontInd++;

        if(frontInd==base) frontInd++;

        if(frontInd==backInd){
            isEmpty=true;
            backInd=base+1;
            frontInd=base-1;
        }
    }

    T front(){
        if(isEmpty) {
            throw std::runtime_error("Queue is empty");
        }
        return q[frontInd];
    }

    T back(){
        if(isEmpty) {
            throw std::runtime_error("Queue is empty");
        }
        return q[backInd];
    }

    bool empty(){
        return isEmpty;
    }

    T maxele(){
        if(isEmpty) {
            throw std::runtime_error("Queue is empty");
        }

        if(maxElement==std::numeric_limits<T>::min()){
            for(int i=frontInd;i<=backInd;i++){
                maxElement=(q[i]>=maxElement)?q[i]:maxElement;
            }
        }

        return maxElement;
    }

    T minele(){
        if (isEmpty) {
            throw std::runtime_error("Queue is empty");
        }

        
        if(minElement==std::numeric_limits<T>::max()){
            for(int i=frontInd;i<=backInd;i++){
                minElement=(q[i]<=minElement)?q[i]:minElement;
            }
        }

        return minElement;
    }

    void clear()
    {
        for (auto i = frontInd; i <= backInd; i++)
        { // Calling destructor on each element
            q[i].~T();
        }

        maxElement = std::numeric_limits<T>::min();
        minElement = std::numeric_limits<T>::max();

        frontInd = base - 1;
        backInd = base + 1;

        isEmpty=true;
    }

};