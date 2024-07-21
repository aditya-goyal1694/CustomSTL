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
        // ---------------------------------------------------------------------------------------------------------------------------------------

        // Cutom helper methods

        void merge(T* data, int l, int mid, int r) {
            int n1 = mid - l + 1;
            int n2 = r - mid;
            T* leftArr = new T[n1];
            T* rightArr = new T[n2];
            for (int i = 0; i < n1; ++i)
                leftArr[i] = data[l + i];
            for (int j = 0; j < n2; ++j)
                rightArr[j] = data[mid + 1 + j];
            int i = 0, j = 0, k = l;
            while (i < n1 && j < n2) {
                if (leftArr[i] <= rightArr[j]) {
                    data[k] = leftArr[i];
                    i++;
                } else {
                    data[k] = rightArr[j];
                    j++;
                }
                k++;
            }
            while (i < n1) {
                data[k] = leftArr[i];
                i++;
                k++;
            }
            while (j < n2) {
                data[k] = rightArr[j];
                j++;
                k++;
            }
            delete[] leftArr;
            delete[] rightArr;
        }

        void mergeSort(T* data, int l, int r) {
            if (l < r) {
                int mid = l + (r - l) / 2;
                mergeSort(data, l, mid);
                mergeSort(data, mid + 1, r);
                merge(data, l, mid, r);
            }
        }

        int partition(T* data, int low, int high) {
            T pivot = data[high];
            int i = (low - 1);
            for (int j = low; j <= high - 1; j++) {
                if (data[j] < pivot) {
                    i++;
                    swap(data[i], data[j]);
                }
            }
            swap(data[i + 1], data[high]);
            return (i + 1);
        }

        void quickSort(T* data, int low, int high) {
            if (low < high) {
                int pi = partition(data, low, high);
                quickSort(data, low, pi - 1);
                quickSort(data, pi + 1, high);
            }
        }

        void insertionSort(T* data, int start, int end) {
            for (int i = start + 1; i <= end; ++i) {
                T key = data[i];
                int j = i - 1;
                while (j >= start && data[j] > key) {
                    data[j + 1] = data[j];
                    --j;
                }
                data[j + 1] = key;
            }
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
                throw out_of_range("Vector is empty");
            }
            return arr[0];
        }

        T& back() {
            if (empty()) {
                throw out_of_range("Vector is empty");
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
                throw out_of_range("Position out of range");
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
                throw out_of_range("Position out of range");
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

        void clear(){
            for(auto i=0;i<s;i++){      //Callling destructor on each element
                arr[i].~T();
            }
            s=0;
        }

        void swap(vector& other) {
            std::swap(arr, other.arr);      //Swaps the data pointers
            std::swap(c, other.c);
            std::swap(s, other.s);
        }


        // ---------------------------------------------------------------------------------------------------------------------------------------

        // Iterators

        T* begin(){
            return arr;
        }

        T* end(){
            return arr+s;
        }

        const T* cbegin() const {
            return arr;
        }

        const T* cend() const {
            return arr + s;
        }

        std::reverse_iterator<T*> rbegin() {
            return reverse_iterator<T*>(end());
        }

        std::reverse_iterator<T*> rend() {
            return reverse_iterator<T*>(begin());
        }

        std::reverse_iterator<const T*> crbegin() const {
            return reverse_iterator<const T*>(cend());
        }

        std::reverse_iterator<const T*> crend() const {
            return reverse_iterator<const T*>(cbegin());
        }

        // ---------------------------------------------------------------------------------------------------------------------------------------

        // Custom Methods

        void sort(int start=0, int end=s-1) {
            if (start < 0 || end >= s || start > end) {
                throw out_of_range("Invalid start or end index.");
            }

            int size=end-start+1;
            if (size < 20) {
                insertionSort(data, start, end);
            } else if (size < 10000) {
                quickSort(data, start, end);
            } else {
                mergeSort(data, start, end);
            }
        }

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