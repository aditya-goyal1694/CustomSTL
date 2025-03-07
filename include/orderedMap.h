#include <iostream>
using namespace std;

#ifndef ORDERED_MAP_H
#define ORDERED_MAP_H

template <typename K, typename V>
class OrderedMap {
private:
    struct Node {
        K key;
        V value;
        Node* left;
        Node* right;

        Node(K k, V v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int size;

    Node* insert(Node* node, K key, V value, bool& exists) {
        if (!node) {
            size++;
            return new Node(key, value);
        }

        if (key < node->key)
            node->left = insert(node->left, key, value, exists);
        else if (key > node->key)
            node->right = insert(node->right, key, value, exists);
        else
            exists = true;

        return node;
    }

    Node* erase(Node* node, K key) {
        if (!node) return nullptr;

        if (key < node->key)
            node->left = erase(node->left, key);
        else if (key > node->key)
            node->right = erase(node->right, key);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                size--;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                size--;
                return temp;
            }

            // Node with two children - replace with inorder successor
            Node* temp = findMin(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = erase(node->right, temp->key);
        }

        return node;
    }

    Node* find(Node* node, K key) {
        if (!node || node->key == key) return node;

        if (key < node->key) return find(node->left, key);
        return find(node->right, key);
    }

    void destroyTree(Node* node) {
        if (!node) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    OrderedMap() : root(nullptr), size(0) {}

    ~OrderedMap() {
        destroyTree(root);
    }

    void insert(K key, V value) {
        bool exists = false;
        root = insert(root, key, value, exists);
    }

    V& operator[](const K& key) {
        Node* node = find(root, key);
        if (node) return node->value;

        bool exists = false;
        root = insert(root, key, V{}, exists);
        return find(root, key)->value;
    }

    void erase(const K& key) {
        root = erase(root, key);
    }

    Node* find(K key) {
        return find(root, key);
    }

    int count(const K& key) {
        return find(root, key) ? 1 : 0;
    }

    int size() {
        return size;
    }

};

#endif
