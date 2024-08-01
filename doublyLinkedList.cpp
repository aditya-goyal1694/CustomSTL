#include <iostream>
#include <stdexcept>

template <typename T>
class doublyLinkedList {
private:
    
    struct Node {
        T val;
        Node* next;
        Node* prev;

        Node(const T& value) : val(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

    // Helper Functions

    // Merge two sorted lists
    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;
        
        if (left->val < right->val) {
            left->next = merge(left->next, right);
            if (left->next) left->next->prev = left;
            left->prev = nullptr;
            return left;
        } else {
            right->next = merge(left, right->next);
            if (right->next) right->next->prev = right;
            right->prev = nullptr;
            return right;
        }
    }

    // Helper function to split the list into two halves
    void split(Node* source, Node** front, Node** back) {
        Node* slow = source;
        Node* fast = source->next;

        while (fast) {
            fast = fast->next;
            if (fast) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *front = source;
        *back = slow->next;
        if (*back) (*back)->prev = nullptr;
        slow->next = nullptr;
    }

    // Recursive merge sort function
    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;

        Node* front = nullptr;
        Node* back = nullptr;

        split(head, &front, &back);

        front = mergeSort(front);
        back = mergeSort(back);

        return merge(front, back);
    }

public:

    // Constructor

    doublyLinkedList() : head(nullptr), tail(nullptr) {}

    // ------------------------------------------------------------------------------------------------------
    // Destructor

    ~doublyLinkedList() {
        while (head) {
            deleteHead();
        }
    }

    // ------------------------------------------------------------------------------------------------------
    // Accessing List

    void printList(){
        Node* current = head;
        while (current) {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // ------------------------------------------------------------------------------------------------------
    // List Manipulation

    // Insert element at the end
    void insert(T ele) {
        Node* newNode = new Node(ele);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Insert element at a specific position
    void insert(T ele, int pos) {
        if (pos < 0) {
            throw std::out_of_range("Position cannot be negative.");
        }
        Node* newNode = new Node(ele);
        if (pos == 0) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            if (!tail) tail = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < pos - 1 && current; ++i) {
                current = current->next;
            }
            if (current) {
                newNode->next = current->next;
                newNode->prev = current;
                if (current->next) current->next->prev = newNode;
                current->next = newNode;
                if (!newNode->next) tail = newNode;
            } else {
                delete newNode;
                throw std::out_of_range("Position exceeds list length.");
            }
        }
    }

    // Delete the first occurrence of an element
    void deleteNode(T ele) {
        Node* current = head;
        while (current) {
            if (current->val == ele) {
                if (current->prev) current->prev->next = current->next;
                if (current->next) current->next->prev = current->prev;
                if (current == head) head = current->next;
                if (current == tail) tail = current->prev;
                delete current;
                return;
            }
            current = current->next;
        }
        throw std::runtime_error("Element not found.");
    }

    // Delete node at the head
    void deleteHead() {
        if (!head) {
            throw std::runtime_error("Cannot delete from an empty list.");
        }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    void sort() {
        head = mergeSort(head);
        
        tail = head;                    // Update tail after sorting
        while (tail && tail->next) {
            tail = tail->next;
        }
    }

    bool find(T ele){
        Node* current = head;
        while (current) {
            if (current->val == ele) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void reverse() {
        Node* temp = nullptr;
        Node* current = head;
        tail = head;
        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp) {
            head = temp->prev;
        }
    }

    void rotateLeft(int k) {
        if (k < 0) {
            throw std::out_of_range("Rotation count cannot be negative.");
        }
        int len = 0;
        Node* current = head;
        while (current) {
            ++len;
            current = current->next;
        }
        if (len == 0) return;

        k %= len;
        if (k == 0) return;

        Node* newTail = head;
        for (int i = 1; i < len - k; ++i) {
            newTail = newTail->next;
        }
        Node* newHead = newTail->next;
        newTail->next = nullptr;
        newHead->prev = nullptr;

        tail->next = head;
        head->prev = tail;
        tail = newTail;
        head = newHead;
    }

    void rotateRight(int k) {
        if (k < 0) {
            throw std::out_of_range("Rotation count cannot be negative.");
        }
        int len = 0;
        Node* current = head;
        while (current) {
            ++len;
            current = current->next;
        }
        if (len == 0) return;

        k %= len;
        if (k == 0) return;

        Node* newTail = head;
        for (int i = 1; i < len - k; ++i) {
            newTail = newTail->next;
        }
        Node* newHead = newTail->next;
        newTail->next = nullptr;
        newHead->prev = nullptr;

        tail->next = head;
        head->prev = tail;
        tail = newTail;
        head = newHead;
    }

};