#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int s;  // size

    // Recursive helper functions

    void preorderTraversal(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void inorderTraversal(Node* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void postorderTraversal(Node* node) {
        if (node == nullptr) return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

    void dfsHelper(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        dfsHelper(node->left);
        dfsHelper(node->right);
    }

    void levelOrderTraversal(Node* node) {
        if (node == nullptr) return;
        int height = getHeight(node);
        for (int i = 1; i <= height; i++) {
            printLevel(node, i);
        }
    }

    void printLevel(Node* node, int level) {
        if (node == nullptr) return;
        if (level == 1) {
            cout << node->data << " ";
        } else if (level > 1) {
            printLevel(node->left, level - 1);
            printLevel(node->right, level - 1);
        }
    }

    Node* insertLevelOrder(Node* node, T element) {
        if (node == nullptr) {
            return new Node(element);
        }

        if (node->left == nullptr) {
            node->left = insertLevelOrder(node->left, element);
        } else if (node->right == nullptr) {
            node->right = insertLevelOrder(node->right, element);
        } else {
            if (getHeight(node->left) <= getHeight(node->right)) {
                insertLevelOrder(node->left, element);
            } else {
                insertLevelOrder(node->right, element);
            }
        }
        return node;
    }

    Node* findElement(Node* node, T element) {
        if (node == nullptr || node->data == element) return node;

        Node* leftResult = findElement(node->left, element);
        if (leftResult != nullptr) return leftResult;

        return findElement(node->right, element);
    }

    Node* findAndDelete(Node* node, T element) {
        if (node == nullptr) return nullptr;

        if (node->data == element) {
            delete node;
            return nullptr;
        }

        node->left = findAndDelete(node->left, element);
        node->right = findAndDelete(node->right, element);

        return node;
    }

    Node* findParent(Node* node, Node* child) {
        if (node == nullptr || node->left == child || node->right == child) {
            return node;
        }

        Node* leftSearch = findParent(node->left, child);
        if (leftSearch != nullptr) return leftSearch;

        return findParent(node->right, child);
    }

public:
    // Constructor
    BinaryTree() : root(nullptr), s(0) {}

    // Destructor
    ~BinaryTree() {
        clearTree(root);
    }

    int getHeight(Node* node) {
        if (node == nullptr) return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    void clearTree(Node* node) {
        if (node == nullptr) return;
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }

    // Level order insertion
    void insert(T element) {
        root = insertLevelOrder(root, element);
        s++;
    }

    void modify(T oldVal, T newVal) {
        Node* node = findElement(root, oldVal);
        if (node == nullptr) {
            throw std::runtime_error("Value to modify not found.");
        }
        node->data = newVal;
    }

    int getSize() {
        return s;
    }

    bool isEmpty() {
        return s == 0;
    }

    bool find(T element) {
        return findElement(root, element) != nullptr;
    }

    void deleteElement(T element) {
        if (isEmpty()) {
            throw std::runtime_error("Tree is empty.");
        }
        if (!find(element)) {
            throw std::runtime_error("Element not found.");
        }
        root = findAndDelete(root, element);
        s--;
    }

    T getParent(T element) {
        Node* target = findElement(root, element);
        if (target == nullptr || target == root) {
            throw std::runtime_error("No parent found or element is root.");
        }

        Node* parent = findParent(root, target);
        if (parent == nullptr) {
            throw std::runtime_error("Parent not found.");
        }

        return parent->data;
    }

    void preorder() {
        if (isEmpty()) {
            cout << "Tree is empty." << endl;
            return;
        }
        preorderTraversal(root);
        cout << endl;
    }

    void inorder() {
        if (isEmpty()) {
            cout << "Tree is empty." << endl;
            return;
        }
        inorderTraversal(root);
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
        levelOrderTraversal(root);
        cout << endl;
    }

    void bfs() {
        levelOrder();
    }

    void dfs() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }
        dfsHelper(root);
        cout << endl;
    }
};
