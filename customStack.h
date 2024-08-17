#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include "customVector.h"
using namespace std;

template <typename T>
class customStack {
private:
    T *st;
    size_t c; // Capacity
    size_t s; // Size

    T maxElement;
    T minElement;

    int topIndex;
    bool isEmpty;

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

    customStack() : st(new T[20]), s(0), c(20), isEmpty(true), topIndex(-1), maxElement(NULL), minElement(NULL) {}

    // Destructor

    ~customStack()
    {
        delete[] st;
    }

    // Methods

    void push(T& ele) {

        if(isEmpty) maxElement=ele;
        else if(maxElement!=NULL){
            maxElement=(ele>=maxElement)?ele:maxElement;
        }
        
        if(isEmpty) minElement=ele;
        else if(minElement!=NULL){
            minElement=(ele<=minElement)?ele:minElement;
        }

        if (s == c)
        {
            new_allocation();
        }

        topIndex++;
        s++;
        st[topIndex]=ele;
        if(isEmpty) isEmpty=false;
    }

    void pop() {
        if(isEmpty) {
            throw std::underflow_error("Stack underflow");
        }

        if(maxElement==st[topIndex]) maxElement=NULL;
        if(minElement==st[topIndex]) minElement=NULL;

        topIndex--;
        s--;
        if(topIndex==-1) isEmpty=true;
    }

    T top(){
        if(isEmpty) {
            throw std::underflow_error("Stack is empty");
        }
        return st[topIndex];
    }

    bool empty(){
        return isEmpty;
    }

    T maxele(){
        if(isEmpty) {
            throw std::underflow_error("Stack is empty");
        }

        if(maxElement==NULL){
            for(T& i : st) maxElement=(i>=maxElement)?i:maxElement;
        }

        return maxElement;
    }

    T minele(){
        if (isEmpty) {
            throw std::underflow_error("Stack is empty");
        }

        if(minElement==NULL){
            for(T& i : st) minElement=(i<=minElement)?i:minElement;
        }

        return minElement;
    }

    void clear()
    {
        for (auto i = 0; i < s; i++)
        { // Calling destructor on each element
            st[i].~T();
        }
        s = 0;
    }

};