#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class LinkedList{
    private:
        struct Node {
        T val;
        Node* next;
        Node(T data) : val(data), next(nullptr) {}
    };

    Node* head;

    public:

        // Constructors

        LinkedList() : head(nullptr) {}

        LinkedList(T val) {
            head = new Node(val);
        }

        // ------------------------------------------------------------------------------------------------------
        // Destructor

        ~LinkedList() {
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }

        // ------------------------------------------------------------------------------------------------------
        // Element Access

        // To find the node at a specific position
        Node* getNodeAt(int pos) {
            if (pos < 0) throw out_of_range("Position cannot be negative");

            Node* current = head;
            int cnt = 0;
            while (current != nullptr && cnt < pos) {
                current = current->next;
                cnt++;
            }
            if (current == nullptr) throw out_of_range("Position out of bounds");
            return current;
        }
        
        // Print the list
        void printList() {
            Node* temp = head;
            while (temp) {
                cout << temp->val << " -> ";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }

        // ------------------------------------------------------------------------------------------------------
        // List Manipulation

        // Insert at the end
        void insert(T ele) {
            Node* newNode = new Node(ele);
            if (!head) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        // Insert at a specific position
        void insert(T ele, int pos) {
            if (pos < 0) throw out_of_range("Position cannot be negative");

            Node* newNode = new Node(ele);
            if (pos == 0) {
                newNode->next = head;
                head = newNode;
                return;
            }

            Node* temp = head;
            for (int i = 0; i < pos - 1 && temp != nullptr; ++i) {
                temp = temp->next;
            }

            if (temp == nullptr) {
                delete newNode;
                throw out_of_range("Position out of bounds");
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        // Delete from the end
        void deleteNode() {
            if (!head) {
                throw runtime_error("List is empty");
            }

            if (!head->next) {
                delete head;
                head = nullptr;
                return;
            }

            Node* temp = head;
            while (temp->next && temp->next->next) {
                temp = temp->next;
            }

            delete temp->next;
            temp->next = nullptr;
        }

        // Delete a specific element
        void deleteNode(T ele) {
            if (!head) {
                throw runtime_error("List is empty");
            }

            if (head->val == ele) {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }

            Node* temp = head;
            while (temp->next && temp->next->val != ele) {
                temp = temp->next;
            }

            if (!temp->next) {
                throw runtime_error("Element not found");
            }

            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }

};