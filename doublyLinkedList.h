#include <iostream>
#include <stdexcept>
using namespace std;

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template <typename T>
class doublyLinkedList
{
private:
    struct Node
    {
        T val;
        Node *next;
        Node *prev;

        Node(const T &value) : val(value), next(nullptr), prev(nullptr) {}
    };

    Node *head;
    Node *tail;

    // Helper Functions

    // Merge two sorted lists
    Node *merge(Node *left, Node *right)
    {
        if (!left)
            return right;
        if (!right)
            return left;

        if (left->val < right->val)
        {
            left->next = merge(left->next, right);

            if (left->next)
                left->next->prev = left;

            left->prev = nullptr;
            return left;
        }
        else
        {
            right->next = merge(left, right->next);

            if (right->next)
                right->next->prev = right;

            right->prev = nullptr;
            return right;
        }
    }

    // Helper function to split the list into two halves
    void split(Node *source, Node **front, Node **back)
    {
        if (!source)
        {
            *front = nullptr;
            *back = nullptr;
            return;
        }

        Node *slow = source;
        Node *fast = source->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        *front = source;
        *back = slow->next;
        slow->next = nullptr;

        if (*back)
            (*back)->prev = nullptr;
    }

    Node *mergeSort(Node *head)
    {
        if (!head || !head->next)
            return head;

        Node *front = nullptr;
        Node *back = nullptr;

        split(head, &front, &back);

        front = mergeSort(front);
        back = mergeSort(back);

        return merge(front, back);
    }

public:
    // Constructor

    doublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor

    ~doublyLinkedList()
    {
        while (head)
        {
            deleteHead();
        }
    }

    // Accessing List

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

    void printList() const
    {
        Node *curr = head;

        while (curr)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }

        cout << endl;
    }

    // List Manipulation

    // Insert element at the end
    void insert(T ele)
    {
        Node *newNode = new Node(ele);

        if (!head)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Insert element at a specific position
    void insert(T ele, int pos)
    {
        if (pos < 0)
        {
            throw std::out_of_range("Position cannot be negative.");
        }

        Node *newNode = new Node(ele);
        if (pos == 0)
        {
            newNode->next = head;

            if (head)
                head->prev = newNode;
            head = newNode;

            if (!tail)
                tail = newNode;
        }
        else
        {
            Node *curr = head;

            for (int i = 0; i < pos - 1 && curr; ++i)
            {
                curr = curr->next;
            }

            if (curr)
            {
                newNode->next = curr->next;
                newNode->prev = curr;

                if (curr->next)
                    curr->next->prev = newNode;
                curr->next = newNode;

                if (!newNode->next)
                    tail = newNode;
            }
            else
            {
                delete newNode;
                throw std::out_of_range("Position exceeds list length.");
            }
        }
    }

    // Delete the first occurrence of an element
    void deleteNode(T ele)
    {
        Node *curr = head;
        while (curr)
        {
            if (curr->val == ele)
            {
                if (curr->prev)
                    curr->prev->next = curr->next;
                if (curr->next)
                    curr->next->prev = curr->prev;
                if (curr == head)
                    head = curr->next;
                if (curr == tail)
                    tail = curr->prev;

                delete curr;
                return;
            }
            curr = curr->next;
        }
        throw std::runtime_error("Element not found.");
    }

    // Delete node at the head
    void deleteHead()
    {
        if (!head)
        {
            throw std::runtime_error("Cannot delete from an empty list.");
        }

        Node *temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete temp;
    }

    void sort()
    {
        head = mergeSort(head);

        tail = head; // Update tail after sorting
        while (tail && tail->next)
        {
            tail = tail->next;
        }
    }

    bool find(T ele) const
    {
        Node *curr = head;
        while (curr)
        {
            if (curr->val == ele)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void reverse()
    {
        Node *temp = nullptr;
        Node *curr = head;
        tail = head;
        while (curr)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp)
        {
            head = temp->prev;
        }
    }

    void rotateLeft(int k)
    {
        if (k < 0)
        {
            throw std::out_of_range("Rotation count cannot be negative.");
        }
        int len = 0;
        Node *curr = head;
        while (curr)
        {
            ++len;
            curr = curr->next;
        }
        if (len == 0)
            return;

        k %= len;
        if (k == 0)
            return;

        Node *newTail = head;
        for (int i = 1; i < len - k; ++i)
        {
            newTail = newTail->next;
        }
        Node *newHead = newTail->next;
        newTail->next = nullptr;
        if (newHead)
            newHead->prev = nullptr;

        tail->next = head;
        if (head)
            head->prev = tail;
        tail = newTail;
        head = newHead;
    }

    void rotateRight(int k)
    {
        if (k < 0)
        {
            throw std::out_of_range("Rotation count cannot be negative.");
        }
        int len = 0;
        Node *curr = head;
        while (curr)
        {
            ++len;
            curr = curr->next;
        }
        if (len == 0)
            return;

        k %= len;
        if (k == 0)
            return;

        Node *newTail = head;
        for (int i = 1; i < len - k; ++i)
        {
            newTail = newTail->next;
        }
        Node *newHead = newTail->next;
        newTail->next = nullptr;
        newHead->prev = nullptr;

        tail->next = head;
        if (head)
            head->prev = tail;
        tail = newTail;
        head = newHead;
    }
};

#endif