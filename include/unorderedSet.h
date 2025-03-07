#include <iostream>
#include <type_traits>                                           // For is_integral
using namespace std;

#ifndef UNORDERED_SET_H
#define UNORDERED_SET_H

template <typename T>
class UnorderedSet {
private:
    T* keys;
    bool* occupied;
    bool* deleted;
    int capacity;
    int size;

    int hashFunction(const T& key) {
        if constexpr (is_integral<T>::value) {
            return key % capacity;                             // Modulo Hash for integers
        }

        unsigned long hash = 0;
        for (char ch : key) {
            hash = hash * 31 + ch;                            // Rolling Hash for strings
        }

        return hash % capacity;
    }

    void rehash() {
        int oldCapacity = capacity;

        T* oldKeys = keys;
        bool* oldOccupied = occupied;
        bool* oldDeleted = deleted;

        capacity *= 2;
        keys = new T[capacity];
        occupied = new bool[capacity]{};
        deleted = new bool[capacity]{};

        size = 0;
        for (int i = 0; i < oldCapacity; i++) {
            if (oldOccupied[i] && !oldDeleted[i]) {
                insert(oldKeys[i]);
            }
        }

        delete[] oldKeys;
        delete[] oldOccupied;
        delete[] oldDeleted;
    }

public:
    UnorderedSet() {
        capacity = 10;
        size = 0;
        keys = new T[capacity];
        occupied = new bool[capacity]{};
        deleted = new bool[capacity]{};
    }

    ~UnorderedSet() {
        delete[] keys;
        delete[] occupied;
        delete[] deleted;
    }

    void insert(const T& key) {
        if (count(key)) return;

        int ind = hashFunction(key);
        while (occupied[ind]) {
            ind = (ind + 1) % capacity;
        }

        keys[ind] = key;
        occupied[ind] = true;
        deleted[ind] = false;
        size++;

        if ((double)size / capacity > 0.7) {                                  // Rehash if load exceeds 70 %
            rehash();
        }
    }

    void erase(const T& key) {
        int ind = hashFunction(key);
        while (occupied[ind]) {
            if (keys[ind] == key && !deleted[ind]) {
                deleted[ind] = true;
                size--;
                return;
            }
            ind = (ind + 1) % capacity;
        }
    }

    int count(const T& key) {
        int ind = hashFunction(key);
        while (occupied[ind]) {
            if (keys[ind] == key && !deleted[ind]) {
                return 1;
            }
            ind = (ind + 1) % capacity;
        }
        return 0;
    }

    T* find(const T& key) {
        int ind = hashFunction(key);
        while (occupied[ind]) {
            if (keys[ind] == key && !deleted[ind]) {
                return &keys[ind];
            }
            ind = (ind + 1) % capacity;
        }
        return nullptr;
    }
};

#endif
