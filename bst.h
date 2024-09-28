#include <iostream>
#include <stdexcept>
#include "customQueue.h"
using namespace std;

template<typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int s;  // Size of the tree

    // Recursive helper functions
    Node* insert(Node* node, T element) {
        if (node == nullptr) {
            return new Node(element);
        }

        if (element < node->data) {
            node->left = insert(node->left, element);
        } else {
            node->right = insert(node->right, element);
        }
        return node;
    }

    bool search(Node* node, T element) {
        if (node == nullptr) {
            return false;
        }

        if (node->data == element) {
            return true;
        } else if (element < node->data) {
            return search(node->left, element);
        } else {
            return search(node->right, element);
        }
    }

    Node* deleteElement(Node* node, T element) {
        if (node == nullptr) {
            throw runtime_error("Element not found.");
        }

        if (element < node->data) {
            node->left = deleteElement(node->left, element);
        } else if (element > node->data) {
            node->right = deleteElement(node->right, element);
        } else {
            // Node found, delete it
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                // Node has two children, find inorder successor
                Node* successor = findMin(node->right);
                node->data = successor->data;
                node->right = deleteElement(node->right, successor->data);
            }
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void inorderTraversal(Node* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void preorderTraversal(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorderTraversal(Node* node) {
        if (node == nullptr) return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

    void levelOrderTraversal() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }

        customQueue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            if (current) {
                cout << current->data << " ";
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            } else {
                cout << "X ";  // 'X' represents an invalid node
            }
        }
        cout << endl;
    }

    void dfsTraversal(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        dfsTraversal(node->left);
        dfsTraversal(node->right);
    }

public:
    // Constructor
    BinarySearchTree() : root(nullptr), s(0) {}

    // Destructor
    ~BinarySearchTree() {
        clear(root);
    }

    void clear(Node* node) {
        if (node == nullptr) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    void insert(T element) {
        root = insert(root, element);
        s++;
    }

    bool search(T element) {
        return search(root, element);
    }

    void remove(T element) {
        root = deleteElement(root, element);
        s--;
    }

    bool isEmpty() {
        return s == 0;
    }

    int getHeight(Node* node) {
        if (node == nullptr) return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    void inorder() {
        if (isEmpty()) {
            cout << "Tree is empty." << endl;
            return;
        }
        inorderTraversal(root);
        cout << endl;
    }

    void preorder() {
        if (isEmpty()) {
            cout << "Tree is empty." << endl;
            return;
        }
        preorderTraversal(root);
        cout << endl;
    }

    void postorder() {
        if (isEmpty()) {
            cout << "Tree is empty." << endl;
            return;
        }
        postorderTraversal(root);
        cout << endl;
    }

    void levelOrder() {
        if (isEmpty()) {
            cout << "Tree is empty." << endl;
            return;
        }
        levelOrderTraversal();
    }

    void bfs() {
        levelOrder();
    }

    void dfs() {
        if (isEmpty()) {
            cout << "Tree is empty." << endl;
            return;
        }
        dfsTraversal(root);
        cout << endl;
    }
};
