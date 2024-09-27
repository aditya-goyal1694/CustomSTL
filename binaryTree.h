#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class BinaryTree {
private:
    T* tree;
    int c;     // Capacity
    int s;     // Size

    void resizeTree() {
        c += 20;
        T* newTree = new T[c];
        for (int i = 0; i < s; ++i) {
            newTree[i] = tree[i];
        }
        delete[] tree;
        tree = newTree;
    }

    // Recursive functions for tree traversals
    void preorderTraversal(int index) {
        if (index >= s) return;
        cout << tree[index] << " ";
        preorderTraversal(2 * index + 1);
        preorderTraversal(2 * index + 2);
    }

    void inorderTraversal(int index) {
        if (index >= s) return;
        inorderTraversal(2 * index + 1);
        cout << tree[index] << " ";
        inorderTraversal(2 * index + 2);
    }

    void postorderTraversal(int index) {
        if (index >= s) return;
        postorderTraversal(2 * index + 1);
        postorderTraversal(2 * index + 2);
        cout << tree[index] << " ";
    }

    void dfsTraversal(int index) {
        if (index >= s) return;
        cout << tree[index] << " ";
        dfsTraversal(2 * index + 1);
        dfsTraversal(2 * index + 2);
    }

public:
    // Constructor
    BinaryTree(int cap = 20) : c(cap), s(0) {
        tree = new T[c];
    }

    // Destructor
    ~BinaryTree() {
        delete[] tree;
    }

    // Level order insertion
    void insert(T element) {
        if (s == c) {
            resizeTree();
        }
        tree[s] = element;
        s++;
    }

    void modify(T oldVal, T newVal) {
        bool found = false;
        for (int i = 0; i < s; ++i) {
            if (tree[i] == oldVal) {
                tree[i] = newVal;
                found = true;
                break;
            }
        }
        if (!found) {
            throw std::runtime_error("Value to modify not found.");
        }
    }

    int getParent(int ind) {
        if (ind <= 0 || ind >= s) {
            throw std::runtime_error("Index out of bounds or no parent.");
        }
        return (ind - 1) / 2;
    }

    // Get left child index of a node
    int getLeft(int ind) {
        int left = 2 * ind + 1;
        if (left >= s) {
            throw std::runtime_error("No left child.");
        }
        return left;
    }

    // Get right child index of a node
    int getRight(int ind) {
        int right = 2 * ind + 2;
        if (right >= s) {
            throw std::runtime_error("No right child.");
        }
        return right;
    }

    T getElementAt(int index) {
        if (index < 0 || index >= s) {
            throw std::runtime_error("Index out of bounds.");
        }
        return tree[index];
    }

    int getSize() {
        return s;
    }

    bool isEmpty() {
        return s == 0;
    }

    bool find(T element) {
        for (int i = 0; i < s; ++i) {
            if (tree[i] == element) {
                return true;
            }
        }
        return false;
    }

    // Need to fix
    void deleteElement(T element) {
        if (isEmpty()) {
            throw std::runtime_error("Tree is empty.");
        }
        for (int i = 0; i < s; ++i) {
            if (tree[i] == element) {
                tree[i] = tree[s - 1];  // Replace with the last element
                s--;  // Decrease the size
                return;
            }
        }
        throw std::runtime_error("Element not found.");
    }

    void preorder() {
        if (isEmpty()) {
            cout << "Tree is empty." << endl;
            return;
        }
        preorderTraversal(0);
        cout << endl;
    }

    void inorder() {
        if (isEmpty()) {
            cout << "Tree is empty." << endl;
            return;
        }
        inorderTraversal(0);
        cout << endl;
    }

    void postorder() {
        if (isEmpty()) {
            cout << "Tree is empty." << endl;
            return;
        }
        postorderTraversal(0);
        cout << endl;
    }

    void levelOrder() {
        if (isEmpty()) {
            cout << "Tree is empty." << endl;
            return;
        }

        for (int i = 0; i < s; ++i) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    void bfs() {
        if (isEmpty()) {
            cout << "Tree is empty." << endl;
            return;
        }
        levelOrder();
    }

    void dfs() {
        if (isEmpty()) {
            cout << "Tree is empty." << endl;
            return;
        }
        dfsTraversal(0);
        cout << endl;
    }
};
