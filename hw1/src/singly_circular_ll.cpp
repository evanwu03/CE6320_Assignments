
#include "singly_circular_ll.h"




Node* buildCircle(const int n, Node*& cur, int& size) { 

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

    Node* head = new Node{.data = 1, .next = nullptr};
    head->next = head;

    cur = head; 

    for (int i = 0; i < n; i++) { 
        
    }

}

void nextK(Node* & cur, int& size, int k) { 



}

void delCurrent(Node* & cur, int& size) { 



}


void printOnce(Node* cur) { 



}