
#include "singly_circular_ll.h"
#include <iostream>

Node *buildCircle(const int n, Node *&cur, int &size)
{

    // cur = nullptr;

    // make the head (first node)
    // The head points back to itself
    // cur will temporarily point to head

    // for (1..n)
    //      Create a node
    //      cur->next = node
    //      cur = node
    //      cur->next = head // as the current node is the
    //      size++;

    Node* head = new Node{1, nullptr};
    head->next = head;
    cur = head;

    for (int i = 2; i <= n; i++)
    {

        // Create a new node
        Node *node = new Node{i, nullptr};

        // Current node now points to new node.
        cur->next = node;

        // Since new node is at the tail, update it's next pointer to head
        node->next = head;

        // Move the cur pointer to newly created node
        cur = node;

        size++;
    }

    return head;
}

void nextK(Node *&cur, int &size, int k)
{
    if (!cur || size == 0) { 
        std::cout << "Could not traverse list because list is empty.\n";
        return; 
    }
    for (int i = 0; i < (k % size); i++) { 
        cur = cur->next;
    }
}

void delCurrent(Node *&cur, int &size)
{
    if (!cur || size == 0) { 
        std::cout << "Could current node as list is empty\n";
        return;
    }

    // Traverse until you find previous node 
    Node* prev = cur; 
    while(prev->next != cur) { 
        prev = prev->next;
    }

    prev->next = cur->next;

    // Save node to be deleted;
    Node* nodeToDelete = cur; 

    // Update pointer
    cur = cur->next;

    // Safe to delete node now
    delete nodeToDelete;
    nodeToDelete = nullptr; 
    size--;
}

// Displays all nodes in the singly circular linked list
void printOnce(Node *&cur, const int size)
{
    if (!cur || size == 0) {
        std::cout << "Could not print because list is empty.\n"; 
        return;
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << "[" << i << "] " << cur->data << "\n";

        cur = cur->next;
    }
}

void printOnce(Node *head)
{

    if (!head) {
        std::cout << "Could not print because list is empty.\n"; 
        return;
    } 

    Node *cur = head;
    int i = 0;

    do
    {
        std::cout << "[" << i << "] " << cur->data << "\n";
        cur = cur->next;
        i++;

    } while (cur != head);
}

void deleteCircle(Node *&head, int &size)
{

    if (!head || size == 0) { 
        std::cout << "Could not delete because list is already empty.\n"; 
        return;
    } 
    Node *cur = head;

    for (int i = 0; i < size; i++)
    {

        Node *next = cur->next;
        delete cur;
        cur = next;
    }

    head = nullptr;
    size = 0;
}