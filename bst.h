#include <iostream>
#include <stdexcept>

template<typename T>
class BinarySearchTree {
private:
    T* tree;
    int c;      // capacity
    int s;      // size

    void resizeTree() {
        c += 20;
        T* newTree = new T[c];
        for (int i = 0; i < s; ++i) {
            newTree[i] = tree[i];
        }
        delete[] tree;
        tree = newTree;
    }

    // Recursive helper functions
    void insert(int index, T element) {
        if (index >= c) {
            throw runtime_error("Index exceeds c.");
        }

        if (tree[index] == T()) {  // If the position is empty
            tree[index] = element;
            return;
        }

        if (element < tree[index]) {
            insert(2 * index + 1, element);  // Left child
        } else {
            insert(2 * index + 2, element);  // Right child
        }
    }

    bool search(int index, T element) {
        if (index >= s || tree[index] == T()) {
            return false;
        }

        if (tree[index] == element) {
            return true;
        } else if (element < tree[index]) {
            return search(2 * index + 1, element);
        } else {
            return search(2 * index + 2, element);
        }
    }

    void deleteElement(int index, T element) {
        if (index >= s || tree[index] == T()) {
            throw runtime_error("Element not found.");
        }

        if (tree[index] == element) {
            tree[index] = T();          // Setting to default value
            return;
        }

        if (element < tree[index]) {
            deleteElement(2 * index + 1, element);
        } else {
            deleteElement(2 * index + 2, element);
        }
    }

    void inorderTraversal(int index) {
        if (index >= s || tree[index] == T()) return;
        inorderTraversal(2 * index + 1);
        cout << tree[index] << " ";
        inorderTraversal(2 * index + 2);
    }

    void preorderTraversal(int index) {
        if (index >= s || tree[index] == T()) return;
        cout << tree[index] << " ";
        preorderTraversal(2 * index + 1);
        preorderTraversal(2 * index + 2);
    }

    void postorderTraversal(int index) {
        if (index >= s || tree[index] == T()) return;
        postorderTraversal(2 * index + 1);
        postorderTraversal(2 * index + 2);
        cout << tree[index] << " ";
    }

    void dfsTraversal(int index) {
        if (index >= s || tree[index] == T()) return;
        cout << tree[index] << " ";
        dfsTraversal(2 * index + 1);
        dfsTraversal(2 * index + 2);
    }

public:
    // Constructor
    BinarySearchTree(int cap = 20) : c(cap), s(0) {
        tree = new T[c]();
    }

    // Destructor
    ~BinarySearchTree() {
        delete[] tree;
    }

    void insert(T element) {
        if (s == c) {
            resizeTree();
        }
        insert(0, element);
        s++;
    }

    bool search(T element) {
        return search(0, element);
    }

    void remove(T element) {
        deleteElement(0, element);
        s--;
    }

    bool isEmpty() {
        return s == 0;
    }

    void inorder() {
        inorderTraversal(0);
        cout << endl;
    }

    void preorder() {
        preorderTraversal(0);
        cout << endl;
    }

    void postorder() {
        postorderTraversal(0);
        cout << endl;
    }

    void levelOrder() {
        if (isEmpty()) {
            cout << "Tree is empty." << endl;
            return;
        }

        T invalid = T(); // Default-initialized value
        
        for (int i = 0; i < s; ++i) {
            if (tree[i] != invalid) {
                cout << tree[i] << " ";
            } else {
                cout << "X ";  // 'X' represents an invalid node
            }
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