#include <iostream>
using namespace std;

#ifndef ORDERED_SET_H
#define ORDERED_SET_H

template <typename T>
class OrderedSet {
private:
    struct Node {
        T key;
        Node* left;
        Node* right;

        Node(T k) : key(k), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int size;

    Node* insert(Node* node, T key, bool& exists) {
        if (!node) {
            size++;
            return new Node(key);
        }

        if (key < node->key)
            node->left = insert(node->left, key, exists);
        else if (key > node->key)
            node->right = insert(node->right, key, exists);
        else
            exists = true;

        return node;
    }

    Node* erase(Node* node, T key) {
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

            Node* temp = findMin(node->right);
            node->key = temp->key;
            node->right = erase(node->right, temp->key);
        }
        return node;
    }

    Node* find(Node* node, T key) {
        if (!node || node->key == key) return node;
        if (key < node->key) return find(node->left, key);
        return find(node->right, key);
    }

    Node* findMin(Node* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    void destroyTree(Node* node) {
        if (!node) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    OrderedSet() : root(nullptr), size(0) {}

    ~OrderedSet() {
        destroyTree(root);
    }

    void insert(T key) {
        bool exists = false;
        root = insert(root, key, exists);
    }

    void erase(const T& key) {
        root = erase(root, key);
    }

    bool find(T key) {
        return find(root, key) != nullptr;
    }

    int count(const T& key) {
        return find(root, key) ? 1 : 0;
    }

    int getSize() {
        return size;
    }
};

#endif
