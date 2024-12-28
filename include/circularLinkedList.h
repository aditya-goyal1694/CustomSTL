#include <iostream>
#include <stdexcept>
using namespace std;

#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

template <typename T>
class CircularLinkedList
{
private:
    struct Node
    {
        T val;
        Node *next;
        Node(T data) : val(data), next(nullptr) {}
    };

    Node *head;

    // HELPER FUNCTIONS

    Node *rotate(Node *head, int k)
    {
        if (!head || k == 0)
            return head;

        Node *oldTail = head;
        int len = 1;

        while (oldTail->next != head)
        {
            oldTail = oldTail->next;
            len++;
        }

        k = k % len;
        if (k == 0)
            return head;

        Node *newTail = head;
        for (int i = 1; i < len - k; i++)
        {
            newTail = newTail->next;
        }

        Node *newHead = newTail->next;
        newTail->next = head; // Closing the circular link
        oldTail->next = newHead;

        return newHead;
    }

public:
    // Constructors
    CircularLinkedList() : head(nullptr) {}

    CircularLinkedList(T val)
    {
        head = new Node(val);
        head->next = head; // Circular link
    }

    // Destructor
    ~CircularLinkedList()
    {
        if (!head)
            return;

        Node *curr = head;
        Node *nextNode;

        do
        {
            nextNode = curr->next;
            delete curr;
            curr = nextNode;
        } while (curr != head);
    }

    // ELEMENT ACCESS

    // To find the node at a specific position
    Node *getNodeAt(int pos) const
    {
        if (pos < 0)
            throw out_of_range("Position cannot be negative");

        Node *curr = head;
        int cnt = 0;
        do
        {
            if (cnt == pos)
                return curr;
            curr = curr->next;
            cnt++;
        } while (curr != head);

        throw out_of_range("Position out of bounds");
    }

    // Print the list
    void printList() const
    {
        if (!head)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        do
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }

    // LIST MANIPULATION

    // Insert at the end
    void insert(T ele)
    {
        Node *newNode = new Node(ele);
        if (!head)
        {
            head = newNode;
            head->next = head; // Circular link
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Closing the circular link
        }
    }

    // Insert at a specific position
    void insert(T ele, int pos)
    {
        if (pos < 0)
            throw out_of_range("Position cannot be negative");

        Node *newNode = new Node(ele);
        if (pos == 0)
        {
            if (!head)
            {
                head = newNode;
                head->next = head; // Circular link
            }
            else
            {
                Node *tail = head;
                while (tail->next != head)
                {
                    tail = tail->next;
                }
                newNode->next = head;
                tail->next = newNode;
                head = newNode;
            }
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos - 1; ++i)
        {
            if (temp->next == head)
                throw out_of_range("Position out of bounds");
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete from the end
    void deleteNode()
    {
        if (!head)
        {
            throw runtime_error("List is empty");
        }

        if (head->next == head)
        { // Only one node
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = head; // Closing the circular link
    }

    // Delete a specific element
    void deleteNode(T ele)
    {
        if (!head)
        {
            throw runtime_error("List is empty");
        }

        if (head->val == ele)
        {
            Node *temp = head;
            Node *tail = head;

            while (tail->next != head)
            {
                tail = tail->next;
            }

            if (tail == head)
            { // Only one node
                delete head;
                head = nullptr;
            }
            else
            {
                head = head->next;
                tail->next = head; // Closing the circular link
                delete temp;
            }
            return;
        }

        Node *temp = head;
        while (temp->next != head && temp->next->val != ele)
        {
            temp = temp->next;
        }

        if (temp->next == head)
        {
            throw runtime_error("Element not found");
        }

        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    int find(T ele) const
    {
        if (!head)
            throw runtime_error("List is empty");

        Node *temp = head;
        int pos = 0;
        do
        {
            if (temp->val == ele)
                return pos;
            temp = temp->next;
            pos++;
        } while (temp != head);

        throw runtime_error("Element not found");
    }

    void reverse()
    {
        if (!head)
            return;

        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;
        Node *tail = head;

        do
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (curr != head);

        head->next = prev; // Close the circular link
        head = prev;       // Set the new head
    }

    void rotateLeft(int k)
    {
        head = rotate(head, k);
    }

    void rotateRight(int k)
    {
        head = rotate(head, -k);
    }
};

#endif