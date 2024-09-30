#include <iostream>
#include <stdexcept>
using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T val;
        Node *next;
        Node(T data) : val(data), next(nullptr) {}
    };

    Node *head;

    // HELPER METHODS

    // Helper function to merge two sorted lists
    Node *merge(Node *left, Node *right)
    {
        if (!left)
            return right;
        if (!right)
            return left;
        if (left->val < right->val)
        {
            left->next = merge(left->next, right);
            return left;
        }
        else
        {
            right->next = merge(left, right->next);
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

        while (fast != nullptr)
        {
            fast = fast->next;
            if (fast != nullptr)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *front = source;
        *back = slow->next;
        slow->next = nullptr;
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

    Node *rotate(Node *head, int k)
    {
        if (!head || k == 0)
            return head;

        Node *oldTail = head;
        int len = 1;

        while (oldTail->next)
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
        newTail->next = nullptr;
        oldTail->next = head;

        return newHead;
    }

public:
    // Constructors

    LinkedList() : head(nullptr) {}

    LinkedList(T val)
    {
        head = new Node(val);
    }

    // Destructor

    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // ELEMENT ACCESS

    // To find the node at a specific position
    Node *getNodeAt(int pos) const
    {
        if (pos < 0)
            throw out_of_range("Position cannot be negative");

        Node *curr = head;
        int cnt = 0;
        while (curr != nullptr && cnt < pos)
        {
            curr = curr->next;
            cnt++;
        }
        if (curr == nullptr)
            throw out_of_range("Position out of bounds");
        return curr;
    }

    // Print the list
    void printList() const
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // LIST MANIPULATION

    // Insert at the end
    void insert(T ele)
    {
        Node *newNode = new Node(ele);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
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
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp != nullptr; ++i)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            delete newNode;
            throw out_of_range("Position out of bounds");
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

        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->next && temp->next->next)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
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
            head = head->next;
            delete temp;
            return;
        }

        Node *temp = head;
        while (temp->next && temp->next->val != ele)
        {
            temp = temp->next;
        }

        if (!temp->next)
        {
            throw runtime_error("Element not found");
        }

        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void sort()
    {
        head = mergeSort(head);
    }

    int find(T ele) const
    {
        Node *temp = head;
        int pos = 0;
        while (temp)
        {
            if (temp->val == ele)
                return pos;
            temp = temp->next;
            pos++;
        }
        throw runtime_error("Element not found");
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
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