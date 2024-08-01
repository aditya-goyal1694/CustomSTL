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

};