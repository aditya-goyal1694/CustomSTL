#include <iostream>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <memory>
#include <limits>
using namespace std;

template <typename T>
class vector{
    private:
        T* arr;
        size_t c;  //Capacity
        size_t s;  //Size

        void new_allocation(){
            c=c+10;
            T* temp=new T[c];

            for(auto i=0;i<s;i++){
                temp[i]=arr[i];
            }

            delete []arr;   //Free the old memory
            arr=temp;

        }

    public:
        // Constructors

        vector() : arr(nullptr), s(0), c(0) {}

        vector(int n) : s(0), c(n) {
            arr = new T[n];
        }

        vector(int n, T val) : c(n), s(n) {
            arr = new T[n];
            for (int i = 0; i < n; ++i) {
                arr[i] = val;
            }
        }

        // ---------------------------------------------------------------------------------------------------------------------------------------

        // Destructor

        ~vector() {
            delete[] arr;
        }

        // ---------------------------------------------------------------------------------------------------------------------------------------


        // Capacity methods

        int size(){
            return s;
        }

        int capacity(){
            return c;
        }

        bool empty(){
            return s==0;
        }

        void resize(size_t newSize){
            c=newSize;
            T* temp=new T[c];

            if(c<s) s=c; 

            for(auto i=0;i<s;i++){
                temp[i]=arr[i];
            }

            delete []arr;
            arr=temp;
        }

        void resize(size_t newSize, T val){         //Custom method
            c=s=newSize;
            T* temp=new T[c];

            if(c<s) s=c; 

            for(auto i=0;i<c;i++){
                temp[i]=val;
            }

            delete []arr;
            arr=temp;
        }

        void reserve(int num){
            c=num;
            s=0;
            T* temp=new T[c];

            delete []arr;
            arr=temp;
        }

        void shrink_to_fit() {
            if (s < c) {
                T* temp = new T[s];
                c=s;

                for (size_t i = 0; i < s; ++i) {
                    temp[i] = arr[i];
                }

                delete[] arr;
                arr = temp;
            }
        }

        // ---------------------------------------------------------------------------------------------------------------------------------------


        // Element Access

        T operator[](int index){
            if(index>=s){
                throw out_of_range("Index out of bound");
            }
            return arr[index];
        }

        T& front() {
            if (empty()) {
                throw std::out_of_range("Vector is empty");
            }
            return arr[0];
        }

        T& back() {
            if (empty()) {
                throw std::out_of_range("Vector is empty");
            }
            return arr[s - 1];
        }

        // ---------------------------------------------------------------------------------------------------------------------------------------


        // Modifiers

        void push_back(T ele){
            if(s==c){
                new_allocation();
            }

            arr[s]=ele;
            s++;
        }

        void pop_back(){
            if(s==0) {
                throw out_of_range("Cannot pop from an empty vector");
                return;
            }
            s--;
        }

        void assign(size_t count, T& value) {
            if (count > c) {
                reserve(count);
            }

            for (auto i = 0; i < count; ++i) {
                arr[i] = value;
            }

            s = count;
        }

        void insert(size_t pos, T& value) {
            if (pos > s) {
                throw std::out_of_range("Position out of range");
            }
            if (s == c) {
                reserve(c + 10);
            }

            T* temp = new T[s+1];
            for (auto i = 0; i < pos-1; i++) {
                temp[i] = arr[i];
            }
            arr[pos-1] = value;
            for (auto i = pos; i < s ; i++) {
                temp[i] = arr[i-1];
            }

            s++;
            delete []arr;
            arr=temp;

        }

        void erase(size_t pos) {
            if (pos >= s) {
                throw std::out_of_range("Position out of range");
            }
            
            T* temp = new T[s-1];
            for (auto i = 0; i < pos-1 ; i++) {
                temp[i] = arr[i];
            }
            for (auto i = pos-1; i < s-1 ; i++) {
                temp[i] = arr[i+1];
            }

            s--;
            delete []arr;
            arr=temp;
        }

        void swap(vector& other) {
            std::swap(arr, other.arr);      //Swaps the data pointers
            std::swap(c, other.c);
            std::swap(s, other.s);
        }


        // ---------------------------------------------------------------------------------------------------------------------------------------

        // Iterators




};

int main(){
    vector<int> myvec(3);
    myvec.push_back(7);
    myvec.push_back(5);
    myvec.push_back(9);
    myvec.push_back(8);
    myvec.push_back(2);
    myvec.pop_back();
    cout<<myvec[4]<<endl;
    cout<<myvec.size()<<endl;
    cout<<myvec.capacity()<<endl;
    
}