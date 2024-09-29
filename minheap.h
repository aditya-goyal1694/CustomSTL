#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class MinHeap {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node* parent;

        Node(T val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node* root;
    int s;          // s

    void swap(Node* a, Node* b) {
        T temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

    // For deletion
    void heapifyDown(Node* node) {
        if (!node) return;

        Node* smallest = node;

        if (node->left && node->left->data < smallest->data) {
            smallest = node->left;
        }

        if (node->right && node->right->data < smallest->data) {
            smallest = node->right;
        }

        if (smallest != node) {
            swap(node, smallest);
            heapifyDown(smallest);
        }
    }

    // For insertion
    void heapifyUp(Node* node) {
        if (!node || !node->parent) return;

        if (node->data < node->parent->data) {
            swap(node, node->parent);
            heapifyUp(node->parent);
        }
    }

    Node* insertNode(Node* node, T element) {
        if (!node) {
            return new Node(element);
        }

        // Level order insertion
        if (!node->left) {
            node->left = new Node(element);
            node->left->parent = node;
            return node->left;
        } else if (!node->right) {
            node->right = new Node(element);
            node->right->parent = node;
            return node->right;
        }

        // If both children are present, we go deeper in the tree
        Node* leftResult = insertNode(node->left, element);
        if (leftResult) return leftResult;

        return insertNode(node->right, element);
    }

    Node* findLast(Node* node) {
        if (!node) return nullptr;

        // Level order traversal
        Node* lastNode = nullptr;
        Node* temp = node;

        while (temp) {
            lastNode = temp;
            if (temp->left) temp = temp->left;
            else if (temp->right) temp = temp->right;
            else break;
        }

        return lastNode;
    }

public:
    // Constructor
    MinHeap() : root(nullptr), s(0) {}

    // Destructor
    ~MinHeap() {
        while (!isEmpty()) {
            extractMin();
        }
    }

    void insert(T element) {
        Node* newNode = insertNode(root, element);
        if (!root) {
            root = newNode;
        }
        heapifyUp(newNode);
        s++;
    }

    T extractMin() {
        if (isEmpty()) {
            throw std::runtime_error("Heap is empty.");
        }

        T minElement = root->data;

        Node* lastNode = findLast(root);
        if (lastNode == root) {
            delete root;
            root = nullptr;
        } else {
            root->data = lastNode->data; // Move last node to root
            if (lastNode->parent) {
                if (lastNode->parent->left == lastNode) {
                    lastNode->parent->left = nullptr;
                } else {
                    lastNode->parent->right = nullptr;
                }
            }
            delete lastNode;
            heapifyDown(root);
        }

        s--;
        return minElement;
    }

    T getMin() {
        if (isEmpty()){
            throw runtime_error("Heap is empty.");
        }
        return root->data;
    }

    bool isEmpty() const {
        return s == 0;
    }

    int gets() const {
        return s;
    }
};
