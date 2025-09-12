
#ifndef SINGLY_CIRCULAR_LL_H
#define SINGLY_CIRCULAR_LL_H

// Defines node of the linked list
struct Node { 
    int data; 
    Node* next; 
};


// Builds a circular list of 1..n nodes, returns pointer to head,
// initializes cur appropriately, and sets size=n. Values of nodes will be initialized from 1..n
Node* buildCircle(int n, Node*& cur, int& size); 

// Advances cur by k % size steps
void nextK(Node* & cur, int& size, int k);

// Deletes the node at cur, updates links, and sets cur = next node
void delCurrent(Node* & cur, int& size);

// Prints the list once around starting from cur (or EMTPY if size = 0);

void printOnce(Node* cur);



#endif // SINGLY_CIRCULAR_LL_H