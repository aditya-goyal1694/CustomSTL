#include <iostream>
#include <string>
#include <type_traits>                                       // For is_integral
using namespace std;

#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H

template <typename K, typename V>
class UnorderedMap {
private:
    K* keys;
    V* values;
    bool* occupied;
    bool* deleted;                                          // marks deleted elements to avoid problems in linear probing
    int capacity;
    int size;

    int hashFunction(const K& key) {
        if constexpr (is_integral<K>::value) {              // checks if K is an integer type (int, long, short, etc)
            return key % capacity;
        }

        unsigned long hash = 0;                             // unsigned to avoid negative overflows and to extend the range
        for (char ch : key) {
            hash = hash * 31 + ch;                          // Standard practice for hashing, and 31 is prime, distributes hash values more uniformly
        }

        return hash % capacity;
    }

    void rehash() {
        int oldCapacity = capacity;

        K* oldKeys = keys;
        V* oldValues = values;
        bool* oldOccupied = occupied;
        bool* oldDeleted = deleted;

        capacity *= 2;
        keys = new K[capacity];
        values = new V[capacity];
        occupied = new bool[capacity]{};
        deleted = new bool[capacity]{};

        size = 0;
        for (int i = 0; i < oldCapacity; i++) {
            if (oldOccupied[i] && !oldDeleted[i]) {
                insert(oldKeys[i], oldValues[i]);                    // Re-inserting valid elements
            }
        }

        delete[] oldKeys;
        delete[] oldValues;
        delete[] oldOccupied;
        delete[] oldDeleted;
    }

public:
    UnorderedMap() {
        capacity = 10;
        size = 0;
        keys = new K[capacity];
        values = new V[capacity]();
        occupied = new bool[capacity]{};
        deleted = new bool[capacity]{};
    }

    ~UnorderedMap() {
        delete[] keys;
        delete[] values;
        delete[] occupied;
        delete[] deleted;
    }

    V& operator[](const K& key) {
        int ind = hashFunction(key);

        if (count(key)) {
            while (occupied[ind]) {
                if (keys[ind] == key && !deleted[ind]) {
                    return values[ind];
                }
                ind = (ind + 1) % capacity;
            }
        }

        while (occupied[ind]) {
            ind = (ind + 1) % capacity;
        }

        keys[ind] = key;
        occupied[ind] = true;
        deleted[ind] = false;
        size++;

        if ((double)size / capacity > 0.7) {                              // Rehash if load factor exceeds 0.7
            rehash();
            return (*this)[key];                                         // Recompute index after rehashing
        }

        return values[ind];                                              // Returning reference for potential assignment
    }

    void insert(K key, V value) {
        (*this)[key] = value;
    }

    void erase(const K& key) {
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

    int count(K key) {
        int ind = hashFunction(key);
        while (occupied[ind]) {
            if (keys[ind] == key && !deleted[ind]) {
                return 1;
            }
            ind = (ind + 1) % capacity;
        }
        return 0;
    }

    V* find(K key) {
        int ind = hashFunction(key);
        while (occupied[ind]) {
            if (keys[ind] == key && !deleted[ind]) {
                return &values[ind];
            }
            ind = (ind + 1) % capacity;
        }
        return nullptr;
    }
};

#endif
